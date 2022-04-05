#include "CancelEvent.h"

bool CancelEvent::Excute()
{
    Cargo* cancelCargo;
    if (Cpointer->DequeueNCargo(CargoID, cancelCargo))
    {
        delete cancelCargo;
        return true;
    }
    return false;
}
