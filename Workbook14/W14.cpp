#include <iostream>         // std::cout
#include <format>           // std::format
#include <string>           // std::string
#include <string_view>      // std::string_view
#include <stdexcept>        // std::runtime_error — Demonstration 4 only
#include <vector> 

class Announcer
{
public:
    Announcer(std::string_view name) : name(name)
    {
        std::cout << std::format("   + {} constructed\n", this->name);
    }

    ~Announcer()
    {
        std::cout << std::format("   - {} destroyed\n", name);
    }

private:
    std::string name;
};

//Problem01
void Puzzle()
{
    Announcer outer{ "outer" };

    for (int i{ 0 }; i < 2; ++i)
    {
        Announcer inner{ "inner" };
    }

    {
        Announcer nested{ "nested" };
        Announcer deeper{ "deeper" };
    }
}
//I expect the output to be: + outer constructed, + inner constructed, - inner destroyed, + inner constructed, - inner destroyed, + nested constructed, + deeper constructed, - deeper destroyed, - nested destroyed, - outer destroyed
//Acid is destroyed last because it is the first thing put on the stack and because a stack is a LIFO data structure it will be destroyed last

//Problem02
class IndentGuard
{
public:
	IndentGuard(int& indentLevel) : indentLevel(indentLevel)
	{
		++this->indentLevel;
	}

	~IndentGuard()
	{
		--indentLevel;
	}

    IndentGuard(const IndentGuard&) = delete;
	IndentGuard& operator = (const IndentGuard&) = delete;

private:
	int& indentLevel;
};

void RecuriveFunction(int& indentLevel, int levelDepth)
{
	IndentGuard guard(indentLevel);

	std::cout << std::format("current indent level: {} at depth: {}\n", indentLevel, levelDepth);

	if (levelDepth == 0)
	{
		return;
	}

	RecuriveFunction(indentLevel, levelDepth - 1);
}

//Problem03
//Deck wouldn't need a destructor as it has std::vector which holds its own destructor
//Timer would need a destructor as it is held in its own table so needs a destructor to destroy it
//Inventory wouldn't need a destructor as it they can both manage their own memory
//TempFile would need a destructor as a file would need a destroyer if it needs to be deleted when out of scope
//Label wouldn't need a destructor as they can manage their own memory

//If sombody copies Timer without a destructor, their would be the original and the copy pointing to the same memory location
//If somebody copies TempFile without a destructor, the copy would be pointing to the file whilst the original would be pointing to nothing

int main() 
{
    //Problem01
	//Puzzle();
    //Problem02
	//RecuriveFunction(*(new int(0)), 3);
    //Problem03
}