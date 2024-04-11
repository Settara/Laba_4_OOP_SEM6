#pragma once
#include "IAO.h"

//Класс для форточки
class Window : public IAO
{
public:
	Window() { ObjectName = "Window"; }		//Переопределение конструктора объект принимает имя Window
	virtual void Start() override;			//Переопределение метода запуска работы объекта
	virtual void Finish() override;			//Переопределение метода завершания работы объекта
	virtual bool GetCondition() override;	//Переопределение метода получения информации о состоянии объекта
	virtual string GiveName() override;		//Переопределение метода передачи информации об имени объекта
};
