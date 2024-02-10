#include <iostream>
#include <cstring>
using namespace std;
#define ll long long
int mod=1e9+7;

ll power(ll base, ll exponent, ll mod) {
    ll result = 1;
    base = base % mod;
    while(exponent) 
    {
        if(exponent&1) 
        {
            result = (result * base) % mod;
            exponent--;
        }
        else
        {
            exponent = exponent / 2;
            base = (base * base) % mod;
        }
    }
    return result;
}

ll preHash[100005];
ll prePower[100005];

ll computeHash(string& s,int l,int r)
{
    ll hash=preHash[r];
    if(l>0)
    hash=(hash-preHash[l-1]+mod)%mod;
    
    hash = (hash * power(prePower[l], mod-2, mod)) % mod;
    return hash;
}



int main() {
	
	string st;
	cin>>st;
	
	ll pre=1;
	ll hash=0;
	for(int i=0;i<st.length();i++)
	{
	    prePower[i]=pre;
	    hash=(hash+((st[i]-'a'+1)*pre)%mod)%mod;
	    preHash[i]=hash;
	    pre=(pre*31)%mod;
	}
	
	//query
	int q;
	cin>>q;
	while(q--)
	{
	    int i1,j1,i2,j2;
	    cin>>i1>>j1;
	    cin>>i2>>j2;
	    
	    ll a=computeHash(st,i1,j1);
	    ll b=computeHash(st,i2,j2);
	    
	    cout<<a<<" "<<b<<endl;
	    if(a==b)
	    cout<<"YES"<<endl;
	    else
	    cout<<"No"<<endl;
	}
	return 0;
}
