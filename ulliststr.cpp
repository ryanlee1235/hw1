#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"
#include <iostream>

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

/**
  * Adds a new value to the back of the list
  *   - MUST RUN in O(1)
  */
void ULListStr::push_back(const std::string& val)
{
  if(tail_ == NULL)
  {
    Item* newNode = new Item();
    tail_ = newNode;
    head_ = newNode;
    newNode->next = NULL;
    newNode->prev = NULL;
    //tail_->first = 0;
    //tail_->last = 1;
    //tail_->val[tail_->last - 1] = val;
  }
  if(tail_->last == 10)
  {
    //std::cout << "New node created" << std::endl;
    Item* newNode = new Item();
    tail_->next = newNode;
    newNode->prev = tail_;
    tail_ = newNode;
    tail_->next = NULL;
    push_back(val);
  }
  else
  {
    tail_->val[tail_->last] = val;
    (tail_->last)++;
    //std::cout << "last var is now: " << tail_->last << std::endl;
    size_++;
  }
  
}

/**
  * Removes a value from the back of the list
  *   - MUST RUN in O(1)
  */
void ULListStr::pop_back()
{
  if(tail_->last != tail_->first)
  {
    tail_->last--;
    size_--;
  }
  if(tail_->last == tail_->first)
  {
    if(head_ != tail_)
    {
      Item* temp = tail_;
      tail_ = tail_->prev;
      tail_->next = NULL;
      delete temp;
    }
    else
    {
      Item* temp = tail_;
      delete temp;
      tail_ = NULL;
      head_ = NULL;
      size_ = 0;
    }
    //pop_back();
  }
}

/**
  * Adds a new value to the front of the list.
  * If there is room before the 'first' value in
  * the head node add it there, otherwise, 
  * allocate a new head node.
  *   - MUST RUN in O(1)
  */
void ULListStr::push_front(const std::string& val)
{
  if(head_ == NULL)
  {
    Item* newNode = new Item();
    tail_ = newNode;
    head_ = newNode;
    newNode->next = NULL;
    newNode->prev = NULL;
    head_->first = 10;
    head_->last = 10;
    // nullcase = false;
  }
  if(head_->first == 0)
  {
    Item* newNode = new Item();
    newNode->next = head_;
    head_->prev = newNode;
    head_ = newNode;
    head_->prev = NULL;
    head_->first = 10;
    head_->last = 10;
    push_front(val);
  }
  else
  {
    head_->val[head_->first - 1] = val;
    (head_->first)--;
    size_++;
  }

}

/**
  * Removes a value from the front of the list
  *   - MUST RUN in O(1)
  */
void ULListStr::pop_front()
{
  if(head_->first != head_->last) 
  {
    head_->first++;
    size_--;
  }
  if(head_->first == head_->last)
  {
    if(head_ != tail_)
    {
      Item* temp = head_;
      head_ = head_->next;
      head_->prev = NULL;
      delete temp;
    }
    else
    {
      Item* temp = head_;
      delete temp;
      tail_ = NULL;
      head_ = NULL;
      size_ = 0;
    }
    //pop_front();
  }
}

/**
  * Returns a const reference to the back element
  *   - MUST RUN in O(1)
  */
std::string const & ULListStr::back() const
{
  if(tail_ == NULL)
  {
    return NULL;
  }
  //std::cout << "tail_->val[(tail_->last) - 1]: " << tail_->val[(tail_->last) - 1] << std::endl;
  //std::cout << "tail_->last: " << tail_->last << std::endl;
  //std::cout << "tail_ = 0: " << tail_->val[0] << std::endl;
  return tail_->val[(tail_->last) - 1];
}

/**
  * Returns a const reference to the front element
  *   - MUST RUN in O(1)
  */
std::string const & ULListStr::front() const
{
  if(head_ == NULL)
  {
    return NULL;
  }
  return head_->val[head_->first];
}

/** 
  * Returns a pointer to the item at index, loc,
  *  if loc is valid and NULL otherwise
  *   - MUST RUN in O(n) 
  */
std::string* ULListStr::getValAtLoc(size_t loc) const
{
  if (loc < 0 || loc >= size_)
  {
    return NULL;
  }
  int index = head_->first + (int)loc;
  int nodenum = (index / 10);
  int nodeindex = (index % 10);
  Item* temp = head_;
  for(int i = 0; i < nodenum; i++)
  {
    temp = temp->next;
  }
  return &(temp->val[nodeindex]);

}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
