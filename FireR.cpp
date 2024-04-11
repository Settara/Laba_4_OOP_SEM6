#include "FireR.h"

bool FireR::GiveWatering(int quantity)
{
	this->ShelfLife = this->ShelfLife - 1;
	if(ShelfLife <= 0)
	{ 
		return false;
	}
	else
	{
		if (quantity <= this->Fullness)
		{
			Fullness = Fullness - quantity;
			return true;
		}
		else
		{
			return false;
		}
	}
}


string FireR::GiveName()
{
	return ReservoirName;
}