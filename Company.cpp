#include "Company.h"
#include"DaynHour.h"
#include<fstream>
#include"Events.h"
#include"PreparationEvent.h"
#include"PromoteEvent.h"
#include"CancelEvent.h"
#include "UI.h"

Company::Company()
{

}

LinkedList<Cargo*>& Company::getCnormal()
{
	return Cnormal;
}
Queue<Cargo*>& Company::getCspecial()
{
	return Cspecial;
}
PriQ<Cargo*>& Company::getCvip()
{
	return Cvip;
}
PriQ <Cargo*>& Company::getCMnormal()
{
	return CMnormal;
}
PriQ<Cargo*>& Company::getCMspecial()
{
	return CMspecial;
}
PriQ<Cargo*>& Company::getCMvip()
{
	return CMvip;
}
Queue<Cargo*>& Company::getDNCargos()
{
	return DNCargos;
}
Queue<Cargo*>& Company::getDSCargos()
{
	return DSCargos;
}
Queue<Cargo*>& Company::getDvCargos()
{
	return DvCargos;
}
Queue<Truck*>& Company::getNtruck()
{
	return Ntruck;
}
Queue<Truck*>& Company::getVtruck()
{
	return Vtruck;
}
Queue<Truck*>& Company::getStruck()
{
	return Struck;
}
PriQ<Truck*>& Company::getMtrucks()
{
	return Mtrucks;
}
Queue<Truck*>& Company::getNtruksincheck()
{
	return Ntruksincheck;
}
Queue<Truck*>& Company::getStruksincheck()
{
	return Struksincheck;
}
Queue<Truck*>& Company::getVtruksincheck()
{
	return Vtruksincheck;
}
PriQ<Truck*>& Company::getloadingtrucks()
{
	return loadingtrucks;
}


void Company::Simulation(DaynHour CurrT)
{
	cout << "please enter 0 for interactive mode, 1 for step by step mode and 2 for silent mode " << endl;
	int mode;
	cin >> mode;
	int counter = 0;
	while (!Eventactions.isEmpty() || !Cnormal.isEmpty() || !Cspecial.isEmpty() || !Cvip.isEmpty() || !CMnormal.isEmpty() || !CMspecial.isEmpty() || !CMvip.isEmpty())
	{

		if (CurrT.gethours() >= 5 && CurrT.gethours() <= 23)
		{
			counter++;
			Events* tempe;
			while (Eventactions.peek(tempe))
			{
				if (tempe->GetEventTime() == CurrT)
				{
					Eventactions.dequeue(tempe);
					tempe->Excute();
					delete tempe;
				}
				else 
				{
					break;
				}
			}
			Cargo* tempc = nullptr;
			if (counter ==6)
			{
				counter = 1;
				if(Cnormal.dequeue(tempc))
				DNCargos.enqueue(tempc);
				if(Cspecial.dequeue(tempc))
				DSCargos.enqueue(tempc);
				if(Cvip.dequeue(tempc))
				DvCargos.enqueue(tempc);
			}
			modes(mode, CurrT);
		}
		else
		{
			counter = 0;
			Events* tempe;
			while (Eventactions.peek(tempe))
			{
				if (tempe->GetEventTime() == CurrT)
				{
					Eventactions.dequeue(tempe);
					delete tempe;
					tempe = nullptr;
				}
				else
				{
					break;
				}
			}
		}
		++CurrT;
	}
}

void Company::modes(int modenum, DaynHour CurrT)
{
	Modesptr = new UI(this);
	switch (modenum)
	{
	case 0:
	{
		Modesptr->Interactivemode(CurrT);
		break;
	}
	case 1:
	{
		Modesptr->Step_by_Step(CurrT);
		break;
	}
	case 2:
	{
		Modesptr->Silentmode(CurrT);
		break;
	}
	default:
	{
		string msg = "you did not choose any mode to display ";
		Modesptr->printmessage(msg);
		exit(1);
	}
	}



}



bool Company::DequeueNCargo(int id,Cargo*& C1)
{
 return Cnormal.remove(id, C1);

}



bool Company::EnqueueCargo(Cargo* C1,type ctype)
{
	switch (ctype)
	{
	case type::vip :
	{
		return Cvip.enqueue(C1, C1->getVipprioity());
	}
	case type::special :
	{
		return Cspecial.enqueue(C1);
	}
	case type::normal :
	{
		return Cnormal.enqueue(C1);
	}
	default:
		return false;
	}
}

void Company::loadall(string file)
{
	ifstream infile;
	infile.open(file, ios::in);
	
	if (infile.is_open())
	{
		int nn, ns, nv, chn, chs, chv, j, can, cas, cav, sn, ss, sv;
		infile >> nn >> ns >> nv;
		infile >> sn >> ss >> sv;
		infile >> can >> cas >> cav;
		infile >> j >> chn >> chs >> chv;
		numberjourney = j;
		for (size_t i = 0; i < nn; i++)
		{
			Truck* t = new Truck(can, chn, j, sn, type::normal);
			Ntruck.enqueue(t);
		}
		for (size_t i = 0; i < ns; i++)
		{
			Truck* t = new Truck(cas, chs, j, ss, type::special);
			Struck.enqueue(t);
		}
		for (size_t i = 0; i < nv; i++)
		{
			Truck* t = new Truck(cav, chv, j, sv, type::vip);
			Vtruck.enqueue(t);
		}
		int au, max;
		infile >> au >> max;
		AutoP = au;
		maxw = max;
		int nev;
		infile >> nev;
		nevent = nev;
		for (size_t i = 0; i < nevent; i++)
		{
			char x;
			infile >> x;
			Events* Pre;
			switch (x)
			{
			case 'R':
			{
				Pre = new PreparationEvent(this);
				Pre->load(infile, 0, file);
				Eventactions.enqueue(Pre);
				break;
			}
			case 'P':
			{
				Pre = new PromoteEvent(this);
				Pre->load(infile, 1, file);
				Eventactions.enqueue(Pre);
				break;
			}
			case'X':
			{
				Pre = new CancelEvent(this);
				Pre->load(infile, 2, file);
				Eventactions.enqueue(Pre);
				break;
			}
			default:
				break;
			}
		}
	}
	else
	{
		Modesptr->printmessage("no file");
		exit(1);
	}
}
