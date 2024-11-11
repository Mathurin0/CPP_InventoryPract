#include <iostream>
#include "inventory.h"
#include "food.h"

int main()
{
	Inventory* inventory = new Inventory();

	Item apple = Food(FoodType::Fruit, EffectType::Speed, "Apple", "A beautifull apple", 10, ItemType::Consumable, 0, 0, 1);
	Item beefSteak = Food(FoodType::Meat, EffectType::Strength, "Beef Steak", "A 200g beef steak", 20, ItemType::Consumable, 0, 0, 1);
	Item salmon = Food(FoodType::Fish, EffectType::FireResistance, "Salmon", "A very tasty salmon", 30, ItemType::Consumable, 0, 0, 1);
	Item carrot = Food(FoodType::Vegetables, EffectType::Poison, "Carrot", "A simple carrot", 5, ItemType::Consumable, 0, 0, 1);
	Item chanterelle = Food(FoodType::Mushroom, EffectType::Defense, "Chanterelle", "A delicious mushroom", 15, ItemType::Consumable, 0, 0, 1);

	*inventory += apple;
	*inventory += beefSteak;
	*inventory += salmon;
	*inventory += carrot;
	*inventory += chanterelle;

	Food* applePointer = dynamic_cast<Food*>(&apple);

	Item dish = applePointer->Cook(inventory->GetContent());
}
