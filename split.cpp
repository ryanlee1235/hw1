/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/
#include "split.h"


/* Add a prototype for a helper function here if you need */
Node* pop_front(Node*& in);

void rec_push_back(Node*& target, Node*& list);

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
// WRITE YOUR CODE HERE
  if(in != nullptr)
  {
    Node* val = pop_front(in);
    if(val->value % 2 == 0)
    {
      rec_push_back(evens, val);

      split(in, odds, evens);
    }
    else
    {
      rec_push_back(odds, val);

      split(in, odds, evens);
    }
  }
}

/* If you needed a helper function, write it here */
Node* pop_front(Node*& in)
{
  if(in)
  {
    Node* temp = in;
    in = in->next;
    return temp;
  }
  return in;
}

void rec_push_back(Node*& target, Node*& list)
{
  if(target == nullptr)
  {
    target = list;

    target->next = nullptr;
  }
  else if(target->next == nullptr)
  {
    target->next = list;
    target->next->next = nullptr;
  }
  else
  {
    rec_push_back(target->next, list);
  }
}