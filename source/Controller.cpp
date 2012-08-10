

#include "Controller.h"



Controller::Controller(Controller* superController)
: mSuperController(superController)
{
}

Controller::~Controller()
{
}

void Controller::handleKey()
{
	if (mSuperController)
		mSuperController->handleKey();
}

void Controller::loadData()
{
}

void Controller::saveData()
{
}
	