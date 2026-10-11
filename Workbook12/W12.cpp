#include <iostream>
#include <format>
#include <string>
#include <vector>
#include <random>
#include <cstdlib>
#include <ctime>

//Problem01
int RollDice(std::mt19937& engine, int count)
{
    std::uniform_int_distribution<int> die{ 1, 6 };
    int total{ 0 };

    for (int i{ 0 }; i < count; ++i)
    {
	    total += die(engine);
    }

    return total;
}

void Problem01()
{
    std::mt19937 engine{ 2024 };
    std::cout << std::format("Total: {} {}\n", RollDice(engine, 3), RollDice(engine, 3));
}

void Problem02()
{
    std::mt19937 a{ 100 };
    std::mt19937 b{ 100 };
    std::mt19937 c{ 101 };
    std::cout << std::format("A: {} {} {}\n", a(), b(), c());
    std::mt19937 d{ 100 };
    d();
    d();
    std::mt19937 e{ 100 };
    std::cout << std::format("B: {} {}\n", d(), e());
    std::mt19937 f{ 55 };
    std::mt19937 g{ f }; // a copy
    std::cout << std::format("C: {} {}\n", f(), g());
    std::mt19937 h{ 55 };
    std::uniform_int_distribution<int> small{ 1, 6 };
    std::uniform_int_distribution<int> big{ 1, 1000 };
    std::cout << std::format("D: {} {}\n", small(h), small(h));
    std::mt19937 i{ 55 };
    std::cout << std::format("E: {} {}\n", big(i), small(i));
}

//Problem03
std::string RollLoot(std::mt19937& engine)
{
    std::uniform_int_distribution<int> roll{ 1, 100 };
    const int value{ roll(engine) };
    if (value <= 60)
    {
        return "copper coin";
    }
    if (value <= 90)
    {
        return "silver ring";
    }
    return "gold idol";
}
int RollDamage(std::mt19937& engine)
{
        std::uniform_int_distribution<int> die{ 1, 8 };
    return die(engine) + die(engine);
}
void Problem03()
{
    std::mt19937 engine{ std::random_device{}() };

    for (int i{ 0 }; i < 8; ++i)
    {
        const std::string loot{ RollLoot(engine) };
		const int damage{ RollDamage(engine) };

        std::cout << std::format(" {} ({} damage)\n", loot, damage);
    }
}

//Problem05
void SpawnWave(std::mt19937& engine, int waveNumber)
{
    std::uniform_int_distribution<int> enemyCountRan{ 3, 7 };
    std::uniform_int_distribution<int> xRan{ 0, 79 };
    std::uniform_int_distribution<int> yRan{ 0, 49 };
    std::uniform_int_distribution<int> healthRan{ 10, 29 };

	const int enemyCount{ enemyCountRan(engine) };

    for (int i{ 0 }; i < enemyCount; ++i)
    {
        int x = xRan(engine);
        int y = yRan(engine);
        int health = healthRan(engine);
        std::cout << std::format("enemy at {},{} hp {}\n", x, y, health);
    }
}
void Problem05()
{
    const unsigned int seed{ 2026 };
    std::cout << std::format("seed {}\n", seed);

    std::mt19937 engine{ seed };

    SpawnWave(engine, 1);
    SpawnWave(engine, 2);
    SpawnWave(engine, 3);

}


int main()
{
    //Problem01();
    //Problem02();
    //Problem03();
    Problem05();
}