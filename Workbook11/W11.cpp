#include <iostream>
#include <format>
#include <string>
#include <vector>
#include <cassert>

//Problem01
std::vector<int> WithPenalty(const std::vector<int>& laps, int penalty)
{
    std::vector<int> result;
    for (int lap : laps)
    {
       result.push_back(lap + penalty);
    }
    return result;
}

void Problem01()
{
    for (const int& lap : WithPenalty({ 91, 88, 94, 87, 90 }, 5))
	{
		std::cout << std::format("{} ", lap);
	}
}

void Problem02()
{

}

void Problem03()
{

}

void Problem04()
{

}

void Problem05()
{

}

void Stretch()
{

}

int main()
{
    //Problem01();
    //Problem02();
    //Problem03();
    //Problem04();
    //Problem05();
    //Stretch();
}