#pragma once
#include "Events.h"
#include "Header.h"
class PreparationEvent : public Events
{
private:
	type cType;
	int DIST;
	int LT;
	int cost;
public:
	bool Excute();
};

