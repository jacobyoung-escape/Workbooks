#include <iostream>
#include <format>
#include <string>
#include <vector>
#include <cassert>

//Problem01
std::vector<int> WithPenalty(const std::vector<int>& laps, int penalty)
{
    std::vector<int> result;
    for (int lap : laps)
    {
       result.push_back(lap + penalty);
    }
    return result;
}

void Problem01()
{
    for (const int& lap : WithPenalty({ 91, 88, 94, 87, 90 }, 5))
	{
		std::cout << std::format("{} ", lap);
	}
}

void Problem03()
{
    std::vector<int> scores{ 40, 85, 12, 97, 63 };
    // 1. print every score
    for (int i = 0; i < scores.size(); ++i)
    {
        std::cout << std::format(" score {}: {}\n", i, scores[i]);
    }
    // 2. find the highest
    int highest{ scores[0] };
    for (int score : scores)
    {
        if (score > highest)
        {
            highest = score;
        }
    }
    std::cout << std::format(" highest: {}\n", highest);
    // 3. print them backwards
    for (int i{ static_cast<int>(scores.size()) - 1 }; i >= 0; --i)
    {
        std::cout << std::format(" backwards: {}\n", scores[i]);
    }
}

//Stretch
struct Track
{
    std::string title{};
    int seconds{ 0 };
};

class Player
{
public:
    void Add(const std::string& title, int seconds)
    {
        tracks.push_back(Track{ title, seconds });

            if (tracks.size() == 1)
            {
                nowPlaying = 0;
            }
    }

    void Report() const
    {
        if (nowPlaying < 0)
        {
            std::cout << " nothing playing\n";
            return;
        }
        const Track& track{ tracks[static_cast<std::size_t>(nowPlaying)] };
        std::cout << std::format(" now playing: {} ({}s)\n", track.title, track.seconds); 
    }

private:
    std::vector<Track> tracks;
    int nowPlaying{ -1 };
};

void Stretch()
{
    Player player;

    player.Add("Opening Titles", 92);
    player.Report(); // fine

    player.Add("The Long Corridor", 187);
    player.Add("Boss Theme", 143);
    player.Add("Credits", 210);

    player.Report(); // ???
}

int main()
{
    //Problem01();
    //Problem03();
    Stretch();
}