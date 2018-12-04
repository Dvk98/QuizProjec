#include "Question.hpp"
#

Question::Question(
    const std::string& question,
    const std::string& answer,
    float              lat,
    float              lon)
    : mQuestion(question), mAnswer(answer), mLat(lat), mLon(lon)
{
}

const std::string& Question::getAnswer() const
{
    return mAnswer;
}

sf::Vector2f Question::getDestination() const
{
    return sf::Vector2f(mLat, mLon);
}

std::string Question::getQuestion() const
{
    return mQuestion;
}