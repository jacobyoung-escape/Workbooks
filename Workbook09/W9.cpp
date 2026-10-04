#include <iostream>
#include <format>
#include <string>

//Problem01
struct Turret
{
	std::string name{};
	int integrity{ 0 };
};

Turret* FindWeakest(Turret& left, Turret& right, int threshold)
{
	Turret* weakest{ right.integrity < left.integrity ? &right : &left };

	if (weakest->integrity > threshold)
	{
		return nullptr;
	}
	return weakest;
}

void Problem01() 
{
	Turret turret1{ "Turret1", 100 };
	Turret turret2{ "Turret2", 80 };
	FindWeakest(turret1, turret2, 90);
}

int main()
{
	Problem01();	
	return 0;
}