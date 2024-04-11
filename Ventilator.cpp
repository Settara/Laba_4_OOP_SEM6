#include "Ventilator.h"

void Ventilator::Start()
{
	this->Condition = true;
}

void Ventilator::Finish()
{
	this->Condition = false;
}

bool Ventilator::GetCondition()
{
	return Condition;
}

string Ventilator::GiveName()
{
	return ObjectName;
}