#include "PromoteEvent.h"

bool PromoteEvent::Excute()
{
	Cargo newcargo ;
	bool exist=Cpointer->DequeueNCargo(GetCargoID(),&newcargo);
	if(!exist)
	return false;
	newcargo.SetCost(newcargo.GetCost() + pcost);
	exist = Cpointer->EnqueueVCargo(&newcargo);
	return exist;
}
