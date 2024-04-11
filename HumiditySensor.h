#pragma once
#include "ISensor.h"

//Класс датчика влажности
class HumiditySensor : public ISensor
{
private:
	int Humidity; //Влажность в процентах 
public:
	HumiditySensor() { SensorName = "HumiditySensor"; } //Переопределение конструктора датчик принимает имя HumiditySensor
	virtual void GetInformation() override;				//Переопределение метода сбора информации с измерительного устройства
	virtual int GiveInformation() override;				//Переопределение метода передачи информации собранной с измерительного устройства
	virtual string GiveName() override;					//Переопределение метода передачи информации об имени датчика
};

