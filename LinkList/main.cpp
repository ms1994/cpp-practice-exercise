#include <bits/stdc++.h>
using namespace std;

#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}
typedef long long ll;
/*
Mi sol para reverse a link list: traverse the link list dada y insertar cada node al inicio de otra link list.
Es decir, guardo las valores de link list que nos dan y los inserto al inicio de una nueva link list, con otra valor de head
y print esa nueva link list.

Reversed Editorial: Necesitamos dos pointers, un next que apunte a temp->next (en mi codigo, tambien llamado current)
y el prev que apunte al current, pero antes de asignar el prev debemos primero mover el pointer del temp (current) al prev
temp->next = prev, y luego ponemos el prev = temp. Por ultimo temp apunta a next.


temp = (*head)
while (temp != NULL) {

    next = temp->next;
    temp->next = prev;
    prev = temp;
    temp = next;
}
(*head) = prev;

Cuando hacemos un traverse de linklist si hacemos el while hasta temp->next != null, significa que vamos a recorrer hasta el
penultimo elemento, lo que es util cuando queremos insertar un elemento en ese node (push Method). Sin embargo cuando
queremos hacer el traverse completo como en el print y el reverse method debemos recorrer hasta que temp !== null
es decir recorre toda la link list.

El push method cuando head == null debemos poner una condicional e insertar el primer node en el head. head = new_node

Cuando insertamos al inicio debemos apuntar el new_node al head.

El zipzap link list seria dos link list que vamos uniendo un elemento de una con un elemento de la otra.

Tendrías dos link list con dos head y dos temp para traverse ambos y cuando uno sea null sale del loop y
decimos que el temp != null, ese temp lo uniremos a la link list sol. Podemos iniciar nuestra link list solucion
con el head1 porque debemos empezar con la primera list, y con un contador (even or odd) decidemos cuando tomo
un valor de la list1 y aumento el temp1 o la list2 con el temp2.

node *sol = (*head1)
node *temp1 = (*head1)
node *temp2 = (*head2)
int cont = 0;
while (temp1 != null && temp2 != null)
{
    if (!cont % 2)
    {
        sol->next = temp2;
        temp2 = temp2->next;
    }
    else {
        sol->next = temp1;
        temp1 = temp1->next;
    }
    cont++;
    sol = sol->next;
}
if (temp1 != null)
{
    sol->next = temp1;
}
if (temp2 != null)
{
    sol->next = temp2
}
//si paso el pointer de sol a la funcion no tengo que retornar nada.
return sol

*/

struct node{
    int value;
    node *next;
};

void insertNode(node **head, int val)
{
    node *temp = new node();
    temp->value = val;
    temp->next = (*head);//el nuevo node no apunta a null, sino a la head, en el isert begining
    (*head) = temp;
// H -> node1 -> node2
// temp -> head = H-> node1 -> node2, temp->node1
//head->temp = H -> temp -> node1 -> node2
}

void pushNode(node **head)
{
    for (int i = 0; i < 5; i++)
    {
        int val;
        cin >> val;
        node *node1 = new node();
        node1->value = val;
        node1->next = NULL;
        node *temp = (*head);
        if ( (*head) == NULL)
        {
            (*head) = node1;
            continue;
        }
        while(temp->next != NULL)
        {
           temp = temp->next;
        }
        temp->next = node1;
    }
}

void print(node **head)
{
    node *temp = (*head);
    while(temp->next != NULL)
    {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << temp->value<<endl;
}

void reversed(node **head)
{
    node *next = NULL;
    node *prev = NULL;
    node *temp = (*head);
    while (temp != NULL)
    {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    (*head) = prev;
}

int main()
{
    send help
    node *head = NULL;
    pushNode(&head);
    /*node *temp = head;
    node *head2 = NULL;
    while (temp != NULL)
    {
        insertNode(&head2, temp->value);
        temp = temp->next;
    }*/
    reversed(&head);
    print(&head);
    cout << "Hello world!" << endl;
    return 0;
}
