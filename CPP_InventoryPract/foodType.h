#pragma once
#include <cstdint>

namespace FoodType {
	enum Type {
		Vegetables = 1 << 0,
		Mushroom = 1 << 1,
		Fish = 1 << 2,
		Meat = 1 << 3,
		Fruit = 1 << 4,
	};

	inline uint8_t operator+(uint8_t const& a, Type const& b) {
		return a | b;
	}

	inline uint8_t operator-(uint8_t const& a, Type const& b) {
		return a ^ b;
	}

	inline void operator+=(uint8_t & a, Type const& b) {
		a = a | b;
	}

	inline void operator-=(uint8_t & a, Type const& b) {
		a = a ^ b;
	}
}