#include <vector>
#include <iostream>
#include <string>

using namespace std;

class BirthdayRanges {
public:

	// adds people who are born on a specific day
	void add(int day, int numberOfPeople)
	{
    	int index = 512 + day;
    	while(index)
    	{
    		tree[index] += numberOfPeople;
    		index /= 2;
    	}
	}

	// removes people who are born on a specific day
	void remove(int day, int numberOfPeople) {
    	int index = 512 + day;
    	if(numberOfPeople <= tree[index])
    	{
    		while(index)
    		{
    			tree[index] -= numberOfPeople;
    			index /= 2;
    		}
    	}
    }

  // returns the number of people born in a range
  	int count(int startDay, int endDay) {
    	startDay += 512;
    	endDay += 513;

    	int startSum = 0, endSum = 0;
    	while(startDay>1)
  		{
  			if(startDay%2)
  				startSum += tree[--startDay];
  			startDay /= 2;
  		}
  		while(endDay>1)
  		{
  			if(endDay%2)
  				endSum += tree[--endDay];
  			endDay /= 2;
  		}

  		return endSum-startSum;
  	}

private:
	int tree[1024] = {0};
};

int main()
{
	BirthdayRanges Test;
	int n,q;
	cin >> n >> q;
	for(int i=0;i<n;i++) {
		int temp;
		cin >> temp;
		Test.add(temp, 1);
	}
	for (auto i = 0; i < q; ++i)
	{
		string asd;
		cin >> asd;
		int a, b;
		cin >> a >> b;
		if(asd == "count")
			cout << Test.count(a, b) << endl;
		else if (asd == "remove")
			Test.remove(a, b);
		else
			Test.add(a, b);
	}

	return 0;
}
