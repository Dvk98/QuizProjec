#include "QuestionPackage.hpp"
#include <fstream>
#include "json.hpp"
#include <iostream>
#include <string>


using json = nlohmann::json;

QuestionPackage::QuestionPackage(std::string name)
	:isActive(0),
	name(name)
{
}

void QuestionPackage::load(std::string path)
{
	std::ifstream i(path);
	json j;
	i >> j;
	
	for (auto cat : j)
	{
		std::string questionText = cat["Question"];
		std::string answerText = cat["Answer"];
		std::string latitude = cat["Latitude"];
		std::string longitude = cat["Longitude"];

		Question question(questionText, answerText, std::stof(latitude), std::stof(longitude));
		mQuestions.emplace_back(question);
	}
	
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