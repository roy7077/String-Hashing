// Time complexity - O(N+N)
// Space complexity- O(N+N)
class Solution {
    public:
    void help(string& s,vector<int>& lps)
    {
        int len=0;
        int j=1;
        while(j<lps.size())
        {
            if(s[len]==s[j])
            {
                len++;
                lps[j]=len;
                j++;
            }
            else
            {
                if(len!=0)
                len=lps[len-1];
                else
                {
                    lps[j]=0;
                    j++;
                }
            }
        }
    }
    string shortestPalindrome(string s) {
        string rev=s;
        reverse(rev.begin(),rev.end());
        string temp=s+'$'+rev;
        int n=temp.length();
        vector<int> lps(n,0);
        help(temp,lps);
        
        string add=s.substr(lps[n-1]);
        reverse(add.begin(),add.end());
        
        return add+s;
    }
};