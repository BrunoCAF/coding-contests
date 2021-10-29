class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int delta, s = 0;
        
        for(int i = 1; i < prices.size(); i++){
            delta = (prices[i] >= prices[i-1]);
            if(delta) s += prices[i] - prices[i-1];
        }
        
        return s;
    }
};