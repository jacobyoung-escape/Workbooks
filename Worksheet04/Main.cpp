#include <iostream>
#include <format>
#include <string>

//Problem04
enum class DamageType { Physical = 0, Fire = 1, Ice = 2, Poison = 3 };
enum class ArmourType { None, Leather, Chain, Plate };

//Problem05
enum class Command { MoveNorth, MoveSouth, Attack, Wait, Quit };

void Problem01()
{
    int health{ 10 };
    int enemyCount{ 3 };

    if (health <= 0)
    {
        std::cout << "Status: dead\n";
    }
    else if (health < 25)
    {
        std::cout << "Status: critical\n";
    }
    else if (enemyCount > 2)
    {
        std::cout << "Status: outnumbered\n";
    }
    else
    {
        std::cout << "Status: ready\n";
    }
}

void Problem02()
{
    int mana{ 0 };
    int arrows{ 5 };
    bool hasStaff{ true };

    if (mana)
    {
        std::cout << "A: mana\n";
    }

    //arrows should be arrows > 0, it still works but should be written differently
    if (arrows)
    {
        std::cout << "B: arrows\n";
    }

    if (hasStaff == true)
    {
        std::cout << "C: staff\n";
    }

    //sets mana to 10, should be == instead of =
    if (mana = 10)
    {
        std::cout << "D: mana again\n";
    }

    std::cout << std::format("E: mana is {}\n", mana);

    //this if statement should have brackets around the whole thin otherwise G will print no matter what
    if (arrows > 3)
        std::cout << "F: plenty of arrows\n";
        std::cout << "G: ready\n";

    if (mana > 5 && arrows > 10)
    {
        std::cout << "H: fully equipped\n";
    }
    else if (mana > 5 || arrows > 10)
    {
        std::cout << "I: partly equipped\n";
    }
}

void Problem03()
{
    bool knowsSpell{ true };
    int mana{ 10 };
    int manaCost{ 5 };
    bool isSilenced{ false };
    
	if (!knowsSpell)
	{
		std::cout << "   You do not know that spell.\n";
	}
	else if (isSilenced)
	{
		std::cout << "   You cannot speak.\n";
	}
    else if (mana < manaCost)
	{
		std::cout << "   Not enough mana.\n";
	}
	else
	{
        std::cout << "   The spell goes off!\n";;
	}
}

//Problem04
int ApplyResistance(int damage, DamageType type, ArmourType armour)
{
    switch (armour)
    {
        case ArmourType::None:
            break;
            return damage;

        case ArmourType::Leather:
            if (type == DamageType::Poison)
                damage = damage / 2;
            else
                break;
            return damage;

        case ArmourType::Chain:
            if (type == DamageType::Physical)
                damage = damage / 2;
            else if (type == DamageType::Ice)
                damage = damage * 2;
            else
                break;
		    return damage;

        case ArmourType::Plate:
            if (type == DamageType::Physical)
                damage = damage / 2;
            else if (type == DamageType::Fire || type == DamageType::Ice)
                damage = damage * 2;
            else
                break;
		    return damage;


    }
	return damage;
}

void Problem04()
{
    std::cout << ApplyResistance(20, DamageType::Fire, ArmourType::Plate) << std::endl;
}

//Problem05
void HandleCommand(Command command)
{
    switch (command)
    {
    case Command::MoveNorth:
        std::cout << "   You move north.\n";
		break;  
   
    case Command::MoveSouth:
        std::cout << "   You move south.\n";
        break;

    case Command::Attack:
        std::cout << "   You attack!\n";
        break;

    case Command::Wait:
        std::cout << "   You wait.\n";
        break;

	case Command::Quit:
        std::cout << "   You quit!\n";
        break;
    }
}

void Problem05()
{
    HandleCommand(Command::MoveNorth);
    HandleCommand(Command::MoveSouth);
    HandleCommand(Command::Attack);
    HandleCommand(Command::Wait);
    HandleCommand(Command::Quit);
}


int main()
{
	//Problem01();
	//Problem02();
	//Problem03();
    //Problem04();
	//Problem05();
	return 0;
}