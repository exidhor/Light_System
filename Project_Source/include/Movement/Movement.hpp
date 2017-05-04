#ifndef DEF_MOVEMENT_HPP
#define DEF_MOVEMENT_HPP

#include <cstdint>
#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>
#include "Movement/Math.hpp"


namespace Movement
{
	template <typename T>
	sf::Vector2<T> offset(sf::Vector2<T> const& start, sf::Vector2<T> const& end);

	template <typename T>
	T distance(sf::Vector2<T> const& start, sf::Vector2<T> const& end);

	template <typename T>
	sf::Vector2<T> deplacement(sf::Vector2<T> const& start, sf::Vector2<T> const& direction, double speed);
}


template <typename T>
sf::Vector2<T> Movement::offset(sf::Vector2<T> const& start, sf::Vector2<T> const& end)
{
	return end - start;
}

template <typename T>
T Movement::distance(sf::Vector2<T> const& start, sf::Vector2<T> const& end)
{
	sf::Vector2<T> distances = Math::abs(offset(start, end));

	return std::sqrt(distances.x * distances.x + distances.y * distances.y);
}

template <typename T>
sf::Vector2<T> Movement::deplacement(sf::Vector2<T> const& start, sf::Vector2<T> const& direction, double speed)
{
	if(speed < 0)
	{
		std::cerr << "Speed < 0 during a call to deplacement" << std::endl;
		return sf::Vector2<T>(); // no deplacement;
	}

	T distanceValue = distance(start, direction);

	if(distanceValue <= speed)
	{
		return offset(start, direction);
	}

	double ratio = speed / distanceValue;

	return offset(start, direction) * (float)ratio;
}

#endif // DEF_MOVEMENT_HPP