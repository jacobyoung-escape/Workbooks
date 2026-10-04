#include <iostream>
#include <format>

//Problem01
int TotalDamage(int hits, int perHit);
void PrintReport(int total);

int TotalDamage(int hits, int perHit)
{ 
    return hits * perHit; 
}

void PrintReport(int total) 
{ 
    std::cout << std::format("Total: {}\n", total);
}

//Problem02
void Mystery()
{
    int counter{ 0 };
    static int tally{ 0 };

    ++counter;
    ++tally;

    std::cout << std::format("counter {}, tally {}\n", counter, tally);
}

void Problem02()
{
    int value{ 5 };
    std::cout << std::format("A: {}\n", value);

    {
        int value{ 50 };
        std::cout << std::format("B: {}\n", value);
        value += 5;
        std::cout << std::format("C: {}\n", value);
    }

    std::cout << std::format("D: {}\n", value);

    Mystery();
    Mystery();
    Mystery();
}

//Problem03
int DrinkPotion(int health)
{
    health += 25;
    std::cout << std::format("   You feel better. Health is now {}\n", health);
    return health;
}

void Problem03()
{
    int playerHealth{ 40 };

    std::cout << std::format("Health: {}\n", playerHealth);
    playerHealth = DrinkPotion(playerHealth);
    std::cout << std::format("Health: {}\n", playerHealth);
}

int PercentageOf(int part, int whole)
{
	return (part * 100) / whole;
}

void PrintStat(const char* label, int value)
{
    std::cout << std::format("{:>11}: {:>5}\n", label, value);
}

void PrintStat(const char* label, float value)
{
    std::cout << std::format("{:>11}: {:>5.1f}\n", label, value);
}

void PrintSeperator(int width, char symbol = '-')
{
    std::cout << std::format("{:-<20}\n", symbol);
}

void Problem04()
{
    int health{ 40 };
    int maxHealth{ 60 };

    PrintSeperator(20, '-');
	PercentageOf(health, maxHealth);
	PrintStat("Health", health);
	PrintStat("Max Health", maxHealth);
	PrintStat("Percent", PercentageOf(health, maxHealth));
	PrintSeperator(20, '-');
}

int main()
{
    //Problem01();
    //int hitCount{ 3 };
    //int damagePerHit{ 7 };
    //int total = TotalDamage(hitCount, damagePerHit);
    //PrintReport(total);
    //Problem02();
	//Problem03();
    Problem04();
	return 0;
}