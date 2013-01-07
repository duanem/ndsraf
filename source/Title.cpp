
#include <PA9.h>
#include "all_gfx.h"

#include "raguna.h"

#include "View.h"
#include "Title.h"
#include "Point.h"


Title::Title(View* superview, const Point& point, const unsigned char* sprite)
: View(superview, get_mScreen(), point)
, mSuperView(superview)
, mScreenNum(get_mScreen())
, mPoint(get_Global(point))
, mName(sprite)
{
	mScreenNum = get_mScreen();
	mPoint = get_Global(point);
	if(mScreenNum == kBottomScreen)
		mSpriteNum = bottom_spritenum();
	else if(mScreenNum == kTopScreen)
		mSpriteNum = top_spritenum();
}

Title::~Title()
{
}

void Title::show()
{
	/// Title
	PA_CreateSprite(
	      mScreenNum // screen
		, mSpriteNum	// Sprite number (auto generated)
		, const_cast<unsigned char*>(mName)
		, OBJ_SIZE_64X32 // Sprite size
		, k256colors // 256 colormode
		, pallet_num() //Sprite palette number
		, mPoint.get_mX(), mPoint.get_mY());
		
}

void Title::hide()
{
	PA_DeleteSprite(mScreenNum, mSpriteNum);
}

int Title::pallet_num()
{
	static int pallete = -1;
	if (pallete < 0)
		pallete = load_pallete(Title_Pal);
	return pallete;
}