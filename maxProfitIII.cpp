class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy(INT_MIN), pre_buy, pre_sell = 0, sell = 0;
        for(int p : prices) {
            pre_buy = buy;
            buy = max(pre_buy, pre_sell - p);
            pre_sell = sell;
            sell = max(pre_sell, pre_buy + p);
        }
        return sell;
    }
};
