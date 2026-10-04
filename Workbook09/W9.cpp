#include <iostream>
#include <format>
#include <string>

//Problem01
//struct Turret
//{
//	std::string name{};
//	int integrity{ 0 };
//};
//
//Turret* FindWeakest(Turret& left, Turret& right, int threshold)
//{
//	Turret* weakest{ right.integrity < left.integrity ? &right : &left };
//
//	if (weakest->integrity > threshold)
//	{
//		return nullptr;
//	}
//	return weakest;
//}
//
//void Problem01() 
//{
//	Turret turret1{ "Turret1", 100 };
//	Turret turret2{ "Turret2", 80 };
//	FindWeakest(turret1, turret2, 90);
//}

void Problem02()
{
    int shields{ 100 };
    int hull{ 80 };

    int* systemPointer{ &shields };

    *systemPointer -= 30;
    std::cout << std::format("A: shields {}, hull {}\n", shields, hull);

    systemPointer = &hull;
    *systemPointer -= 30;
    std::cout << std::format("B: shields {}, hull {}\n", shields, hull);

    int& shieldRef{ shields };
    shieldRef = hull;
    std::cout << std::format("C: shields {}, hull {}\n", shields, hull);

    systemPointer = &shields;
    int copy{ *systemPointer };
    copy = 5;
    std::cout << std::format("D: shields {}, copy {}\n", shields, copy);

    int* another{ systemPointer };
    *another = 1;
    std::cout << std::format("E: shields {}, *systemPointer {}\n", shields, *systemPointer);
}

//Problem05
bool ComputeDamage(int attack, int defence, int* outDamage, bool* outWasCritical)
{
    if (outDamage == nullptr)
    {
        return false;
    }

    int damage{ attack - defence };

    if (damage < 0)
    {
        damage = 0;
    }

    *outDamage = damage;

    if (outWasCritical != nullptr)
    {
        *outWasCritical = damage > 20;
    }

    return true;
}

struct DamageResult
{
    int damage{ 0 };
    bool wasCritical{ false };
};

DamageResult ComputeDamage(int attack, int defence)
{
	int damage{ attack - defence };
	if (damage < 0)
	{
		damage = 0;
	}
	return { damage, damage > 20 };
}

void Problem05()
{
	int damage{};
	bool wasCritical{};
	if (ComputeDamage(50, 30, &damage, &wasCritical))
	{
		std::cout << std::format("Damage: {}, Was Critical: {}\n", damage, wasCritical);
	}
	else
	{
		std::cout << "Failed to compute damage.\n";
	}
}

//stretch
struct Ship
{
    std::string name{};
    int hull{ 0 };
};

class Turret
{
public:
    void Track(Ship* ship)
    {
        target = ship;
    }

    void Fire()
    {
        if (target != nullptr)
        {
            target->hull -= 10;
            std::cout << std::format("   hit {} — hull now {}\n", target->name, target->hull);
        }
        else
        {
            std::cout << "   no target\n";
        }
    }

private:
    Ship* target{ nullptr };
};

void Stretch()
{
    Turret turret;

    {
        Ship freighter{ "Mule", 60 };

        turret.Track(&freighter);
        turret.Fire();
    }

    turret.Fire();
}

int main()
{
	//Problem01();
    //Problem02();
    //Problem05();
	//Stretch();
	return 0;
}