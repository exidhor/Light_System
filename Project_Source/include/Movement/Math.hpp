#ifndef DEF_MATH_HPP
#define DEF_MATH_HPP

#include <cstdint>
#include <SFML/Graphics.hpp>
#include <cmath>

/*!
 * \class Math
 * \brief
 *
 */
namespace Math
{
	template <typename T>	
	sf::Vector2<T> abs(sf::Vector2<T> const& vector);
};

template <typename T>
sf::Vector2<T> Math::abs(sf::Vector2<T> const& vector)
{
	return sf::Vector2<T>(std::abs(vector.x), std::abs(vector.y));
}

#endif // DEF_MATH_HPP
