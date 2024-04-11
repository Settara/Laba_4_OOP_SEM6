#pragma once
#include <string>
using std::string;

//Интерфейс датчиков
class ISensor
{
protected:
	string SensorName; //Имя датчика

public:
	ISensor() { this->SensorName = "SensorName"; };				   //Конструктор без параметра устанавливает имя датчика
	ISensor(string SensorName) { this->SensorName = SensorName; }; //Конструктор устанавливает имя датчика
	virtual void GetInformation() = 0;						       //Метод собирает информацию с измерительного устройства
	virtual int GiveInformation() = 0;							   //Метод передает информацию базе данных
	virtual string GiveName() = 0;								   //Метод передает информацию об имени базе данных

};

