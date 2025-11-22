class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        vector<int> hash(256,-1);
        int maxLen = 0;
        int l=0, r=0;
        while(r<n){
            if(hash[s[r]]!=-1){
                if(hash[s[r]]>=l){
                    l = hash[s[r]]+1;
                }
            }
            int currLen = r-l+1;
            maxLen = max(currLen,maxLen);
            hash[s[r]]=r;
            r++;
        }
        return maxLen;
    }
};

TC - O(n)
SC - O(1)