#include <iostream>
#include <format>
#include <cmath>
#include <limits>

void Problem03()
{
	unsigned int stock{ 3u };
	unsigned int purchased{ 5u };
	int remaining = stock - purchased;
	std::cout << std::format("Stock: {}\n", stock);
	std::cout << std::format("Purchased: {}\n", purchased);
	std::cout << std::format("Remaining: {}\n", remaining);
	std::cout << "Is stock less than purchased? " << (stock < purchased) << "\n";

}

int main()
{
	Problem03();
	return 0;
}