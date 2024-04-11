#pragma once
#include <chrono>
#include <thread>
#include "IDynamicDatabase.h"
#include "ProxyDatabase.h"
#include <iostream>
#include "IAO.h"
#include "IIS.h"

using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds
using namespace std;

//Класс управления теплицей
class IGMS
{
private: 
	int CurrentValue; //Поле содержит текущее значение параметра
	int Counter;	  //Поле содержит счетчик сколько интераций проработает теплица
	bool Working;	  //Поле содержит информацию работает ли система или нет
public:
	IGMS() 
	{
		Working = true; 
	}
	IGMS(int count) 
	{ 
		Working = true; 
		Counter = count;
	}
	//Метод отвечает за логику работы теплицы
	void Management(IDinamicDatabase* DinBase, ProxyDatabase* Database, ISensor* Sensors[NSensors], IAO* Objects[NObjects], IIS* Systems[NSystem]); 
};

