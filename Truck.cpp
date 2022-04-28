#include "Truck.h"

int Truck::IDcounter = 1;

DaynHour Truck::getmovingtime()
{
    return movingtime;
}

Truck::Truck(int truckcapacity, int maintenancetime, int maxj, int speed, type ttype)
{
    this-> truckcapacity= truckcapacity;
    this->maintenancetime= maintenancetime;
    this->speed= speed;
     this->maxj=maxj;
     this->ttype= ttype;
     LCargo = new Cargo*[truckcapacity];
     carriedcargos = 0;
     ID = IDcounter;
     IDcounter++;
}

Truck::Truck()
{
    LCargo = new Cargo*[truckcapacity];
    speed = 0;
    carriedcargos = 0;
    ID = IDcounter;
    IDcounter++;
}

int Truck::getID()
{
    return ID;
}

int Truck::getspeed()
{
    return speed;
}

int Truck::getTcapacity()
{
    return truckcapacity;
}

void Truck::setTcapacity(int C)
{
    truckcapacity = C;
}

int Truck::Mtime()
{
    return maintenancetime;
}

Cargo** Truck::getCargosid()
{
    return  LCargo;
}

int Truck::Tspeed()
{
    return speed;
}

void Truck::setTspeed(int s)
{
    speed = s;
}

float Truck::TdelivaryIn()
{
    deliveryinterval = (GetMaxDistance() / speed) * 2 + GettotalLtime();
    return  deliveryinterval;
}

int Truck::getDeliveryNum()
{
    return maxj;
}

void Truck::setDeliveryNum(int n)
{
    maxj = n;
}

void Truck::print()
{
    cout << ID;
    switch (ttype)
    {
    case type::vip:
    {
        if (carriedcargos == 0)
            break;
        cout << "{";
        int i = 0;
        for (; i < carriedcargos - 1; i++)
            cout << (LCargo[i])->getID() << ",";
        cout << LCargo[i]->getID()<<"}";
        break;

    }
    case type::normal:
    {

        if (carriedcargos == 0)
            break;
        cout << "[";
        int i = 0;
        for (; i < carriedcargos - 1; i++)
            cout << (LCargo[i])->getID() << ",";
        cout << LCargo[i]->getID() << "]";
        break;
    }
    case type::special:
    {

        if (carriedcargos == 0)
            break;
           cout << "(";
        int i = 0;
        for (; i < carriedcargos - 1; i++)
            cout << (LCargo[i])->getID() << ",";
        cout << LCargo[i]->getID() << ")";
        break;
    }
 //if it reach the default hthen error message should be printed
    }
    
}

type Truck::gettype()
{
    return ttype;
}

int Truck::GetCarriedcargos()
{
    return carriedcargos;
}

int Truck::LTpriority(DaynHour CurrTime)
{
    int totalLT = GettotalLtime();
    return CurrTime.DaytoHours() + totalLT;
}

int Truck::GetMaxDistance()
{
    int max = LCargo[0]->GetDistance();
    for (size_t i = 1; i < carriedcargos; i++)
    {
        if (LCargo[i]->GetDistance() > max)
            max = LCargo[i]->GetDistance();
    }
    return max ;
}
int Truck::GettotalLtime()
{
    int totalLT = 0;
    for (int i = 0; i < carriedcargos; i++)
    {
        totalLT += LCargo[i]->GetLtime();
    }
    return totalLT;
}
int Truck:: MTpriority(DaynHour CurrTime)
{
    return CurrTime.DaytoHours() + deliveryinterval;
}