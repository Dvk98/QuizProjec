#pragma once
#include <SFML/Graphics.hpp>

class Question
{
public:
    Question(
        const std::string& question,
        const std::string& answer,
        float              lat,
        float              lon);

    const std::string& getAnswer() const;

    sf::Vector2f getDestination() const;

    std::string getQuestion() const;

private:
    std::string mQuestion;
    std::string mAnswer;
    float       mLat;
    float       mLon;
};