
#ifndef raguna_radiobtn_h
#define raguna_radiobtn_h


#include "control.h"

#include <vector>



class RadioButton : public Control{

public:

	/// constructor
	RadioButton(int screen, int x, int y, const unsigned char* sprite);
	
	/// deconstructor
	~RadioButton();
	
	/// display to screen
	void show();
	
	/// take off screen
	void hide();
	
	/// update
	void draw();
	
	/// handle touches
	void handle();

	/// mFrame control
	void set_mFrame(bool set);
	
	/// return mFrame
	bool get_mFrame();
	
	/// return mSpriteNum
	int get_mSpriteNum();
	
	/// return mScreenNum
	int get_mScreen();
	
private:

	static int pallet_num();
	
	int mScreenNum;
	int mSpriteNum;
	const unsigned char* mName;
	int mXCo, mYCo;
	bool mFrame;
	
};

/// RBGroupS keep track of radio buttons, updating them together, wheras radio_buttons are members of a radio_button_group
class RBGroup : public Control {

public:
	
	/// constructor
	RBGroup();
	
	/// deconstructor
	~RBGroup();
	
	/// display sprites in group
	void show();
	
	/// hide sprites in group
	void hide();
	
	/// update group
	void draw();
	
	/// turn all radiobuttons off
	void disable();
	
	/// handle touches as a group
	void handle();
	
	/// add a RadioButton to the group
	void add(RadioButton* rb);
	
	/// assigns RadioButton to be true.  -1 = all false
	void set_CurRB(int rb);
	
	/// returns RadioButton that is true.  -1 = all false
	int get_CurRB();
	
private:
	
	std::vector<RadioButton*> rbg;
	
};

namespace nsRB
{
	bool getFrame(RadioButton* rb);

	bool wasTouched(RadioButton* rb);
}

#endif