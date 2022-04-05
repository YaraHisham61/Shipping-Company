#pragma once
#include "Cargo.h"
#include "LinkedList.h"
#include "LinkedQueue.h"
#include "Trucklist.h"
#include"LinkedPriorityQueue.h"
#include "Header.h"
class Company
{
private:
	LinkedList <Cargo*> Cnormal;
	LinkedQueue <Cargo*> Cspecial;
	LinkedPriorityQueue <Cargo*> Cvip;

public:
	Company();
	bool DequeueNCargo(int id,Cargo *C1);
	bool EnqueueCargo(Cargo* C1,type ctype);
};

