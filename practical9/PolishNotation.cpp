#include "PolishNotation.h"
#include <iostream>
#include <sstream>
#include <string>
#include <stack>
using namespace std;

PolishNotation::PolishNotation(){
   affix = "";
}

PolishNotation::PolishNotation(string present){
   affix = present;
}

void PolishNotation::setPrefixPresent(string present){
   affix = present;
}

string PolishNotation::convertPrefixToInfix()
{
   string infix = "";
   stack<int> stk;
   int validPresent = 1;
   int value = 0;
   int digits = 0;
   for (int i = affix.length() - 1; i >= 0 && validPresent == 1; i--){
       char ch = affix[i];
       if (ch == ' '){
           digits = 0;
       }
       else if (isdigit(ch)){
           digits++;
           if (digits == 1){
               value = ch - '0';
           }
           else{
               value = value + (ch - '0') * 10;
               stk.pop();              
           }
           stk.push(value);
           if (value > 99){
               validPresent = 0;
           }
       }
       else if ((ch == '+' || ch == '-' || ch == '*' || ch == '/') && stk.size() >= 2 && infix.length() == 0){
           int num1 = stk.top();
           stk.pop();
           int num2 = stk.top();
           stk.pop();
           ostringstream oss;
           oss << infix << "(" << num1 << " " << ch << " " << num2 << ")";
           infix = oss.str();
           digits = 0;
       }
       else if ((ch == '+' || ch == '-' || ch == '*' || ch == '/') && stk.size() == 1 && infix.length() > 0){
           int num = stk.top();
           stk.pop();
           ostringstream oss;
           oss << infix << " " << ch << " " << num;
           infix = oss.str();
           digits = 0;
       }
       else if ((ch == '+' || ch == '-' || ch == '*' || ch == '/') && stk.size() >= 2 && infix.length() > 0){
           int num = stk.top();
           stk.pop();
           ostringstream oss;
           oss << "(" << infix << " " << ch << " " << num << ")";
           infix = oss.str();
           digits = 0;
       }
       else{
           validPresent = 0;
       }
   }
   if (validPresent == 0 || stk.size() > 0){
       infix = "Error";
   }
   return infix;
}

int PolishNotation::computePrefixPresent()
{
   int result = 0;
   stack<int> stk;
   int validPresent = 1;
   int value = 0;
   int digits = 0;
   for (int i = affix.length() - 1; i >= 0 && validPresent == 1; i--){
       char ch = affix[i];
       if (ch == ' '){
           digits = 0;
       }
       else if (isdigit(ch)){
           digits++;
           if (digits == 1){
               value = ch - '0';
           }
           else{
               value = value + (ch - '0') * 10;
               stk.pop();
           }
           stk.push(value);
           if (value > 99){
               validPresent = 0;
           }
       }
       else if (ch == '+' && stk.size() >= 2){
           int num1 = stk.top();
           stk.pop();
           int num2 = stk.top();
           stk.pop();
           stk.push(num1 + num2);
           digits = 0;
       }
       else if (ch == '-' && stk.size() >= 2){
           int num1 = stk.top();
           stk.pop();
           int num2 = stk.top();
           stk.pop();
           stk.push(num1 - num2);
           digits = 0;
       }
       else if (ch == '*' && stk.size() >= 2){
           int num1 = stk.top();
           stk.pop();
           int num2 = stk.top();
           stk.pop();
           stk.push(num1 * num2);
           digits = 0;
       }
       else if (ch == '/' && stk.size() >= 2){
           int num1 = stk.top();
           stk.pop();
           int num2 = stk.top();
           stk.pop();
           stk.push(num1 / num2);
           digits = 0;
       }
       else{
           validPresent = 0;
       }
   }
   if(validPresent == 1 && !stk.empty()){
       result = stk.top();
       stk.pop();
   }
   return result;
}