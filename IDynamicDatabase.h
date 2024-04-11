#pragma once
#include "Characteristic.h"
#include "ISensor.h"

//Класс динамической базы данных
class IDinamicDatabase
{
private:
	string DinamicDatabaseName;	 //Поле хранит имя базы данных
	int TemperatureCurrent;		 //Поле хранит текущее значение температуры
	int HumidityCurrent;		 //Поле хранит текущее значение влажности 
	int LightingCurrent;		 //Поле хранит текущее значение освещения 
	
public:
	IDinamicDatabase(string DinamicDatabaseName);//Констуктор устанавливает имя базы данных
	void SetTemperatureCurrent(ISensor* sensor); //Метод опрашивает датчик и устанавливает значения поля TemperatureCurrent
	void SetHumidityCurrent(ISensor* sensor);	 //Метод опрашивает датчик и устанавливает значения поля HumidityCurrent
	void SetLightingCurrent(ISensor* sensor);	 //Метод опрашивает датчик и устанавливает значения поля LightingCurrent
	int GetTemperatureCurrent();				 //Метод возвращает значения поля TemperatureCurrent
	int GetHumidityCurrent();					 //Метод возвращает значения поля HumidityCurrent
	int GetLightingCurrent();					 //Метод возвращает значения поля LightingCurrent

};