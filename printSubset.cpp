#include <bits/stdc++.h>
using namespace std;


void printSubsets(string ip,string op,set <string> &st){
	if(ip.length() == 0){
	st.insert(op);
		return;
	}
	string op1 = op;
	string op2 = op;
	op2.push_back(ip[0]);
	ip.erase(ip.begin()+0);
	printSubsets(ip,op1,st);
	printSubsets(ip,op2,st);
	return;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string ip; cin >> ip;
    string op = "";
    set<string> st;
    printSubsets(ip,op,st);
    set<string> :: iterator it;
    for(it=st.begin();it!=st.end();++it){
    	cout << *it << " ";
	}
    return 0;
}
