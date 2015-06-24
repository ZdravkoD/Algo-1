#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

typedef pair<string,string> pss; // for ease

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
    bool operator() (const pss &a, const pss &b) {
      return Protocol[a.first] > Protocol[b.first];
    }
  };

  priority_queue<pss, vector<pss>, CompareProtocol> Q; // the "device"

public:

  //receives a packet with specified protocol and payload
  void rcv(string protocol, string payload) {
    Q.push( make_pair(protocol, payload) );
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
  BandwidthManager BM;

  BM.rcv("UDP","zxchzrkljhklzrjlkhklzr");
  BM.rcv("TCP","ghljkajklhgjklare");
  BM.rcv("ICMP","ping87.129.54.123");
  cout << BM.send() << endl;
  cout << BM.send() << endl;

  BM.rcv("DNS","maps.google.com");
  cout << BM.send() << endl;

  BM.rcv("TCP","aejkgjkaegaegae");
  cout << BM.send() << endl;
  cout << BM.send() << endl;
  cout << BM.send() << endl;

  return 0;
}
