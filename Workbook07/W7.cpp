#include <iostream>
#include <format>

struct CarSetup
{
	int frontWing{ 0 };
	int rearWing{ 0 };
	int gearRatio{ 0 };
	int brakeBias{ 0 };
	int tyrePressure{ 0 };
	float rideHeight{ 0.0f };
};

int LapsRemaining(float fuel, float burnRate)
{ 
	return static_cast<int>(fuel / burnRate);
}
void BurnOneLap(float& fuel, float burnRate)
{ 
	fuel -= burnRate; 
}

void Problem01()
{
	float fuel{ 60.0f };
	float burnRate{ 2.4f };
	std::cout << std::format("laps: {}\n", LapsRemaining(fuel, burnRate));
	BurnOneLap(fuel, burnRate);
	std::cout << std::format("fuel now: {:.1f}\n", fuel);

}

//Problem03

int TotalDownForce(const CarSetup& setup)
{
	int final = setup.frontWing + setup.rearWing;
	return final;
}

void SoftenSuspension(CarSetup& setup, float amount)
{
	setup.rideHeight += amount;
}

float FuelForLaps(int laps, float burnRate)
{
	return laps * burnRate;
}

void ApplyPitStop(const CarSetup& setup, float& fuel, float fuelLevel, int pressureChange)
{
	fuel = fuelLevel;
	std::cout << std::format("tyre pressure change: {}\n", pressureChange);
}

void Problem03()
{
    CarSetup setup{ 12, 18, 4, 55, 22, 45.0f };
	float fuel{ 8.0f };

	std::cout << std::format("downforce: {}\n", TotalDownForce(setup));
	std::cout << std::format("fuel for 20 laps: {:.1f}\n", FuelForLaps(20, 2.4f));

	SoftenSuspension(setup, 5.0f);
	std::cout << std::format("ride height: {:.1f}\n", setup.rideHeight);

	ApplyPitStop(setup, fuel, 100.0f, 2);
	std::cout << std::format("fuel after stop: {:.1f}\n", fuel);
}

//Problem04
void Swap(int& first, int&	 second)
{
	int temporary{ first };
	first = second;
	second = temporary;
}

int& Fastest(int& lapA, int& lapB)
{
	if (lapA < lapB)
	{
		return lapA;
	}

	return lapB;
}

void Problem04()
{
	int driverOne{ 84 };
	int driverTwo{ 91 };

	Swap(driverOne, driverTwo);
	std::cout << std::format("after swap: {} {}\n", driverOne, driverTwo);

	int& best{ Fastest(driverOne, driverTwo) };
	std::cout << std::format("best lap: {}\n", best);
}

void Stretch()
{
	for (CarSetup& setup : { CarSetup{ 12, 18, 4, 55, 22, 45.0f },
		CarSetup{ 15, 22, 5, 52, 20, 40.0f } })
	{
		setup.frontWing += 1;
		std::cout << std::format("front wing: {}\n", setup.frontWing);
	}

	std::cout << std::format("sizeof(CarSetup) = {}\n", sizeof(CarSetup));
}

int ProblemStretch()
{
	Stretch();
	return 0;
}

int main()
{
	//Problem01();
	//Problem03();
	//Problem04();
	ProblemStretch();
	return 0;
}