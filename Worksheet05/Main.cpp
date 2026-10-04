#include <iostream>
#include <format>

void Problem01()
{
	int i = 3;
	for (int i = 3; i > 0; --i)
	{
	std::cout << std::format("{}...\n", i);
	}
	std::cout << "Liftoff!\n";
}

void Problem02()
{
    for (int i = 0; i < 4; ++i)
    {
        std::cout << std::format("A{} ", i);
    }
    std::cout << "\n";

    int j{ 0 };
    do
    {
        std::cout << std::format("B{} ", j);
        ++j;
    } while (j < 0);
    std::cout << "\n";

    int k{ 0 };
    while (k < 0)
    {
        std::cout << std::format("C{} ", k);
        ++k;
    }
    std::cout << "\n";

    for (int m = 0; m < 6; ++m)
    {
        if (m == 2)
        {
            continue;
        }

        if (m == 4)
        {
            break;
        }

        std::cout << std::format("D{} ", m);
    }
    std::cout << "\n";

    for (int p = 0; p < 3; ++p)
    {
        for (int q = 0; q < 2; ++q)
        {
            std::cout << std::format("E{}{} ", p, q);
        }
    }
    std::cout << "\n";
}

//Problem03
void Broken1()
{
    for (int i = 1; i <= 5; ++i)
    {
        std::cout << std::format("{} ", i);
    }
    std::cout << "\n";
}

void Broken2()
{
    for (int i = 1; i <= 5; ++i)
    {
        std::cout << std::format("{} ", i);
    }
    std::cout << "\n";
}

void Broken3()
{
    int i{ 0 };
    while (i <= 4)
    {
        std::cout << std::format("{} ", ++i);
    }
    std::cout << "\n";
}

void Broken4()
{
    for (int i = 1; i <= 5; ++i)
    {
        std::cout << std::format("{} ", i);
    }
    std::cout << "\n";
}

void Problem03()
{ 
	Broken1(); 
	Broken2();
	Broken3();
    Broken4();
}

//Problem04
constexpr int RoomWidth{ 12 };
constexpr int RoomHeight{ 6 };
int doorIndex{ 0 };

void Problem04()
{
	for (int y = 0; y < RoomHeight; y++)
	{
		std::cout << '\n';
		for (int x = 0; x < RoomWidth; x++)
		{
			if (x == 0 || x == RoomWidth - 1 || y == 0 || y == RoomHeight - 1)
			{
				std::cout << '#';
			}
			else
			{
				std::cout << '.';
			}
		}
	}

	std::cout << '\n';

	for (int y = 0; y < RoomHeight; y++)
	{
		std::cout << '\n';
		for (int x = 0; x < RoomWidth; x++)
		{
			if (x == 0 && y == RoomHeight / 2)
			{
				std::cout << '+';
			}
			else if (x == 0 || x == RoomWidth - 1 || y == 0 || y == RoomHeight - 1)
			{
				std::cout << '#';
			}
			else
			{
				std::cout << '.';
			}
		}
	}

	std::cout << '\n';

	for (int y = 0; y < RoomHeight; y++)
	{
		std::cout << '\n';
		for (int x = 0; x < RoomWidth; x++)
		{
			if (x == 0 && y == RoomHeight / 2)
			{
				std::cout << '+';
				doorIndex = y * RoomWidth + x;
			}
			else if (y == 0)
			{
				std::cout << std::format("{}", y * RoomWidth + x);
			}
			else if (x == 0 || x == RoomWidth - 1 || y == 0 || y == RoomHeight - 1)
			{
				std::cout << '#';
			}
			else
			{
				std::cout << '.';
			}
		}
	}
	std::cout << "\n" << doorIndex;
}

int main()
{ 
	//Problem01();
    //Problem02();
    //Problem03();
	Problem04();   
	return 0;
}