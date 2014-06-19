// https://oj.leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (0 == prices.size()) {
            return 0;
        }
        int result = 0;
        for (int i = 0; i < prices.size() - 1; ++i) {
            if (prices[i] < prices[i + 1]) {
                result += prices[i + 1] - prices[i];
            }
        }
        return result;
    }
};
