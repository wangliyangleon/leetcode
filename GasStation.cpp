// https://oj.leetcode.com/problems/gas-station/
class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        if (gas.size() != cost.size()) {
            return -1;
        }
        vector<int> gas_rem;
        int sum = 0;
        for (int i = 0; i < gas.size(); ++i) {
            gas_rem.push_back(gas.at(i) - cost.at(i));
            sum += gas_rem.at(i);
        }
        if (sum < 0) {
            return -1;
        }

        for (int i = 0; i < gas.size(); ++i) {
            sum = 0;
            for (int j = i; j < gas.size() + i; ++j) {
                if (sum < 0) {
                    i = j - 1;
                    break;
                } else {
                    sum += gas_rem.at(j % gas.size());
                }
            }
            if (sum >= 0) {
                return i;
            }
        }
        return -1;
    }
};
