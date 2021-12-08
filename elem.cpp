// CS311 Yoshii - el_t for HW8 Hash Table
// Element type of a list node is defined here
// el_t can be changed by the client to fit its needs
//----------------------------------------------------

#include "elem.h"

// blank element
el_t::el_t()
{
  key = -1;  // cannot be 0 because 0 is a valid key
  team_name = "";
  park_name = "";
  location = "";
  capacity = -1;
  roof = "";
}

// initializing constructor to create an el_t object 
el_t::el_t(int akey, string ateam_name, string apark_name, string alocation, int total_capacity, string roof_type)
{
  key = akey;
  team_name = ateam_name;
  park_name = apark_name;
  location = alocation;
  capacity = total_capacity;
  roof = roof_type;
}

// ONLY the key part should be available to the user of this class
int el_t::getkey()
{
  return key;
}

// ONLY the key part should be available to the user of this class 
void el_t::setkey(int akey)
{
  key = akey;
}
  
// overload == for search based on the key part only
bool el_t::operator==(el_t OtherOne)
{
  if (key == OtherOne.key) return true; else return false;
}

bool el_t::operator!=(el_t OtherOne)
{
  if (key != OtherOne.key) return true; else return false;
}

// overload cout 
ostream& operator<<(ostream& os, const el_t& E)  
{  
  os << E.key << " " << E.team_name << " " << E.park_name << " " << E.location << " " << E.capacity << " " << E.roof;
  return os;  
}  
