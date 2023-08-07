#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node (int val)
{
    data = val;
    left = NULL;
    right = NULL;
}

};

class Solution
{
    map <int, int> positions;
    vector <int> permutation;
public:
    void maxValue(int ant, int sup, vector<int> a)
    {
        int mx = -1;
        for (int i = ant; i < sup; i++)
        {
            if (a[i] > mx) mx = a[i];
        }
        int pos = find(a.begin(), a.end(), mx) - a.begin();
        positions[mx] = pos;
        permutation.push_back(mx);
        if (pos - 1 >= 0 && pos - 1 >= ant) maxValue(ant, pos, a);
        if (pos + 1 != sup && pos < sup) maxValue(pos + 1, sup, a);
        return;
    }
    void createTree (vector <int> a)
    {
        Node* root = NULL;
        for (auto it: permutation)
        {
            root = insertNode(root, it);
        }
        //preOrder(root);
        //cout << endl;
        for (int i: a) printDeep(root, i, 0);
    }
    Node* insertNode(Node* root, int val)
    {
            if (root == NULL) root = new Node(val);
            else if (positions[val] < positions[root->data]) root->left = insertNode(root->left, val);
            else root->right = insertNode(root->right, val);
            return root;
    }
    void preOrder (Node* root)
    {
        if (root == NULL) return;
        printf("%d ", root->data);//el inOrder el printf va debajo del root->left
        preOrder(root->left);
        preOrder(root->right);//el postOrder el printf va despues del root->right o sea al final
    }
    void printDeep(Node* root, int val, int deep)
    {
        if (root == NULL) return;
        if (root->data == val)
        {
            printf("%d ", deep);
            return;
        }
        deep++;
        printDeep(root->left, val, deep);
        printDeep(root->right, val, deep);
    }
    void printPermutation ()
    {
        for (auto it: permutation) printf("%d ", it);
    }
};


int main()
{

    int n;
    scanf("%d", &n);
    vector <int> a(n);
    for (int &x :a) scanf("%d", &x);
    Solution obj;
    obj.maxValue(0,n,a);
    //obj.printPermutation();
    //cout << endl;
    obj.createTree(a);
    return 0;
}
