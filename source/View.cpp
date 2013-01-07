
#include <PA9.h>
#include "all_gfx.h"

#include "raguna.h"

#include "View.h"
#include "Point.h"


View::View(View* superview, int screen, const Point& point)
: mSuperView(superview)
, mScreenNum(screen)
, mPoint(point)
{
}

View::~View()
{
}

void View::show()
{
	for(std::vector<View*>::iterator ViewIter = Views.begin(); ViewIter != Views.end(); ++ViewIter)
	{
		(*ViewIter)->show();
	}
}

void View::hide()
{
	for(std::vector<View*>::iterator ViewIter = Views.begin(); ViewIter != Views.end(); ++ViewIter)
	{
		(*ViewIter)->hide();
	}
}

void View::draw()
{
	for(std::vector<View*>::iterator ViewIter = Views.begin(); ViewIter != Views.end(); ++ViewIter)
	{
		(*ViewIter)->draw();
	}
}

void View::handle()
{
	for(std::vector<View*>::iterator ViewIter = Views.begin(); ViewIter != Views.end(); ++ViewIter)
	{
		(*ViewIter)->handle();
	}
}

void View::update()
{
	for(std::vector<View*>::iterator ViewIter = Views.begin(); ViewIter != Views.end(); ++ViewIter)
	{
		(*ViewIter)->update();
	}
}

void View::add(View* view)
{
	Views.push_back(view);
}

int View::get_mScreen() const
{
	if(mSuperView)
		return mSuperView->get_mScreen();
		
	else
		return mScreenNum;
		
}

Point View::get_mPoint() const
{
	return mPoint;
}

Point View::get_Global(const Point& p)
{
	if(mSuperView)
		return (mSuperView->get_mPoint() + p);
		
	else
		return mPoint;
		
}
