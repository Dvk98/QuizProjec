#pragma once

#include <filesystem>
#include <fstream>
#include <string>
#include <vector>
#include "Question.hpp"

class QuestionPackage
{
public:
    explicit QuestionPackage(const std::filesystem::path& path);

    void setActive(bool isActive);

    bool isActive() const;

    const std::string& getName() const;

    const std::string& getDescription() const;

public:
    std::vector<Question> mQuestions;
    std::string           mAuthor;
    std::string           mName;
    std::string           mDescription;
    bool                  mIsActive{false};
};
