#include <iostream>
#include <format>
#include <limits>
#include <cstdint>

void problem03()
{
	char pilotCallsign = 'K';
	int torpedoesRemaining = 6;
	double fuelRemaining = 0.6237;
	bool autopilotEngaged = false;
	long long shipMass = 4200000000;

	std::cout << std::format(" |   Callsign |         {} | \n |  Torpedoes |         {} | \n |       Fuel |     {:.2f} | \n |  Autopilot |     {} | \n |       Mass |  {} | ", pilotCallsign, torpedoesRemaining, fuelRemaining * 100, autopilotEngaged, shipMass);
}

int main()
{
	problem03();
	return 0;
}