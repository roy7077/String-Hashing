class Solution
{
    public:
    vector <int> search(string pat, string txt)
    {
        int n=pat.length();
        int m=txt.length();
        
        pat=(pat)+'$'+txt;
        vector<int> lps(pat.size(),0);
        int len=0;
        int j=1;
        while(j<pat.size())
        {
            if(pat[len]==pat[j])
            {
                lps[j]=len+1;
                len++;
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
        
        vector<int> ans;
        for(int i=0;i<lps.size();i++)
        {
            if(lps[i]==n)
            ans.push_back(i-n-n+1);
        }
        return ans;
    }
     
};
