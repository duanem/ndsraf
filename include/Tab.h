
#ifndef raguna_tab_h
#define raguna_tab_h

#include <PA9.h>

#include "Control.h"

#include "Controller.h"
#include "NumberSprite.h"

#include <vector>

class Tab : public Control {

public:

	/// constructor
	Tab(int screen, int x, int y, const unsigned char* sprite, const PA_BgStruct* background, Controller* controller);
	
	/// destructor
	virtual ~Tab();
	
	/// show tab_sprite
	void show();
	
	/// hide tab_sprite
	void hide();
	
	/// show members in group
	void enable();
	
	/// hide members in group
	void disable();
	
	/// update tab_sprite
	void draw();
	
	/// update members in group
	void update();
	
	/// handle touches for members in group
	void handle();

	/// add a member to the tab
	void add(Control* c);
	
	/// mFrame = set
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
	int mXCo; int mYCo;
	const unsigned char* mName;
	bool mFrame; bool mShown;
	const PA_BgStruct* mBackGround;
	
	std::vector<Control*> tab;
	
	Controller* mController;

};

// ---------------------------------------------------------------------------------------------------------------------------

class TabGroup : public Control {

public:
	
	/// constructor
	TabGroup(Controller* controller);
	
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
	
	/// add a Tab to the group
	void add(Tab* tab);
	
	/// CurTab = tab
	void set_CurTab(int tab);
	
	/// NewTab = tab
	void set_NewTab(int tab);

	/// return CurTab
	int get_CurTab();

	/// return NewTab
	int get_NewTab();
	
	/// return number of tabs
	int size();
	
private:
	
	int CurTab; int NewTab;
	
	std::vector<Tab*> tabs;
	
	Controller* mController;
};

// --------------------------------------------------------------------------------------------------------------------------

namespace nsTG
{
	bool wasTouched(Tab* tab);
}

#endif