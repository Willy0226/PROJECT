// CS311 Yoshii Complete all functions with their comments

// ====================================================
//HW#: HW3P1 slist  inheriting from llist
//Your name: Ting Wei Chien
//Complier:  g++
//File type: slist.cpp implementation file
//=====================================================

using namespace std;
#include<iostream>
#include"slist.h" 

// ** Make sure llist constructor and destructors have couts in them


// do not change this one
slist::slist(){
 //cout << "slist constructor:" << endl;
}


// positions always start at 1

int slist::search(el_t key){
  Node *P;
  P=Front;
  int count=1;
  while(P!=NULL){
    if(P->Elem == key){
      return count;
    }
    P=P->Next;
    count++;
  }
}

el_t slist::search2(el_t X){
  el_t M; // blank
  Node *P;
  P=Front;
  int slot=0;
  /* X has only the ID part set.
     In the slist look for matching el_t in Elem (the same code as search)
     Return the el_t obj or if not found
     return a blank object M*/ 
  if(!isEmpty()){        //if not empty
    while(!(P==NULL)){   //while p not equal to NULL
      slot++;            //increase slot by 1
      if(P->Elem == X){  //if the element that P is pointing equal to X(key) 
	return P->Elem;  //return that element
      }      
      P=P->Next; //next slot
    } 
  }
  if(isEmpty()){         //if is empty 
    return M;            //return blank
  }
  return M;
}

// don't forget to throw OutOfRange for bad pos 
void slist::replace(el_t element, int pos){
  if (pos<1||pos>Count){ //error case
    throw OutOfRange();
  }
  Node *P;
  P=Front;
  for(int i=1;i<pos;i++){
    P=P->Next;
  }
  P->Elem=element;
}
bool slist::operator==(const slist& OtherOne)
{
  if(Count==OtherOne.Count){
    Node *P;
    P=OtherOne.Front;
    Node *Q;
    Q=this->Front;
    while(P!=NULL&&Q!=NULL){
      if(P->Elem!=Q->Elem){
	return false;
      }
      P=P->Next;
      Q=Q->Next;
    }
    return true;
  }
  return false;

  // if not the same length, return false
  // if the same lengths, check each node to see if the elements are the same
} 
