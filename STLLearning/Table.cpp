#include "Table.h"

HashTable::HashTable() 
{
    for (int i = 0; i < TableSize; i++)
    {
        Table[i] = new Info;
        Table[i]->name = "none";
        Table[i]->money = 0;
    }
}


int HashTable::hash(std::string key) 
{
    int HashSum = 0;

    for (int i = 0; i < key.size(); i++)
    {
        HashSum = HashSum + (int)key[i];
    }
    int result = HashSum % TableSize;

    return result;
}

void HashTable::print()
{
    
        for (int i = 0; i < TableSize; i++)
        {
            std::cout << "N = " << i << " name is = " << Table[i]->name << " money = " << Table[i]->money << '\n';
        }
    
}

void HashTable::AddInfo(const std::string& newname, int value)
{
    bool isFound = false;
    int index = hash(newname);
    int currentIndex = index;

    if (Table[index]->name == "none")
    {
        Table[index]->name = newname;
        Table[index]->money = value;
        isFound = true;
    }
    else
    {
        if (SearchForEmpty(TableSize, index)) // looking after current index 
        {
            Table[index]->name = newname;
            Table[index]->money = value;
            isFound = true;
        }

        index = 0;

        if (!isFound && SearchForEmpty(currentIndex, index)) // looking before current index from begining of the table
        {
            Table[index]->name = newname;
            Table[index]->money = value;
            isFound = true;
        }

        if (!isFound)
        {
            std::cout << "got no empty space left";
        }
    }
}

bool HashTable::SearchForEmpty(int limit, int& Start)
{
    
        for (int i = Start; i < limit; i += 2)
        {
            if (Table[i]->name == "none")
            {
                Start = i;
                return true;
            }
        }
        return false;

    
}
