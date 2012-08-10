
#ifndef raguna_control_h
#define raguna_control_h

#include "View.h"



class Control: public View {

public:
	
	virtual void show()=0;
	
	virtual void hide()=0;
	
	virtual void draw()=0;
	
	virtual void handle()=0;
	
	//...
	
protected:

	//...
	
private:

	//...
	
};

#endif