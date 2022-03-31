#pragma once
#include "DaynHour.h"
class Events
{
private:
	DaynHour ET;
public:

	virtual void Execute() = 0;

};

