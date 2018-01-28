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
bool insertLT(Ring head, int pos);
bool deleteLT(Ring head, int pos);
bool displayLT(Ring head);
bool destroyLT(Ring head);

int main() 
{
    Ring head = new ring;
    if (createLT(head)) {
        cout << "no problem" << endl;
    }
    else cout << "can't create linked table!" << endl;
    head->px = head->start;
    while (head->px != NULL)
    {
        cout << head->px->nu << " ";
        cout << endl;
        head->px = head->px->next;
    }
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
        cout << "so so" << endl;
        Node pnode = new node; 
        pnode->nu = 0;
        pnode->next = NULL;
        head->px->next = pnode;
        head->px = pnode;
        head->length++;
        len--;
    }

    return true;
}
