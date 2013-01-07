
#ifndef raguna_tab_h
#define raguna_tab_h

#include <PA9.h>

#include "Control.h"

#include "Controller.h"

#include "View.h"
#include "Point.h"

#include <vector>

class Tab : public Control {

public:

	/// constructor
	Tab(View* superview, const Point& point, const unsigned char* sprite, const PA_BgStruct* background, Controller* controller);
	
	/// destructor
	virtual ~Tab();
	
	/// show tab_sprite
	void show();
	
	/// hide tab_sprite
	void hide();
	
	/// show members in group
	void display();
	
	/// hide members in group
	void conceal();
	
	/// update tab_sprite
	void draw();
	
	/// update members in group
	void update();
	
	/// handle touches for members in group
	void handle();
	
	/// allow all contents of a tab to be disabled or enabled
	void set_disabled(bool set);

	/// add a member to the tab
	void add(Control* c);
	
	/// mFrame = set
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
	const PA_BgStruct* mBackGround;
	Controller* mController;
	
	bool mFrame;
	bool mShown;
	bool disabled;
	
	std::vector<Control*> tab;
	
	int mSpriteNum;

};

// ---------------------------------------------------------------------------------------------------------------------------

class TabGroup : public Control {

public:
	
	/// constructor
	TabGroup(View* superview, const Point& point, Controller* controller);
	
	/// destructor
	~TabGroup();
	
	/// display sprites in group
	void show();
	
	/// hide sprites in group
	void hide();
	
	/// update group
	void draw();
	
	/// update members of tabs in group
	void update();
	
	/// handle tabs based off touches
	void handle();
	
	void set_disabled(bool set);
	
	/// add a Tab to the group
	void add(Tab* tab);
	
	/// CurTab = tab
	void set_CurTab(int tab);
	
	/// NewTab = tab
	void set_NewTab(int tab);

	/// return CurTab
	int get_CurTab() const;

	/// return NewTab
	int get_NewTab() const;
	
	/// return number of tabs
	int size() const;
	
private:
	
	View* mSuperView;
	int mScreenNum;
	Point mPoint;
	Controller* mController;
	
	int CurTab;
	int NewTab;
	
	bool disabled;
	
	std::vector<Tab*> tabs;
	
};

// --------------------------------------------------------------------------------------------------------------------------

namespace nsTG
{
	bool wasTouched(Tab* tab);
}

#endif