#include "Cargo.h"

Cargo::Cargo(DaynHour Cprepare, int Cload, int distance, double cost, int id, type c)
{
	this-> Cprepare= Cprepare;
	this-> Cload= Cload;
	this-> distance= distance;
	this-> cost=cost;
	this->ctype=c;
	this-> ID=id;
}
Cargo::Cargo(){}
void Cargo::SetCost(int ncost)
{
	cost = ncost;
}
double Cargo::GetCost()
{
	return cost;
}
int Cargo::getID()
{
	return ID;
}
