#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void corruptedArray()
    {
        int n;
        scanf("%d", &n);
        vector <int> b(n+2);
        for (int &i: b) scanf("%d", &i);
//si usas un vector con la funcione erase tarda mucho
        multiset <int> answer(b.begin(), b.end()); //set y multiset son guardados como binary tree por lo que
        //las funciones de search and erase se consiguen en O(log n)
        long long sum = accumulate(b.begin(),b.end(), 0LL);
        for (int x:b)
        {
            sum -= x;
            answer.erase(answer.find(x));
            if (sum % 2 == 0 && (sum / 2) <= 2000000000 && answer.find(sum/2) != answer.end())
            {
                answer.erase(answer.find(sum/2));
                for (auto it: answer)
                {
                    printf("%d ", it);
                }
                printf("\n");
                return;
            }
            sum += x;
            answer.insert(x);
        }
        printf("-1\n");
        return;
    }
};

int main()
{
    int t;
    Solution obj;
    scanf("%d", &t);
    while (t--)
    {
        obj.corruptedArray();
    }
    return 0;
}
