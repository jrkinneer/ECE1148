class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum_gas = 0;
        int sum_cost = 0;
        int in_tank = 0;
        int best_station = 0;
        for (int i = 0; i < gas.size(); i++){
            sum_gas += gas[i];
            sum_cost += cost[i];

            in_tank += gas[i] - cost[i];

            if (in_tank < 0){
                best_station++;
                in_tank = 0;
            }

        }

        if (sum_gas >= sum_cost){
            return best_station;
        }
        else{
            return -1;
        }

    }
};
