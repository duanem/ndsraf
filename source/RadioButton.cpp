
#include <PA9.h>
#include "all_gfx.h"

#include "raguna.h"

#include "RadioButton.h"



RadioButton::RadioButton(int screen, int x, int y, const unsigned char* sprite)
: mScreenNum(screen)
, mName(sprite)
, mXCo(x), mYCo(y)
, mFrame(false)
{
	if(mScreenNum == kBottomScreen)
		mSpriteNum = bottom_spritenum();
	else if(mScreenNum == kTopScreen)
		mSpriteNum = top_spritenum();
}

RadioButton::~RadioButton()
{
}

void RadioButton::show()
{
	PA_CreateSprite(
		  mScreenNum
		, mSpriteNum
		, const_cast<unsigned char*>(mName)
		, OBJ_SIZE_64X32
		, k256colors
		, pallet_num()
		, mXCo, mYCo);
		
	PA_SetSpriteAnim(mScreenNum, mSpriteNum, mFrame);
}

void RadioButton::hide()
{
	PA_DeleteSprite(mScreenNum, mSpriteNum);
}

void RadioButton::draw()
{
	PA_SetSpriteAnim(mScreenNum, mSpriteNum, mFrame);
}

// no need to handle touches on RadioButtons, RBGroup's do that for us
void RadioButton::handle()
{
}

void RadioButton::set_mFrame(bool set)
{
	mFrame = set;
}

bool RadioButton::get_mFrame()
{
	return mFrame;
}

int RadioButton::get_mSpriteNum()
{
	return mSpriteNum;
}

int RadioButton::get_mScreen()
{
	return mScreenNum;
}

int RadioButton::pallet_num()
{
	static int pallete = -1;
	if (pallete < 0)
		pallete = load_pallete(Type_Pal);
	return pallete;
}

// ------------------------------------------------------------------------------------------------------------------------------
RBGroup::RBGroup()
{	
}

RBGroup::~RBGroup()
{
}

void RBGroup::show()
{
	for(std::vector<RadioButton*>::iterator rbgIter = rbg.begin(); rbgIter != rbg.end(); ++rbgIter)
	{
		(*rbgIter)->show();
	}
}

void RBGroup::hide()
{
	for(std::vector<RadioButton*>::iterator rbgIter = rbg.begin(); rbgIter != rbg.end(); ++rbgIter)
	{
		(*rbgIter)->hide();
	}
}
	
void RBGroup::draw()
{
	for(std::vector<RadioButton*>::iterator rbgIter = rbg.begin(); rbgIter != rbg.end(); ++rbgIter)
	{
		(*rbgIter)->draw();
	}
}

void RBGroup::disable()
{
	for(std::vector<RadioButton*>::iterator rbgIter = rbg.begin(); rbgIter != rbg.end(); ++rbgIter)
	{
		(*rbgIter)->set_mFrame(false);
	}
}

void RBGroup::handle()
{
	for(std::vector<RadioButton*>::iterator rbgIter = rbg.begin(); rbgIter != rbg.end(); ++rbgIter)
	{
		if(Stylus.Released && (*rbgIter)->get_mScreen() == kBottomScreen && PA_SpriteStylusOver((*rbgIter)->get_mSpriteNum()))
		{
			for(std::vector<RadioButton*>::iterator rbgIter2 = rbg.begin(); rbgIter2 != rbg.end(); ++rbgIter2)
			{
				if((*rbgIter2) != (*rbgIter))
				{
					(*rbgIter2)->set_mFrame(false);
				}
			}
			
			(*rbgIter)->set_mFrame(true);
		}
	}
}

void RBGroup::add(RadioButton* rb)
{
	rbg.push_back(rb);
}

void RBGroup::set_CurRB(int rb)
{
	for(std::vector<RadioButton*>::iterator rbgIter = rbg.begin(); rbgIter != rbg.end(); ++rbgIter)
	{
		(*rbgIter)->set_mFrame(false);
	}
	
	rbg[rb]->set_mFrame(true);
}

int RBGroup::get_CurRB()
{
	for(unsigned int i = 0; i < rbg.size(); ++i)
	{
		if(rbg[i]->get_mFrame() == true)
			return i;
			
		// possibly returning nothing = dangerous
		// want to break out of for loop (and function) at return of i,
		// if no return by end of for loop, return a default number (standing for no RadioButton)
	}
}
