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
  
  if(empty()){
    Item* temp = new Item();
    temp->val[0]  = val;
    temp->first = 0;
    temp->last = 1;
    head_ = tail_ = temp;
    size_++;
    return;
  }
  else if(head_->first == 0){
    Item* temp = new Item();
    temp->first = 9;
    temp->last = 10;
    temp->val[temp->last-1]  = val;
    temp->next = head_;
    head_->prev = temp;
    head_ = temp;
    size_++;
  }else{
    head_->val[head_->first - 1] = val;
    head_->first--;
  }
}

void ULListStr::push_back(const std::string& val){
  
  if(empty()){
    Item* temp = new Item();
    temp->val[9]  = val;
    temp->first = 9;
    temp->last = 10;
    head_ = tail_ = temp;
    size_++;
    return;
  }
  else if(tail_->last == ARRSIZE) {
    Item* temp = new Item();
    temp->val[0]  = val;
    temp->prev = tail_;
    tail_->next = temp;
    tail_ = temp;
    size_++;
  }else{
    tail_->val[tail_->last+1] = val;
    tail_->last++;
  }
}

std::string const & ULListStr::front() const{
  return head_->val[head_->first];
}

std::string const & ULListStr::back() const{
  return tail_->val[tail_->last];
}

void ULListStr::pop_back(){
  if(tail_->last == 1){
    //if there is only one like object in list at beginning but at end of whole list
  }else{
    tail_->val[tail_->last] = NULL;
    tail->last--; 
  }
}

void ULListStr::pop_front(){
  if(tail_->last == 1){
    //if there is only one like object in list at end but at the beginning of whole list
  }else{
    head_->val[head_->first] = NULL;
    head_->first--; 
  }
}

std::string* ULListStr::getValAtLoc(size_t loc) const{
  Item* temp = head_;
  for(int i = temp->first, it = 0; it <= loc; it++,i++){
    if(i == 9){
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
