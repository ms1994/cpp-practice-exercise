#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

int findOdd(const vector<int>& numbers);

int main()
{
    vector<int> ms;
    ms.push_back(1);
    ms.push_back(1);
    ms.push_back(3);
    ms.push_back(6);
    ms.push_back(6);
    cout << findOdd(ms) << endl;

}
int findOdd(const vector<int>& numbers){
    int countElement;
    for(unsigned int i = 0; i < numbers.size(); i++){
    countElement = count(numbers.begin(), numbers.end(), numbers[i]);
    if (countElement % 2 == 1) return numbers[i];
    }
    return -1;
}
