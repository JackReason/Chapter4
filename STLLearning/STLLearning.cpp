

#include <iostream>
#include <string>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <set>



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

bool LookForSmart(const std::pair<const std::string, Character>& chr)
{
	Character PoopyButtHole("PoppyButtHole", 500, BrainLevel::AVERAGE);

	return chr.second.GetBrainLEvel() > PoopyButtHole.GetBrainLEvel();

}


void LookForTheBest(const std::string& chr) 
{
	if (chr == "Rick")
		std::cout << chr << " is the best!\n";

	else
		std::cout << chr << " is your average character\n";

	
}

int main()
{

	// find_if algorithm

	std::map<std::string, Character> SeriesM;

	
	SeriesM.emplace("Morty", Character("Morty", 120, BrainLevel::FOOL));
	SeriesM.emplace("Summer", Character("Summer", 320, BrainLevel::SMART));
	SeriesM.emplace("Rick", Character("Rick", 1000, BrainLevel::BRAINIAC));
	SeriesM.emplace("Beth", Character ("Beth", 680, BrainLevel::SMART));

	Character PoopyButtHole("PoppyButtHole", 500, BrainLevel::AVERAGE);
	
	

	auto Result = find_if(SeriesM.begin(), SeriesM.end(), [PoopyButtHole]( const std::pair<const std::string, Character>& chr)
		{
			Character temp = chr.second;
			return temp > PoopyButtHole;
		});

	
	if (Result != SeriesM.end())
	{
		std::cout << Result->second.GetName() << " is cooler than mr. PoppyButtHole\n\n";
	}

	

	// count_if algorithm

	std::unordered_map<std::string, Character> SeriesU;

	SeriesU.emplace("Morty", Character("Morty", 120, BrainLevel::FOOL));
	SeriesU.emplace("Summer", Character("Summer", 320, BrainLevel::SMART));
	SeriesU.emplace("Rick", Character("Rick", 1000, BrainLevel::BRAINIAC));
	SeriesU.emplace("Beth", Character("Beth", 680, BrainLevel::SMART));
	SeriesU.emplace("EvilMorty", Character("EvilMorty", 1000, BrainLevel::BRAINIAC));
	SeriesU.emplace("BirdPerson", Character("BirdPerson", 830, BrainLevel::SMART));
	SeriesU.emplace("GearHead", Character("GearHead", 70, BrainLevel::AVERAGE));


	auto SmartPeople = count_if(SeriesU.begin(), SeriesU.end(), LookForSmart);

	std::cout << SmartPeople << " characters are smarter then mr. PoopyButtHole\n\n";

	// for_each algorithm

	std::set<std::string> SeriesS;

	SeriesS.emplace("Morty");
	SeriesS.emplace("Summer");
	SeriesS.emplace("Rick");
	SeriesS.emplace("Beth");
	SeriesS.emplace("EvilMorty");
	SeriesS.emplace("BirdPerson");
	SeriesS.emplace("GearHead");
	

	for_each(SeriesS.begin(), SeriesS.end(), LookForTheBest);

}