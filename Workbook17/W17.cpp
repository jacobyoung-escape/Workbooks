#include <iostream> // std::cout
#include <format> // std::format
#include <string> // std::string
#include <string_view> // std::string_view
#include <vector> // std::vector
#include <memory> // std::unique_ptr, std::make_unique
#include <utility> // std::move

//Problem01
class Asset
{
public:
	Asset(std::string_view name) : name(name)
	{
		std::cout << std::format(" + {} loaded\n", this->name);
	}
	virtual ~Asset()
	{
		std::cout << std::format(" - {} released\n", name);
	}
	virtual void Describe() const
	{
		std::cout << std::format(" {} — an asset\n", name);
	}

		const std::string & GetName() const { return name; }
protected:
	std::string name;
};

class Texture : public Asset
{
public:
	Texture(std::string_view name, int pixels) : Asset(name), pixels(pixels) {}
	void Describe() const override
	{
		std::cout << std::format(" {} — texture, {}x{}\n", name, pixels,
			pixels);
	}
private:
	int pixels{ 0 };
};

class Mesh : public Asset
{
public:
	Mesh(std::string_view name, int triangles) : Asset(name), triangles(triangles)
	{
	}
	void Describe() const override
	{
		std::cout << std::format(" {} — mesh, {} triangles\n", name,
			triangles);
	}
private:
	int triangles{ 0 };
};

std::unique_ptr<Asset> MakeAsset(std::string_view kind, std::string_view name)
{
	if (kind == "mesh")
	{
		return std::make_unique<Mesh>(name, 32);
	}

	if (kind == "texture")
	{
		return std::make_unique<Texture>(name, 165);
	}

	return nullptr;
}

//When I removed virtual from ~asset no lines of output disappeared. The constructor isn't affected as it knows what it needs to build so removing virtual doesn't impact it.

//Problem02
class Level
{
public:
	//terrain should've been assigned in the initialiser list
	Level(std::string_view name) : name(name), terrain(std::make_unique<Mesh>("terrain", 20000))
	{
	}

	//Didn't need a delete

	Mesh* GetTerrain() const 
	{ 
		return terrain.get(); 
	}

private:
	std::string name;
	//Should've been a unique pointer initialising terrain
	std::unique_ptr<Mesh> terrain;
};

//GetTerrain should reeturn Mesh* because the pointer would look at whats in the memory location 

//Problem03
//1. std::vector<std::unique_ptr<Prop>> as the your variables don't have the props the scene has the props
//2. Prop* as it just needs to be a reference
//3. std::unique_ptr<Prop> as it is becoming it's own prop
//4. const Prop& as it only needs to be read
//5. std::unique_ptr<Texture> as every prop has a unique texture
//6. std::unique_ptr<Mesh> as they may need a mesh
//7. std::unique_ptr<Prop> as it is it's own prop being handed to the caller.

int main() 
{
	//Problem01
	//MakeAsset("mesh", "floor");
	//MakeAsset("texture", "wood");
	//MakeAsset("none", "none");
}
