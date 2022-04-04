#include "Company.h"
#include "Cargolist.h"
#include "Cargo.h"
Company::Company()
{

}

bool Company::DequeueNCargo(int id,Cargo* C1)
{
 return Cnormal.remove(id, C1);

}

bool Company::EnqueueVCargo(Cargo* cptr)
{
	return Cvip.enqueue(cptr);
	
}


