//CS311 Yoshii Linked List class

//INSTRUCTION:
//Must use the provided HW3P1_help.doc to create llist.cpp
//It helps to first create if-then-else structure to fill in later.
//- Make sure PURPOSE and PARAMETER comments are given in detail
//- Make sure all if-then-else are commented describing which case it is
//- Make sure all local variables are described fully with their purposes

//EMACS HINT:
//  You can copy from a Word document to emacs (contrl-right click)
//  cntr-K cuts and cntr-Y pastes
//  Esc x replace-str does string replacements
//  Esc > goes to the end of the file; Esc < to the beginning
//  Tab on each line will indent perfectly for C++

// ====================================================
//HW#: HW3P1 llist
//Your name: Ting Wei Chien
//Complier:  g++
//File type: llist.cpp implementation file
//=====================================================

using namespace std;
#include<iostream>
#include"llist.h" 

llist::llist(){
  //cout << "... in llist constructor..." << endl; 
Front=NULL;
Rear=NULL;
Count=0;
}
llist::~llist(){
  //cout << ".... in llist destructor..." << endl;
  el_t x; 
  while(!isEmpty()){
    deleteFront(x);
  }
}  
//PURPOSE:return true of the list is empty othewise false
//PARAMETER:none
bool llist::isEmpty(){ // be sure to check all 3 data members

  if(Front==NULL&&Rear==NULL&&Count==0){
    return true;
  }
  else{
    return false;
  }
}
//PURPOSE:display all element in the list
//PARAMETER:none
void llist::displayAll(){   // be sure to display horizontally in [  ] with

  if(isEmpty()){  //special case
    cout<<"[empty]"<<endl;
  }
  else{ //regulor case
    Node* P;
    P=new Node;
    P=Front;
   
    cout<<"[";
    while(P!=NULL){
	cout<<P->Elem<<" "; //" " to create a space between two element
	P=P->Next;
	
    }
    cout<<"]"<<endl;
  }// blanks between elements
}

//PURPOSE:add an element to the rear of the list
//PARAMETER:NewNum is for the New Node
void llist::addRear(el_t NewNum){ // comment the 2 cases

  if(isEmpty()){ //special case
    Node* P;
    P=new Node;
    P->Elem=NewNum;
    P->Next=NULL;
    Front=P;
    Rear=P;

  }
  else{ //regular case
    Rear->Next=new Node;
    Rear=Rear->Next;
    Rear->Elem=NewNum;
    Rear->Next=NULL;
    
  }
  Count++;
}
//PURPOSE:add an element to the front of the list
//PARAMETER:NewNum is for the new node
void llist::addFront(el_t NewNum){  // comment the 2 cases

  if(isEmpty()){ //special case
    Node* P;
    P=new Node;
    P->Elem=NewNum;
    P->Next=NULL;
    Front=P;
    Rear=P;
    Count++;
  }
  else{ //regular case
    Node* P;   
    P=new Node;
    P->Next=Front;
    Front=P;
    Front->Elem=NewNum;
    Count++;
  }
}


//PURPOSE:delete an element from the front of the list
//PARAMETER:provide a holder (OldNum) for the element
void llist::deleteFront(el_t& OldNum){  // comment the 3 cases

  if(isEmpty()){ //error case
    throw Underflow();
  }
  else if(Count==1){ //special case
    OldNum=Front->Elem;
    delete Front;
    Front=NULL;
    Rear=NULL;
    Count--;
  }
  else{ //regular case
    OldNum=Front->Elem;
    Node* P;
    P=Front->Next;
    delete Front;
    Front=P;
    Count--;
  }
}
//PURPOSE:delete an element front the rear of the list
//PARAMETER:provide a holder (OldNum) for the element
void llist::deleteRear(el_t& OldNum){ // comment the 3 cases

  if(isEmpty()){
    throw Underflow();
  }
  else if(Count==1){ //special case
    OldNum=Rear->Elem;
    delete Rear;
    Front=NULL;
    Rear=NULL;
    Count--;
  }
  else{ //regular case
    OldNum=Rear->Elem;
    Node* P=Front;
    while(P->Next!=Rear){
      P=P->Next;
    }
    delete Rear;
    Rear=P;
    Rear->Next=NULL;
    Count--;
  }
}

/* harder ones follow */

// Utility Function to move a local pointer to the Jth node
void llist::moveTo(int J, Node*& temp){  // moves temp J-1 times to go to the Jth node
 
  temp=Front;
  for ( int K = 1;K<=J-2;K++ ){
  temp=temp->Next;
   }
}

//PURPOSE:remove an element at Ith position
//PARAMETER:I, OldNum
void llist::deleteIth(int I, el_t& OldNum){  // use moveTo to move local pointers. Be sure to comment to which node you are moving them. Do not forget to set OldNum.  
  if (I>Count||I<1){ //error case
    throw OutOfRange();
  }
  else if(isEmpty()){ //empty case
      throw Underflow();
  }
  else if(I==Count){ //special case 1
    deleteRear(OldNum);
  }
  else if(I==1){ //special case 2
    deleteFront(OldNum);
  }
  else{ //regular case
    Node *P,*Q;
    P=Front;
    
    moveTo(I,P);

    Q=P->Next;
    OldNum=Q->Elem;
    P->Next=Q->Next;

    delete Q;
    Count--;
  }
}
//PURPOSE:add a element before Ith position
//PARAMETER:I, newNum
void llist::insertIth(int I, el_t newNum){ // use moveTo to move local pointers. Be sure to comment to which node you are moving them.
  if((I<1)||(I>Count+1)){ //error case
    throw OutOfRange();
  }
  else if(isEmpty()){ //empty case
    throw Underflow();
  }
  else if (I==1){ //special case 1
    addFront(newNum);
  }
  else if (I==Count+1){ //special case 2 
    addRear(newNum);
  }
  else{ //regular case
    Node *P,*Q;
    P=Front;

    moveTo(I,P);

    Q=new Node;
    Q->Next=P->Next;
    P->Next=Q;
    Q->Elem=newNum;

    Count++;
  }
}

//PURPOSE:copy constructor, allow passing of a list by value and returning of a list by value
//PARAMETER:Original
llist::llist(const llist& Original){ // use my code
  Front=NULL; Rear=NULL; Count=0;
  Node *P;
  P=Original.Front;
  while(P!=NULL){
    addRear(P->Elem);
    P=P->Next;
  }
}
//PURPOSE:overloaded operator for copying a list
//PARAMETER:Otherone
llist& llist::operator=(const llist& OtherOne){ // use my code
  el_t x;
  if(&OtherOne!=this){
    while(!this->isEmpty()){
      this->deleteRear(x);
    }
    Node *P;
    P=OtherOne.Front;
    while(P!=NULL){
      this->addRear(P->Elem);
      P=P->Next;
    }
  }
  return *this;
}
