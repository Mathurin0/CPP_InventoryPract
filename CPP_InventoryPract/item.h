#pragma once
#include <string>

class Item
{
public :
	Item(std::string name, std::string description, int cost, uint8_t type, int manaConsumptionAmount, int curseLevel, int durability);
	~Item();

	void SetType(std::uint8_t type);
	uint8_t GetType();
	void AddType(std::uint32_t type);
	void RemoveType(std::uint32_t type);

	void ConsumeMana();
	void CursedEffect();
	bool UseDurability();

private :
	std::string mName;
	std::string mDescription;
	int mCost;
	uint8_t mType;
	int mManaConsumptionAmount;
	int mCurseLevel;
	int mDurability;
};
