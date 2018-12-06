#include "QuestionPackage.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include "json.hpp"

using json = nlohmann::json;

QuestionPackage::QuestionPackage(const std::filesystem::path& path)
{
    std::ifstream i(path);
    json          j;
    i >> j;

    mName = j["Name"];
    mAuthor = j["Author"];

    for (const auto& cat : j["Questions"]) {
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

const std::string& QuestionPackage::name() const
{
    return mName;
}

const std::string& QuestionPackage::getDescription() const
{
    return mDescription;
}
