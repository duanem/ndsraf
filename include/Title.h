
#ifndef raguna_Title_h
#define ragune_Title_h

#include <PA9.h>
#include "all_gfx.h"

#include "raguna.h"

#include "View.h"
#include "Point.h"

class Title : public View {

public:
	
	Title(View* superview, const Point& point, const unsigned char* sprite);
	
	~Title();
	
	void show();
	
	void hide();
	
private:

	static int pallet_num();
	
	View* mSuperView;
	int mScreenNum;
	Point mPoint;
	const unsigned char* mName;
	
	int mSpriteNum;
	
};

#endif
	
