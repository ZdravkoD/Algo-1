#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Count_B[366];


vector<unsigned int> birthdays_count(vector<unsigned int> &Birthdays,vector< pair<unsigned int,unsigned int> > &Ranges)
{
    vector<unsigned int> Result;

    for(int i=0;i<Birthdays.size();i++)
    {
        Count_B[Birthdays[i]]++;
    }

    for(int i=0;i<Ranges.size();i++)
    {
        int Answ=0;

        for(int j=Ranges[i].first;j<=Ranges[i].second;j++)
        {
            Answ += Count_B[j];
        }

        Result.push_back(Answ);
    }

    return Result;
}

int main()
{
    vector<unsigned int> Birthdays = {0,10,31,53,23,66,78,66,5,4,43,23}; // length = 12
    vector< pair<unsigned int,unsigned int> > Ranges;
    Ranges.push_back(make_pair(0,2));
    Ranges.push_back(make_pair(3,20));
    Ranges.push_back(make_pair(2,44));
    Ranges.push_back(make_pair(40,80));
    Ranges.push_back(make_pair(0,365));

    vector<unsigned int> Result = birthdays_count(Birthdays,Ranges);

    for(unsigned int i=0;i<Result.size();i++)
    {
        cout << Result[i] << endl;
    }

    return 0;
}
