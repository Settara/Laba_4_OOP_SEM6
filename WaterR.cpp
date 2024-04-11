#include "WaterR.h"

bool WaterR::GiveWatering(int quantity)
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


string WaterR::GiveName()
{
	return ReservoirName;
}