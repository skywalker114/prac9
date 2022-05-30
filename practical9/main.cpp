#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include "PolishNotation.h"
using namespace std;

int main()
{
   string affix;  
   cout << "Sample input: ";
   getline(cin, affix);
   PolishNotation polish(affix);
   string infix = polish.convertPrefixToInfix();
   cout << "Sample output: " << infix;
   if (infix.compare("Error") != 0){
       int result = polish.computePrefixPresent();    
       cout << " = " << result;
   }
   cout << endl << endl;
   return 0;
}