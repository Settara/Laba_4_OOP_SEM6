#include "IDynamicDatabase.h"

IDinamicDatabase::IDinamicDatabase(string DinamicDatabaseName)
{
	this->DinamicDatabaseName = DinamicDatabaseName;
}

void IDinamicDatabase::SetTemperatureCurrent(ISensor* sensor)
{
	sensor->GetInformation();
	TemperatureCurrent = sensor->GiveInformation();
}

void IDinamicDatabase::SetHumidityCurrent(ISensor* sensor)
{
	sensor->GetInformation();
	HumidityCurrent = sensor->GiveInformation();
}

void IDinamicDatabase::SetLightingCurrent(ISensor* sensor)
{
	sensor->GetInformation();
	LightingCurrent = sensor->GiveInformation();
}

int IDinamicDatabase::GetTemperatureCurrent()
{
	return TemperatureCurrent;
}

int IDinamicDatabase::GetHumidityCurrent()
{
	return HumidityCurrent;
}

int IDinamicDatabase::GetLightingCurrent()
{
	return LightingCurrent;
}