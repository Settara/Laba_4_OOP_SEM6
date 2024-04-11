#include "LightingSensor.h"

void LightingSensor::GetInformation()
{
	Lighting = (int)((rand() / 32767.0) * (2000)) ; //Генерация случайной освещенности от 0 до 2000 люксов 
}

int LightingSensor::GiveInformation()
{
	return Lighting;
}

string LightingSensor::GiveName()
{
	return SensorName;
}