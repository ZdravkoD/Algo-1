#include <iostream>
#include <vector>
#include <algorithm> // sort

using namespace std;

class Contact {
public:
string name;
int number;

    Contact(const int &number,const string &name)   {
        this->name=name;
        this->number=number;
        }
};

// function that compares to integers, used for sorting vector of class Contact
bool Compare(Contact i, Contact j)  {
  return (i.number < j.number);
  }

class PhoneBook {
public:
  // Find the names of people based on their phone numbers.
  vector<string> lookupNames(vector<Contact> phoneBook, vector<int> numbers) {
    sort(phoneBook.begin(),phoneBook.end(),Compare);
    vector<string> Result;

    for(unsigned int i=0;i<numbers.size();i++)  {
      int lo = 0, hi = phoneBook.size()-1;

      while(lo <= hi) {
        int mid = lo + (hi-lo)/2;

        if(phoneBook[mid].number == numbers[i]) {
          Result.push_back(phoneBook[mid].name);
          break;
        }
        else if(phoneBook[mid].number < numbers[i]) {
          lo = mid+1;
        }
        else {
          hi = mid-1;
        }
      }

      if(lo>hi)
        Result.push_back(""); // empty result
    }

    return Result;
    }
};

int main()
{
  int n, m;
  cin >> n >> m;
  vector<Contact> phoneBook;
  vector<int> numbers(m);
  for(int i=0;i<n;i++) {
    int t;
    string s;
    cin >> t >> s;
    phoneBook.push_back(Contact(t,s));
  }
  for(int i=0;i<m;i++) {
    cin >> numbers[i];
  }

  PhoneBook P;
  vector<string> Result = P.lookupNames(phoneBook, numbers);
  for(unsigned int i=0;i<Result.size();i++)
    cout << Result[i] << endl;

  return 0;
}
