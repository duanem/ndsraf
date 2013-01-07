
#ifndef _raguna_NumSprite_h
#define _raguna_NumSprite_h

#include "Control.h"

#include "View.h"
#include "Point.h"

#include <vector>



class NumberSprite : public Control {

public:
	
	/// constructor
	NumberSprite(View* superview, const Point& point, const unsigned char* sprite);
	
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
	int get_mFrame() const;
	
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
	
	View* mSuperView;
	
	int mScreenNum;
	Point mPoint;
	
	int mYCo;
	std::vector<int> mXCos;
	
	std::vector<int> mSpriteNums;
	
	const unsigned char* mName;
	int mTitleSpriteNum;
	
	int mFrame;
	int mDigits;
	
};
	

#endif