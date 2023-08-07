#include <iostream>
#include <string>
#include "Solution.h"
#include<sstream>

using namespace std;

int main()
{
    Solution obj;
    const int arr [10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    ostringstream os;
    for (int i : arr) {
        os << i;
    }
    string a(os.str());
    a += "jola";
    cout << obj.createPhoneNumber(arr) << endl;
    return 0;
}
