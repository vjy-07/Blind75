class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buyPrice = prices[0];
        int maxProfit = 0;
        for(int i=1;i<n;i++){
            int currProfit = prices[i]-buyPrice;
            maxProfit = max(maxProfit, currProfit);
            buyPrice = min(buyPrice, prices[i]); 
        }
        return maxProfit;
    }
};

TC - O(n)
SC - O(1)