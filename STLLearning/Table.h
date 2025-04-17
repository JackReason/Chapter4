#pragma once
#include <iostream>
#include <string>

class HashTable {

public:
    HashTable();

    int hash(std::string key);

    void print();
    
    void AddInfo(const std::string& newname, int value);


private:

    static const int TableSize = 100;

    struct Info
    {
    public:
        std::string name;
        int money;

    };

    Info* Table[TableSize];

    bool SearchForEmpty(int limit, int& Start);
    

};