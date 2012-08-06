
#include <PA9.h>
#include "all_gfx.h"

#include "raguna.h"

#include "view.h"
#include "control.h"

#include "tab.h"

#include <vector>



Tab::Tab(int screen, int x, int y, const unsigned char* sprite, const PA_BgStruct* background, Controller* controller)
: mScreenNum(screen)
, mXCo(x), mYCo(y)
, mName(sprite)
, mFrame(false)
, mShown(false)
, mBackGround(background)
, mController(controller)
{
	if(mScreenNum == kBottomScreen)
		mSpriteNum = bottom_spritenum();
	else if(mScreenNum == kTopScreen)
		mSpriteNum = top_spritenum();
}

Tab::~Tab()
{
}

void Tab::show()
{
	PA_CreateSprite(
	      mScreenNum // screen
		, mSpriteNum	// Sprite number (auto generated)
		, const_cast<unsigned char*>(mName) // Sprite name (changes based off of class being called from)
		, OBJ_SIZE_64X32 // Sprite size
		, k256colors // 256 colormode
		, pallet_num() //Sprite palette number
		, mXCo, mYCo);
}

void Tab::hide()
{
	PA_DeleteSprite(mScreenNum, mSpriteNum);
}

void Tab::enable()
{
	while(mShown == false)
	{
		for(std::vector<Control*>::iterator ControlIter = tab.begin(); ControlIter != tab.end(); ++ControlIter)
		{
			(*ControlIter)->show();
		}
		PA_LoadBackground(mScreenNum, 3, const_cast<PA_BgStruct*>(mBackGround));
		mShown = true;
	}
}

void Tab::disable()
{
	while(mShown == true)
	{
		for(std::vector<Control*>::iterator ControlIter = tab.begin(); ControlIter != tab.end(); ++ControlIter)
		{
			(*ControlIter)->hide();
		}
		PA_DeleteBg(mScreenNum, 3);
		mShown = false;
	}
}
	

void Tab::draw() 
{
	PA_SetSpriteAnim(mScreenNum, mSpriteNum, mFrame);
}

void Tab::update()
{
	for(std::vector<Control*>::iterator ControlIter = tab.begin(); ControlIter != tab.end(); ++ControlIter)
	{
		(*ControlIter)->draw();
	}
}

void Tab::handle()
{
	for(std::vector<Control*>::iterator ControlIter = tab.begin(); ControlIter != tab.end(); ++ControlIter)
	{
		(*ControlIter)->handle();
	}
	mController->handleKey();
}

void Tab::add(Control* c)
{
	tab.push_back(c);
}

void Tab::set_mFrame(bool set)
{
	mFrame = set;
}

bool Tab::get_mFrame()
{
	return mFrame;
}

int Tab::get_mSpriteNum()
{
	return mSpriteNum;
}

int Tab::get_mScreen()
{
	return mScreenNum;
}

int Tab::pallet_num()
{
	static int pallete = -1;
	if (pallete < 0)
		pallete = load_pallete(Tab_Pal);
	return pallete;
}

// ---------------------------------------------------------------------------------------------------------------------------

TabGroup::TabGroup(Controller* controller)
: CurTab(0)
, NewTab(CurTab)
, mController(controller)
{
}

TabGroup::~TabGroup()
{
}

void TabGroup::show()
{
	for(std::vector<Tab*>::iterator TabIter = tabs.begin(); TabIter != tabs.end(); ++TabIter)
	{
		(*TabIter)->show();
	}
}

void TabGroup::hide()
{
	for(std::vector<Tab*>::iterator TabIter = tabs.begin(); TabIter != tabs.end(); ++TabIter)
	{
		(*TabIter)->hide();
	}
}

void TabGroup::draw() 
{
	tabs[CurTab]->enable();
	
	if(CurTab != NewTab)
	{
		tabs[CurTab]->disable();
		CurTab = NewTab;
		tabs[CurTab]->enable();
	}
	
	for(unsigned int i = 0; i < tabs.size(); ++i)
	{
		int x = i;
		if(x != CurTab)
			tabs[x]->set_mFrame(false);
		else
			tabs[x]->set_mFrame(true);
			
		tabs[i]->draw();
	}
}

void TabGroup::update()
{
	tabs[CurTab]->handle();
	tabs[CurTab]->update();
}

void TabGroup::handle()
{
	if(Stylus.Released)
	{
		for(unsigned int i = 0; i < tabs.size(); ++i)
		{
			if(tabs[i]->get_mScreen() == kBottomScreen && PA_SpriteStylusOver(tabs[i]->get_mSpriteNum()))
			{
				NewTab = i;
			}
		}
	}
	else
		mController->handleKey();
}

void TabGroup::add(Tab* tab)
{
	tabs.push_back(tab);
}

void TabGroup::set_CurTab(int tab)
{
	CurTab = tab;
}

void TabGroup::set_NewTab(int tab)
{
	NewTab = tab;
}

int TabGroup::get_CurTab()
{
	return CurTab;
}

int TabGroup::get_NewTab()
{
	return NewTab;
}

int TabGroup::size()
{
	return tabs.size();
}

