#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int findOdd(const vector<int>& numbers);

int main()
{
    vector<int> ms = { 1, 1, 3,76, 76};
    cout << findOdd(ms) << endl;

}
int findOdd(const vector<int>& numbers){
    int countElement;
    for(int i = 0; i < numbers.size(); i++){
    countElement = count(numbers.begin(), numbers.end(), numbers[i]);
    if countElement % 2 == 1 return numbers[i];
}
}
