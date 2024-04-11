#pragma once
#include "ISensor.h"

//Класс датчика света
class LightingSensor : public ISensor
{
private:
	int Lighting; //Освещенность в люксах 
public:
	LightingSensor() { SensorName = "LightingSensor"; } //Переопределение конструктора датчик принимает имя LightingSensor
	virtual void GetInformation() override;				//Переопределение метода сбора информации с измерительного устройства
	virtual int GiveInformation() override;				//Переопределение метода передачи информации собранной с измерительного устройства
	virtual string GiveName() override;					//Переопределение метода передачи информации об имени датчика
};

