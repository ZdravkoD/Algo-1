#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

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
//      cout << "NOT FOUND!" << endl;
      printf("NOT FOUND!\n");
    else
      //cout << it->number << endl;
      printf("%d\n",it->number);
  }

  //list all records in an alphabetical order
  void list() {
    for(unsigned int i=0;i<Vec.size();i++)
      //cout << Vec[i].name << " - " << Vec[i].number << endl;
      printf("%s %d\n",Vec[i].name.c_str(),Vec[i].number);
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
  int n;
  scanf("%d",&n);
  PhoneBook P;

  for(int i=0;i<n;i++) {
    char cmd[20],name[1000];
    int number;
    scanf("%s",cmd);
    if(strcmp(cmd,"insert")==0) {
      scanf("%d%s",&number,name);
      P.insert(Contact(name,number));
    }
    else if(strcmp(cmd,"lookup")==0) {
      scanf("%s",name);
      P.lookup(name);
    }
    else if(strcmp(cmd,"list")==0) {
      P.list();
    }
    else {
      scanf("%s",name);
      P.remove(name);
    }
  }

  return 0;
}
