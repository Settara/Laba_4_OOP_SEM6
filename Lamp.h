#pragma once
#include "IAO.h"

//Класс для натриевой газоразрядной лампы
class Lamp : public IAO
{
public:
	Lamp() { ObjectName = "Lamp"; }			//Переопределение конструктора объект принимает имя Lamp
	virtual void Start() override;			//Переопределение метода запуска работы объекта
	virtual void Finish() override;			//Переопределение метода завершания работы объекта
	virtual bool GetCondition() override;	//Переопределение метода получения информации о состоянии объекта
	virtual string GiveName() override;		//Переопределение метода передачи информации об имени объекта
};

