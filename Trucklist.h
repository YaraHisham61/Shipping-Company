#pragma once
#include "Truck.h"
#include"Header.h"
#include"LinkedList.h"
using namespace std;
#include<iostream>
class Trucklist
{
private:
	LinkedList<Truck*> tspecial;
	LinkedList<Truck*> tnormal;
	LinkedList<Truck*> tvip;
public:
	Truck * remove( int id, type c);

	
};

