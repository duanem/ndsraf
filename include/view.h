
#ifndef raguna_view_h
#define raguna_view_h

#include <vector>

#include "Point.h"
#include "raguna.h"



/// VIEWS INLCUDE - Controls(user manipulated displays) and TabGroups(displays that contain controls)
class View {

public:

	View(View* superview, int screen, const Point& point);
	
	virtual ~View();
	
	virtual void show();
	
	virtual void hide();
	
	virtual void draw();
	
	virtual void handle();
	
	virtual void update();
	
	virtual void add(View* view);
	
	virtual int get_mScreen() const;
	
	virtual Point get_mPoint() const;
	
	virtual Point get_Global(const Point& p);

	//...
	
protected:
	
	//...

private:

	std::vector<View*> Views;
	View* mSuperView;
	
	int mScreenNum;
	Point mPoint;

};

#endif