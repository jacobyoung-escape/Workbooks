#include <iostream>
#include <format>
#include <cmath>
#include <limits>

constexpr int WeaponCount{ 4 };
int currentWeapon{ 0 };
int previousWeapon;
int nextWeapon;

void Problem04()
{
	previousWeapon = (currentWeapon - 1) % WeaponCount;
	nextWeapon = (currentWeapon + 1) % WeaponCount;
	std::cout << std::format("previous Weapon: {}\n", previousWeapon);
	std::cout << std::format("Next Weapon: {}\n", nextWeapon);
}

int main()
{
	Problem04();
	return 0;
}