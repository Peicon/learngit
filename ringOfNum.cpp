#include<iostream>
using namespace std;

typedef struct node {
    int nu;
    node* next = NULL;
}*Node;

typedef struct ring {
    int length = 0;
    Node start = NULL;
    Node px = NULL;
    Node end = NULL;
}*Ring;

bool createLT(Ring head, int len = 10);
bool insertLT(Ring head, Node pnode, int pos = 0);
bool deleteLT(Ring head, int pos = 0);
bool displayLT(Ring head);
bool destroyLT(Ring head);

int main() 
{
    Ring head = new ring;
    if (createLT(head)) {
        cout << "no problem" << endl;
    }
    else cout << "can't create!" << endl;
    displayLT(head);

    Node p1 = new node;
    p1->nu = 1;
    insertLT(head, p1, 1);
    cout << head->length << endl;
    displayLT(head);

    Node p5 = new node;
    p5->nu = 5;
    insertLT(head, p5, 5);
    cout << head->length << endl;
    displayLT(head);

    Node pp = new node;
    pp->nu = 99;
    insertLT(head, pp);
    cout << head->length << endl;
    displayLT(head);

    return 0;
}

bool createLT(Ring head, int len)
{
    if (len <= 0)
    {
        head = NULL;
        return false;
    }

    Node phead = new node;
    phead->nu = 0;
    phead->next = NULL;
    head->start = phead;
    head->px = phead;
    head->length++;

    while (len > 1) 
    {
        Node pnode = new node; 
        pnode->nu = 0;
        pnode->next = NULL;
        head->px->next = pnode;
        head->px = pnode;
        head->length++;
        len--;
    }
    head->end = head->px;

    return true;
}

bool insertLT(Ring head, Node pnode, int pos)
{
    if (pos < 0 || pos > head->length)
    {
        return false;
    }

    if (pos == 0) 
    {
        head->end->next = pnode;
        head->end = pnode;
        head->length++;
        return true;
    } 

    if (pos == 1) 
    {
        pnode->next = head->start;
        head->start = pnode;
        head->length++;
        return true;
    }

    head->px = head->start;
    while (pos-- > 2) 
    {
        head->px = head->px->next; 
    }
    pnode->next = head->px->next;
    head->px->next = pnode;
    head->length++;
    return true;
}

bool displayLT(Ring head)
{
    if (head == NULL) 
    {
        return false;
    }
    head->px = head->start;
    int n = 1;
    while (head->px != NULL)
    {
        cout << n++ << ": " << head->px->nu << " ";
        cout << endl;
        head->px = head->px->next;
    }
    cout << endl;
    return true;
}
