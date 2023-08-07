#include <bits/stdc++.h>

using namespace std;

class Solution
{
    int n;
public:
    Solution ()
    {
        cin >> n;
    }
    int answer()
    {
        string s;
        cin >> s;
        int cont = 0;
        map <char, int> symbolCount;
        for (size_t i = 0; i < s.length(); i++)
        {
            symbolCount[s[i]]++;
        }
        if (symbolCount['<'] > 0 && symbolCount['>'] > 0)
        {
            for (int i = 0; i < n; i++)
            {
                int next = (i + 1) % n;
                if (s[i] == '-')
                {
                    if (s[next] == '-') cont++;
                    else cont += 2;
                }
            }
            return cont > n ? n : cont;
        }
        return n;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Solution obj;
        cout << obj.answer() << endl;
    }
}
