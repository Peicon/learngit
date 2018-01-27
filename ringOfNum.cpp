#include<iostream>
using namespace std;

struct node {
    int nu;
    node* next = NULL;
};

struct node2 {
    int nu;
    node2 *next1 = NULL;
    node2 *next2 = NULL;
};

int main() 
{
    node *head = NULL;
    node n1, n2;
    n1.nu = 0, n2.nu = 1;
    head = &n1;
    n1.next = &n2;

    while (head != NULL)
    {
        cout << head->nu << " ";
        cout << endl;
        head = head->next;
    }
    return 0;
}
