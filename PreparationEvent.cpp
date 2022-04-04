#include "PreparationEvent.h"

bool PreparationEvent::Excute()
{
	Cargo* ptr = new Cargo(ET, LT, DIST, cost, CargoID, cType);
	return Cpointer->EnqueueNCargo(CargoID,ptr);
}
