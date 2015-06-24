#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Contact {
public:
  Contact(string name,int number) {
    this->name=name;
    this->number=number;
  }
  string name;
  int number;
};

class PhoneBook {
private:
  vector<Contact> Vec;
  static bool Comp(const Contact &a, const Contact &b) {
    return a.name < b.name;
  }

public:

  //inserts a new contact
  void insert(Contact contact) {
    if(Vec.size()==0) {
      Vec.push_back(contact);
    }
    else {
      vector<Contact>::iterator it = lower_bound(Vec.begin(),Vec.end(),contact,Comp);
      if(it!=Vec.end() && it->name==contact.name)
        Vec[it-Vec.begin()].number = contact.number;
      else
        Vec.insert(it,contact);
    }
  }

  //lookup a name and print its phone number
  void lookup(string name) {
    vector<Contact>::iterator it = lower_bound(Vec.begin(),Vec.end(),Contact(name,0),Comp);

    if(it == Vec.end() || it->name != name)
      cout << "NOT FOUND!" << endl;
    else
      cout << it->number << endl;
  }

  //list all records in an alphabetical order
  void list() {
    for(unsigned int i=0;i<Vec.size();i++)
      cout << Vec[i].name << " - " << Vec[i].number << endl;
  }

  //remove a record for a given name
  void remove(string name) {
    vector<Contact>::iterator it = lower_bound(Vec.begin(),Vec.end(),Contact(name,0),Comp);

    if(it!=Vec.end() && it->name==name)
      Vec.erase(it);
  }
};

int main()
{
  PhoneBook P;
  P.insert(Contact("E",1));
  P.insert(Contact("F",2));
  P.insert(Contact("I",3));
  P.insert(Contact("J",4));
  P.insert(Contact("E",1114));
  P.insert(Contact("G",1223124));
  P.insert(Contact("B",1224));
  P.list();
  cout << endl;

  P.lookup("S");
  P.lookup("E");
  P.lookup("A");

  P.remove("A");
  P.list();
  cout << endl;

  P.remove("B");
  P.list();



  return 0;
}
