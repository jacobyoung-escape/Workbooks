#include <iostream>
#include <format>
#include <cmath>
#include <limits>

void Problem05()
{
	int health{ 30 };
	int maxHealth{ 100 };
	bool hasPotion{ true };
	bool isPoisoned{ false };
	bool inCombat{ true };
	// 1. Intended: "is health below a quarter of maximum?"
	bool isCritical = health < (maxHealth / 4);
	// 2. Intended: "print whether health is below 50"
	std::cout << "Low health: " << (health < 50) << "\n";
	// 3. Intended: "has a potion, and is either poisoned or in combat"
	bool shouldDrink = hasPotion && (isPoisoned || inCombat);
	// 4. Intended: "health as a percentage"
	float percentage = static_cast<float>(health) / maxHealth * 100.0f;
	// 5. Intended: "not poisoned, and in combat"
	bool fightingClean = (!isPoisoned && inCombat);
}

int main()
{
	Problem05();
	return 0;
}