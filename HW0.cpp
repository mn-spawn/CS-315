//
// Created by Madeline Spawn on 3/31/22.
//
#include <iostream>
using namespace std;

int addMultNum();
int add(int a, int b);
int mult(int a, int b);

int main()
{
    addMultNum();
}

int addMultNum()
{
    int lineNum;
    std::cin >> lineNum;

    for (int i = 0; i < lineNum; i++)
    {
        int a,b;
        std::cin >> a >> b;
        std::cout << add(a,b) << " " << mult(a,b);

        std::cout << '\n';
    }
}

//helper functions
int add(int a, int b)
{
    return a+b;
}

int mult(int a, int b)
{
    return a*b;
}
