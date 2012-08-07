
#ifndef _raguna_Controller_h
#define _raguna_Controller_h

#include <PA9.h>

#include "model.h"

/// controllers handle key presses
class Controller {

public:

	Controller(Controller* superController);
	
	virtual ~Controller();
	
	virtual void loadData(const MatchData& MatchInfo);		// eek! dependencies! (on RoboEI (model))
	
	virtual void savaData(MatchData* MatchInfo);
	
	virtual void handleKey();
	
private:

	Controller* mSuperController;
	
};

#endif