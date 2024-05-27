#ifndef SUPPMETHODS_H
#define SUPPMETHODS_H
#include <iostream>
#include <sstream>
#include <limits>
#include<algorithm>

using namespace std;

class SuppMethods
{
public:
    static string readLine();
    static char readChar();
    static string convIntToString(int number);
    static float readFloat();
    static int readInt();
    static int convStringToInt(string word);
};

#endif
