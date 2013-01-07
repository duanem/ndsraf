
#ifndef raguna_point_h
#define raguna_point_h

class Point {
	
public:

	Point(int x, int y);
	
	~Point();
	
	Point operator= (const Point& p);
	Point operator+= (const Point& p);
	Point operator-= (const Point& p);
	
	int get_mX() const;
	
	int get_mY() const;
	
private:

	int mX;
	int mY;
	
};

Point operator+ (const Point& a, const Point& b);
Point operator- (const Point& a, const Point& b);

#endif