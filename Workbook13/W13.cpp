#include <iostream> // std::cout
#include <format> // std::format
#include <string> // std::string
#include <string_view> // std::string_view
#include <vector> // std::vector

//Problem01
std::string Extension(const std::string& path)
{
	const std::size_t dot{ path.rfind('.') };

	if (dot != std::string::npos)
	{
		return path.substr(dot);
	}

	return ""; 
}

//Problem02
std::string Scoreboard(std::string_view name, int score, float percentage) 
{
	return std::format("{:.<14}{:>6}{:7.1f}%\n", name, score, percentage);
}

//Problem03
//Only needs to read the word
bool IsRudeWord(std::string_view word);
//If its appended to a log then it needs to be passed by value to keep a copy of it
void AppendToLog(std::string message);
//Just needs to be read to count vowels
int CountVowels(std::string_view text);
//Needs to be changed to capitalise the string
void Capitalise(std::string& text);
//You only need to read the pattern int amount of times
std::string Repeat(std::string_view pattern, int times);
//Capitalise is the bug because it takes a reference and changes it in the function but it isn't passed back and the function is destroyed so the original isn't changed and no warrning is produced

int main()
{
	//Problem01
	//std::cout << std::format("The extension of the file is: {}\n", Extension("save.dat"));
	//std::cout << std::format("The extension of the file is: {}\n", Extension("levels/cavern_02.dat"));
	//std::cout << std::format("The extension of the file is: {}\n", Extension("README"));
	//std::cout << std::format("The extension of the file is: {}\n", Extension("archive.tar.gz"));
	//std::cout << std::format("The extension of the file is: {}\n", Extension(".gitignore"));
    //Problem02
	//Scoreboard(std::string("goblin"), 1240, 66.7);
	//Scoreboard(std::string("orc chieftain"), 9915, 99.2);
	//Scoreboard(std::string("rat"), 5, 0.4)
	//Problem03
}