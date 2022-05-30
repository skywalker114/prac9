#ifndef POLISHNOTATION_H
#define POLISHNOTATION_H
#include <iostream>
using namespace std;

class PolishNotation
{
public:
   PolishNotation();
   PolishNotation(string present);
   void setPrefixPresent(string present);
   string convertPrefixToInfix();
   int computePrefixPresent();
private:  
   string affix;
};
#endif
