#pragma once
#include "R.h"

//Класс системы полива 
class IIS
{
private: 
	R* Reservoir;	  //Поле хранит указатель на резервуар
	string SystemType;//Поле хранит тип системы
public:
	//Система полива конфигурируется конкретным объектом резервуара и делегирует ему выполнение полива
	IIS(R* Reservoir)
	{
		this->Reservoir = Reservoir;
		this->SystemType = Reservoir->GiveName();
	}
	bool StartWatering(int quantity);
	string GiveSystemType();
};

