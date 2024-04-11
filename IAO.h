#pragma once
#include <string>
using std::string;

//Интерфейс для Прикладного объекта
class IAO
{
protected:
	string ObjectName;  //Переменная содержит имя объекта 
	bool Condition;		//Переменная содержит информацию работает ли объект в данный момент
public:
	IAO() //Конструктор без параметра устанавливает имя объекта как безымянный и устанавливает первоначальное состояние не работает
	{
		ObjectName = "ObjectName";
		Condition = false;
	};
	IAO(string ObjectName) //Конструктор устанавливает имя объекта и устанавливает первоначальное состояние не работает
	{ 
		this->ObjectName = ObjectName; 
		this->Condition = false;
	}; 
	virtual void Start() = 0;		//Метод запускает работу объекта
	virtual void  Finish() = 0;		//Метод завершает работу объекта
	virtual bool GetCondition() = 0;//Метод позволяет получить информацию о состоянии объекта
	virtual string GiveName() = 0;	//Метод передает информацию об имени базе данных

};

