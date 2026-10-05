#include <iostream>                        
#include <format>

//Problem01
class ComboMeter
{
public:
	void AddHit() { ++combo; }
	void Break() { combo = 0; }
	int  GetCombo() const { return combo; }
	bool IsActive() const { return combo > 0; }

private:
	int combo{ 0 };
};

TEST_CASE("Breaking a combo resets the combo to zero")
{
	ComboMeter meter;
	meter.AddHit();
	meter.AddHit();
	meter.Break();
	REQUIRE(meter.GetCombo() == 0);
	REQUIRE_FALSE(meter.IsActive());
}

TEST_CASE("Needs a combo of 3")
{
	ComboMeter meter;
	meter.AddHit();
	meter.AddHit();
	meter.AddHit();
	REQUIRE(meter.GetCombo() == 3);
	REQUIRE(meter.IsActive());
}

//Problem02
class AmmoClip
{
public:
	AmmoClip() = default;
	AmmoClip(int capacity) : rounds(capacity), capacity(capacity) {}

	int  GetRounds() const { return rounds; }
	bool IsEmpty() const { return rounds == 0; }

	void Fire(int shots)
	{
		rounds -= shots;
	}

	void Reload()
	{
		rounds = capacity;
	}

private:
	int rounds{ 0 };
	int capacity{ 1 };
};

TEST_CASE("A new clip is full")
{
	AmmoClip clip{ 30 };

	REQUIRE(clip.GetRounds() == 30);
	REQUIRE_FALSE(clip.IsEmpty());
}

TEST_CASE("Firing uses rounds")
{
	AmmoClip clip{ 30 };

	clip.Fire(10);

	REQUIRE(clip.GetRounds() == 20);
}

TEST_CASE("A clip cannot go below empty")
{
	AmmoClip clip{ 30 };

	clip.Fire(50);

	CHECK(clip.GetRounds() == 0);
	CHECK(clip.IsEmpty());
}

TEST_CASE("Reloading refills the clip")
{
	AmmoClip clip{ 30 };

	clip.Fire(50);
	clip.Reload();

	REQUIRE(clip.GetRounds() == 30);
}

//Problem03
int WaveScore(int waveNumber)
{
    int enemies{ 3 + waveNumber };
    int multiplier{ 1 + waveNumber / 4 };

    return enemies * 10 * multiplier;
}

void PartA()
{
    int total{ 0 };

    for (int wave{ 1 }; wave <= 30; ++wave)
    {
        total += WaveScore(wave);
    }

    std::cout << std::format("total {}\n", total);
}

//Problem04
class CooldownTimer
{
public:
	CooldownTimer() = default;
	CooldownTimer(int durationTurns) : duration(durationTurns) {}

	bool IsReady() const { return remaining == 0; }
	int  GetRemaining() const { return remaining; }

	bool TryUse()
	{
		if (IsReady() == false)
		{
			return false;
		}

		remaining = duration;
		return true;
	}

	void Tick()
	{
		if (remaining > 0)
		{
			--remaining;
		}
	}

private:
	int remaining{ 0 };
	int duration{ 1 };
};

TEST_CASE("A new timer is ready")
{
	CooldownTimer timer{ 3 };
	REQUIRE(timer.IsReady());
	REQUIRE(timer.GetRemaining() == 0);
}
TEST_CASE("Using a ready timer sets the remaining turns")
{
	CooldownTimer timer{ 3 };
	REQUIRE(timer.TryUse());
	REQUIRE_FALSE(timer.IsReady());
	REQUIRE(timer.GetRemaining() == 3);
}
TEST_CASE("Using a non-ready timer fails")
{
	CooldownTimer timer{ 3 };
	REQUIRE(timer.TryUse());
	REQUIRE_FALSE(timer.TryUse());
}
TEST_CASE("Ticking a timer counts down the remaining turns")
{
	CooldownTimer timer{ 3 };
	REQUIRE(timer.TryUse());
	timer.Tick();
	REQUIRE(timer.GetRemaining() == 2);
	timer.Tick();
	REQUIRE(timer.GetRemaining() == 1);
	timer.Tick();
	REQUIRE(timer.GetRemaining() == 0);
	REQUIRE(timer.IsReady());
}
TEST_CASE("Ticking a ready timer does nothing")
{
	CooldownTimer timer{ 3 };
	REQUIRE(timer.IsReady());
	timer.Tick();
	REQUIRE(timer.GetRemaining() == 0);
}
TEST_CASE("Using a timer after it has counted down works")
{
	CooldownTimer timer{ 3 };
	REQUIRE(timer.TryUse());
	timer.Tick();
	timer.Tick();
	timer.Tick();
	REQUIRE(timer.IsReady());
	REQUIRE(timer.TryUse());
}

int main()
{
    PartA();
	return 0;
}