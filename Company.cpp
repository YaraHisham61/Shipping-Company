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

void Company::movingcargoscheck(DaynHour currT)
{
	Cargo* temp;
	CMnormal.peek(temp);
	while (temp->GetEndMovingTime() >= currT.DaytoHours())
	{
		Truck* ttemp = temp->GetTruck();
		for (int i = 0; i < ttemp->getTcapacity(); i++)
		{
			if (temp = ttemp->getCargo(i))
			{
				ttemp->setCargo(nullptr, i);
				break;
			}
		}
		DNCargos.enqueue(temp);
		CMnormal.dequeue(temp);
		CMnormal.peek(temp);
	}
	CMspecial.peek(temp);
	while (temp->GetEndMovingTime() >= currT.DaytoHours())
	{
		Truck* ttemp = temp->GetTruck();
		for (int i = 0; i < ttemp->getTcapacity(); i++)
		{
			if (temp = ttemp->getCargo(i))
			{
				ttemp->setCargo(nullptr, i);
				break;
			}
		}
		DSCargos.enqueue(temp);
		CMspecial.dequeue(temp);
		CMspecial.peek(temp);
	}
	CMvip.peek(temp);
	while (temp->GetEndMovingTime() >= currT.DaytoHours())
	{
		Truck* ttemp = temp->GetTruck();
		for (int i = 0; i < ttemp->getTcapacity(); i++)
		{
			if (temp = ttemp->getCargo(i))
			{
				ttemp->setCargo(nullptr, i);
				break;
			}
		}
		DvCargos.enqueue(temp);
		CMvip.dequeue(temp);
		CMvip.peek(temp);
	}
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
			if (counter == 6)
			{
				counter = 1;
				if (Cnormal.dequeue(tempc))
					DNCargos.enqueue(tempc);
				if (Cspecial.dequeue(tempc))
					DSCargos.enqueue(tempc);
				if (Cvip.dequeue(tempc))
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



bool Company::DequeueNCargo(int id, Cargo*& C1)
{
	return Cnormal.remove(id, C1);

}



bool Company::EnqueueCargo(Cargo* C1, type ctype)
{
	switch (ctype)
	{
	case type::vip:
	{
		return Cvip.enqueue(C1, C1->getVipprioity());
	}
	case type::special:
	{
		return Cspecial.enqueue(C1);
	}
	case type::normal:
	{
		return Cnormal.enqueue(C1);
	}
	default:
		return false;
	}
}

void Company::truckFcheckTavail(DaynHour currT)
{
	Truck* removet;

	while (Vtruksincheck.peek(removet))
	{
		if (removet->incheckpriority() >= currT.DaytoHours())
		{
			Vtruksincheck.dequeue(removet);
			Vtruck.enqueue(removet);
		}
		else break;
	}
	while (Struksincheck.peek(removet))
	{
		if (removet->incheckpriority() >= currT.DaytoHours()) {
			Struksincheck.dequeue(removet);
			Struck.enqueue(removet);
		}
		else
			break;
	}
	while (Ntruksincheck.peek(removet))
	{
		if (removet->incheckpriority() >= currT.DaytoHours())
		{
			Ntruksincheck.dequeue(removet);
			Ntruck.enqueue(removet);
		}
		else
			break;
	}
}

void Company::movingtrucksToavailAcheck(DaynHour currT)
{
	Truck* removet;

	while (Mtrucks.peek(removet))
	{
		if (removet->Getendmoving() >= currT.DaytoHours())
		{
			if (removet->needsmainaience())
			{
				removet->resetjourneys();
				enqueuechecktrucks(removet);
			}
			else
				enqueueavailtrucks(removet);
		}
		else
			break;
	}
}

bool Company::enqueueavailtrucks(Truck* truck)
{
	switch (truck->gettype())
	{
	case type::vip:
	{
		return Ntruck.enqueue(truck);
	}
	case type::special:
	{
		return Struck.enqueue(truck);
	}
	case type::normal:
	{
		return Vtruck.enqueue(truck);
	}
	default:
		return false;
	}
}

bool Company::enqueuechecktrucks(Truck* truck)
{
	switch (truck->gettype())
	{
	case type::vip:
	{
		return Ntruksincheck.enqueue(truck);
	}
	case type::special:
	{
		return Struksincheck.enqueue(truck);
	}
	case type::normal:
	{
		return Vtruksincheck.enqueue(truck);
	}
	default:
		return false;
	}
}

void Company::loadingTrucktomoving(DaynHour currT)
{
	Truck* removet;
	while (loadingtrucks.peek(removet))
	{
		if (removet->Getendloading() >= currT.DaytoHours())
		{
			removet->addjourney();
			removet->setmovingtime(currT);
			Mtrucks.enqueue(removet, removet->MTpriority(currT));
		}
		else
			break;
	}
}

bool Company::NormalCheckMaxW(DaynHour currT)
{
	Cargo* Ncargo;
	Truck* AvaNTruck;
	int count = 0;

	Ntruck.peek(AvaNTruck);
	if (AvaNTruck&& loadingtrucks.getcount()<3)
	{
		Ntruck.dequeue(AvaNTruck);
		while (count < AvaNTruck->getTcapacity() && Cnormal.peekFront(Ncargo) && Ncargo->GetWaitingtime(currT).DaytoHours() >= MaxW)
		{
			AvaNTruck->setCargo(Ncargo, count);
			count++;
		}
		loadingtrucks.enqueue(AvaNTruck, AvaNTruck->LTpriority(currT));
		return true;
	}
	else if (Struck.peek(AvaNTruck) && loadingtrucks.getcount() < 3)
	{
		Struck.dequeue(AvaNTruck);
		while (count < AvaNTruck->getTcapacity() && Cspecial.peek(Ncargo) && Ncargo->GetWaitingtime(currT).DaytoHours() >= MaxW)
		{
			AvaNTruck->setCargo(Ncargo, count);
			count++;
		}
		loadingtrucks.enqueue(AvaNTruck, AvaNTruck->LTpriority(currT));
		return true;
	}
	
	return false;
}

bool Company::SpecialCheckMaxW(DaynHour currT)
{
	Cargo* Scargo;
	Truck* AvaSTruck;
	int count = 0;

	Struck.peek(AvaSTruck);
	if (AvaSTruck && loadingtrucks.getcount() < 3)
	{
		Struck.dequeue(AvaSTruck);
		while (count < AvaSTruck->getTcapacity() && Cspecial.peek(Scargo) && Scargo->GetWaitingtime(currT).DaytoHours() >= MaxW)
		{
			AvaSTruck->setCargo(Scargo, count);
			count++;
		}
		loadingtrucks.enqueue(AvaSTruck, AvaSTruck->LTpriority(currT));
		return true;

	}
	return false;
}

void Company::AutoPromotion(DaynHour CurrTime)
{
	Cargo* Ncargo;
	while (Cnormal.peekFront(Ncargo) && Ncargo->GetWaitingtime(CurrTime).getday() >= AutoP)
	{
		Cnormal.dequeue(Ncargo);
		Ncargo->SetType(type::vip);
		Cvip.enqueue(Ncargo, Ncargo->getVipprioity());
	}
}

void Company::laodingvip(DaynHour currT)
{
	Truck* ttempv;
	Vtruck.peek(ttempv);
	Truck* ttempn;
	Ntruck.peek(ttempn);
	Truck* ttemps;
	Struck.peek(ttemps);
	if (ttempv != NULL)
	{
		if (Cvip.getcount() >= ttempv->getTcapacity())
		{
			Vtruck.dequeue(ttempv);
			for (size_t i = 0; i < ttempv->getTcapacity(); i++)
			{
				Cargo* ctemp;
				Cvip.dequeue(ctemp);
				ttempv->setCargo(ctemp, i);
			}
			loadingtrucks.enqueue(ttempv, ttempv->LTpriority(currT));
		}
	}
	else if (ttempn != NULL)
	{
		if (Cvip.getcount() >= ttempn->getTcapacity())
		{
			Ntruck.dequeue(ttempn);
			for (size_t i = 0; i < ttempn->getTcapacity(); i++)
			{
				Cargo* ctemp;
				Cvip.dequeue(ctemp);
				ttempn->setCargo(ctemp, i);
			}
			loadingtrucks.enqueue(ttempn, ttempn->LTpriority(currT));
		}
	}
	else if (ttemps != NULL)
	{
		if (Cvip.getcount() >= ttemps->getTcapacity())
		{
			Struck.dequeue(ttemps);
			for (size_t i = 0; i < ttemps->getTcapacity(); i++)
			{
				Cargo* ctemp;
				Cvip.dequeue(ctemp);
				ttemps->setCargo(ctemp, i);
			}
			loadingtrucks.enqueue(ttemps, ttemps->LTpriority(currT));
		}
	}

}
void Company::laodingnormal(DaynHour currT)
{
	Truck* ttempn;
	Ntruck.peek(ttempn);
	if (ttempn != NULL)
	{
		if (Cnormal.getCount() >= ttempn->getTcapacity())
		{
			Ntruck.dequeue(ttempn);
			for (size_t i = 0; i < ttempn->getTcapacity(); i++)
			{
				Cargo* ctemp;
				Cnormal.dequeue(ctemp);
				ttempn->setCargo(ctemp, i);
			}
			loadingtrucks.enqueue(ttempn, ttempn->LTpriority(currT));
		}
	}
}
void Company::laodingspecial(DaynHour currT)
{
	Truck* ttemps;
	Struck.peek(ttemps);
	if (ttemps != NULL)
	{
		if (Cspecial.Getcount() >= ttemps->getTcapacity())
		{
			Struck.dequeue(ttemps);
			for (size_t i = 0; i < ttemps->getTcapacity(); i++)
			{
				Cargo* ctemp;
				Cspecial.dequeue(ctemp);
				ttemps->setCargo(ctemp, i);
			}
			loadingtrucks.enqueue(ttemps, ttemps->LTpriority(currT));
		}
	}
}
void Company::CargosAssignment(DaynHour currT)
{
	if (loadingtrucks.getcount() < 3)
	{
		laodingvip(currT);
		if (!SpecialCheckMaxW(currT))
			laodingspecial(currT);
		if (!NormalCheckMaxW(currT))
			laodingnormal(currT);
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
		MaxW = max;
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

void Company::saveall(DaynHour currT)
{
	string file;
	cout << "please enter the file name to save";
	cin >> file;
	file += ".txt";
	ofstream outfile;
	outfile.open(file, ios::out);
	if (outfile.is_open())
	{
		outfile << "CDT  ID  PT  WT  TID" << endl;
		/*while (!CDT.isEmpty())
		{
			Cargo* temp;
			CDT.dequeue(temp);
			outfile << temp->GetCargodeliverytime().getday()<<":"<< temp->GetCargodeliverytime().gethours()<<"  " << temp->getID()<<"  "<< temp->GetPreparetime().getday() << ":" << temp->GetPreparetime().gethours() << "  " << temp->GetWaitingtime().getday() << ":" << temp->GetWaitingtime().gethours() << "  " << temp->GetTruck()->getID() << endl;
		}*/
		outfile << "........................................................." << endl;
		outfile << "........................................................." << endl;
		outfile << "Cargos:";
		outfile << DNCargos.Getcount() + DvCargos.Getcount() + DSCargos.Getcount() << " [ N: " << DNCargos.Getcount() << ", S: " << DSCargos.Getcount() << ", V: " << DvCargos.Getcount() << "]" << endl;
		int tmp = 0;
		while (!DNCargos.isEmpty())
		{
			Cargo* temp;
			DNCargos.dequeue(temp);
			tmp += temp->GetWaitingtime(currT).DaytoHours();
		}
		while (!DSCargos.isEmpty())
		{
			Cargo* temp;

			DSCargos.dequeue(temp);

			tmp += temp->GetWaitingtime(currT).DaytoHours();
		}
		while (!DvCargos.isEmpty())
		{
			Cargo* temp;
			DvCargos.dequeue(temp);
			tmp += temp->GetWaitingtime(currT).DaytoHours();
		}
		DaynHour d(to_string(tmp));
		outfile << "Cargo Avg Wait = " << d.getday() << ":" << d.gethours() << endl;

		////autopromote

		outfile << "Truck: " << Ntruck.Getcount() + Vtruck.Getcount() + Struck.Getcount();




	}
	else
	{
		cout << "Not Save" << "\n";
	}
}
