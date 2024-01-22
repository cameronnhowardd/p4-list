#include <iostream>
#include <string> 
#include <cassert> 
#include <sstream>
#include <utility>



template <typename T>
class List {
  //OVERVIEW: a doubly-linked, double-ended list with Iterator interface
public:
    List(): listSize(0), first(nullptr), last(nullptr) {};
    
  //EFFECTS:  returns true if the list is empty
  bool empty() const{
  
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
      if (first != nullptr){
        return first->datum;
    }
  }

  //REQUIRES: list is not empty
  //EFFECTS: Returns the last element in the list by reference
  T & back(){
    if (last != nullptr){
        return last->datum;
    }
  }
  

  //EFFECTS:  inserts datum into the front of the list
  void push_front(const T &datum){
    if (listSize == 0){
        Node newNode = {0, 0, datum};
        first = &newNode;
        last = &newNode;
    }
    else if (listSize >= 1){
    Node newNode = {0, first, datum};
    (*first).prev = &newNode;
    first = &newNode;
    }
    listSize++;
  }

  //EFFECTS:  inserts datum into the back of the list
  void push_back(const T &datum){
    if (listSize == 0){
        Node oldNode = {0, 0, datum};
        last = &oldNode;
        first = &oldNode;
        listSize++;
    }
    else if (listSize >= 1){
    Node oldNode = {last, 0, datum};
    (*first).prev = &oldNode;
    *last = oldNode;
    listSize++;
    }
    
  
  }
  //REQUIRES: list is not empty
  //MODIFIES: may invalidate list iterators
  //EFFECTS:  removes the item at the front of the list
  void pop_front(){
    if (listSize != 0){
       Node *delet = first;
       first = delet->next;
       listSize--;
       
  }
  
  }

  //REQUIRES: list is not empty
  //MODIFIES: may invalidate list iterators
  //EFFECTS:  removes the item at the back of the list
  void pop_back(){
    if (listSize != 0){
       Node *delet = last;
       last = delet->prev;
       listSize--;
  }
  
  }

  //MODIFIES: may invalidate list iterators
  //EFFECTS:  removes all items from the list
  void clear(){
    if(listSize != 0){
      Node *nodeDelete = first;
      while (nodeDelete != nullptr){
      Node *nextNode = nodeDelete->next;
      nodeDelete = nextNode;
      listSize--;
    }
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
    // This operator will be used to test your code. Do not modify it.
    // Requires that the current element is dereferenceable.
    Iterator& operator--() {
      assert(node_ptr);
      node_ptr = node_ptr->prev;
      return *this;
    }

  private:
    Node *node_ptr; //current Iterator position is a List node
    // add any additional necessary member variables here

    // add any friend declarations here

    // construct an Iterator at a specific position
    Iterator(Node *p);

  };//List::Iterator
  ////////////////////////////////////////

  // return an Iterator pointing to the first element
  Iterator begin() const {
    return Iterator(first);
  }

  // return an Iterator pointing to "past the end"
  Iterator end() const;

  //REQUIRES: i is a valid, dereferenceable iterator associated with this list
  //MODIFIES: may invalidate other list iterators
  //EFFECTS: Removes a single element from the list container
  void erase(Iterator i);

  //REQUIRES: i is a valid iterator associated with this list
  //EFFECTS: inserts datum before the element at the specified position.
  void insert(Iterator i, const T &datum);

};//List

int main() {
    List<int> ex;
    std::cout << "empty() test should return 1: " << ex.empty() << std::endl;
    std::cout << "listSize test: should return 0: " << ex.size() << std::endl;
    int myInteger = 42;
    ex.push_back(myInteger);
    std::cout << "num" << ex.front() << std::endl;
    std::cout << "listSize test: should return 1: " << ex.size() << std::endl;
    std::cout << "num" << ex.back() << std::endl;
    int x = 41;
    ex.push_front(x);
    std::cout << "num" << ex.front() << std::endl;
    ex.pop_front();
    std::cout << "num" << ex.front() << std::endl;
    ex.pop_back();
    std::cout << "listSize" << ex.size() << std::endl;
    int y = 1;
    int a = 2;
    int b = 3;
    int c = 4;
    ex.push_back(y);
    ex.push_back(a);
    ex.push_back(b);
    ex.push_back(c);
    ex.clear();
    std::cout << "listSize" << ex.size() << std::endl;





}