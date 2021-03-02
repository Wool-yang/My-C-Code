#include<iostream>
#include<random>
#include<time.h>
#include<fstream>

using namespace std;

int main()
{
    srand((int)time(NULL));	

    
    ofstream out("record.txt");
    for(int i = 1;i <= 10000000;i++)
    {
        out << rand() * rand() << " ";
    } 
    return 0;
}

