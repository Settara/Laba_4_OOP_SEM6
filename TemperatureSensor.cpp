#include "TemperatureSensor.h"

void TemperatureSensor::GetInformation()
{
	Temperature = (int)((rand() / 32767.0) * (50)) + 273; //Генерация случайной температуры от 0 до 50 градусов(Цельсия) в кельвинах
}

int TemperatureSensor::GiveInformation()
{
	return Temperature;
}

string TemperatureSensor::GiveName()
{
	return SensorName;
}