
#include <PA9.h>
#include "all_gfx.h"

#include "raguna.h"

#include "NumberSprite.h"

#include <vector>

NumberSprite::NumberSprite(int screen, int x, int y, const unsigned char* title)
: mScreenNum(screen)
, mName(title)
, mFrame(0)
, mDigits(1)
, mYCo(y)
{
	if(mScreenNum == kBottomScreen)
	{
		mTitleSpriteNum = bottom_spritenum();
		mSpriteNums.push_back(bottom_spritenum());
	}
	else if(mScreenNum == kTopScreen)
	{
		mTitleSpriteNum = top_spritenum();
		mSpriteNums.push_back(top_spritenum());
	}

	mXCos.push_back(x);
}

NumberSprite::~NumberSprite()
{
}

void NumberSprite::show()
{
	// numbers
	for(int i = 0; i < mDigits; ++i)
	{
		PA_CreateSprite(
		  mScreenNum
		, mSpriteNums[i]
		, (void*)Number_Sprite
		, OBJ_SIZE_16X32
		, k256colors
		, pallet_num()
		, mXCos[i], mYCo);
		
		int curValue = get_mFrame();
		
		for(int i = 0; i < mDigits; ++i)
		{
			int newValue = curValue%10;
			curValue = curValue/10;
			
			PA_SetSpriteAnim(mScreenNum, mSpriteNums[i], newValue);
			
		}
	}
	
	// title
	PA_CreateSprite(
		  mScreenNum
		, mTitleSpriteNum
		, const_cast<unsigned char*>(mName)
		, OBJ_SIZE_64X32
		, k256colors
		, titlepallet_num()
		, mXCos[mDigits-1] - 64, mYCo);
}

void NumberSprite::hide()
{
	for(int i = 0; i < mDigits; ++i)
	{
		PA_DeleteSprite(mScreenNum, mSpriteNums[i]);
	}
	
	PA_DeleteSprite(mScreenNum, mTitleSpriteNum);
}

void NumberSprite::draw()
{
	while(calc_digit() < mDigits && calc_digit() != 0)
		del_digit();
	while(calc_digit() > mDigits)
		add_digit();
	
	int curValue = get_mFrame();
		
	for(int i = 0; i < mDigits; ++i)
	{
		int newValue = curValue%10;
		curValue /= 10;
		
		PA_SetSpriteAnim(mScreenNum, mSpriteNums[i], newValue);
	}
}

// no use other than making the class not abstract
void NumberSprite::handle()
{
}

int NumberSprite::get_mFrame()
{
	return mFrame;
}

void NumberSprite::set_mFrame(int value)
{
	mFrame = value;
}

void NumberSprite::inc_mFrame()
{
	++mFrame;
}

void NumberSprite::dec_mFrame()
{
	--mFrame;
}

int NumberSprite::calc_digit()
{
	int digits = 0;
	
	int curValue = get_mFrame();
	
	while(curValue != 0)
	{
		curValue = curValue/10;
		
		++digits;
	}
	
	return digits;
}
	
void NumberSprite::add_digit()
{
	++mDigits;
	
	int totalDigits = mSpriteNums.size();
	if(mDigits > totalDigits)
	{
		if(mScreenNum == kBottomScreen)
			mSpriteNums.push_back(bottom_spritenum());
		else if(mScreenNum == kTopScreen)
			mSpriteNums.push_back(top_spritenum());
			
		mXCos.push_back(mXCos[mDigits-2]-12);
	}
	
	PA_CreateSprite(
		  mScreenNum
		, mSpriteNums[mDigits-1]
		, (void*)Number_Sprite
		, OBJ_SIZE_16X32
		, k256colors
		, pallet_num()
		, mXCos[mDigits-1], mYCo);
		
	PA_SetSpriteXY(
		  mScreenNum
		, mTitleSpriteNum
		, mXCos[mDigits-1] - 64, mYCo);	
}

void NumberSprite::del_digit()
{
	--mDigits;
	
	PA_DeleteSprite(mScreenNum, mSpriteNums[mDigits]);
	
	PA_SetSpriteXY(
		  mScreenNum
		, mTitleSpriteNum
		, mXCos[mDigits-1] - 64, mYCo);
}
	
int NumberSprite::pallet_num()
{
	static int pallete = -1;
	if (pallete < 0)
		pallete = load_pallete(Number_Pal);
	return pallete;
}

int NumberSprite::titlepallet_num()
{
	static int pallete = -1;
	if (pallete < 0)
		pallete = load_pallete(Title_Pal);
	return pallete;
}
