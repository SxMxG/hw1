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

void ULListStr::push_front(const std::string& val){
  
  if(empty()){
    Item* temp = new Item();
    temp->val[0]  = val;
    temp->first = 0;
    temp->last = 1;
    temp->prev = nullptr;
    temp->next = nullptr;
    head_ = tail_ = temp;
    size_++;
    return;
  }
  else if(head_->first == 0){
    Item* temp = new Item();
    temp->first = 9;
    temp->last = 10;
    temp->val[9]  = val;
    temp->next = head_;
    head_->prev = temp;
    head_ = temp;
    head_->prev = nullptr;
    size_++;
  }else{
    head_->val[head_->first - 1] = val;
    head_->first--;
    size_++;
  }
}

void ULListStr::push_back(const std::string& val){
  
  if(empty()){
    Item* temp = new Item();
    temp->val[0]  = val;
    temp->first = 0;
    temp->last = 1;
    temp->next = nullptr;
    temp->prev = nullptr;
    head_ = tail_ = temp;
    size_++;
    return;
  }
  else if(tail_->last == ARRSIZE) {
    Item* temp = new Item();
    temp->first = 0;
    temp->last = 1;
    temp->val[0]  = val;
    temp->prev = tail_;
    tail_->next = temp;
    tail_ = temp;
    tail_->next = nullptr;
    size_++;
  }else{
    tail_->val[tail_->last] = val;
    tail_->last++;
    size_++;
  }
}

std::string const & ULListStr::front() const{
  return head_->val[head_->first];
}

std::string const & ULListStr::back() const{
  return tail_->val[tail_->last-1];
}

void ULListStr::pop_back(){
  tail_->val[tail_->last-1] = "";
  tail_->last--;
  if(tail_->first == tail_->last){
    Item* temp = tail_;
    if(tail_->prev != nullptr){
      tail_ = tail_->prev;
      tail_->next = nullptr;
    }else{
      tail_ = nullptr;
      head_ = nullptr;
    }
    delete temp;
  }
  size_--;
}

void ULListStr::pop_front(){
  head_->val[head_->first] = "";
  head_->first++;
  if(head_->first == head_->last){
    Item* temp = head_;
    if(head_->next != nullptr){
      head_ = head_->next;
      head_->prev = nullptr;
    }else{
      head_ = nullptr;
      tail_ = nullptr;
    }
    delete temp;
    
  }
  size_--;
}

std::string* ULListStr::getValAtLoc(size_t loc) const{
  Item* temp = head_;

  for(size_t i = temp->first, it = 0; it <= loc; it++,i++){
    if(i == 10){
      temp = temp->next;
      i = 0;
    }
    if(it == loc){
      return &temp->val[i];
    } 
  }
  return NULL;
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
