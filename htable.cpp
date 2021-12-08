// CS311 Yoshii - Hash Table - complete all ** parts.
// Note: this class does not know the parts of element except for key
// so that it would work even if each element in the hash table changed
//-----------------------------------------------------

// ============================================
// HW#: HW8 Hash Table
// Name: Ting Wei Chien
// File Type: implementation htable.cpp
// =============================================

using namespace std;
#include <iostream>
#include "htable.h"
#include <fstream>


htable::htable()
{}

htable::~htable()
{}

// a simple hash function that uses % TSIZE simply
int htable::hash(int key){
  
  int first = (key/10000)%10; //first digit
  int mid = (key/10)%1000; // middle 3 digits
  int last = key%10; // last digit

  return (first+mid+last) % TSIZE;  //key mod table size
}

// adds the element to the table and returns slot#
int htable::add(el_t element ){

  int slot = hash(element.getkey());  // hash with the key part
  // ** Note that this means adding the element to a slist in the slot (addRear)
  table[slot].addRear(element);
  return slot;
}

//remove an element from the table
int htable::deleteIt(el_t element){
 
  int slot = hash (element.getkey()); // hash with the key part
  table[slot].deleteRear(element); // detelt the element from a slist in the slot (deleteRear)
  return slot;
}

//save data to another file
void htable::saveTable(ostream&fout, el_t element){

  for(int i=0;i<TSIZE;i++){ 
    while(!table[i].isEmpty()){ //while the slot is not empty

      table[i].deleteFront(element); // delete element;
      fout<< element <<endl; // sent to file
    }
  }
}

// finds element using the skey and returns the found element itself
// or a blank element  -- there is no cout in here
el_t htable::find(int skey){
 
  int slot = hash(skey); // hash with skey
  el_t selement;  // this is the element to look for in slist
  // initialize selement with just the skey
  selement.key = skey;
  // call slist's search2 with selement which returns the found element 
  el_t x;
  x = table[slot].search2(selement); 
  // return the found element from here (it could be blank)
  return x;
}

// displays the entire table with slot#s too
void htable::displayTable(){

  for (int i = 0; i < TSIZE; i++)
    { cout << i << ":" ;   
      table[i].displayAll();// call slist's displayAll
    }
}
