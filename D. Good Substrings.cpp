#include <iostream>
#include <cstring>
#include <set>
using namespace std;
#define ll long long
#define mod 1000000007

int main() {
	
	string str,good;
	cin>>str;
	cin>>good;
	
	int k;
	cin>>k;
	
	set<pair<int,int>> st;
	for(int i=0;i<str.length();i++)
	{
	    ll hash1=0;
	    ll hash2=0;
	    ll pr1=1;
	    ll pr2=1;
	    int bad=0;
	    for(int j=i;j<str.length();j++)
	    {
	        if(good[str[j]-'a']=='0')
	        bad++;
	        
	        if(bad>k)
	        break;
	        
	        hash1=(hash1+((str[j]-'a'+1)*pr1)%mod)%mod;
	        hash2=(hash2+((str[j]-'a'+1)*pr2)%mod)%mod;
	        st.insert({hash1,hash2});
	        pr1=(pr1*31)%mod;
	        pr2=(pr2*37)%mod;
	    }
	}
// 	cout<<st.size()<<endl;
	return st.size();
}
