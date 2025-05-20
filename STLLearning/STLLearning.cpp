

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
public:

	Arr() 
	{
		A = 1.2;
		B = 7;
		C = 4.6;
	}

	
	
	void print()
	{
		std::cout << "Struct elements = " << A << " " << B << " " << C << '\n';
	}
private:

	double A;
	int B;
	float C;
};

struct S
{
	std::string m_message{ "Hello" };
};


class Container
{
public:
	Container()
	{
		first = reinterpret_cast<Arr*>(Mas);
		last = first + 10;
	}

	 Arr* begin()
	{
		return first;
	}

	 Arr* end()
	{
		return last;
	}

	void print()
	{
		for (Arr* it{ first }; it != last; it++)
		{
			it->print();
		}

	}
private:
	alignas(alignof(Arr)) double Mas[10 * sizeof(Arr)];
	Arr* first;
	Arr* last;
	//Arr* Iterator;
	
};

void Swap(std::vector<int>& vec, int i, int y)
{
	int temp = vec[i];
	vec[i] = vec[y];
	vec[y] = temp;

}

void CustomHeapSort(std::vector<int>& vec)
{
	int Size = vec.size();
	for (int i = 0; i < Size-1; i++)                           
	{
		Swap(vec, 0, Size - (i+1));                           // main swap
		int p = 0;
		bool AnotherRound = false;                            // bool for local swaping
		int Range = Size - i - 2;

		//std::cout << "After main swap = ";
		//printVector(vec);

		do
		{
			int left = 2 * p + 1;
			int right = 2 * p + 2;
			int parent = p;

			if (Range < left)                              // parent has no children
				break;

			if (left == Range)                             // parent has only left child
			{
				if (vec[left] > vec[parent])
				{
					Swap(vec, parent, left);
					break;
				}
				break;
			}

			if (vec[left] > vec[right])                      // parent has both children
			{
				if (vec[left] > vec[parent])
				{
					Swap(vec, parent, left);
					p = left;
					AnotherRound = true;
				}
				else 
				{
					AnotherRound = false;
				}

			}
			else
			{
				if (vec[right] > vec[parent])
				{
					Swap(vec, parent, right);
					p = right;
					AnotherRound = true;
				}
				else
				{
					AnotherRound = false;
				}
			}

		} while (AnotherRound);
		
		//printVector(vec);
		
	
	}
	for (int i = 0; i < (Size / 2); i++)
	{
		int second = Size - 1 - i;
		Swap(vec, i, second);
		
	}

}




int main()
{
	
	
	

	
	// uninitialized memory

	Container Jack;

	std::uninitialized_default_construct(Jack.begin(), Jack.end());

	Jack.print();


	// heap

	std::vector<int> Vec{ 35,22,45,2,456,67,12,87,90 };

	std::cout << "Vector is : \n";
	printVector(Vec);

	//std::cout << std::is_heap(Vec.begin(), Vec.end());

	std::make_heap(Vec.begin(), Vec.end());

	std::cout << "Heap is : \n";
	printVector(Vec);

	std::cout << "Custom heap sorting : \n";

	CustomHeapSort(Vec);
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