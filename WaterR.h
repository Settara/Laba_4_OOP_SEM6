#pragma once
#include "R.h"
class WaterR : public R
{
private:
	
public:
	//Переопределение конструктора резервуар принимает имя WaterReservoir
	WaterR() { 
		this->ReservoirName = "WaterReservoir";
		this->Fullness = 100;
	}		
	virtual bool GiveWatering(int quantity) override;	//Переопределение метода для передачи нужного количества жидкости
	virtual string GiveName() override;					//Переопределение метода передачи информации об имени датчика
};

