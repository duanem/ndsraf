
#ifndef raguna_checkbox_h
#define raguna_checkbox_h


#include  "Control.h"

#include "View.h"
#include "Point.h"



class CheckBox : public Control {

public:

	/// constructor
	CheckBox(View* superview, const Point& point, const unsigned char* sprite);
	
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
	
	/// change disabled state
	virtual void set_disabled(bool set);
	
	/// return mFrame
	virtual bool get_mFrame() const;
	
	/// frame control
	virtual void set_mFrame(bool frame);
	
	/// return mSpriteNum
	virtual int get_mSpriteNum() const;

	/// return mTitleSpriteNum
	int get_mTitleSpriteNum() const;

private:

	static int pallet_num();
	
	static int titlepallet_num();

	View* mSuperView;
	int mScreenNum;
	Point mPoint;
	
	const unsigned char* mName;
	
	int mFrame;
	int disabled;
	
	int mSpriteNum;
	int mTitleSpriteNum;
};

class SpecialBox : public CheckBox {

public:

	/// constructor
	SpecialBox(View* superview, const Point& point, const unsigned char* sprite);
	
	/// deconstuctor
	~SpecialBox();

	/// display sprite on screen
	void show();
	
	/// hide sprites off screen
	void hide();
	
	/// update animation
	void draw();

	/// handle touches
	void handle();
	
	/// change disabled state
	void set_disabled(bool set);
	
	/// return mFrame
	bool get_mFrame() const;
	
	/// frame control
	void set_mFrame(bool frame);
	
	/// return mSpriteNum
	int get_mSpriteNum() const;
	
private:

	static int pallet_num();

	View* mSuperView;
	int mScreenNum;
	Point mPoint;
	
	const unsigned char* mName;
	
	int mFrame;
	int disabled;
	
	int mSpriteNum;
	
};

#endif