

#include <iostream>
#include <string>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <set>
#include <vector>



enum BrainLevel
{
	DOOP,
	FOOL,
	AVERAGE,
	SMART,
	BRAINIAC

};

class Character
{
public:
	Character(const std::string name, int cool, BrainLevel level)
	{
		this->Name = name;
		this->Cool = cool;
		this->Intelligence = level;
	}

	Character(const Character& copy)
	{
		this->Name = copy.Name;
		this->Cool = copy.Cool;
		this->Intelligence = copy.Intelligence;
	}


	int GetCool() const
	{
		return Cool;
	}

	std::string GetName() const
	{
		return Name;
	}

	bool operator>(const Character& other )
	{
		return this->Cool > other.GetCool();
	}

	BrainLevel GetBrainLEvel() const
	{
		return Intelligence;
	}
private:


private :
	std::string Name;
	int Cool;
	BrainLevel Intelligence;
	

};





void Print(const std::pair<std::string, Character>& chr)
{
	std::cout << chr.first << '\n';
}


class Fighter
{
	using Str = std::string;
public:
	Fighter(Str name, Str First, Str Second, Str Third, Str Fourth) : Name(name)
	{
		this->PowerLevels = new Str[4];
		PowerLevels[0] = First;
		PowerLevels[1] = Second;
		PowerLevels[2] = Third;
		PowerLevels[3] = Fourth;
	}
		
	Fighter(const Fighter& copy)
	{
		Name = copy.Name;
		std::cout << "copy constunctor called for " << Name <<'\n';
		this->PowerLevels = new Str[4];
		for (int i = 0; i < 4; i++)
		{
			this->PowerLevels[i] = copy.PowerLevels[i];
		}
	
		 
	}

	
	Fighter& operator=(const Fighter& copy) 
	{
		delete[] this->PowerLevels;
		Name = copy.Name;
		std::cout << "copy constunctor called for " << Name << '\n';
		this->PowerLevels = new Str[4];
		for (int i = 0; i < 4; i++)
		{
			this->PowerLevels[i] = copy.PowerLevels[i];
		}
		
		return *this;
	}

	Str PrintName()
	{
		return Name;
	}
private:
	Str Name;
	std::string* PowerLevels;
};

int main()
{


	// copy algorithm for unordered_map 

	std::cout << " Copy unordered_map\n";

	std::unordered_map<std::string, Character> SeriesU;

	std::unordered_map<std::string, Character> SeriesCoolCharacters;


	SeriesU.emplace("Morty", Character("Morty", 120, BrainLevel::FOOL));
	SeriesU.emplace("Summer", Character("Summer", 320, BrainLevel::SMART));
	SeriesU.emplace("Rick", Character("Rick", 1000, BrainLevel::BRAINIAC));
	SeriesU.emplace("Beth", Character("Beth", 680, BrainLevel::SMART));
	SeriesU.emplace("EvilMorty", Character("EvilMorty", 1000, BrainLevel::BRAINIAC));
	SeriesU.emplace("BirdPerson", Character("BirdPerson", 830, BrainLevel::SMART));
	SeriesU.emplace("GearHead", Character("GearHead", 70, BrainLevel::AVERAGE));

	Character PoopyButtHole("PoppyButtHole", 500, BrainLevel::AVERAGE); 

	copy_if(SeriesU.begin(), SeriesU.end(), std::inserter(SeriesCoolCharacters, SeriesCoolCharacters.begin()), [PoopyButtHole](const std::pair<std::string, Character>& chr) {
		
		return chr.second.GetCool() > PoopyButtHole.GetCool() ;
		});

	std::cout << "These are cool characters : \n";

	std::unordered_map<std::string, Character>::const_iterator It;
	It = SeriesCoolCharacters.begin();
	for_each(SeriesCoolCharacters.begin(), SeriesCoolCharacters.end(), Print);
	
	
	// deep copy

	std::cout << "\n Deep Copy \n ";

	std::vector<Fighter> DB =
	{
		Fighter("Goku", "SSJ1","SSJ2", "SSJ3", "SSBlue"),
		Fighter("Vegeta", "SSJ1","SSJ2", "SSJ3", "SSBlue")
	};

	std::vector<Fighter> DBdouble;
	

	copy(DB.cbegin(), DB.cend(), back_inserter(DBdouble));
	std::cout << "\nAfter coping we have two doubles\n";
	std::cout << DBdouble[0].PrintName() << '\n';
	std::cout << DBdouble[1].PrintName() << '\n';

	// fill algorithm

	Fighter Krillin("Krillin", "Kame", "Kame1", "Kame2", "Kame3");
	fill(DBdouble.begin(), DBdouble.end(), Krillin);


	std::cout << "\n\nChanging list with Krillins\n";
	std::cout << "Now we have : \n";
	std::cout << DBdouble[0].PrintName() << '\n';
	std::cout << DBdouble[1].PrintName() << '\n';


	
	
	
}