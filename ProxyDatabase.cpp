#include "ProxyDatabase.h"

void ProxyDatabase::SetTemperatureMax(int value)
{
	realDatabase->SetTemperatureMax(value);
}

void ProxyDatabase::SetTemperatureMin(int value)
{
	realDatabase->SetTemperatureMin(value);
}

void ProxyDatabase::SetHumidityMax(int value)
{
	realDatabase->SetHumidityMax(value);
}

void ProxyDatabase::SetHumidityMin(int value)
{
	realDatabase->SetHumidityMin(value);
}

void ProxyDatabase::SetLightingMax(int value)
{
	realDatabase->SetLightingMax(value);
}

void ProxyDatabase::SetLightingMin(int value)
{
	realDatabase->SetLightingMin(value);
}

int ProxyDatabase::GetInformation(Characteristic name)
{
	return realDatabase->GetInformation(name);
}