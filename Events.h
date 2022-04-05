#pragma once
#include "DaynHour.h"
#include "Company.h"
#include "Cargo.h"
#include "Header.h"
class Events
{
protected:
	DaynHour ET;
	int CargoID;
public:
	Events(DaynHour t, int id, Company* Cptr);
	DaynHour GetEventTime();
	void SetEventTime(DaynHour t);
	int GetCargoID();
	void SetCargoID(int id);
	virtual bool Execute() = 0;
	Company* Cpointer;

};

