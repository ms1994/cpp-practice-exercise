#include "Nodes.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;


Nodes::Nodes()
{
    //ctor
}
string Nodes::brainLuck(const string &code, const string &input)
{
    string outp1 = "";
    if (code.length() == 0) return outp1;
    fill();
    int i = 0;
    int spaceLoop = 0;
    int indexInput = 0;
    Node *current, *left, *right;
    initialization(&Head, &left, &current, &right);
    while(i < code.length()){
        char symbol = code[i];
        if (symbol == '<'){
            right = current;
            current = left;
            if (left == Head){
                while(left->next != NULL)
                    left = left->next;
            }
            else {
                left = Head;
                while(left->next != current)
                    left = left->next;
            }
        }
        if (symbol == '>') {
            left = current;
            current = right;
            if (right->next == NULL)
                right = Head;
            else right = right->next;
        }
        if (symbol == '[' && current->value == 0){
            spaceLoop = countSpaceLoop(code, i);
            i = i + spaceLoop;
        }
        if (symbol == ']' && current->value != 0){
            spaceLoop = countSpaceLoop(code, i);
            i = i - spaceLoop;
        }
        if (symbol == '+')
            current->value = (current->value +1) % 256;
        if (symbol == '-')
            current->value = (current->value -1) % 256;
        if (symbol == ','){
            current->value = (int) input[indexInput];
            size_t inpLen = input.length();
            indexInput++;
            indexInput %= inpLen;
        }
        if (symbol == '.'){
            char response = (char) current->value;
            outp1 += response;
        }
        i++;
    }
    return outp1;
}

void Nodes::initialization(Node **Head, Node **left, Node **current, Node **right){
    *current = (*Head);
    *right = (*current)->next;
    *left = (*Head);
    while((*left)->next != NULL)
        *left = (*left)->next;
}

int Nodes::countSpaceLoop(string code, int indexCode)
{
    int cont = 0;
    int countBrackets = 0;
    if (code[indexCode] == '[' && cont == 0) {
         while (indexCode < code.length()){
            char symbol = code[indexCode];
            if (symbol =='[' && cont > 0)
            {
                countBrackets++;
            }
            if (symbol != ']'){
                indexCode++;
                cont++;
            }
            else if(countBrackets == 0) {
                return cont;
            }
            else {
                indexCode++;
                cont++;
                countBrackets--;
            }
        }
    }
    if (code[indexCode] == ']' && cont == 0)
    {
        while (indexCode < code.length()){
            char symbol = code[indexCode];
            if (symbol ==']' && cont > 0)
            {
                countBrackets++;
            }
            if (symbol != '['){
                indexCode--;
                cont++;
            }
            else if(countBrackets == 0) {
                return cont;
            }
            else {
                indexCode--;
                cont++;
                countBrackets--;
            }
        }
    }

    return cont;
}

void Nodes::push_final(){
    Node* node = new Node();
    node->value = 1;//se puede insertar el valor o hacer que la funcion resiba un nodo
    node->next = NULL;
    Node* temp = Head; //para insertar al final del list
    while(temp->next != NULL){
        temp = temp->next; //me lleva hasta el ultimo node
    }
    temp->next = node;//el node se pasa como parametro o se crea en la funcion y se pasa el valor

}

  void Nodes::insert_begin(){
    Node* node = new Node();
    node->value = 0;//pongo como parametro el valor que quiero insertar
    node->next = Head;
    Head = node;
  }
  void Nodes::fill(){
    for (int i = 0; i < 1000; i++){
        insert_begin();
       // push_final(); //debe tener la lista algun elemento para ejecutar este metodo
    }
  }
void Nodes::print(){
    Node* n2 = Head;
    while (n2 != NULL){//me paro en el ultimo node y no lo reviso por eso se coloca n2 != null
        cout << n2->value << " ";
        n2 = n2->next;
    }
}

void Nodes::deleteCells()
{
    for (int i = 0; i < 3000; i++){
        Node *temp = new Node();
        temp = Head;
        Head = Head->next;
        delete temp;
    }
}

