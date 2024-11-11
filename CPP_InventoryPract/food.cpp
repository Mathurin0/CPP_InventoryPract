#include "food.h"

Food::Food(uint8_t foodType, uint8_t effect, std::string name, std::string description, int cost, uint8_t type, int manaConsumptionAmount, int curseLevel, int durability) : Consumable(effect, name, description, cost, type, manaConsumptionAmount, curseLevel, durability)
{
	mFoodType = foodType;
}

void Food::SetEffect(uint8_t foodType)
{
	mFoodType = foodType;
}

uint8_t Food::GetEffect()
{
	return mFoodType;
}

bool Food::HasEffect(uint8_t foodType)
{
	if ((mFoodType & foodType) != 0)
	{
		return true;
	}
	return false;
}

void Food::AddEffect(uint32_t foodType)
{
	mFoodType += foodType;
}

void Food::RemoveEffect(uint32_t foodType)
{
	mFoodType -= foodType;
}

Item Food::Cook(std::vector<Item> ingredients)
{
	uint8_t dishType = 0;
	uint8_t dishEffect = 0;

	for (int i = 0; i < ingredients.size(); i++)
	{
		Food* food = dynamic_cast<Food*>(&ingredients[i]);

		dishType += food->mFoodType;
		dishEffect += food->mEffect;
	}

	std::string dishName;
	if (dishType & FoodType::Vegetables && dishType & FoodType::Mushroom && dishType & FoodType::Fish && dishType & FoodType::Meat && dishType & FoodType::Fruit)
	{
		dishName = "sweat and salty land-sea forest soup";
	}
	else if (dishType & FoodType::Vegetables && dishType & FoodType::Mushroom && dishType & FoodType::Fish && dishType & FoodType::Meat)
	{
		dishName = "salty land-sea forest soup";
	}
	else if (dishType & FoodType::Vegetables && dishType & FoodType::Mushroom && dishType & FoodType::Fish && dishType & FoodType::Fruit)
	{
		dishName = "sweat and salty sea forest soup";
	}
	else if (dishType & FoodType::Vegetables && dishType & FoodType::Mushroom && dishType & FoodType::Fruit && dishType & FoodType::Meat)
	{
		dishName = "sweat and salty land forest soup";
	}
	else if (dishType & FoodType::Vegetables && dishType & FoodType::Fruit && dishType & FoodType::Fish && dishType & FoodType::Meat)
	{
		dishName = "sweat and salty land-sea soup";
	}
	else if (dishType & FoodType::Fruit && dishType & FoodType::Mushroom && dishType & FoodType::Fish && dishType & FoodType::Meat)
	{
		dishName = "sweatland-sea forest soup";
	}
	else if (dishType & FoodType::Vegetables && dishType & FoodType::Mushroom && dishType & FoodType::Fruit)
	{
		dishName = "sweat and salty vegetarian forest salad";
	}
	else if (dishType & FoodType::Vegetables && dishType & FoodType::Mushroom && !(dishType & FoodType::Fish) && !(dishType & FoodType::Meat))
	{
		dishName = "vegetarian forest salad";
	}
	else if (dishType & FoodType::Fruit && dishType & FoodType::Mushroom && !(dishType & FoodType::Fish) && !(dishType & FoodType::Meat))
	{
		dishName = "fruit mushroom skewer";
	}
	else if (dishType & FoodType::Vegetables && dishType & FoodType::Mushroom && !(dishType & FoodType::Fish) && !(dishType & FoodType::Meat))
	{
		dishName = "vegetarian forest salad";
	}
	else if (dishType & FoodType::Fish && dishType & FoodType::Meat && !(dishType & FoodType::Vegetables) && !(dishType & FoodType::Mushroom) && !(dishType & FoodType::Fruit))
	{
		dishName = "land-sea proteins";
	}
	else
	{
		dishName = "classic dish";
	}

	bool isFirstEffect = true;
	std::string dishDescription = "";
	if (dishEffect & EffectType::Speed)
	{
		if (isFirstEffect)
			isFirstEffect = false;

		dishDescription += "tempo";
	}
	if (dishEffect & EffectType::Strength)
	{
		if (!isFirstEffect)
		{
			dishDescription += ", ";
		}
		else
		{
			isFirstEffect = false;
		}

		dishDescription += "robusto";
	}
	if (dishEffect & EffectType::Defense)
	{
		if (!isFirstEffect)
		{
			dishDescription += ", ";
		}
		else
		{
			isFirstEffect = false;
		}

		dishDescription += "protecto";
	}
	if (dishEffect & EffectType::Poison)
	{
		if (!isFirstEffect)
		{
			dishDescription += ", ";
		}
		else
		{
			isFirstEffect = false;
		}

		dishDescription += "poisonous";
	}
	if (dishEffect & EffectType::WaterBreathing)
	{
		if (!isFirstEffect)
		{
			dishDescription += ", ";
		}
		else
		{
			isFirstEffect = false;
		}

		dishDescription += "water-breathing";
	}
	if (dishEffect & EffectType::FireResistance)
	{
		if (!isFirstEffect)
		{
			dishDescription += ", ";
		}
		else
		{
			isFirstEffect = false;
		}

		dishDescription += "demon-skinned";
	}
	if (dishEffect & EffectType::ColdProtection)
	{
		if (!isFirstEffect)
		{
			dishDescription += ", ";
		}
		else
		{
			isFirstEffect = false;
		}

		dishDescription += "anti-cold";
	}

	Item* outputItem = new Dish(dishType, dishEffect, dishName, dishDescription, 30, ItemType::Consumable, 0, 0, 1);

	std::cout << "Name : " << dishName << std::endl;
	std::cout << "Description : " << dishDescription << std::endl;

	return *outputItem;
}
