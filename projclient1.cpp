// CS311 Project Client using a generic hash table
// Loading the data file has to happen here because
// generic htable should not know about the file
// format.
//
// Change everywhere it says **
// Must write / change @@ functions in htable.
// ** Must improve the user interface!

#include "htable.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

// ** Add purpose of your program here
// I watch a lot of baseball and I want to visit all MLB ballpark in the future.
// This program can let me know the detail about a ballpark quickly by searching its area code.
// When I insert an area code, I will get the team’s name, ballpark name, its location, capacity, if there is a roof or not.

int main()
{
  htable T;  // generic hash table

  // All declarations happen outside switch
  int key;          //  area code
  string team_name; // team's name 
  string park_name; // ball park's name
  string location;  // its location
  int capacity;     // total capacity
  string roof;      // roof type
  el_t E;           // blank element
  
  // File info declared outside switch
  // Only the client should know about file names
  string fname;
  cout << "Welcome! This is a MLB ball park search engine" <<endl;
  cout << "What is the input file? (.txt)";
  cin >> fname;
  ifstream fin (fname.c_str(), ios::in);
  ofstream fout ("newout.txt", ios::out);


  int ans = 0;
  while (ans != 7)
    {
      // *** change menu items to be descriptive
      cout << "MENU------------------ :"<<endl;
      cout << "1. Load data from a file" << endl;
      cout << "2. Display the table" << endl;
      cout << "3. Search using area code as a key" << endl;
      cout << "4. Add a new ballpark" << endl;
      cout << "5. Delete an exist ballpark" << endl;
      cout << "6. Save data to a file" << endl;
      cout << "7. Exit" << endl;
      cout << "==>";
      cin >> ans;

      switch (ans)
	{

	case 1: // ** change element parts to yours
          // LOADING
	  while (fin >> key)
	    { fin >> team_name;
	      fin >> park_name;
	      fin >> location;
	      fin >> capacity;
	      fin >> roof;	       
	      T.add(el_t(key, team_name, park_name, location, capacity, roof));
	    } 
	  cout << "loaded data..." << endl; 
	  break;

	case 2:
          // DISPLAYING
	  T.displayTable(); 
          break;

	case 3: // ** change key to yours
          // SEARCHING
	  cout << "Enter an area code to look for: ";
	  cin >> key; 
	  E = T.find(key);
	  if (E == el_t()) /// was blank
     	    cout << "Not found" << endl;
          else cout << "Found " << E << endl;
	  break;

	case 4: // ** change element parts to yours
          // ADDING
          cout << "Enter an area code as key: "; cin >> key;
	  E = T.find(key);
	  if (E != el_t()){
	    cout<< "This ball park might has already existed" << endl;
	    cout << E << endl;
	    break;
	  }	    
	  else{
	    cout << "Enter a team name: "; cin >> team_name;
	    cout << "Enter a ballpark name: "; cin >> park_name; 
	    cout << "Enter a location: "; cin >> location;
	    cout << "Enter total capacity: ";cin >> capacity;
	    cout << "Enter roof type: ";cin >> roof;
	    cout << "In Slot: " << T.add(el_t(key, team_name, park_name, location, capacity, roof));
	    cout << "  added." << endl;
	    break;
	  }
       
	case 5: // ** change key to yours
          // DELETING 
          cout << "Enter an area code: "; cin >> key;
	  E = T.find(key);
	  if(E == el_t()){ /// was blank
	    cout<< "Not found" << endl;
	  }
	  else{
	    cout << "In Slot: " << T.deleteIt(el_t(key, team_name, park_name, location, capacity, roof)); //@@ NEW
	    cout << "  deleted." << endl;
	    // ** what happens if the item was not found?
	    // I add if_else statement so if not found just say not found
	  }	   
	  break;
        
	case 6:
          // SAVING TO FILE
	  T.saveTable(fout, el_t(key,team_name,park_name,location,capacity,roof)); // @@ NEW	  
	  cout << "Sent data to newout.txt" << endl; 
          cout << "Be sure to rename it before using it as input" << endl;
	  break;

        default:
	  cout << "No action" << endl;
	  break;
	}
    }// end of loop

  fin.close();
  fout.close();
}

