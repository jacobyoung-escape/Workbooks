#include <iostream>
#include <format>
#include <limits>
#include <cstdint>

void Problem04()
{
	std::cout << std::format("bool {}, max {}\n",
		sizeof(bool), std::numeric_limits<bool>::max());
	std::cout << std::format("char {}, max {}\n",
		sizeof(char), static_cast<int>(std::numeric_limits<char>::max()));
	std::cout << std::format("short {}, max {}\n",
		sizeof(short), std::numeric_limits<short>::max());
	std::cout << std::format("int {}, max {}\n",
		sizeof(int), std::numeric_limits<int>::max());
	std::cout << std::format("long long {}, max {}\n",
		sizeof(long long), std::numeric_limits<long long>::max());
	std::cout << std::format("float {}, max {}\n",
		sizeof(float), std::numeric_limits<float>::max());
	std::cout << std::format("uint8_t {}, max {}\n",
		sizeof(std::uint8_t), std::numeric_limits<std::uint8_t>::max());
	std::cout << std::format("int32_t {}, max {}\n",
		sizeof(std::int32_t), std::numeric_limits<std::int32_t>::max());
}

int main()
{
	Problem04();
	return 0;
}