#include "item.h"
#include "itemType.h"
#include<iostream>

Item::Item(std::string name, std::string description, int cost, uint8_t type, int manaConsumptionAmount, int curseLevel, int durability)
{
	mName = name;
	mDescription = description;
	mCost = cost;
	mType = type;
	mManaConsumptionAmount = manaConsumptionAmount;
	mCurseLevel = curseLevel;
	mDurability = durability;
}

Item::~Item()
{

}

void Item::SetType(std::uint8_t type)
{
	mType = type;
}

uint8_t Item::GetType()
{
	return mType;
}

bool Item::HasType(std::uint8_t type)
{
	if ((mType & type) != 0)
	{
		return true;
	}
	return false;
}

std::string Item::GetName()
{
	return mName;
}

void Item::AddType(std::uint32_t type)
{
	mType += type;
}

void Item::RemoveType(std::uint32_t type)
{
	mType -= type;
}

void Item::ConsumeMana()
{
	if (mType & ItemType::Magic) {
		printf("%i mana consumed", mManaConsumptionAmount);
	}
}

void Item::CursedEffect()
{
	if (mType & ItemType::Cursed) {
		printf("%i damages because of curse effect", mCurseLevel * 10);
	}
}

bool Item::UseDurability()
{
	if (mType & ItemType::Breackable) {
		mDurability--;
		printf("durability used : durability is now %i", mDurability);

		if (mDurability == 0) {
			printf("the item is broken");
			return false;
		}
	}
	return true;
}

void Item::SpreadFire(Item item)
{
	item.mIsBurning = true;
	std::cout << "Spread fire to " << item.mName << std::endl;
}
