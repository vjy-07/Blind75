class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int maxi=INT_MIN;
        int res=0;
        for(int i=0;i<n;i++){
            res+=nums[i];
            if(res>maxi){
                maxi=res;
            }
            if(res<0){
                res=0;
            }
        }
        return maxi;
    }
};

TC - O(n)
SC - O(1)