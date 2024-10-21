#include "item.h"
#include "itemType.h"

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

void Item::AddType(std::uint32_t type)
{
	mType |= type;
}

void Item::RemoveType(std::uint32_t type)
{
	mType ^= type;
}

void Item::ConsumeMana()
{
	if (mType & CreaType::Magic) {
		printf("%i mana consumed", mManaConsumptionAmount);
	}
}

void Item::CursedEffect()
{
	if (mType & CreaType::Cursed) {
		printf("%i damages because of curse effect", mCurseLevel * 10);
	}
}

bool Item::UseDurability()
{
	if (mType & CreaType::Breackable) {
		mDurability--;
		printf("durability used : durability is now %i", mDurability);

		if (mDurability == 0) {
			printf("the item is broken");
			return false;
		}
	}
	return true;
}
