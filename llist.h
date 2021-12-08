//CS311 Yoshii
//INSTRUCTION:
//Llist class - header file template 
//You must complete the ** parts and then complete llist.cpp
//Don't forget PURPOSE and PARAMETERS 

// =======================================================
// HW#: HW3P1 llist
// Your name: Ting Wei Chien
// Compiler:  g++ 
// File type: headher file  llist.h
//=======================================================

#include "elem.h"

// alias el_t : element type def
// el_t Elem;  // int for now but can change later

//a list node is defined here as a struct Node for now
struct Node
{
  el_t Elem;   // elem is the element stored
  Node *Next;  // next is the pointer to the next node
};
//---------------------------------------------------------

class llist
{
 protected:
  Node *Front;       // pointer to the front node
  Node *Rear;        // pointer to the rear node
  int  Count;        // counter for the number of nodes

  // untility function to move to a specified node position
  void moveTo(int, Node*&);
  
 public:

  // Exception handling classes 
  class Underflow{};
  class OutOfRange{};  // thrown when the specified Node is out of range

  llist ();     // constructor to create a list object
  ~llist();     // destructor to destroy all nodes
  
  //return true if the list is empty, otherwise false
  bool isEmpty();
    
  //display all elements in the list
  void displayAll();

  //add an element to the front of the list
  void addFront(el_t);
    
  //add an element to the rear of the list
  void addRear(el_t);

  //delete an element from the front of the list
  void deleteFront(el_t&);
    
  //delete an element from the rear of the list
  void deleteRear(el_t&);
  
  //delete Ith element in the list
  void deleteIth(int, el_t&);  // calls moveTo

  //sdd sn element to the list before that Ith element
  void insertIth(int, el_t);   // calls moveTo

  //Copy Constructor to allow pass by value and return by value of a llist
  llist(const llist&);
  
  //Overloading of = (returns a reference to a llist)
  llist& operator=(const llist&); 

};
