#ifndef DEBUG_HPP
#define DEBUG_HPP

//! @file
//! Some debug files implementation

#include <SFML/System/Vector2.hpp>
#include <iostream>

template<typename T>
std::ostream& operator<<(std::ostream& out, const sf::Vector2<T>& vec) {
	out << "[" << vec.x << ", " << vec.y << "]";
	return out;
}

#endif // DEBUG_HPP
