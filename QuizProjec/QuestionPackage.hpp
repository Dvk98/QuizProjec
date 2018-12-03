#pragma once

#include <vector>
#include <fstream>
#include <string>
#include "Question.hpp"

class QuestionPackage {

public:
	QuestionPackage(std::string name);
	void load(std::string path);
	void setActive();
	void setInactive();
	bool getState();

	std::string getName();
	std::string getDescription();

public:
	std::vector<Question> mQuestions;

private:
	std::string name;
	std::string description;
	bool isActive;
};