#pragma once

namespace ItemType {
	enum Type {
		Breackable = 1<<0,
		Cursed = 1<<1,
		Magic = 1<<2,
		Consumable = 1<<3,
		Tool = 1<<4,
		Weapon = 1<<5,
		Armor = 1<<6,
		Food = 1<<8
	};

	uint8_t operator +(uint8_t const& a, Type const& b) {
		return a | b;
	}

	uint8_t operator -(uint8_t const& a, Type const& b) {
		return a ^ b;
	}

	void operator +=(uint8_t & a, Type const& b) {
		a = a | b;
	}

	void operator -=(uint8_t & a, Type const& b) {
		a = a ^ b;
	}
}