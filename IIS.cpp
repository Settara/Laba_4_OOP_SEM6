#include "IIS.h"

bool IIS::StartWatering(int quantity)
{
	return this->Reservoir->GiveWatering(quantity);
}

string IIS::GiveSystemType()
{
	return this->SystemType;
}