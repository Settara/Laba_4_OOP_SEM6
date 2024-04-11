#include "IGMS.h"

void IGMS::Management(IDinamicDatabase* DinBase, ProxyDatabase* Database, ISensor* Sensors[NSensors], IAO* Objects[NObjects], IIS* Systems[NSystem])
{
	//Для начала нужно опросить все датчики чтобы узнать текущие параметры
	do
	{	
		for (int i = 0; i < NSensors; i++) {
			if (Sensors[i]->GiveName() == "TemperatureSensor")
			{
				DinBase->SetTemperatureCurrent(Sensors[i]);			//Опрашиваем датчик
				CurrentValue = DinBase->GetTemperatureCurrent();	//Получаем значение с датчика и записываем в поле текущее значение
				cout << endl << "Текущее значение температуры: " << CurrentValue;
				//Если температура больше чем должна быть
				if (CurrentValue > Database->GetInformation(temperatureMax))
				{
					cout << endl << "Максимально допустимое значение температуры: " << Database->GetInformation(temperatureMax);
					cout << endl << "Температура больше чем должна быть ";
					//Перебираем прикладные объекты чтобы найти нужный
					for (int i = 0; i < NObjects; i++) {
						if (Objects[i]->GiveName() == "Ventilator") {
							Objects[i]->Start();
							cout << endl << "Включаем вентилятор";
						}
						if (Objects[i]->GiveName() == "Window") {
							Objects[i]->Finish();
							cout << endl << "Закрываем окно";
						}
					}
				}
				//Если температура меньше чем должна быть
				if (CurrentValue < Database->GetInformation(temperatureMin))
				{
					cout << endl << "Минимально допустимое значение температуры: " << Database->GetInformation(temperatureMin);
					cout << endl << "Температура меньше чем должна быть " ;
					//Перебираем прикладные объекты чтобы найти нужный
					for (int i = 0; i < NObjects; i++) {
						if (Objects[i]->GiveName() == "Window") {
							Objects[i]->Start();
							cout << endl << "Открываем окно";
						}
						if (Objects[i]->GiveName() == "Ventilator") {
							Objects[i]->Finish();
							cout << endl << "Выключаем вентилятор";
						}
					}
				}
			}
			else
			{
				if (Sensors[i]->GiveName() == "HumiditySensor")
				{
					DinBase->SetHumidityCurrent(Sensors[i]);		//Опрашиваем датчик
					CurrentValue = DinBase->GetHumidityCurrent();	//Получаем значение с датчика и записываем в поле текущее значение
					cout << endl << "Текущее значение влажности: " << CurrentValue;
					//Если влажность больше чем должна быть 
					if (CurrentValue > Database->GetInformation(humidityMax))
					{
						cout << endl << "Максимально допустимое значение влажности: " << Database->GetInformation(humidityMax);
						cout << endl << "Влажность больше чем должна быть ";
						//Перебираем прикладные объекты чтобы найти нужный
						for (int i = 0; i < NObjects; i++) {
							if (Objects[i]->GiveName() == "Window") {
								Objects[i]->Start();
								cout << endl << "Открываем окно";
							}
						}
					}
					//Если влажность меньше чем должна быть
					if (CurrentValue < Database->GetInformation(humidityMin))
					{
						cout << endl << "Минимально допустимое значение влажности: " << Database->GetInformation(humidityMin);
						cout << endl << "Влажность меньше чем должна быть ";
						//Перебираем прикладные объекты чтобы найти нужный
						for (int i = 0; i < NObjects; i++) {
							if (Objects[i]->GiveName() == "Window") {
								Objects[i]->Finish();
								cout << endl << "Закрываем окно";
							}
						}
						//Перебираем системы полива чтобы найти нужную
						for (int i = 0; i < NSystem; i++) {
							if (Systems[i]->GiveSystemType() == "WaterReservoir") {
								if (Systems[i]->StartWatering(5) == true)
								{
									cout << endl << "Пошел полив растений";
								}
								else
								{
									cout << endl << "Не хватило воды";
								};
							}
						}
					}
				}
				else
				{
					if (Sensors[i]->GiveName() == "LightingSensor")
					{
						DinBase->SetLightingCurrent(Sensors[i]);	 //Опрашиваем датчик
						CurrentValue = DinBase->GetLightingCurrent();//Получаем значение с датчика и записываем в поле текущее значение
						cout << endl << "Текущее значение освещенности: " << CurrentValue;
						//Если освещенность больше чем должна быть 
						if (CurrentValue > Database->GetInformation(lightingMax))
						{
							cout << endl << "Максимально допустимое значение освещенности: " << Database->GetInformation(lightingMax);
							cout << endl << "Освещенность больше чем должна быть ";
							//Перебираем прикладные объекты чтобы найти нужный
							for (int i = 0; i < NObjects; i++) {
								if (Objects[i]->GiveName() == "Lamp") {
									Objects[i]->Finish();
									cout << endl << "Выключаем лампу";
								}
							}
						}
						//Если освещенность меньше чем должна быть
						if (CurrentValue < Database->GetInformation(lightingMin))
						{
							cout << endl << "Минимально допустимое значение освещенности: " << Database->GetInformation(lightingMin);
							cout << endl << "Освещенность меньше чем должна быть ";
							//Перебираем прикладные объекты чтобы найти нужный
							for (int i = 0; i < NObjects; i++) {
								if (Objects[i]->GiveName() == "Lamp") {
									Objects[i]->Start();
									cout << endl << "Включаем лампу";
								}
							}
						}
					}
					else
					{
						//Ничего не делать
					}
				}
			}
		}
		//После этого выжидаем какое-то время и повторяем заново
		sleep_until(system_clock::now() + seconds(1));
		Counter--;
		if (Counter <= 0) 
		{
			Working = false;
		}
	} while (Working == true);
}