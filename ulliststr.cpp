#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

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
  Item* temp = new Item();
  temp->val  = val;
  if(empty()){
    head_ = tail_ = temp;
    size_++;
    return;
  }
  else{
    temp->next = head_;
    head_->prev = temp;
    head_ = temp;
    size_++;
  }
}

void ULListStr::push_back(const std::string& val){
  Item* temp = new Item();
  temp->val  = val;
  if(empty()){
    head_ = tail_ = temp;
    size_++;
    return;
  }
  else{
    temp->prev = tail_;
    tail_->next = temp;
    tail_ = temp;
    size_++;
  }
}

std::string const & ULListStr::front() const{
  return head_->val;
}

std::string const & ULListStr::back() const{
  return tail_->val;
}


std::string* ULListStr::getValAtLoc(size_t loc) const{
  Item* temp = new Item();
  temp = head_;
  for(int i = 0; i < loc;i++){
    temp = temp->next;
  }
  return temp->val;
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
