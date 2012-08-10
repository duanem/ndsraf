
#ifndef raguna_checkbox_h
#define raguna_checkbox_h


#include  "Control.h"



class CheckBox : public Control {

public:

	/// constructor
	CheckBox(int screen, int x, int y, const unsigned char* sprite);
	
	/// deconstuctor
	virtual ~CheckBox();

	/// display sprite on screen
	virtual void show();
	
	/// hide sprites off screen
	virtual void hide();
	
	/// update
	virtual void draw();
	
	/// handle touches
	virtual void handle();
	
	virtual void disable();
	
	virtual void enable();
	
	/// return mFrame
	virtual bool get_mFrame();
	
	/// frame control
	virtual void set_mFrame(bool frame);
	
	/// return mSpriteNum
	virtual int get_mSpriteNum();
	
	/// return mScreenNum
	virtual int get_mScreen();
	
private:

	static int pallet_num();
	
	static int titlepallet_num();

	int mScreenNum;
	int mSpriteNum;
	int mTitleSpriteNum;
	int mXCo, mYCo;
	const unsigned char* mName;
	bool mFrame;
	bool disabled;
};

class SpecialBox : public CheckBox {

public:

	/// constructor
	SpecialBox(int screen, int x, int y, const unsigned char* sprite);
	
	/// deconstuctor
	~SpecialBox();

	/// display sprite on screen
	void show();
	
	/// hide sprites off screen
	void hide();
	
	/// update frame
	void draw();
	
	/// handle touches
	void handle();
	
	/// do not allow touches
	void disable();
	
	/// allow touches
	void enable();
	
	/// return mFrame
	bool get_mFrame();
	
	/// frame control
	void set_mFrame(bool frame);
	
	/// return mSpriteNum
	int get_mSpriteNum();
	
	/// return mScreenNum
	int get_mScreen();
	
private:

	static int pallet_num();

	int mScreenNum;
	int mSpriteNum;
	int mXCo, mYCo;
	const unsigned char* mName;
	bool mFrame;
	bool disabled;
	
};

#endif