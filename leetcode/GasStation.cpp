class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int r = 0, sum = 0;
        int total = 0;
        for (int i = 0; i < gas.size(); i++) {
            sum += gas[i] - cost[i];
            total += gas[i] - cost[i];
            if (sum < 0) {
                r = i + 1;
                sum = 0;
            }
        }
        if (total >= 0) return r;
        return -1;
    }
};
