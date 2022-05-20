#pragma once
#include "Cargo.h"
#include "LinkedList.h"
#include "Queue.h"
#include"PriQ.h"
#include "Header.h"
class Events;
class UI;
#include "Truck.h"


class Company
{
private:
	int AutoP;
	UI* Modesptr;

	//Waiting cargos
	LinkedList <Cargo*> Cnormal;
	Queue <Cargo*> Cspecial;
	PriQ <Cargo*> Cvip;
	
	//Moving cargos
	PriQ <Cargo*> CMnormal;
	PriQ <Cargo*> CMspecial;
	PriQ <Cargo*> CMvip;

	//Deliviered cargos
	Queue <Cargo*> DNCargos;
	Queue <Cargo*> DSCargos;
	Queue <Cargo*> DvCargos;

	//Loading cargos
	PriQ <Cargo*> LNcargos;
	PriQ <Cargo*> LScargos;
	PriQ <Cargo*> LVcargos;

	//Event list
	Queue <Events*> Eventactions;

	//Available trucks

	Queue <Truck*> Ntruck;
	Queue <Truck*> Vtruck;
	Queue <Truck*> Struck;

	//Moving trucks
	PriQ <Truck*> Mtrucks;

	//In-check trucks
	Queue <Truck*>Ntruksincheck;
	Queue <Truck*>Struksincheck;
	Queue <Truck*>Vtruksincheck;

	//loading trucks
	PriQ <Truck*> loadingtrucks;

	int numberjourney; //Number of journeys of trucks before Check-up
	int maxw;
	int nevent;

public:
	Company();
	LinkedList <Cargo*>& getCnormal();
	Queue <Cargo*>& getCspecial();
	PriQ <Cargo*>& getCvip();
	PriQ <Cargo*>& getCMnormal();
	PriQ <Cargo*>& getCMspecial();
	PriQ <Cargo*>& getCMvip();
	Queue <Cargo*>& getDNCargos();
	Queue <Cargo*>& getDSCargos();
	Queue <Cargo*>& getDvCargos();
	Queue <Truck*>& getNtruck();
	Queue <Truck*>& getVtruck();
	Queue <Truck*>& getStruck();
	//moving truck
	PriQ <Truck*>& getMtrucks();
	//incheck trucks
	Queue <Truck*>& getNtruksincheck();
	Queue <Truck*>& getStruksincheck();
	Queue <Truck*>& getVtruksincheck();

	//loading trucks
	PriQ <Truck*>& getloadingtrucks();


	void Simulation(DaynHour CurrT);
	void modes(int modenum, DaynHour CurrT);
	void loadall(string file);
	bool DequeueNCargo(int id,Cargo *& C1);
	bool EnqueueCargo(Cargo* C1,type ctype);
	void truckFcheckTavail(DaynHour currT);
	void movingtrucksToavailAcheck(DaynHour currT);
	bool enqueueavailtrucks(Truck* truck);
	bool enqueuechecktrucks(Truck* truck);
	void loadingTrucktomoving(DaynHour currT);
	void CargosAssignment(DaynHour currT);
	void saveall();
};
