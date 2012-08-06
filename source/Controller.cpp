

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

void Controller::loadData(const MatchData& MatchInfo)
{
}

void Controller::savaData(MatchData* MatchInfo)
{
}
	