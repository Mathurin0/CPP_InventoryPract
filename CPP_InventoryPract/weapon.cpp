#include "weapon.h"

Weapon::Weapon(int attack, std::string name, std::string description, int cost, int manaConsumptionAmount, int curseLevel, int durability) : Item(name, description, cost, ItemType::Weapon, manaConsumptionAmount, curseLevel, durability)
{
	mAttack = attack;
}

void Weapon::Equip()
{
	std::cout << "You equipped the weapon : " << mName << std::endl;
}

void Weapon::Attack()
{
	std::cout << "You inflicted " << mAttack << " damages !" << std::endl;
}

void Weapon::SetAttack(int attack)
{
	mAttack = attack;
}

uint8_t Weapon::GetAttack()
{
	return mAttack;
}
