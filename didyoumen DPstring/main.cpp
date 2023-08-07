#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string typo(string s)
    {
        int n = s.length();
        char consonant = '#';
        int cont = 0;
        bool different = false;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i'|| s[i] == 'o' || s[i] == 'u')
            {
                different = false;
                cont = 0;
                consonant = '#';
            }
            else
            {
                cont++;
                if (consonant == '#')
                {
                    consonant = s[i];
                }
                if (s[i] != consonant) different = true;
                if (cont > 2 && different)
                {
                    s = s.substr(0,i) + " " + typo(s.substr(i));
                    break;
                }
            }
        }
        return s;
    }
};

int main()
{
    string s;
    cin >> s;
    Solution obj;
    cout << obj.typo(s) << endl;
    return 0;
}
