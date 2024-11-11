#pragma once
#include <string>
#include "IFlammable.h"

class Item : IFlammable
{
public :
	Item(std::string name, std::string description, int cost, uint8_t type, int manaConsumptionAmount, int curseLevel, int durability);
	~Item();

	std::string GetName();
	void SetType(uint8_t type);
	uint8_t GetType();
	bool HasType(uint8_t type);
	void AddType(uint32_t type);
	void RemoveType(uint32_t type);

	void ConsumeMana();
	void CursedEffect();
	bool UseDurability();

	void IFlammable::SpreadFire(Item item) override;

	bool operator ==(Item b) {
		if (mName == b.mName &&
			mDescription == b.mDescription &&
			mCost == b.mCost &&
			mType == b.mType &&
			mManaConsumptionAmount == b.mManaConsumptionAmount &&
			mCurseLevel == b.mCurseLevel &&
			mDurability == b.mDurability) {
			return true;
		}
		else {
			return false;
		}
	}

protected :
	std::string mName;
	std::string mDescription;
	int mCost;
	uint8_t mType;
	int mManaConsumptionAmount;
	int mCurseLevel;
	int mDurability;
	int mIsBurning = false;
};
