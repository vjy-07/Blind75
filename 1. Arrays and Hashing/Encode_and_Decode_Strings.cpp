class Solution {
  public:
    string encode(vector<string>& s) {
        // code here
        string res;
        for(auto str: s){
            res+= to_string(str.size())+"#"+str;
        }
        return res;
    }

    vector<string> decode(string& s) {
        // code here
        vector<string> res;
        int i=0;
        while(i<s.size()){
            int j=i;
            while(s[j]!='#'){
                j++;
            }
            int len = stoi(s.substr(i,j-i));
            i=j+1;
            j=i+len;
            res.push_back(s.substr(i,len));
            i = j;
        }
        return res;
    }
};

TC - O(m)
SC - (m+n) where m is total length of all strings and n is number of strings