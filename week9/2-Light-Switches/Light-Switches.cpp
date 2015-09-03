#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define N 16

struct Switch{
bool TogglesBulb[N];
};
Switch Switches[N];
bool Bulbs[N];
vector<int> Solution;

/** Reads the input **/
void read()
{
  string State;
  for(int i=0;i<N;i++) {
    cin >> State;
    Bulbs[i] = (State=="on" ? true : false);
  }

  for(int i=0;i<N;i++) {
    for(int j=0;j<N;j++) {
      cin >> Switches[i].TogglesBulb[j];
    }
  }
}

/** Returns true if any bulb is on **/
bool bulbsOn()
{
  for(int i=0;i<N;i++) {
    if(Bulbs[i])
      return true;
  }

  return false;
}

/** Inverses the state of the bulbs to which the 'cur' switch is connected to **/
void toggleBulbs(const Switch &cur)
{
  for(int i=0;i<N;i++) {
    if(cur.TogglesBulb[i])  {

      Bulbs[i]=!Bulbs[i];
    }
  }
}

/** Checks combination without repetitions with given parameters:
* k - number of switches to include in the combination.
* curElement - Position of the current switch(count of switches until now).
* startFrom - From which switch to count combinations
**/
bool checkCombination(const int &k, const int curElement, const int startFrom)
{
  for(int i=startFrom;i<N;i++)  {
    toggleBulbs(Switches[i]);

    if(curElement == k) {
      if(bulbsOn()) {
        toggleBulbs(Switches[i]); // return to previous state
      }
      else {
        Solution.push_back(i+1);
        return true;
      }
    }
    else {
      if(checkCombination(k,curElement+1,i+1))  {
        Solution.push_back(i+1);
        return true;
      }
      else {
        toggleBulbs(Switches[i]); // return to previous state
      }
    }
  }

  return false;
}

/** Solves the problem.
* Checks combinations with 1,2,3,...,N switches.
**/
void solve()
{
  for(int i=1;i<=N;i++) {
    if(checkCombination(i,1,0)) {
      return;
    }
  }
}

/** Prints the solution of the problem.
* If there is no solution it prints "IMPOSSIBLE!".
* Otherwise it prints the switches in sorted order
**/
void printSolution()
{
  if(Solution.size()==0)  {
    cout << "IMPOSSIBLE!" << endl;
    return;
  }

  sort(Solution.begin(),Solution.end());

  for(unsigned int i=0;i<Solution.size();i++)  {
    cout << Solution[i] << " ";
  }
  cout << endl;
}

int main()
{
  read();

  solve();

  printSolution();

  return 0;
}
