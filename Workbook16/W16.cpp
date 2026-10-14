#include <iostream> // std::cout
#include <format> // std::format
#include <string> // std::string
#include <string_view> // std::string_view
#include <vector> // std::vector

//Problem01
class Noisy
{
public:
	Noisy(std::string_view label) : label(label)
	{
		std::cout << std::format(" + member {}\n", this->label);
	}
	~Noisy()
	{
		std::cout << std::format(" - member {}\n", label);
	}

private:
	std::string label;
};

class Base
{
public:
	Base() : baseMember("base's")
	{
		std::cout << " + Base body\n";
	}
		~Base()
	{
		std::cout << " - Base body\n";
	}

private:
	Noisy baseMember;
};

class Derived : public Base
{
public:
	Derived() : derivedMember("derived's"), derivedProblem("problem")
	{
		std::cout << " + Derived body\n";
	}
	~Derived()
	{
		std::cout << " - Derived body\n";
	}
private:
	Noisy derivedProblem;
	Noisy derivedMember;
};

void Demo02_Order()
{
	std::cout << "=== Demonstration 2: Order ===\n\n";
	{
		Derived thing;
	}
	std::cout << "\n";
}

//+ member base's, + Base body, + member problem, + member derived's, + Derived body, - Derived body, - member derived's, - member problem, - Base body, - member base's
//That is the only order that could be safe bacause the destructor has to destroy the parts that may depend on other parts first so that iot doesn't cause problems if the thing it depends on is destroyed first.

//Problem02
class Ability
{
//All ability declarations need virtual
public:
	virtual ~Ability() = default; //virtual
	virtual int Cost() const { return 0; }
	virtual void Describe() const { std::cout << "an ability\n"; } //virtual
};
class Fireball : public Ability
{
//All fireball declarations needed const to stop them from being changed
public:
	int Cost() const { return 12; } //const
	void Describe() const { std::cout << "a fireball\n"; }
};

//None of them produce a compiler message
//~ability not being virtual would still be a bug if Ability& wasn't used and only fireball by it's own name was in every class because even if ability isn't called delting ability would still need to function without the caller asking for it

//Problem03
//1. neither, wizards aren't spells and don't have spells in them
//2. inherit, savefiles are ipersistable
//3. compose, inventories store items
//4. neither, a rectangle isn't a square nor does it have squares
//5. compose, the engine has a map
//6. inherit, the playerdestructible is a destructible

int main() 
{
	//Problem01
	//Demo02_Order();
	//Problem02
	//Fireball thing;
}