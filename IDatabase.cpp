#include "IDatabase.h"

IDatabase::IDatabase()
{
	DatabaseName = "Nameless";
}

IDatabase::IDatabase(string DatabaseName)
{
	this->DatabaseName = DatabaseName;
}

void IDatabase::SetTemperatureMax(int value)
{
	TemperatureMax = value;
}

void IDatabase::SetTemperatureMin(int value)
{
	TemperatureMin = value;
}

void IDatabase::SetHumidityMax(int value)
{
	HumidityMax = value;
}

void IDatabase::SetHumidityMin(int value)
{
	HumidityMin = value;
}

void IDatabase::SetLightingMax(int value)
{
	LightingMax = value;
}

void IDatabase::SetLightingMin(int value)
{
	LightingMin = value;
}

int IDatabase::GetInformation(Characteristic name)
{
	if (name == temperatureMax)
	{
		return TemperatureMax;
	}
	else 
	{
		if (name == temperatureMin)
		{
			return TemperatureMin;
		}
		else
		{
			if (name == humidityMax)
			{
				return HumidityMax;
			}
			else
			{

				if (name == humidityMin)
				{
					return HumidityMin;
				}
				else
				{
					if (name == lightingMax)
					{
						return LightingMax;
					}
					else
					{
						if (name == lightingMin)
						{
							return LightingMin;
						}
					}
				}
			}
		}
	}

}
