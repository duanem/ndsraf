
#include <PA9.h>
#include "all_gfx.h"

#include "raguna.h"

#include "CheckBox.h"



CheckBox::CheckBox(int screen, int x, int y, const unsigned char* sprite)
: mScreenNum(screen)
, mXCo(x), mYCo(y)
, mName(sprite)
, mFrame(false)
, disabled(false)
{
	if(mScreenNum == kBottomScreen)
	{
		mSpriteNum = bottom_spritenum();
		mTitleSpriteNum = bottom_spritenum();
	}
	else if(mScreenNum == kTopScreen)
	{
		mSpriteNum = top_spritenum();
		mTitleSpriteNum = top_spritenum();
	}
}

CheckBox::~CheckBox()
{
}

void CheckBox::show()
{
	/// CheckBox
	PA_CreateSprite(
	      mScreenNum // screen
		, mSpriteNum	// Sprite number (auto generated)
		, (void*)CheckBox_Sprite // Sprite mName (changes based off of class being called from)
		, OBJ_SIZE_16X16 // Sprite size
		, k256colors // 256 colormode
		, pallet_num() //Sprite palette number
		, mXCo, mYCo);
	
	/// title
	PA_CreateSprite(
		  mScreenNum
		, mTitleSpriteNum
		, const_cast<unsigned char*>(mName)
		, OBJ_SIZE_64X32
		, k256colors
		, titlepallet_num()
		, mXCo - 70, mYCo - 8);
		
	PA_SetSpriteAnim(mScreenNum, mSpriteNum, mFrame);
}

void CheckBox::hide()
{
	PA_DeleteSprite(mScreenNum, mSpriteNum);
	PA_DeleteSprite(mScreenNum, mTitleSpriteNum);
}

void CheckBox::draw()
{	
	PA_SetSpriteAnim(mScreenNum, mSpriteNum, mFrame);
}

void CheckBox::handle()
{
	if(!disabled)
	{
		if(Stylus.Released && mScreenNum == kBottomScreen && 
		  (PA_SpriteStylusOver(mSpriteNum) || PA_SpriteStylusOver(mTitleSpriteNum)))
			mFrame = !mFrame;
	}
}

void CheckBox::disable()
{
	disabled = true;
}

void CheckBox::enable()
{
	disabled = false;
}

void CheckBox::set_mFrame(bool frame)
{
	mFrame = frame;
}

bool CheckBox::get_mFrame()
{
	return mFrame;
}

int CheckBox::get_mSpriteNum()
{
	return mSpriteNum;
}

int CheckBox::get_mScreen()
{
	return mScreenNum;
}

int CheckBox::pallet_num()
{
	static int pallete = -1;
	if (pallete < 0)
		pallete = load_pallete(CheckBox_Pal);
	return pallete;
}

int CheckBox::titlepallet_num()
{
	static int pallete = -1;
	if (pallete < 0)
		pallete = load_pallete(Title_Pal);
	return pallete;
}

// ------------------------------------------------------------------------------------------------------------------------

SpecialBox::SpecialBox(int screen, int x, int y, const unsigned char* sprite)
: CheckBox(screen, x, y, sprite)
, mScreenNum(screen)
, mXCo(x), mYCo(y)
, mName(sprite)
, mFrame(false)
, disabled(false)
{
	if(mScreenNum == kBottomScreen)
		mSpriteNum = bottom_spritenum();
	else if(mScreenNum == kTopScreen)
		mSpriteNum = top_spritenum();
}

SpecialBox::~SpecialBox()
{
}

void SpecialBox::show()
{
	/// SpecialBox
	PA_CreateSprite(
	      mScreenNum // screen
		, mSpriteNum	// Sprite number (auto generated)
		, const_cast<unsigned char*>(mName)
		, OBJ_SIZE_64X32 // Sprite size
		, k256colors // 256 colormode
		, pallet_num() //Sprite palette number
		, mXCo, mYCo);
		
	PA_SetSpriteAnim(mScreenNum, mSpriteNum, mFrame);
}

void SpecialBox::hide()
{
	PA_DeleteSprite(mScreenNum, mSpriteNum);
}

void SpecialBox::draw()
{	
	PA_SetSpriteAnim(mScreenNum, mSpriteNum, mFrame);
}

void SpecialBox::handle()
{
	if(!disabled)
	{
		if(Stylus.Released && mScreenNum == kBottomScreen && 
		   PA_SpriteStylusOver(mSpriteNum))
			mFrame = !mFrame;
	}
}

void SpecialBox::disable()
{
	disabled = true;
}

void SpecialBox::enable()
{
	disabled = false;
}

void SpecialBox::set_mFrame(bool frame)
{
	mFrame = frame;
}

bool SpecialBox::get_mFrame()
{
	return mFrame;
}

int SpecialBox::get_mSpriteNum()
{
	return mSpriteNum;
}

int SpecialBox::get_mScreen()
{
	return mScreenNum;
}

int SpecialBox::pallet_num()
{
	static int pallete = -1;
	if (pallete < 0)
		pallete = load_pallete(Type_Pal);
	return pallete;
}