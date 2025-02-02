/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include <iostream>
using namespace std;
#include "split.h"


void printList(Node* head)
{
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main(int argc, char* argv[])
{
  Node* node6 = new Node(6, nullptr);
  Node* node5 = new Node(5, node6);
  Node* node4 = new Node(4, node5);
  Node* node3 = new Node(3, node4);
  Node* node2 = new Node(2, node3);
  Node* node1 = new Node(1, node2);
  Node* head = node1;

  Node* evens = nullptr;
  Node* odds = nullptr;
  cout << "in list before: ";
  printList(head);
  cout << endl;

  cout << "odds list before: ";
  printList(odds);
  cout << endl;

  cout << "evens list before: ";
  printList(evens);
  cout << endl;

  split(head, odds, evens);

  cout << "in list after: ";
  printList(head);
  cout << endl;

  cout << "odds list after: ";
  printList(odds);
  cout << endl;

  cout << "evens list after: ";
  printList(evens);
  cout << endl;

}
