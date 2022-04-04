#pragma once
#include "Cargo.h"
#include "LinkedList.h"
#include "LinkedQueue.h"
#include "Trucklist.h"
class Company
{
	LinkedList <Cargo*> Cnormal;
	LinkedQueue <Cargo*> Cspecial;
	LinkedQueue <Cargo*> Cvip;

public:
	Company();

	bool DequeueNCargo(int id,Cargo *C1);
	bool EnqueueVCargo(Cargo* cptr);
};

