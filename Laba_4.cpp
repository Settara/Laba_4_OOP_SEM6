// Laba_4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include "IAO.h"
#include "ProxyDatabase.h"
#include "IGMS.h"
#include "ProxyDatabase.h"
#include "TemperatureSensor.h"
#include "HumiditySensor.h"
#include "LightingSensor.h"
#include "Window.h"
#include "Ventilator.h"
#include "Lamp.h"
#include "FireR.h"
#include "WaterR.h"



int main()
{
    setlocale(LC_ALL, "RUS");
    //Создаем систему управления теплицей
    IGMS* ManagmentSystem = new IGMS(3);
    //Cоздаем динамиическую базу данных
    IDinamicDatabase* DinB = new IDinamicDatabase("Динамическая база данных");
    //Cоздаем статическую базу данных
    IDatabase* DB = new IDatabase();
    //Cоздаем прокси для базы данных
    ProxyDatabase* PD = new ProxyDatabase(DB);
    //Создаем массив указателей на датчики
    ISensor* Sensors[NSensors];
    //Создаем датчики
    Sensors[0] = new TemperatureSensor();
    Sensors[1] = new HumiditySensor();
    Sensors[2] = new LightingSensor();
    //Создаем массив указателей на прикладные объекты
    IAO* Objects[NObjects];
    //Создаем прикладные объекты
    Objects[0] = new Window();
    Objects[1] = new Ventilator();
    Objects[2] = new Lamp();
    //Создаем резервуары
    R* WaterReservoir = new WaterR();
    R* FireReservoir = new FireR();
    //Создаем массив указателей на системы полива
    IIS* Systems[NSystem];
    //Создаем системы полива которые конфигурируются непосредственно резервуарами
    Systems[0] = new IIS(WaterReservoir);
    Systems[1] = new IIS(FireReservoir);
    //Устанавливаем граничные значения для базы данных
    PD->SetHumidityMax(80);
    PD->SetHumidityMin(20);
    PD->SetLightingMax(1900);
    PD->SetLightingMin(500);
    PD->SetTemperatureMax(307);
    PD->SetTemperatureMin(293);
    //Вызываем главный метод управления теплицей
    ManagmentSystem->Management(DinB, PD, Sensors, Objects, Systems);
    cout << endl << "Сделал работу Иван Чепрасов" << endl;
} 
