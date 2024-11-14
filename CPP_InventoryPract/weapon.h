#pragma once
#include <iostream>
#include "item.h"
#include "itemType.h"

class Weapon : public Item
{
public :
	Weapon(int attack, std::string name, std::string description, int cost, int manaConsumptionAmount, int curseLevel, int durability);

	void Equip();
	void Attack();

	void SetAttack(int attack);
	uint8_t GetAttack();

protected:
	uint8_t mAttack;
};

