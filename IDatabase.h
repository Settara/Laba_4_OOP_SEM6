#pragma once
#include <string>
#include "Characteristic.h"
using std::string;

//Класс статической базы данных
class IDatabase
{
private:
	string DatabaseName;	 //Поле хранит имя базы данных
	int TemperatureMax;		 //Поле хранит максимальное значение температуры
	int TemperatureMin;		 //Поле хранит минимальное  значение температуры 
	int HumidityMax;		 //Поле хранит максимальное значение влажности 
	int HumidityMin;		 //Поле хранит минимальное  значение влажности 
	int LightingMax;		 //Поле хранит максимальное значение освещения 
	int LightingMin;		 //Поле хранит минимальное  значение освещения 

public:
	IDatabase( );										    //Констуктор по умолчанию устанавливает имя базы данных
	IDatabase(string DatabaseName);						    //Констуктор устанавливает имя базы данных
	void SetTemperatureMax(int value);						//Метод устанавливает значения поля TemperatureMax
	void SetTemperatureMin(int value);						//Метод устанавливает значения поля TemperatureMin
	void SetHumidityMax(int value);							//Метод устанавливает значения поля HumidityMax
	void SetHumidityMin(int value);							//Метод устанавливает значения поля HumidityMin
	void SetLightingMax(int value);							//Метод устанавливает значения поля LightingMax
	void SetLightingMin(int value);							//Метод устанавливает значения поля LightingMin
	virtual int GetInformation(Characteristic name);		//Метод выбирает нужную информацию и передает числовое значение.
	
};

