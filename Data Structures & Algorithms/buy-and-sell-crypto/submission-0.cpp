class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int profit = 0;

        int anchor = -1;
        int i = 0;
        int val;

        while (i < prices.size()) {
            if (anchor == -1) {
                anchor = prices[i];
                i++;
                continue;
            }

            val = prices[i];
            if (val - anchor <= 0) {
                anchor = val;
                i++;
            } else {
                profit = std::max(val - anchor, profit);
                i++;
            }
            
        }

        return profit;
    }
};
