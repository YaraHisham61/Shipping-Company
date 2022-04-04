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

bool Company::EnqueueNCargo(Cargo* C1)
{

	return Cnormal.enqueue(C1); //Needs to be handled
}


bool Company::EnqueueVCargo(Cargo* cptr)
{
	/*return Cvip.Enqueue(cptr);*/ //Needs to add priority according to the eqn
	
}


