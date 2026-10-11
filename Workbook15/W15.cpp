#include <iostream>
#include <format>
#include <string>
#include <fstream>
#include <stdexcept>
#include <filesystem>

//Problem01
std::string Trim(std::string_view text)
{
	std::size_t first{ text.find_first_not_of(" \t") };

	if (first == std::string_view::npos)
	{
		return "";
	}

	const std::size_t last{ text.find_last_not_of(" \t") };

	return std::string(text.substr(first, last - first + 1));
}


void ReadConfig(const std::string& Filename, std::vector<std::string>& keys, std::vector<std::string>& values) 
{
	std::ifstream in{Filename};

	if (!in)
	{
		throw std::runtime_error("Failed to open config file");
	}

	std::string line;

	while (std::getline(in, line)) 
	{
		const std::string trimmed{ Trim(line) };

		if (trimmed.empty() || trimmed.starts_with('#'))
		{
			continue;
		}

		const std::size_t equals{ trimmed.find('=') };

		if (equals == std::string::npos)
		{
			throw std::runtime_error("Bad config line: " + trimmed);
		}

		keys.push_back(Trim(std::string_view{ trimmed }.substr(0, equals)));
		values.push_back(Trim(std::string_view{ trimmed }.substr(equals + 1)));
	}
}

//Problem02
int ReadIntSentinel(std::ifstream& in)
{
	int value{ 0 };

	if (!(in >> value))
	{
		throw std::runtime_error("Failed to read integer from file");
	}

	return value;
}

//Problem03
//1. return false, because missing save is a valid state and not an error
//2. throw, don't need all five integers so can be thrown
//3. take an std::error_code, a destructor can't throw so we would need an error code
//4. return false, if the wrong monster name is searched you would need to return a failed input
//5. throw, shouldn't use a width that is varied / tied to a variable
//6. return false, if the player can't afford the item false needs to be returned

//4 could be arguable as you could throw at the time when an incorrect monster is input instead of returning false, 6 could be thrown aswell because if the person can't afford the item the transaction will need to be thrown

int main()
{
	//ReadConfig();
	//ReadIntSentinel();
}