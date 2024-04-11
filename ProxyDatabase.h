#pragma once
#include "IDatabase.h"

//Прокси-класс статической базы данных
class ProxyDatabase : public IDatabase
{
private:
    IDatabase* realDatabase;

public:
	//Конструктор по умолчанию присваивает полю realDatabase NULL
	ProxyDatabase()
	{
		this->realDatabase = NULL;
	};
	//Конструктор принимает указатель на экземпляр объекта Database и присваивает его значение полю realDatabase
    ProxyDatabase(IDatabase* realDatabase) 
	{
		this->realDatabase = realDatabase;
	}; 
	virtual void SetTemperatureMax(int value);					//Метод устанавливает значения поля TemperatureMax
	virtual void SetTemperatureMin(int value);					//Метод устанавливает значения поля TemperatureMin
	virtual void SetHumidityMax(int value);						//Метод устанавливает значения поля HumidityMax
	virtual void SetHumidityMin(int value);						//Метод устанавливает значения поля HumidityMin
	virtual void SetLightingMax(int value);						//Метод устанавливает значения поля LightingMax
	virtual void SetLightingMin(int value);						//Метод устанавливает значения поля LightingMin
	virtual int GetInformation(Characteristic name) override;	//Метод выбирает нужную информацию и передает числовое значение.
};

