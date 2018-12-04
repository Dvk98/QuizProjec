#pragma once
#include <SFML/System.hpp>
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>

sf::Vector2f convertGeoToMercator(float lat, float lon, sf::Vector2f map, sf::Vector2f offset)
{
	auto latitude = lat;
	auto longitude = lon;


	auto mapWidth = map.x;
	auto xMid = mapWidth / 2.0f;
	auto mapHeight = map.y;
	auto yMid = mapHeight / 2.0f;
	auto mapOffsetX = offset.x;
	auto mapOffsetY = offset.y;
	auto R = mapWidth / M_PI / 2;
	//std::cout << "MapWidth/Mapheight: " << mapWidth << "|" << mapHeight << std::endl;
	//std::cout << "MapOffsetX/Y " << mapOffsetX << "|" << mapOffsetY << std::endl;
	//std::cout << "latitude/longitude: " << coordinates.x << "|" << coordinates.y << std::endl;

	auto x = R* (longitude * M_PI / 180.0f);
	auto latrad = (latitude/ 2.0f) * M_PI / 180.0f;
	auto mercN = log(tan((M_PI / 4.0f) + latrad));
	auto y = mapWidth / (2.0f * M_PI) * mercN;

	std::cout << x << "|" << y << std::endl;
	std::cout << mapHeight << "|||" << latrad << std::endl;
	return sf::Vector2f(xMid + x, yMid - y);

}


sf::Vector2f convertGeoToMercator2(sf::Vector2f coordinates, sf::Vector2f map, sf::Vector2f offset, sf::Vector2f windowSize)
{
	auto latitude = coordinates.x;
	auto longitude = coordinates.y;

	auto mapWidth = map.x;
	auto mapHeight = map.y;
	auto mapOffsetX = offset.x;
	auto mapOffsetY = offset.y;

	auto x = (longitude + 180)*((mapWidth) / 360);
	auto latRad = latitude * M_PI / 180;
	auto mercN = log(tan((M_PI / 4.0f) + (latRad / 2.0f)));
	auto y = ((mapHeight) / 2) - ((mapHeight)*mercN / (2.0f*M_PI));
	std::cout << x << "|" << y << std::endl;
	return sf::Vector2f(x + mapOffsetX, y + mapOffsetY);

}