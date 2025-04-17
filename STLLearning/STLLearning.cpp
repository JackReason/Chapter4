

#include <iostream>
#include <string>
#include "Table.h"






int main()
{
    HashTable Jack;
    Jack.AddInfo(std::string("Monty"), 500);
    Jack.AddInfo(std::string("Gadget"), 750);
    Jack.AddInfo(std::string("Chip"), 820);
    Jack.AddInfo(std::string("Dale"), 120); 
    Jack.AddInfo(std::string("Zipper"), 1750);
    Jack.print();
}

