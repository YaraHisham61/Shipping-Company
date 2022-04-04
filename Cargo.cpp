#include "Cargo.h"

Cargo::Cargo(DaynHour Cprepare, DaynHour Cload, int distance, double cost, int id, type c)
{
	this-> Cprepare= Cprepare;
	this-> Cload= Cprepare;
	this-> distance= distance;
	this-> cost=cost;
	this->ctype=c;
	this-> ID=id;
}
Cargo::Cargo(){}
int Cargo::getID()
{
	return ID;
}
