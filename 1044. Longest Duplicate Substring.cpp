class Solution {
    private:
    vector<long> ori;
    long prime = 1e15 + 7;
    public:
    string rabinKarp(string s, int len) {
        if(len == 0)
            return "";
        
        int l = s.length();
        unordered_map<long, int> hash;
        long cur = 0;
        
        for(int i = 0; i < len; i++)
            cur = (cur * 26 + (s[i] - 'a'))%prime;
        
        hash[cur] = 0;
        for(int i = len; i < l; i++) {
            cur = ((cur - ori[len - 1] * (s[i - len] - 'a'))%prime + prime)%prime;
            cur = (cur * 26 + (s[i] - 'a'))%prime;
            
            if(hash.find(cur) == hash.end()) {
                hash[cur] = i - len + 1;
            }
            else {
                return s.substr(hash[cur], len);
            }
        }
        return "";
    }
    
    string longestDupSubstring(string s) {
        int l = s.length(), lo = 0, hi = l;
        ori = vector<long>(l, 0);
        for(int i = 0; i < l; i++) {
            ori[i] = (i == 0)? 1 : ((ori[i - 1] * 26) % prime);
        }
        
        string res;
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            string dup = rabinKarp(s, mid);
            
            if((int)dup.size() > (int)res.size()) {
                res = dup;
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }
        return res;
    }
};