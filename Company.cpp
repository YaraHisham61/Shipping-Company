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

bool Company::EnqueueCargo(Cargo* C1,type ctype)
{
	switch (ctype)
	{
	case type::vip :
	{
		/*return Cvip.Enqueue(C1);*/ //Needs to add priority according to the eqn
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
	 //Needs to be handled
}



