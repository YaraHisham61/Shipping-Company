#pragma once
#include "DaynHour.h"
#include"Header.h"
#include "Cargo.h"
#include <ostream>
#include "Queue.h"

class Truck
{
	static int IDcounter;
	DaynHour movingtime;
	int truckcapacity;
	int maintenancetime;
	int speed;
	float deliveryinterval;
	int ID;
	type ttype;
	int maxj;
	Cargo** LCargo;//it has the id of the cargos it carry
	int carriedcargos;

	//truck can have a pointer to the cargo type it load
public:
	DaynHour getmovingtime();
	Truck(int truckcapacity, int maintenancetime, int maxj,int speed, type ttype);
	Truck();
	int getID();
	int getspeed();
	int getTcapacity();
	void setTcapacity(int C);
	int Mtime();
	Cargo** getCargosid();
	int Tspeed();
	void setTspeed(int s);
	float TdelivaryIn();
	int getDeliveryNum();
	void setDeliveryNum(int n);
	void print();
	type gettype();
	int GetCarriedcargos();
	int MTpriority(DaynHour CurrTime);
	int LTpriority(DaynHour CurrTime);
	int GetMaxDistance();
	int GettotalLtime();
};
