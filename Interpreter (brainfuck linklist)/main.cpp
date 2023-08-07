#include <iostream>
#include <string>
#include "Nodes.h"
using namespace std;
struct Node //crear una link list para el brainfuck
{
    int value;
    Node* next;
};
void print2(Node *Head){
    Node* n2 = Head;
    while (n2 != NULL){
        cout << n2->value << " ";
        n2 = n2->next;
    }
}

void initialization(Node **Head, Node **left, Node **current, Node **right){
    *current = (*Head);//desreferenciar un pointer de un pointer
    *right = (*current)->next;//se coloca el parentesis porque el pointer tiene una menor procedencia que el ->
    *left = (*Head);//forma de trabajar con pointers de pointer
    while((*left)->next != NULL)
        *left = (*left)->next;
}
int main()
{
    //para insertar valores se utiliza el temp = new node
    //para crear un nuevo nodo y asignarle un valor
    //luego con el while y otro temp1 viajo a traves del link list hasta el pointer null
    // y se asigna temp1 -> next = temp (el nodo con el nuevo valor)
    //una link list solo puede viajar hacia delante
    //Para iterar e ir back and forth en la link list se utilizan los pointer prev next y current
    //con recursion solo se usan dos pointer q y p
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
    Nodes obj;
    sol1 = obj.brainLuck(code1, tw);
    sol2 = obj.brainLuck(code2, mw);
    sol3 = obj.brainLuck(code3, dw);
    cout << sol1 << endl;
    cout << sol2 << endl;
    cout << sol3 << endl;
    cout << result << endl;


    //tw.append(1, (char) 255);
    //obj.print();
   //string out2 = "";
   //out2 = obj.brainLuck(",[.[-],]", tw2);
   //out.append(1, conv);
   //cout << current->value << " ";
  // cout << conv << endl;
    //cout << out2 << endl;

    //cout << "algo" << "  " << 345 % 256 << endl;

    return 0;
}
