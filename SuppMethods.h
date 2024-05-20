#ifndef SUPPMETHODS_H
#define SUPPMETHODS_H
#include <iostream>
#include <sstream>

using namespace std;

class SuppMethods
{
public:
    static string readLine();
    static char readChar();
    static string convIntToString(int number);
    static int convStringToInt(string word);
    static float readFloat();
};

#endif
