

#ifndef raguna_h
#define raguna_h


enum
{
	kBottomScreen = 0,
	kTopScreen = 1
	
};

enum
{
	k16colors = 0,
	k256colors = 1
	
};

// count backwards and auto assign sprite nums (bottom screen)
int bottom_spritenum();

// count backwards and auto assign sprite nums (top screen)
int top_spritenum();

// keep track of pallete numbers
int pallete_num();

// loads a pallete and returns its number for use by later funcitons
int load_pallete(const unsigned short* pallete);

#endif	// RAGUNA_H