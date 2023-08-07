#include <bits/stdc++.h>

using namespace std;


void update(int indexSp, vector<int>  &tree, string &sp, unordered_map<int, int> &indexTree, unordered_map<int, int> &indexS);
void changeTree(int index, int indexTree, string &sp, vector<int> &tree);


int main()
{
    int k;
    cin >> k;
    int n = pow(2,k-1);
    string sp;
    cin >> sp;
    int lenSp = sp.length();
    unordered_map <int, int> indexS;
    unordered_map <int, int> indexTree;
    vector <int> tree(2*n);
    for (int i = 0; i < n; i++)
    {
        indexS[i] = n+i;
        indexTree[n+i] = i;
        if (sp[i]=='?') tree[n+i] = 2;
        else tree[n+i] = 1;
    }
    for (int j = k-2; j>=1; j--)
    {
        int n2 = pow(2,j);
        for (int i = 0; i < n2; i++)
        {
            indexS[n+i] = n2+i;
            indexTree[n2+i] = n+i;
            changeTree(n+i,n2+i,sp,tree);
        }
        n += n2;
    }
    indexS[lenSp-1] = 1;
    indexTree[1] = lenSp-1;
    changeTree(lenSp-1,1,sp,tree);
    int q;
    cin >> q;
    while(q--)
    {
        int p;
        char c;
        cin >> p >> c;
        p--;
        sp[p] = c;
        update(p, tree, sp,indexTree,indexS);
        cout << tree[1] << endl;
    }
}

void changeTree(int index, int indexTree, string &sp, vector<int> &tree)
{
    if (2*indexTree < tree.size())
    {
        if (sp[index] == '1')
        {
            tree[indexTree] = tree[2*indexTree+1];
        }
        if (sp[index] == '0')
        {
            tree[indexTree] = tree[2*indexTree];
        }
        if (sp[index] == '?')
        {
            tree[indexTree] = tree[2*indexTree] +tree[2*indexTree+1];
        }
    }
    else
    {
        if (sp[index] == '?') tree[indexTree] = 2;
        else tree[indexTree] = 1;
    }

}


void update(int indexSp,vector<int> &tree, string &sp, unordered_map<int, int> &indexTree, unordered_map<int, int> &indexS)
{
    int indexT = indexS[indexSp];
    //acomodar
    for (int i = indexT; i>= 1; i /= 2)
    {
        int index = indexTree[i];
        changeTree(index,i,sp,tree);
    }
}
