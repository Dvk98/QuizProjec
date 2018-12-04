#pragma once

#include <fstream>
#include <string>
#include <vector>
#include "Question.hpp"

class QuestionPackage
{
public:
    explicit QuestionPackage(const std::string& mName);

    void load(std::string path);

    void setActive(bool isActive);

    bool isActive() const;

    const std::string& getName() const;

    const std::string& getDescription() const;

public:
    std::vector<Question> mQuestions;
    std::string           mName;
    std::string           mDescription;
    bool                  mIsActive{false};
};