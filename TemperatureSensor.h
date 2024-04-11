#pragma once
#include "ISensor.h"

//Класс датчика температуры
class TemperatureSensor : public ISensor
{
private:
	int Temperature;							//Температура в Кельвинах
public:
	TemperatureSensor() { SensorName = "TemperatureSensor"; }	//Переопределение конструктора датчик принимает имя TemperatureSensor
	virtual void GetInformation() override;						//Переопределение метода сбора информации с измерительного устройства
	virtual int GiveInformation() override;						//Переопределение метода передачи информации собранной с измерительного устройства
	virtual string GiveName() override;							//Переопределение метода передачи информации об имени датчика
};

