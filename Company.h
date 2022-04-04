#pragma once
#include "Cargo.h"
#include "LinkedList.h"
#include "LinkedQueue.h"
#include "Trucklist.h"
#include"LinkedPriorityQueue.h"
class Company
{
private:
	LinkedList <Cargo*> Cnormal;
	LinkedQueue <Cargo*> Cspecial;
	LinkedPriorityQueue <Cargo*> Cvip;

public:
	Company();
	bool DequeueNCargo(int id,Cargo *C1);
	bool EnqueueNCargo(Cargo* C1);
	bool EnqueueVCargo(Cargo* cptr);
};

