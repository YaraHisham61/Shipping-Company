#include "PromoteEvent.h"

bool PromoteEvent::Excute()
{
	Cargo * promcargo ;
	bool exist=Cpointer->DequeueNCargo(GetCargoID(), promcargo);
	if(!exist)
	return false;
	promcargo->SetCost(promcargo->GetCost() + pcost);
	exist = Cpointer->EnqueueCargo(promcargo,type::vip);
	return exist;
}
