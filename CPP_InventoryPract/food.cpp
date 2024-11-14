#include "food.h"

Food::Food(uint8_t foodType, uint8_t effect, std::string name, std::string description, int cost, int manaConsumptionAmount, int curseLevel, int durability) : Consumable(effect, name, description, cost, manaConsumptionAmount, curseLevel, durability)
{
	mFoodType = foodType;
}

void Food::SetFoodType(uint8_t foodType)
{
	mFoodType = foodType;
}

uint8_t Food::GetFoodType()
{
	return mFoodType;
}

bool Food::HasFoodType(uint8_t foodType)
{
	if ((mFoodType & foodType) != 0)
	{
		return true;
	}
	return false;
}

void Food::AddFoodType(uint32_t foodType)
{
	mFoodType += foodType;
}

void Food::RemoveFoodType(uint32_t foodType)
{
	mFoodType -= foodType;
}

Item Food::Cook(std::vector<Item*> ingredients)
{
	uint8_t dishType = 0;
	uint8_t dishEffect = 0;

	for (int i = 0; i < ingredients.size(); i++)
	{
		Food* food = dynamic_cast<Food*>(ingredients[i]);

		dishType += food->mFoodType;
		dishEffect += food->mEffect;
	}

	std::string dishName;
	if (dishType & FoodType::Vegetables && dishType & FoodType::Mushroom && dishType & FoodType::Fish && dishType & FoodType::Meat && dishType & FoodType::Fruit)
	{
		dishName = "Sweat and salty land-sea forest soup";
	}
	else if (dishType & FoodType::Vegetables && dishType & FoodType::Mushroom && dishType & FoodType::Fish && dishType & FoodType::Meat)
	{
		dishName = "Salty land-sea forest soup";
	}
	else if (dishType & FoodType::Vegetables && dishType & FoodType::Mushroom && dishType & FoodType::Fish && dishType & FoodType::Fruit)
	{
		dishName = "Sweat and salty sea forest soup";
	}
	else if (dishType & FoodType::Vegetables && dishType & FoodType::Mushroom && dishType & FoodType::Fruit && dishType & FoodType::Meat)
	{
		dishName = "Sweat and salty land forest soup";
	}
	else if (dishType & FoodType::Vegetables && dishType & FoodType::Fruit && dishType & FoodType::Fish && dishType & FoodType::Meat)
	{
		dishName = "Sweat and salty land-sea soup";
	}
	else if (dishType & FoodType::Fruit && dishType & FoodType::Mushroom && dishType & FoodType::Fish && dishType & FoodType::Meat)
	{
		dishName = "Sweat land-sea forest soup";
	}
	else if (dishType & FoodType::Vegetables && dishType & FoodType::Mushroom && dishType & FoodType::Fruit)
	{
		dishName = "Sweat and salty vegetarian forest salad";
	}
	else if (dishType & FoodType::Vegetables && dishType & FoodType::Mushroom && !(dishType & FoodType::Fish) && !(dishType & FoodType::Meat))
	{
		dishName = "Vegetarian forest salad";
	}
	else if (dishType & FoodType::Fruit && dishType & FoodType::Mushroom && !(dishType & FoodType::Fish) && !(dishType & FoodType::Meat))
	{
		dishName = "Fruit mushroom skewer";
	}
	else if (dishType & FoodType::Vegetables && dishType & FoodType::Mushroom && !(dishType & FoodType::Fish) && !(dishType & FoodType::Meat))
	{
		dishName = "Vegetarian forest salad";
	}
	else if (dishType & FoodType::Fish && dishType & FoodType::Meat && !(dishType & FoodType::Vegetables) && !(dishType & FoodType::Mushroom) && !(dishType & FoodType::Fruit))
	{
		dishName = "Land-sea proteins";
	}
	else
	{
		dishName = "Classic dish";
	}

	bool isFirstEffect = true;
	std::string dishDescription = "";
	if (dishEffect & EffectType::Speed)
	{
		if (isFirstEffect)
		{
			dishDescription += "This dish gives you the following effects : ";
			isFirstEffect = false;
		}

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
			dishDescription += "This dish gives you the following effects : ";
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
			dishDescription += "This dish gives you the following effects : ";
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
			dishDescription += "This dish gives you the following effects : ";
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
			dishDescription += "This dish gives you the following effects : ";
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
			dishDescription += "This dish gives you the following effects : ";
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
			dishDescription += "This dish gives you the following effects : ";
			isFirstEffect = false;
		}

		dishDescription += "anti-cold";
	}

	Item* outputItem = new Dish(dishType, dishEffect, dishName, dishDescription, 30, 0, 0, 1);


	std::cout << std::endl;
	std::cout << "You cooked a dish :" << dishName << std::endl;
	std::cout << "Description : " << dishDescription << std::endl;
	std::cout << std::endl;

	return *outputItem;
}
