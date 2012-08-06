
#ifndef raguna_view_h
#define raguna_view_h

#include <vector>



/// VIEWS INLCUDE - Controls(user manipulated displays) and TabGroups(displays that contain controls)
class View {

public:

	View();
	
	virtual ~View();
	
	virtual void show();
	
	virtual void hide();
	
	virtual void draw();
	
	virtual void handle();
	
	virtual void update();
	
	virtual void add(View* view);

	//...
	
protected:
	
	//...

private:

	std::vector<View*> Views;
	View* superView;

};

#endif