#pragma once
#include <iostream>
#include "queuelist.h"
#include"Cargo.h"
#include "Header.h"
#include "LinkedList.h"
using namespace std;

class Cargolist
{
private:

	 

public:
	queuelist <Cargo*> special;
	LinkedList <Cargo*> Cnormal;
	queuelist <Cargo*> cvip;//it will be proirty
	bool addcargo(int id, type c);
	//Cargo * remove( int id, type c);
	//bool addcargo();
	bool creatcargo(DaynHour Cprepare, DaynHour Cload, int distance, double cost, int id, type c);




};
