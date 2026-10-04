#include <iostream>
#include <format>
#include <limits>
#include <cstdint>

void Problem05()
{
	
	int currentShields{ 73 };
	int maximumShields{ 120 };

	float fraction = static_cast<float>(currentShields) / maximumShields;
	float percentage = fraction * 100.0f;
	std::cout << std::format("Shields at {:.1f}%\n", percentage);
}

int main()
{
	Problem05();
	return 0;
}