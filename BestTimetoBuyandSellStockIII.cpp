// https://oj.leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (1 >= prices.size()) {
            return 0;
        }

        _profite_b2n.assign(prices.size(), 0);
        _profite_n2e.assign(prices.size(), 0);
        int cur_min_price = INT_MAX;
        int cur_max_price = INT_MIN;
        int max_profit = INT_MIN;
        int index = 0; 

        _profite_b2n[0] = 0;        
        cur_min_price = prices.at(0);
        for (int i = 1; i < prices.size(); ++i) {
            cur_min_price = std::min(cur_min_price, prices.at(i));
            _profite_b2n[i] = std::max(_profite_b2n[i - 1], prices.at(i) - cur_min_price);
        }

        _profite_n2e[prices.size() - 1] = 0;
        cur_max_price = prices.at(prices.size() - 1);
        for (int i = prices.size() - 2; i >= 0; --i) {
            cur_max_price = std::max(cur_max_price, prices.at(i));
            _profite_n2e[i] = std::max(_profite_n2e[i + 1], cur_max_price - prices.at(i));
        }   

        for (int i = 0; i < prices.size(); ++i) {
            max_profit = std::max(max_profit, _profite_b2n[i] + _profite_n2e[i]);
        }   
        return max_profit;

    }

private:
    int _maxProfitPart(int start, int end) {
        if (start == end) {
            return 0;
        }   
    }   

    vector<int> _profite_b2n;
    vector<int> _profite_n2e;
};  
