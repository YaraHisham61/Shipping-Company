#include "Events.h"
Events::Events(DaynHour t, int id , Company* Cptr)
{
	ET = t;
	CargoID = id;
	Cpointer = Cptr;
}

DaynHour Events::GetEventTime()
{
	return ET;
}

void Events::SetEventTime(DaynHour t)
{
	ET = t;
}

int Events::GetCargoID()
{
	return CargoID;
}

void Events::SetCargoID(int id)
{
	CargoID = id;
}
