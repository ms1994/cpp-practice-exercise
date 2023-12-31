// C++ program to count increasing subsequences
// in an array of digits.
#include<bits/stdc++.h>
using namespace std;

// Function To Count all the sub-sequences
// possible in which digit is greater than
// all previous digits arr[] is array of n
// digits
int countSub(vector<int> &arr, int n)
{
    // count[] array is used to store all sub-
    // sequences possible using that digit
    // count[] array covers all the digit
    // from 0 to 9
    vector<int> count(10, 0);

    // scan each digit in arr[]
    for (int i=0; i<n; i++)
    {
        // count all possible sub-sequences by
        // the digits less than arr[i] digit
        for (int j=arr[i]-1; j>=0; j--)
            count[arr[i]] += count[j];

        // store sum of all sub-sequences plus
        // 1 in count[] array
        count[arr[i]]++;
    }

    // now sum up the all sequences possible in
    // count[] array
    int result = 0;
    for (int i=0; i<10; i++)
        result += count[i];

    return result;
}

// Driver program to run the test case
int main()
{
    vector<int>arr;
    arr.push_back(1);
    arr.push_back(3);
    arr.push_back(2);
    arr.push_back(1);
    int n = arr.size();
    cout << countSub(arr,n);
    return 0;
}
