

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
	return rand()%12;
};



int main()
{

	//generate algorithm and partial_sort_copy

	std::cout << "My list is : \n";

	std::vector<int> Vector1(10);

	std::generate(Vector1.begin(), Vector1.end(), gen);

	for (auto i : Vector1)
	{
		std::cout << i << ' ';
		
	}

	std::cout << '\n';

	std::cout << "New list is : \n";

	std::vector<int> Vector2(20);

	std::generate(Vector2.begin(), Vector2.end(), gen);
	
	for (auto i : Vector2)
	{
		std::cout << i << ' ';

	}
	std::cout << '\n';
	
	std::partial_sort_copy(Vector1.begin(), Vector1.end(), Vector2.begin(), Vector2.end(), [](int x, int y) {
		return  x>y;
		});

	std::cout << "After sort_copy : \n";

	for (auto i : Vector2)
	{
		std::cout << i << ' ';

	}
	
	std::cout << '\n';
	
	// lower_bound etc

	std::sort(Vector1.begin(), Vector1.end());

	auto Item = std::lower_bound(Vector1.begin(), Vector1.end(), 5);

	std::cout << "list after sorting is : \n";

	for (auto i : Vector1)
	{
		std::cout << i << ' ';

	}

	std::cout << "\nLooking for 5 \n";

	if (*Item == 5)
	{
		std::cout << "there is a 5\n";

		auto NextItem = std::upper_bound(Vector1.begin(), Vector1.end(),5);

		std::cout << "the next after 5 is : " << *NextItem;

	}
	else
		std::cout << "there is no 5\n";

	
	std::cout << "\nThe set is : \n";

	std::set<int> seq = { 12,6573,321,3,78,92,45,65,56,123 };
	for (auto i : seq) 
	{
		std::cout << i << " ";

	}

	std::cout << '\n'; 

	std::cout << "\nUpper_bound of set 65 is : " << *seq.upper_bound(65);

	std::cout << "\nLower_bound of set 66 is : " << *seq.lower_bound(66);


	// includes, set difference

	std::set<int> seq2 = { 78,92,45 };

	std::cout << "\nThe second set is : \n";

	for (auto i : seq2)
	{
		std::cout << i << " ";

	}
	std::cout << '\n';

	std::cout << "Is the second a subsequence of the first?\n";
	bool ItIs = std::includes(seq.begin(), seq.end(), seq2.begin(), seq2.end());
	if (ItIs)
	{
		std::cout << "Yes\n";
	}
	else
	{
		std::cout << "No\n";
	}

	std::set<int> seq3;
	std::set_difference(seq.begin(), seq.end(), seq2.begin(), seq2.end(), std::inserter(seq3, seq3.begin()));

	std::cout << "Now we copy all numbers from the first which are not in the second to the third : \n";

	for (auto i : seq3)
	{
		std::cout << i << " ";

	}
	std::cout << '\n';
}