#pragma once
#pragma once
#include <iostream>
#include"LinkedList.h"
#include"Cargo.h"
#include "Header.h"
using namespace std;

class Cargolist
{
	LinkedList <Cargo*> special;
	LinkedList <Cargo*> cnormal;
	LinkedList <Cargo*> cvip;

public:
	bool addcargo(int id, type c);
	//Cargo * remove( int id, type c);
	//bool addcargo();
	bool creatcargo(DaynHour Cprepare, DaynHour Cload, int distance, double cost, int id, type c);




};
