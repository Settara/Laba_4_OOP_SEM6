#include "HumiditySensor.h"

void HumiditySensor::GetInformation()
{
	Humidity = (int)((rand() / 32767.0) * (100)); //Генерация случайной влажности от 0 до 100 процентов 
}

int HumiditySensor::GiveInformation()
{
	return Humidity;
}

string HumiditySensor::GiveName()
{
	return SensorName;
}