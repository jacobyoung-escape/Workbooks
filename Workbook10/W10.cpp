#include <iostream>                        
#include <format>

//Problem03
int WaveScore(int waveNumber)
{
    int enemies{ 3 + waveNumber };
    int multiplier{ 1 + waveNumber / 4 };

    return enemies * 10 * multiplier;
}

void PartA()
{
    int total{ 0 };

    for (int wave{ 1 }; wave <= 30; ++wave)
    {
        total += WaveScore(wave);
    }

    std::cout << std::format("total {}\n", total);
}

int main()
{
    PartA();
	return 0;
}