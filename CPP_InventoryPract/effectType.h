#pragma once
#include <cstdint>

namespace EffectType {
	enum Type {
		Speed = 1 << 0, // tempo
		Strength = 1 << 1, // robusto
		Defense = 1 << 2, // protecto
		Poison = 1 << 3, // poisonous
		WaterBreathing = 1 << 4, // water-breathing
		FireResistance = 1 << 5, // demon skinned
		ColdProtection = 1 << 6 // anti-cold
	};

	uint8_t operator +(uint8_t const& a, Type const& b) {
		return a | b;
	}

	uint8_t operator -(uint8_t const& a, Type const& b) {
		return a ^ b;
	}

	void operator +=(uint8_t& a, Type const& b) {
		a = a | b;
	}

	void operator -=(uint8_t& a, Type const& b) {
		a = a ^ b;
	}
}