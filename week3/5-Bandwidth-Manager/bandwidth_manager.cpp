#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

typedef pair<pair<string,int>,string> ppsis; // for ease

// set priority of protocols
std::map<string,int> Protocol = {
  {"ICMP",1},
  {"UDP" ,2},
  {"RTM" ,3},
  {"IGMP",4},
  {"DNS" ,5},
  {"TCP" ,6}};

class BandwidthManager {
private:
  struct CompareProtocol {
    bool operator() (const ppsis &a, const ppsis &b) {
      if(Protocol[a.first.first]==Protocol[b.first.first])
        return a.first.second>b.first.second;

      return Protocol[a.first.first]>Protocol[b.first.first];
    }
  };

  priority_queue<ppsis, vector<ppsis>, CompareProtocol> Q; // the "device"


public:

  //receives a packet with specified protocol and payload
  void rcv(string protocol, string payload) {
    static int count=0;
    Q.push(make_pair(make_pair(protocol,count++), payload));
  }

  //returns the payload of the packet which should be sent
  string send() {
    if(Q.empty()) {
      return "Nothing to send!";
    }

    string ret = Q.top().second;
    Q.pop();
    return ret;
  }
};

int main()
{
  int n;
  cin >> n;

  BandwidthManager BM;

  for(int i=0;i<n;i++) {
    string cmd,Protocol,Payload;
    cin >> cmd;
    if(cmd=="rcv") {
      cin >> Protocol >> Payload;
      BM.rcv(Protocol,Payload);
    }
    else {
      cout << BM.send() << endl;
    }
  }

  return 0;
}
