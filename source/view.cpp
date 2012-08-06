
#include <PA9.h>
#include "all_gfx.h"

#include "raguna.h"

#include "view.h"



View::View()
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