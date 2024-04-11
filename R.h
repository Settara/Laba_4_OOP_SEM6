#pragma once
#include <string>
using std::string;

//Интерфейс резервуаров
class R
{
protected:
	string ReservoirName; //Имя резервуара
	int Fullness; //Наполненность резервуара

public:
	//Конструктор по умолчанию устанавливает имя резервуара
	R() 
	{
		this->ReservoirName = "ReservoirName"; 
		this->Fullness = 0;
	};				  
	R(string SensorName) { this->ReservoirName = SensorName; };	   //Конструктор устанавливает имя резервуара
	virtual bool GiveWatering(int quantity) = 0;				   //Метод передает нужное количество жидкости
	virtual string GiveName() = 0;								   //Метод передает информацию об имени резервуара
};

