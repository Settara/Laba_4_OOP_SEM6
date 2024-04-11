#include "Lamp.h"

void Lamp::Start()
{
	this->Condition = true;
}

void Lamp::Finish()
{
	this->Condition = false;
}

bool Lamp::GetCondition()
{
	return Condition;
}

string Lamp::GiveName()
{
	return ObjectName;
}