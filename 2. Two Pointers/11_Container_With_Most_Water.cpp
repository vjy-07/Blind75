class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int s = 0, e = n-1;
        int total = INT_MIN;
        while(s<e){
            int hei = min(height[s],height[e]);
            int width = e-s;
            int currTotal = hei*width;
            total = max(total, currTotal);
            if(height[s]>height[e]){
                e--;
            }
            else{
                s++;
            }
        }
        return total;
    }
};

TC - O(n)
SC - O(1)
