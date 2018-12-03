#pragma once
#include <SFML/Graphics.hpp>

class Question
{
public:
	Question(std::string question, std::string answer, float lat, float lon);
	std::string getAnswer();
	sf::Vector2f getDestination();
	std::string getQuestion();


private:
	std::string mQuestion;
	std::string mAnswer;
	float mLat;
	float mLon;
};