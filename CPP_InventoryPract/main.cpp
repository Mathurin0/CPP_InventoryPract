#include <iostream>
#include "inventory.h"
#include "food.h"
#include "armor.h"
#include "tool.h"
#include "weapon.h"

int main()
{
	Inventory* inventory = new Inventory();

	Food apple = Food(FoodType::Fruit, EffectType::Speed, "Apple", "A beautifull apple", 10, 0, 0, 1);
	Food beefSteak = Food(FoodType::Meat, EffectType::Strength, "Beef Steak", "A 200g beef steak", 20, 0, 0, 1);
	Food salmon = Food(FoodType::Fish, EffectType::FireResistance, "Salmon", "A very tasty salmon", 30, 0, 0, 1);
	Food carrot = Food(FoodType::Vegetables, EffectType::Poison, "Carrot", "A simple carrot", 5, 0, 0, 1);
	Food chanterelle = Food(FoodType::Mushroom, EffectType::Defense, "Chanterelle", "A delicious mushroom", 15, 0, 0, 1);
	Armor ironChestplate = Armor(15, "Iron Chestplate", "A solid iron chestplate", 50, 0, 0, 1);
	Armor goldChestplate = Armor(30, "Gold Chestplate", "A shiny gold chestplate", 100, 0, 0, 1);
	Armor diamondChestplate = Armor(60, "Diamond Chestplate", "A solid diamond chestplate", 200, 0, 0, 1);
	Tool ironPickaxe = Tool(15, "Iron Pickaxe", "A simple iron pickaxe", 25, 0, 0, 1);
	Tool goldPickaxe = Tool(30, "Gold Pickaxe", "A shiny gold pickaxe", 50, 0, 0, 1);
	Tool diamondPickaxe = Tool(60, "Diamond Pickaxe", "A solid diamond pickaxe", 100, 0, 0, 1);
	Weapon ironSword = Weapon(15, "Iron Sword", "A simple iron pickaxe", 20, 0, 0, 1);
	Weapon goldSword= Weapon(30, "Gold Sword", "A shiny gold pickaxe", 40, 0, 0, 1);
	Weapon diamondSword = Weapon(60, "Diamond Sword", "A solid diamond pickaxe", 80, 0, 0, 1);


	// flammable interface
	std::cout << "FLAMMABLE INTERFACE :" << std::endl;
	ironChestplate.Burn();
	ironChestplate.SpreadFire(&ironPickaxe);
	std::cout << std::endl;

	// Inventory Operators / remove item from inventory regardless of position
	std::cout << "INVENTORY OPERATORS :" << std::endl;
	*inventory += apple;
	*inventory += beefSteak;
	*inventory += salmon;
	*inventory += carrot;
	*inventory += chanterelle;
	*inventory -= carrot;
	std::cout << std::endl;

	// Tag Operators
	std::cout << "TAG OPERATORS :" << std::endl;
	uint8_t tag = ItemType::Armor;
	tag += ItemType::Breackable;
	tag -= ItemType::Armor;
	tag = tag + ItemType::Weapon;
	tag = tag - ItemType::Breackable;

	// HasTag function
	std::cout << "HAS TAG FUNCTION :" << std::endl;
	ironChestplate.AddType(ItemType::Magic);
	bool hasTypeMagic = ironChestplate.HasType(ItemType::Magic);
	bool hasTypeCursed = ironChestplate.HasType(ItemType::Cursed);
	if (hasTypeMagic)
		std::cout << ironChestplate.GetName() << " has type 'Magic'" << std::endl;
	else
		std::cout << ironChestplate.GetName() << " don't have type 'Magic'" << std::endl;

	if (hasTypeCursed)
		std::cout << ironChestplate.GetName() << " has type 'Cursed'" << std::endl;
	else
		std::cout << ironChestplate.GetName() << " don't have type 'Cursed'" << std::endl;
	std::cout << std::endl;

	// Cooking system
	std::cout << "COOCKING SYSTEM :" << std::endl;
	inventory->AddToPot(&apple);
	inventory->AddToPot(&beefSteak);
	inventory->AddToPot(&salmon);
	inventory->AddToPot(&chanterelle);

	Item fistDish = apple.Cook(inventory->GetPotContent());
	inventory->ClearPotContent();

	*inventory += apple;
	*inventory += carrot;
	*inventory += chanterelle;

	inventory->AddToPot(&apple);
	inventory->AddToPot(&carrot);
	inventory->AddToPot(&chanterelle);

	Item secondDish = apple.Cook(inventory->GetPotContent());
	inventory->ClearPotContent();

	// Sort items
	std::cout << "SORT ITEMS :" << std::endl;
	*inventory += goldSword;
	*inventory += ironChestplate;
	*inventory += diamondSword;
	*inventory += ironPickaxe;
	*inventory += salmon;
	*inventory += goldChestplate;
	*inventory += diamondPickaxe;
	*inventory += apple;
	*inventory += chanterelle;
	*inventory += ironSword;
	*inventory += diamondChestplate;
	*inventory += beefSteak;
	*inventory += goldPickaxe;
	*inventory += carrot;
	inventory->PrintInventory();
	std::cout << std::endl;

	*inventory -= goldSword;
	*inventory -= ironChestplate;
	*inventory -= diamondSword;
	*inventory -= ironPickaxe;
	inventory->PrintInventory();
	std::cout << std::endl;

	*inventory -= salmon;
	*inventory -= goldChestplate;
	*inventory -= diamondPickaxe;
	*inventory -= apple;
	*inventory -= chanterelle;
	inventory->PrintInventory();
	std::cout << std::endl;

	*inventory -= ironSword;
	*inventory -= diamondChestplate;
	*inventory -= beefSteak;
	*inventory -= goldPickaxe;
	*inventory -= carrot;
	inventory->PrintInventory();
}
