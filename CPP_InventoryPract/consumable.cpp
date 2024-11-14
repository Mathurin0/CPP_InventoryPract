#include "consumable.h"

Consumable::Consumable(uint8_t effect, std::string name, std::string description, int cost, int manaConsumptionAmount, int curseLevel, int durability) : Item(name, description, cost, ItemType::Consumable, manaConsumptionAmount, curseLevel, durability)
{
	mEffect = effect;
}

void Consumable::Consume()
{
	std::cout << "You consummed " << mName << " and got following effects : " << std::endl;

	if (mEffect > 1 << 6) {
		std::cout << "Cold Protection" << std::endl;
		mEffect -= EffectType::ColdProtection;
	}
	if (mEffect > 1 << 5) {
		std::cout << "Fire Resistance" << std::endl;
		mEffect -= EffectType::FireResistance;
	}
	if (mEffect > 1 << 4) {
		std::cout << "Water Breathing" << std::endl;
		mEffect -= EffectType::WaterBreathing;
	}
	if (mEffect > 1 << 3) {
		std::cout << "Poison" << std::endl;
		mEffect -= EffectType::Poison;
	}
	if (mEffect > 1 << 2) {
		std::cout << "Defense" << std::endl;
		mEffect -= EffectType::Defense;
	}
	if (mEffect > 1 << 1) {
		std::cout << "Strength" << std::endl;
		mEffect -= EffectType::Strength;
	}
	if (mEffect > 1 << 0) {
		std::cout << "Speed" << std::endl;
		mEffect -= EffectType::Speed;
	}

	delete(this);
}

void Consumable::SetEffect(uint8_t effect)
{
	mEffect = effect;
}

uint8_t Consumable::GetEffect()
{
	return mEffect;
}

bool Consumable::HasEffect(uint8_t effect)
{
	if ((mEffect & effect) != 0)
	{
		return true;
	}
	return false;
}

void Consumable::AddEffect(uint32_t effect)
{
	mEffect += effect;
}

void Consumable::RemoveEffect(uint32_t effect)
{
	mEffect -= effect;
}
