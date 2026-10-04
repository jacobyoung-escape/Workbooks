#include <iostream>
#include <format>
#include <cmath>
#include <limits>

constexpr int MaximumArmour{ 50 };
int currentArmour{ 40 };
int rawDamage{ 7 };

void Problem01()
{ 
	float reduction = static_cast<float>(currentArmour) / MaximumArmour;
	std::cout << std::format("Reduction: {:.2f}\n", reduction);
	float finalDamage = rawDamage * (1.0f - reduction);
	std::cout << std::format("Damage taken: {:.2f}\n", finalDamage);

}
int main()
{
	Problem01();
	return 0;
}