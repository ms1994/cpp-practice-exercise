#include <bits/stdc++.h>

using namespace std;


class Solution
{
    int MAX_LENGTH = 50;
public:
    void commonPrefix()
    {
        int n;
        scanf("%d", &n);
        vector <string> words;
        words.push_back(anyWord("",0));
        vector <int> a(n);
        for (int &x: a) scanf("%d", &x);
        for (int i = 0; i < n; i++)
            words.push_back(anyWord(words[i],a[i]));
        for (auto word : words) cout << word << endl;
    }

    string anyWord(string s, int k)
    {
        string newWord = "";
        srand(time(0));
        if (s.length() == 0)
        {
            for (int i = 0; i < MAX_LENGTH; i++)
            {
                newWord += char ('a' + (rand()%26));
            }
            return newWord;
        }
        for (int i = 0; i < k; i++)
            newWord += s[i];
        int i = k;
        while (i < MAX_LENGTH)
        {
            char letter = char ('a' + (rand()%26));
            if (letter == s[i]) continue;
            newWord += letter;
            i++;
        }
        return newWord;
    }
};

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        Solution obj;
        obj.commonPrefix();
    }

    return 0;
}
