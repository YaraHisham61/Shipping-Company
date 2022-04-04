#pragma once
#include "Events.h"
class PromoteEvent : public Events
{
	int pcost;
public:
	bool Excute();
};

