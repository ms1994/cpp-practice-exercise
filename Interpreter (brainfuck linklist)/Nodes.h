#ifndef NODES_H
#define NODES_H
#include <iostream>
#include <string>

using namespace std;


class Nodes
{
    struct Node //crear una link list para el brainfuck
{
    int value;
    Node* next;
};
    Node* Head = NULL; //el header del link list // nunca se modifica
    public:
        Nodes();
        void push_final();
        void insert_begin();
        void fill();
        void print();
        void deleteCells();
        void initialization(Node **Head, Node **left, Node **current, Node **right);
        string brainLuck(const string &code, const string &input);
        int countSpaceLoop(string code, int indexCode);
    protected:
    private:
};

#endif // NODES_H
