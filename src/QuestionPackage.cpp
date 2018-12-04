#include "QuestionPackage.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include "json.hpp"

using json = nlohmann::json;

QuestionPackage::QuestionPackage(const std::string& mName) : mName(mName) {}

void QuestionPackage::load(std::string path)
{
    std::ifstream i(path);
    json          j;
    i >> j;

    for (const auto& cat : j) {
        mQuestions.emplace_back(
            cat["Question"], cat["Answer"],
            std::stof(std::string{cat["Latitude"]}),
            std::stof(std::string{cat["Longitude"]}));
    }
}

void QuestionPackage::setActive(bool isActive)
{
    mIsActive = isActive;
}

bool QuestionPackage::isActive() const
{
    return mIsActive;
}

const std::string& QuestionPackage::getName() const
{
    return mName;
}

const std::string& QuestionPackage::getDescription() const
{
    return mDescription;
}