

#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>


void HeapSort(std::vector<int>& A)
{
	int Count = A.size();
	std::vector<int>::iterator it = A.begin();
	do
	{
		for (;it!=A.end()-1;++it)
			if (*it > *(it + 1))
			{
				int temp = *(it + 1);
				*(it + 1) = *it;
				*it = temp;
			}
		it = A.begin();
		Count--;
	} while (Count!=0);
}
bool chkPremutation( std::vector<int>::const_iterator Str1,  std::vector<int>::const_iterator End1, std::vector<int>::const_iterator Str2, std::vector<int>::const_iterator End2)
{
	std::vector<int>::const_iterator temp1 = Str1;
	std::vector<int>::const_iterator temp2 = Str2;


	int Sum1 = 0;
	int Sum2 = 0;
	for (; Str1 != End1; Str1++)
	{
		Sum1 += *Str1;
		//std::cout << Sum1;
	}
	for (; Str2 != End2; Str2++)
	{
		Sum2 += *Str2;
	}
	if (Sum1 != Sum2)
	{
		std::cout << "\nSum failed!\n";
		return false;
	}
		

	Str1 = temp1;
	Str2 = temp2;

	int count = 1;

	for (; Str1 != End1; Str1++)
	{
		if (count == 1)
		{
			count = 0;
			for (; Str2 != End2; ++Str2)
			{
				if (*Str1 == *Str2)
					count++;

			}
		}
		Str2 = temp2;
	}

	if (count == 1)
		return true;
	else
		return false;
}

void printVector(const std::vector<int>& v)
{
	for (auto item : v)
	{
		std::cout << item << " ";

	}
	std::cout << '\n';
}

struct Arr
{
	Arr() : A(1.11), B(2), C(3.33) {}

	double A;
	int B;
	float C;
	
	void print()
	{
		std::cout << "Struct elements = " << A << " " << B << " " << C << '\n';
	}
};

struct S
{
	std::string m_message{ "Hello" };
};

int main()
{
	//uninitialized_memory
	constexpr int n = 10;

	alignas(alignof(Arr)) double Mas[n * sizeof(Arr)];

	auto first{ reinterpret_cast<Arr*>(Mas) };
	auto last{ first + n };

	std::uninitialized_default_construct(first, last);

	for (auto it{ first }; it != last; ++it)
	{
		it->print();
	}
	
	// heap

	std::vector<int> Vec{ 6,3,867,4,234,54,-34,5777,987 };
	printVector(Vec);

	std::cout << "Vector is : \n";
	std::make_heap(Vec.begin(), Vec.end());

	std::cout << "Heap is : \n";
	printVector(Vec);

	std::pop_heap(Vec.begin(), Vec.end());

	std::cout << "Heap after pop_heap : \n";
	printVector(Vec);

	//std::cout << std::is_heap(Vec.begin(), Vec.end());

	std::push_heap(Vec.begin(), Vec.end());

	std::cout << "Heap after push_heap : \n";
	printVector(Vec);


	std::cout << "Heap after sorting : \n";
	HeapSort(Vec);
	printVector(Vec);


	//premutations

	std::vector<int> X{ 1,2,3,7,6,5,4 };
	std::vector<int> Y{ 7,4,5,3,6,2,1 };

	
	if (chkPremutation(X.begin(), X.end(), Y.begin(), Y.end()))
	{
		std::cout << "\nIt is a premutation\n";
	}
	else
	{
		std::cout << "\nIt is not a premutation\n";
	}


}