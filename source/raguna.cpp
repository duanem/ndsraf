

#include <PA9.h>

#include "raguna.h"



// count backwards and auto assign sprite nums (bottom screen)
int bottom_spritenum()
{
	static int cur_bottom_spritenum = 127;
	return cur_bottom_spritenum--;
}

// count backwards and auto assign sprite nums (top screen)
int top_spritenum()
{
	static int cur_top_spritenum = 127;
	return cur_top_spritenum--;
}

// keep track of pallete numbers
int pallete_num()
{
	static int pallete_index = 0;
	return pallete_index++;
}

// loads a pallete with any name you want and returns its number for use by later funcitons
int load_pallete(const unsigned short* pallete)
{
	int pallete_result = pallete_num();
	PA_LoadSpritePal(kBottomScreen,
					 pallete_result,
					 const_cast<unsigned short*>(pallete));
	PA_LoadSpritePal(kTopScreen,
					 pallete_result,
					 const_cast<unsigned short*>(pallete));
	return pallete_result;
}