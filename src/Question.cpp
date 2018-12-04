#include "Question.hpp"
#

Question::Question(
    std::string question,
    std::string answer,
    float       lat,
    float       lon)
    : mQuestion(question), mAnswer(answer), mLat(lat), mLon(lon)
{
}

std::string Question::getAnswer()
{
    return mAnswer;
}

sf::Vector2f Question::getDestination()
{
    return sf::Vector2f(mLat, mLon);
}

std::string Question::getQuestion()
{
    return mQuestion;
}