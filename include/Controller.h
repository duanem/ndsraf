
#ifndef _raguna_Controller_h
#define _raguna_Controller_h

#include <PA9.h>

#include "model.h"

/// controllers handle key presses
class Controller {

public:

	Controller(Controller* superController);
	
	virtual ~Controller();
	
	virtual void loadData();
	
	virtual void saveData();
	
	virtual void handleKey();
	
private:

	Controller* mSuperController;
	
};

#endif