#include "Solution.h"
#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;


Solution::Solution()
{
    //ctor
}
 string Solution::brainLuck(const string &code, const string &input)
 {
     string output = "";
     if (code.length() == 0) return output;
     vector <int> cells(3000, 0);
     int indexVectorCell = 0;
     size_t i = 0;
     int spaceLoop = 0;
     size_t indexInput = 0;
     while(i < code.length())
     {
        char symbol = code[i];
        if (symbol == '<') {
            indexVectorCell--;
            if (indexVectorCell < 0) indexVectorCell = cells.size() - 1;
        }
        if (symbol == '>') {
            indexVectorCell++;
            if (indexVectorCell == cells.size()) indexVectorCell = 0;
        }
        if (symbol == '[' && cells[indexVectorCell] == 0) {
            spaceLoop = countSpaceLoop(code,i);
            i = i + spaceLoop;
        }
        if (symbol == ']' && cells[indexVectorCell] != 0){
            spaceLoop = countSpaceLoop(code, i);
            i = i - spaceLoop;
        }
        if (symbol == '+') cells[indexVectorCell] = (cells[indexVectorCell] +1) % 256;
        if (symbol == '-') cells[indexVectorCell] = (cells[indexVectorCell] -1) % 256;
        if (symbol == ',') {
            cells[indexVectorCell] = (int) input[indexInput];
            indexInput = (indexInput + 1) % input.length();
          }
        if (symbol == '.'){
            char response = (char) cells[indexVectorCell];
            output.append(1, response);
        }
        i++;
     }
     return output;
 }

int Solution::countSpaceLoop(string code, size_t indexCode)
{
    int cont = 0;
    int countBrackets = 0;
    if (code[indexCode] == '[' && cont == 0) {
         while (indexCode < code.length()){
            char symbol = code[indexCode];
            if (symbol =='[' && cont > 0)
            {
                countBrackets++;
            }
            if (symbol != ']'){
                indexCode++;
                cont++;
            }
            else if(countBrackets == 0) {
                return cont;
            }
            else {
                indexCode++;
                cont++;
                countBrackets--;
            }
        }
    }
    if (code[indexCode] == ']' && cont == 0)
    {
        while (indexCode < code.length()){
            char symbol = code[indexCode];
            if (symbol ==']' && cont > 0)
            {
                countBrackets++;
            }
            if (symbol != '['){
                indexCode--;
                cont++;
            }
            else if(countBrackets == 0) {
                return cont;
            }
            else {
                indexCode--;
                cont++;
                countBrackets--;
            }
        }
    }

    return cont;
}
