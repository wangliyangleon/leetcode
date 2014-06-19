// https://oj.leetcode.com/problems/best-time-to-buy-and-sell-stock/
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int result = 0, tmp = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (tmp + (prices[i] - prices[i - 1]) > 0) {
                tmp += (prices[i] - prices[i - 1]);
                if (tmp > result) {
                    result = tmp;
                }
            } else {
                tmp = 0;
            }
        }
        return result;
    }
};
