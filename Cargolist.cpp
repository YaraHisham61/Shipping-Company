#include "Cargolist.h"
#include"Cargo.h"

bool Cargolist::addcargo(int id, type c)
{
    return false;
}

bool Cargolist::creatcargo(DaynHour Cprepare, DaynHour Cload, int distance, double cost, int id, type c)
{
    Cargo* cptr = new Cargo(Cprepare, Cload, distance, cost,id, c);

    return false;

}
bool DequeueNCargo(int id)
{
  //  Cnormal.remove();
}



