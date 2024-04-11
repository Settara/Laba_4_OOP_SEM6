#pragma once
#include "IAO.h"

//Класс для вентилятора
class Ventilator : public IAO
{
public:
	Ventilator() { ObjectName = "Ventilator"; }			//Переопределение конструктора объект принимает имя Ventilator
	virtual void Start() override;						//Переопределение метода запуска работы объекта
	virtual void Finish() override;						//Переопределение метода завершания работы объекта
	virtual bool GetCondition() override;				//Переопределение метода получения информации о состоянии объекта
	virtual string GiveName() override;					//Переопределение метода передачи информации об имени объекта
};

