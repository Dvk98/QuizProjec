#include "QuestionPackage.hpp"

QuestionPackage::QuestionPackage()
	:isActive(0)
{
}

void QuestionPackage::load()
{
	//load QuestionPackage from JSON File
}

void QuestionPackage::setActive()
{
	isActive = 1;
}

void QuestionPackage::setInactive()
{
	isActive = 0;
}

bool QuestionPackage::getState()
{
	return isActive;
}

std::string QuestionPackage::getName()
{
	return name;
}

std::string QuestionPackage::getDescription()
{
	return description;
}