
#include <PA9.h>
#include "all_gfx.h"

#include "raguna.h"

#include "RadioButton.h"
#include "View.h"
#include "Point.h"

#include <algorithm>
#include <vector>



RadioButton::RadioButton(View* superview, const Point& point, const unsigned char* sprite)
: Control(superview)
, mSuperView(superview)
, mScreenNum(get_mScreen())
, mPoint(get_Global(point))
, mName(sprite)
, mFrame(false)
, disabled(false)
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
		, mPoint.get_mX(), mPoint.get_mY());
		
	if(!disabled)
		PA_SetSpriteAnim(mScreenNum, mSpriteNum, mFrame);
}

void RadioButton::hide()
{
	PA_DeleteSprite(mScreenNum, mSpriteNum);
}

void RadioButton::draw()
{
	if(!disabled)
		PA_SetSpriteAnim(mScreenNum, mSpriteNum, mFrame);
}

// no need to handle touches on RadioButtons, RBGroup's do that for us
void RadioButton::handle()
{
}

void RadioButton::set_disabled(bool set)
{
	disabled = set;
}
	
void RadioButton::set_mFrame(bool set)
{
	mFrame = set;
}

bool RadioButton::get_mFrame() const
{
	return mFrame;
}

int RadioButton::get_mSpriteNum() const
{
	return mSpriteNum;
}

int RadioButton::pallet_num()
{
	static int pallete = -1;
	if (pallete < 0)
		pallete = load_pallete(Type_Pal);
	return pallete;
}

// ------------------------------------------------------------------------------------------------------------------------------
RBGroup::RBGroup(View* superview, const Point& point)
: Control(superview)
, mSuperView(superview)
, mScreenNum(get_mScreen())
, mPoint(get_Global(point))
, disabled(false)
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
	{
		for(std::vector<RadioButton*>::iterator rbgIter = rbg.begin(); rbgIter != rbg.end(); ++rbgIter)
		{
			(*rbgIter)->draw();
		}
	}
}

void RBGroup::set_disabled(bool set)
{
	disabled = set;
}

void RBGroup::handle()
{
	if(!disabled)
	{
		using namespace nsRB;
		
		std::vector<RadioButton*>::iterator found;
		unsigned int touched = 0;
		
		if(Stylus.Released)
		{	
			// check to see if one in the group was touched
			found = std::find_if(rbg.begin(), rbg.end(), wasTouched);
			
			// assign numerical place of the one found (rbg.size() = not found)
			touched = std::distance(rbg.begin(), found);
			
			if(touched != rbg.size())
			{
				for(std::vector<RadioButton*>::iterator rbgIter = rbg.begin(); rbgIter != rbg.end(); ++rbgIter)
				{
					(*rbgIter)->set_mFrame(false);
				}
				
			(*found)->set_mFrame(true);
			}
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
	
	if(rb != -1)
		rbg[rb]->set_mFrame(true);
}

int RBGroup::get_CurRB()
{
	using namespace nsRB;
	
	std::vector<RadioButton*>::iterator found;
	unsigned int result = 0;
	
	//look through group for one that is true
	found = std::find_if(rbg.begin(), rbg.end(), getFrame);
		
	//record position of the one that was true (rbg.size() = not found)
	result = std::distance(rbg.begin(), found);
	
	if(result == rbg.size())
	{
		result = -1;
	}
	
	return result;
}

namespace nsRB
{
	bool getFrame(RadioButton* rb)
	{
		return rb->get_mFrame();
	}

	bool wasTouched(RadioButton* rb)
	{
		return (PA_SpriteStylusOver(rb->get_mSpriteNum()) && rb->get_mScreen() == kBottomScreen);
	}
}

