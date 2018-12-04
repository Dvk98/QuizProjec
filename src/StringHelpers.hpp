#pragma once

#include <sstream>

// Since std::to_string doesn't work on MinGW we have to implement
// our own to support all platforms.
template <typename T>
std::string toString(sf::Vector2<T> value)
{
	std::stringstream stream;
	stream << '(' << value.x << '|' << value.y << ')';
	return stream.str();
}
