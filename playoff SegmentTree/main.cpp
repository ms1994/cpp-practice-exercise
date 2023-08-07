#include <bits/stdc++.h>

using namespace std;


void changeTree2(int index, int indexTree, string &sp, vector<int> &tree);


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k;
    cin >> k;
    int n = pow(2,k);
    string sp;
    cin >> sp;
    int lenSp = sp.length();
    vector <int> tree(2*n, 1);
    reverse(sp.begin(),sp.end());
     auto changeTree = [&](int index, int indexTree) {
            if (sp[index] == '1')
            {
                return tree[indexTree] = tree[2*indexTree];
            }
            else if (sp[index] == '0')
            {
                return tree[indexTree] = tree[2*indexTree+1];
            }
            else
            {
                return tree[indexTree] = tree[2*indexTree] +tree[2*indexTree+1];
            }
    };
    for (int i = n-1; i >=1; i--)
    {
        changeTree(i-1,i);
    }
    int q;
    cin >> q;
    while(q--)
    {
        int p;
        char c;
        cin >> p >> c;
        p = lenSp-p;
        sp[p] = c;
        changeTree2(p,p+1,sp,tree);
        cout << tree[1] << endl;
    }
}

void changeTree2(int index, int indexTree, string &sp, vector<int> &tree)
{
        if (indexTree == 0 ) return;
        if (sp[index] == '1')
        {
            tree[indexTree] = tree[2*indexTree];
        }
        else if (sp[index] == '0')
        {
            tree[indexTree] = tree[2*indexTree+1];
        }
        else
        {
            tree[indexTree] = tree[2*indexTree] +tree[2*indexTree+1];
        }
        int aux = indexTree/2;
        changeTree2(aux-1, aux, sp, tree);
}

