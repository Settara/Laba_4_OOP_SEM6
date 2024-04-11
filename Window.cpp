#include "Window.h"

void Window::Start()
{
	this->Condition = true;
}

void Window::Finish()
{
	this->Condition = false;
}

bool Window::GetCondition()
{
	return Condition;
}

string Window::GiveName()
{
	return ObjectName;
}
