#ifndef LIST_HPP
#define LIST_HPP
/* List.hpp
 *
 * doubly-linked, double-ended list with Iterator interface
 * EECS 280 Project 4
 */

#include <iostream>
#include <cassert> //assert
#include <cstddef> //NULL


template <typename T>
class List {
  //OVERVIEW: a doubly-linked, double-ended list with Iterator interface
public:
    List(){
      listSize = 0;
      first = nullptr;
      last = nullptr;
    }

    List (const List<T> &other){
      listSize = 0;
      first = nullptr;
      last = nullptr;
      copy_all(other);
    }

    List& operator=(const List<T> &other){
      if (this == &other) {
        exit(1);
      }
      clear();
      copy_all(other);
      return *this;
    }

  ~List(){
    clear();
  }

  //EFFECTS:  returns true if the list is empty
  bool empty() const {
  
    if (listSize == 0) {
        return true;
    }
    return false;
  }

  //EFFECTS: returns the number of elements in this List
  //HINT:    Traversing a list is really slow.  Instead, keep track of the size
  //         with a private member variable.  That's how std::list does it.
  int size() const{
    return listSize;
  }

  //REQUIRES: list is not empty
  //EFFECTS: Returns the first element in the list by reference
  T & front(){
    if (listSize != 0) {
      return first->datum;
    }
    else {
      throw std::runtime_error("Attempted to access front of an empty list");
    }
  }

  //REQUIRES: list is not empty
  //EFFECTS: Returns the last element in the list by reference
  T & back(){
    if (listSize != 0){
        return last->datum;
    }
    else {
        throw std::runtime_error("Attempted to access back of an empty list");
    }
  }
  

  //EFFECTS:  inserts datum into the front of the list
  void push_front(const T &datum){
    if (listSize == 0){
        Node* newNode = new Node;
        newNode->next = 0;
        newNode->prev = 0;
        newNode->datum = datum;
        first = newNode;
        last = newNode;
        listSize++;
    }
    else if (listSize >= 1){
      Node* newNode = new Node;
      newNode->next = 0;
      newNode->prev = first;
      newNode->datum = datum; 
      (*first).prev = newNode;
      first = newNode;
      listSize++;
    }
      
  }

  //EFFECTS:  inserts datum into the back of the list
  void push_back(const T &datum){
    if (listSize == 0){
        Node* oldNode = new Node; 
        oldNode->next = 0;
        oldNode->prev = 0;
        oldNode->datum = datum;
        last = oldNode;
        first = oldNode;
        listSize++;
    }
    else if (listSize >= 1){
    Node* oldNode = new Node; 
    oldNode->next = 0;
    oldNode->prev = last;
    oldNode->datum = datum;
    (*last).next = oldNode;
    last = oldNode;
    listSize++;
    }
  }
  //REQUIRES: list is not empty
  //MODIFIES: may invalidate list iterators
  //EFFECTS:  removes the item at the front of the list
  void pop_front(){
  Node *delet = first;
    if (listSize > 1){
       first = delet->next;
       first->prev = nullptr;
       listSize--;
       delete delet;
    }
    else if(listSize == 1){
      delete delet;
      first = nullptr;
      last = nullptr;
      listSize--;
    }
  }

  //REQUIRES: list is not empty
  //MODIFIES: may invalidate list iterators
  //EFFECTS:  removes the item at the back of the list
  void pop_back(){
    Node *delet = last;
    if (listSize > 1){
       last = delet->prev;
       last->next = nullptr;
       listSize--;
       delete delet;
    }
    else if(listSize == 1){
      delete delet;
      first = nullptr;
      last = nullptr;
      listSize--;
    }
  }

  //MODIFIES: may invalidate list iterators
  //EFFECTS:  removes all items from the list
  void clear(){ //help
    while (listSize != 0){
      pop_back();
    }
  }
  

  // You should add in a default constructor, destructor, copy constructor,
  // and overloaded assignment operator, if appropriate. If these operations
  // will work correctly without defining these, you can omit them. A user
  // of the class must be able to create, copy, assign, and destroy Lists

private:
  //a private type
  struct Node {
    Node *next;
    Node *prev;
    T datum;
  };

  //REQUIRES: list is empty
  //EFFECTS:  copies all nodes from other to this
  void copy_all(const List<T> &other){
    if(listSize == 0){
      Node* target = other.first;
      while (target != nullptr){
        this->push_back(target->datum);
        target = target->next;
      }
    }
  }

  Node *first;   // points to first Node in list, or nullptr if list is empty
  Node *last;    // points to last Node in list, or nullptr if list is empty
  int listSize;  

public:
  ////////////////////////////////////////
  class Iterator {
    //OVERVIEW: Iterator interface to List

    // You should add in a default constructor, destructor, copy constructor,
    // and overloaded assignment operator, if appropriate. If these operations
    // will work correctly without defining these, you can omit them. A user
    // of the class must be able to create, copy, assign, and destroy Iterators.

    // Your iterator should implement the following public operators: *,
    // ++ (prefix), default constructor, == and !=.

  public:
    
    Iterator(){
      node_ptr = nullptr;
    }
  
  // This operator will be used to test your code. Do not modify it.
    // Requires that the current element is dereferenceable.
    Iterator& operator--() {
      assert(node_ptr);
      node_ptr = node_ptr->prev;
      return *this;
    }

    Iterator& operator++(){
      assert(node_ptr);
      node_ptr = node_ptr->next;
      return *this;
    }

    bool operator==(const Iterator &other) const{
      return this->node_ptr == other.node_ptr;
      
    }
    T& operator*(){
      return node_ptr->datum;
    }
    bool operator!=(const Iterator &other) const{
      return this->node_ptr != other.node_ptr;
    }


  private:
    Node *node_ptr; //current Iterator position is a List node
    // add any additional necessary member variables here
    friend class List;
    // add any friend declarations here

    // construct an Iterator at a specific position
    Iterator(Node *node){
      node_ptr = node;
    }
    
  };//List::Iterator
  ////////////////////////////////////////

  // return an Iterator pointing to the first element
  Iterator begin() const {
    return Iterator(first);
  }

  // return an Iterator pointing to "past the end"
  Iterator end() const {
    return (Iterator(nullptr));
  }

  //REQUIRES: i is a valid, dereferenceable iterator associated with this list
  //MODIFIES: may invalidate other list iterators
  //EFFECTS: Removes a single element from the list container
  void erase(Iterator i){
    if (empty()){
      return;
    }
    if (i.node_ptr != nullptr){
      Node *delet = i.node_ptr;
      if (delet == first){
      pop_front();
      }
      else if (delet == last){
        pop_back();
      }
      else{
        delet->prev->next = delet->next;
        delet->next->prev = delet->prev;
        listSize--;
        delete delet;
        
      }
      
    }
  }

  //REQUIRES: i is a valid iterator associated with this list
  //EFFECTS: inserts datum before the element at the specified position.
  void insert(Iterator i, const T &datum){
      Node *add = i.node_ptr;
      if ((add == first) || (add == nullptr)){
        push_front(datum);
      }
      else if (add == last){
        push_back(datum);
      }
      else{
        Node *newNode = new Node;
        newNode->prev = add->prev;
        newNode->next = add;
        newNode->datum = datum;
        add->prev->next = newNode;
        add->prev = newNode;
        listSize++;
      }
    }

  

};
#endif