
#include <PA9.h>

#include "Point.h"


Point::Point(int x, int y)
: mX(x)
, mY(y)
{
}

Point::~Point()
{
}

Point Point::operator= (const Point& p)
{

	int newX = p.mX;
	int newY = p.mY;
	
	return Point(newX, newY);
}

Point Point::operator+= (const Point& p)
{
	mX += p.mX;
	mY += p.mY;
	
	return *this;
}

Point Point::operator-= (const Point& p)
{
	mX -= p.mX;
	mY += p.mY;
	
	return *this;
}

int Point::get_mX() const
{
	return mX;
}

int Point::get_mY() const
{
	return mY;
}

Point operator+ (const Point& a, const Point& b)
{
	int newX = a.get_mX() + b.get_mX();
	int newY = a.get_mY() + b.get_mY();
	
	return Point(newX, newY);
}

Point operator- (const Point& a, const Point& b)
{
	int newX = a.get_mX() - b.get_mX();
	int newY = a.get_mY() - b.get_mY();
	
	return Point(newX, newY);
}

