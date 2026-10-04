#include <iostream>
#include <format>
#include <cmath>

//Problem01
struct Rectangle
{
	int height{ 0 };
	int width{ 0 };

	Rectangle() = default;
	
	Rectangle(int width, int height) : width(width), height(height) {}

	int Area() const 
	{ 
		return width * height; 
	}

	bool operator==(const Rectangle& rhs) const
	{
		return width == rhs.width && height == rhs.height;
	}
};

void Problem01()
{
	std::cout << Rectangle{ 3, 4 }.Area();
}	

//Problem04
struct Fraction
{
	int numerator{ 0 };
	int denominator{ 1 };

	Fraction() = default;
	Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator) {}

	float AsDecimal() const
	{
		return static_cast<float>(numerator) / denominator;
	}

	Fraction operator*(const Fraction& rhs) const
	{
		return { numerator * rhs.numerator, denominator * rhs.denominator };
	}

	bool operator==(const Fraction& rhs) const
	{
		return { numerator * rhs.denominator == denominator * rhs.numerator };
	}

	void Print() const
	{
		std::cout << std::format("{}/{} ({:.3f})\n", numerator, denominator, AsDecimal());
	}
};

void Problem04()
{
	Fraction threeQuarters{ 3, 4 };
	Fraction twoThirds{ 2, 3 };
	Fraction sixTwelfths{ 6, 12 };
	Fraction oneHalf{ 1, 2 };

	threeQuarters.Print();                              // 3/4 (0.750)
	twoThirds.Print();                                  // 2/3 (0.667)

	Fraction product{ threeQuarters * twoThirds };
	product.Print();                                    // 6/12 (0.500)

	std::cout << std::format("6/12 == 1/2 ? {}\n", sixTwelfths == oneHalf);
}	

//Problem06
class Stopwatch
{
public:
	Stopwatch(int limitSeconds);

	const int GetElapsed();          
	void Tick();                  
	const bool HasFinished();          
	void Reset();                  
	const float AsMinutes();              
	void SetLimit(int seconds);     
	const int GetLimit();                 

private:
	int elapsedSeconds{ 0 };
	int limitSeconds{ 0 };
};

void Problem06()
{
	
}

int main() 
{
	//Problem01();
	//Problem04();
	Problem06();
	return 0;
}