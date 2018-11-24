#pragma once

#include <vector>
#include "Question.hpp"

class QuestionPackage {

public:
	QuestionPackage();
	void load();
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