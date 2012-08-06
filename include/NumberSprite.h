
#ifndef _raguna_NumSprite_h
#define _raguna_NumSprite_h

#include "control.h"

#include <vector>



class NumberSprite : public Control {

public:
	
	/// constructor
	NumberSprite(int screen, int x, int y, const unsigned char* title);
	
	/// destructor
	~NumberSprite();
	
	/// display
	void show();
	
	/// take off screen
	void hide();
	
	/// update
	void draw();
	
	/// handle touches
	void handle();
	
	/// return mFrame
	int get_mFrame();
	
	/// frame control
	void set_mFrame(int value);
	
	/// ++mFrame;
	void inc_mFrame();
	
	/// --mFrame;
	void dec_mFrame();
	
private:
	
	/// calculate the number of digits that mFrame has
	int calc_digit();
	
	/// increase number of digits
	void add_digit();
	
	/// decrease number of digits
	void del_digit();
	
	static int pallet_num();
	static int titlepallet_num();
	
	
	int mScreenNum;
	int mTitleSpriteNum;
	const unsigned char* mName;
	int mFrame;
	
	int mDigits;
	
	int mYCo;
	std::vector<int> mXCos;
	
	std::vector<int> mSpriteNums;
	
};
	

#endif