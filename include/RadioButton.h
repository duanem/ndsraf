
#ifndef raguna_radiobtn_h
#define raguna_radiobtn_h


#include "Control.h"
#include "View.h"
#include "Point.h"

#include <vector>



class RadioButton : public Control{

public:

	/// constructor
	RadioButton(View* superview, const Point& point, const unsigned char* sprite);
	
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
	
	/// change disabled state
	void set_disabled(bool set);

	/// mFrame control
	void set_mFrame(bool set);
	
	/// return mFrame
	bool get_mFrame() const;
	
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

/// RBGroupS keep track of radio buttons, updating them together, wheras radio_buttons are members of a radio_button_group
class RBGroup : public Control {

public:
	
	/// constructor
	RBGroup(View* superview, const Point& point);
	
	/// deconstructor
	~RBGroup();
	
	/// display sprites in group
	void show();
	
	/// hide sprites in group
	void hide();
	
	/// update group
	void draw();
	
	/// set disabled state
	void set_disabled(bool set);
	
	/// handle touches as a group
	void handle();
	
	/// add a RadioButton to the group
	void add(RadioButton* rb);
	
	/// assigns RadioButton to be true.  -1 = all false
	void set_CurRB(int rb);
	
	/// returns RadioButton that is true.  -1 = all false
	int get_CurRB();
	
private:
	
	View* mSuperView;
	int mScreenNum;
	Point mPoint;
	
	int disabled;
	
	std::vector<RadioButton*> rbg;
	
};

namespace nsRB
{
	bool getFrame(RadioButton* rb);

	bool wasTouched(RadioButton* rb);
}

#endif