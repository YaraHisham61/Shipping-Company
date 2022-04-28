#include "UI.h"

ostream& operator <<(ostream& out, Truck& CurrT)
{
	out << CurrT.getID();
	if (CurrT.GetCarriedcargos() == 0)
		return out;
	switch ((CurrT.getCargosid()[0])->getctype())
	{
	case type::vip:
	{
		out << "{";
		int i = 0;
		for (; i < CurrT.GetCarriedcargos() - 1; i++)
			out << ((CurrT.getCargosid())[i])->getID() << ",";
		out << (CurrT.getCargosid())[i]->getID() << "}";
		break;

	}
	case type::normal:
	{
		out << "[";
		int i = 0;
		for (; i < CurrT.GetCarriedcargos() - 1; i++)
			out << ((CurrT.getCargosid())[i])->getID() << ",";
		out << (CurrT.getCargosid())[i]->getID() << "]";
		break;
	}
	case type::special:
	{


		out << "(";
		int i = 0;
		for (; i < CurrT.GetCarriedcargos() - 1; i++)
			out << ((CurrT.getCargosid())[i])->getID() << ",";
		out << (CurrT.getCargosid())[i]->getID() << ")";
		break;
	}
	//if it reach the default hthen error message should be printed
	}
	return out;
}

ostream& operator <<(ostream& out, Cargo& CurrC)
{

	out << CurrC.getID();
	return out;
}



UI::UI(Company* cptr)
{
	this->Cptr = cptr;
}

void UI::printmessage(string msg)
{
	cout << msg << endl;
}

void UI::Interactivemode(DaynHour CurrT)
{
	cin.ignore();
	//the output file should be produced
	cout << "Current Time (Day:Hour) :";
	string time = CurrT.stringdisplay();
	cout << time<<endl;
	printwaitingcargos();
	cout << "-----------------------------------------------------" << endl;
	printLoadingTrucks();
	cout << "-----------------------------------------------------" << endl;
	printEmptytruck();
	cout << "-----------------------------------------------------" << endl;
	printmovingcargos();
	cout << "-----------------------------------------------------" << endl;
	printincheckcTrucks();
	cout << "-----------------------------------------------------" << endl;
	printDeliveredCargos();
	cout << endl << endl;
	//cin.ignore();
}

void UI::Silentmode(DaynHour CurrT)
{
	//the output file should be produced
	cout << "Silent Mode" << endl << "Simulation Starts" << endl << "Simulation Ends, output file created"<<endl;
}

void UI::Step_by_Step(DaynHour CurrT)
{
	//the output file should be produced
	cout << "Current Time (Day:Hour) :";
	string time = CurrT.stringdisplay();
	cout << time << endl;

	printwaitingcargos();
	cout << "-----------------------------------------------------" << endl;
	printLoadingTrucks();
	cout << "-----------------------------------------------------" << endl;
	printEmptytruck();
	cout << "-----------------------------------------------------" << endl;
	printmovingcargos();
	cout << "-----------------------------------------------------" << endl;
	printincheckcTrucks();
	cout << "-----------------------------------------------------" << endl;
	printDeliveredCargos();
	cout << endl << endl;
	//delivered.
	//it should take some time 
	Sleep(10);
}

void UI::printincheckcTrucks()
{
	int num = (Cptr->getNtruksincheck().Getcount()) + (Cptr->getStruksincheck().Getcount()) + (Cptr->getVtruksincheck().Getcount());
	cout << num << " In-Check Trucks : [";
	Cptr->getNtruksincheck().print();
	cout << "] (";
	Cptr->getStruksincheck().print();
	cout << ") {";
	Cptr->getVtruksincheck().print();
	cout << "}" << endl;
}

void UI::printwaitingcargos()
{

	int num = (Cptr->getCnormal().getCount()) + (Cptr->getCspecial().Getcount()) + (Cptr->getCvip().getcount());
	cout << num<< " Waiting Cargos : [";
	Cptr->getCnormal().print();
	cout << "] (";
	Cptr->getCspecial().print();
	cout << ") {";
	Cptr->getCvip().print();
	cout << "}" << endl;
}

void UI::printmovingcargos()
{
	int num = (Cptr->getCMnormal().getcount()) + (Cptr->getCMspecial().getcount()) + (Cptr->getCMvip().getcount());
	cout << num << " Moving cargos : [";
	Cptr->getCMnormal().print();
	cout << "] (";
	Cptr->getCMspecial().print();
	cout << ") {";
	Cptr->getCMvip().print();
	cout << "}" << endl;
}

void UI::printEmptytruck()
{
	int num = (Cptr->getNtruck().Getcount()) + (Cptr->getStruck().Getcount()) + (Cptr->getVtruck().Getcount());
	cout << num << " Empty Trucks :[";
	Cptr->getNtruck().print();
	cout << "] (";
	Cptr->getStruck().print();
	cout << ") {";
	Cptr->getVtruck().print();
	cout << "}" << endl;
}

void UI::printDeliveredCargos()
{
	int num = (Cptr->getDNCargos().Getcount()) + (Cptr->getDSCargos().Getcount()) + (Cptr->getDvCargos().Getcount());
	cout << num << " Delivered Cargos : [";
	Cptr->getDNCargos().print();
	cout << "] (";
	Cptr->getDSCargos().print();
	cout << ") {";
	Cptr->getDvCargos().print();
	cout << "}" << endl;
}

void UI::printLoadingTrucks()
{
	int num = Cptr->getloadingtrucks().getcount();
	cout << num << " Loading Trucks";
	Cptr->getloadingtrucks().print();
	cout << endl;
}
