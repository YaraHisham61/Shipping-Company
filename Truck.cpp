#include "Truck.h"

int Truck::IDcounter = 1;

bool Truck::needsmainaience()
{
    return numofjourney >= maxj;
}

void Truck::addjourney()
{
    numofjourney++;
}
DaynHour Truck::getmovingtime()
{
    return movingtime;
}


Truck::Truck(int truckcapacity, int maintenancetime, int maxj, int speed, type ttype)
{
    this->truckcapacity = truckcapacity;
    this->maintenancetime = maintenancetime;
    this->speed = speed;
    this->maxj = maxj;
    this->ttype = ttype;
    LCargo = new Cargo * [truckcapacity];
    carriedcargos = 0;
    ID = IDcounter;
    IDcounter++;
    numofjourney = 0;
    endmoving = 0;

}

Truck::Truck()
{
    endmoving = 0;
    numofjourney = 0;
    LCargo = new Cargo * [truckcapacity];
    speed = 0;
    carriedcargos = 0;
    ID = IDcounter;
    IDcounter++;
}

int Truck::incheckpriority()
{
    return endcheck;

}
void Truck::setincheckpriorty(DaynHour currT)
{
    endcheck = maintenancetime + currT.DaytoHours();
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
    endloading = CurrTime.DaytoHours() + totalLT;
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
    return max;
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
int Truck::Getendmoving()
{
    return endmoving;
}
int Truck::Getendloading()
{
    return endloading;
}
void Truck::setmovingtime(DaynHour currt)
{
    movingtime = currt;
}
void Truck::resetjourneys()
{
    numofjourney -= maxj;
}
void Truck::setCargo(Cargo* c, int i)
{
    LCargo[i] = c;
}
int Truck::MTpriority(DaynHour CurrTime)
{
    endmoving = CurrTime.DaytoHours() + deliveryinterval;
    return CurrTime.DaytoHours() + deliveryinterval;
}
