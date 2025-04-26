

#include <iostream>
#include <string>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <set>
#include <list>
#include <vector>




int gen()
{
	return rand();
};



int main()
{


	
	//generate algorithm

	std::cout << "My list is : \n";

	std::list<int> MyList(10);

	std::generate(MyList.begin(), MyList.end(), gen);

	for (auto i : MyList)
	{
		std::cout << i << '\n';
		
	}

	std::list<int> NewList(10);

	// transform alorithm

	std::cout << "A new list is : \n";

	std::transform(MyList.cbegin(), MyList.cend(), NewList.begin(), [](int x) {
		
		return x % 10;
		});



	for (auto i : NewList)
	{
		std::cout << i << '\n';

	}

	std::cout << "The list after removing elements :\n";

	auto NewBegin = std::remove_if(NewList.begin(), NewList.end(), [](int x) {
		return x > 3;
		});

	NewList.erase(NewBegin, NewList.end());

		for (auto i : NewList)
		{
			std::cout << i << '\n';

		}
	// remove_if algorithm



}