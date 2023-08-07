#include "Solution.h"
#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

using namespace std;

int main()
{
    string tw = "codewars";
    string mw = "codewars";
    string dw;
    mw.append(1,(char)0);
    tw.append(1,(char)255);
    dw.append(1, (char) 7);
    dw.append(1, (char) 3);
    string result;
    result.append(1, (char)21);
    string code1 = ",+[-.,+]";
    string code2 = ",[.[-],]";
    string code3 = ",>,<[>[->+>+<<]>>[-<<+>>]<<<-]>>.";
    string sol1, sol2, sol3;
    Solution obj;
    sol1 = obj.brainLuck(code1, tw);
    sol2 = obj.brainLuck(code2, mw);
    sol3 = obj.brainLuck(code3, dw);
    cout << sol1 << endl;
    cout << sol2 << endl;
    cout << sol3 << endl;
    cout << result << endl;
    return 0;
}
