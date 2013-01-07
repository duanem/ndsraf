
#include <PA9.h>
#include "all_gfx.h"

#include "raguna.h"

#include "View.h"
#include "Control.h"

#include "Tab.h"

#include <algorithm>
#include <vector>



Tab::Tab(View* superview, const Point& point, const unsigned char* sprite, const PA_BgStruct* background, Controller* controller)
: Control(superview, point)
, mSuperView(superview)
, mScreenNum(get_mScreen())
, mPoint(get_Global(point))
, mName(sprite)
, mBackGround(background)
, mController(controller)
, mFrame(false)
, mShown(false)
, disabled(false)
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
		, mPoint.get_mX(), mPoint.get_mY());
}

void Tab::hide()
{
	PA_DeleteSprite(mScreenNum, mSpriteNum);
}

void Tab::display()
{
	while(mShown == false)
	{
		for(std::vector<Control*>::iterator ControlIter = tab.begin(); ControlIter != tab.end(); ++ControlIter)
		{
			(*ControlIter)->show();
		}
		if(mScreenNum == kBottomScreen)
			PA_LoadBackground(mScreenNum, 3, const_cast<PA_BgStruct*>(mBackGround));
		mShown = true;
	}
}

void Tab::conceal()
{
	while(mShown == true)
	{
		for(std::vector<Control*>::iterator ControlIter = tab.begin(); ControlIter != tab.end(); ++ControlIter)
		{
			(*ControlIter)->hide();
		}
		if(mScreenNum == kBottomScreen)
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
	if(!disabled)
	{
		for(std::vector<Control*>::iterator ControlIter = tab.begin(); ControlIter != tab.end(); ++ControlIter)
		{
			(*ControlIter)->handle();
		}
		mController->handleKey();
	}
}

void Tab::set_disabled(bool set)
{
	disabled = set;
}

void Tab::add(Control* c)
{
	tab.push_back(c);
}

void Tab::set_mFrame(bool set)
{
	mFrame = set;
}

bool Tab::get_mFrame() const
{
	return mFrame;
}

int Tab::get_mSpriteNum() const
{
	return mSpriteNum;
}

int Tab::pallet_num()
{
	static int pallete = -1;
	if (pallete < 0)
		pallete = load_pallete(Tab_Pal);
	return pallete;
}

// ---------------------------------------------------------------------------------------------------------------------------

TabGroup::TabGroup(View* superview, const Point& point, Controller* controller)
: Control(superview, point)
, mSuperView(superview)
, mScreenNum(get_mScreen())
, mPoint(get_Global(point))
, mController(controller)
, CurTab(0)
, NewTab(CurTab)
, disabled(false)

{
}

TabGroup::~TabGroup()
{
}

void TabGroup::show()
{
	CurTab = 0; // always show the first tab when reloading an entire TabGroup
	for(std::vector<Tab*>::iterator TabIter = tabs.begin(); TabIter != tabs.end(); ++TabIter)
	{
		(*TabIter)->show();
	}
	tabs[CurTab]->display();
}

void TabGroup::hide()
{
	for(std::vector<Tab*>::iterator TabIter = tabs.begin(); TabIter != tabs.end(); ++TabIter)
	{
		(*TabIter)->hide();
	}
	tabs[CurTab]->conceal();
}

void TabGroup::draw() 
{
	if(CurTab != NewTab)
	{
		tabs[CurTab]->conceal();
		CurTab = NewTab;
		tabs[CurTab]->display();
	}
	
	for(std::vector<Tab*>::iterator TabIter = tabs.begin(); TabIter != tabs.end(); ++TabIter)
	{
		(*TabIter)->set_mFrame(false);
		
		tabs[CurTab]->set_mFrame(true);
		
		(*TabIter)->draw();
	}
}

void TabGroup::update()
{
	tabs[CurTab]->handle();
	tabs[CurTab]->update();
}

void TabGroup::handle()
{
	if(!disabled)
	{
		using namespace nsTG;
		
		std::vector<Tab*>::iterator found;
		unsigned int touched = 0;
		
		if(Stylus.Released)
		{	
			// check to see if one in the group was touched
			found = std::find_if(tabs.begin(), tabs.end(), wasTouched);
			
			// assign numerical place of the one found (tabs.size() = not found)
			touched = std::distance(tabs.begin(), found);
			
			if(touched != tabs.size())
			{
				NewTab = touched;
			}
		}
		else
			mController->handleKey();
	}
}

void TabGroup::set_disabled(bool set)
{
	disabled = set;
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

int TabGroup::get_CurTab() const
{
	return CurTab;
}

int TabGroup::get_NewTab() const
{
	return NewTab;
}

int TabGroup::size() const
{
	return tabs.size();
}

// --------------------------------------------------------------------------------------------------------------------------
namespace nsTG
{
	bool wasTouched(Tab* tab)
	{
		return (PA_SpriteStylusOver(tab->get_mSpriteNum()) && tab->get_mScreen() == kBottomScreen);
	}
}

