#pragma once
#include "R.h"
class FireR : public R
{
private:
	int ShelfLife; //Переменная отвечает за срок хранения пожаротушащей жидкости
public:
	//Переопределение конструктора резервуар принимает имя FireReservoir
	FireR() {
		this->ReservoirName = "FireReservoir";
		this->Fullness = 75;
		this->ShelfLife = 5;
	}
	virtual bool GiveWatering(int quantity) override;	//Переопределение метода для передачи нужного количества жидкости
	virtual string GiveName() override;					//Переопределение метода передачи информации об имени датчика
};

