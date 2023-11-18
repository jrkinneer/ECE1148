#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        if (amount == 0){
            return 0;
        }

        int values[++amount];

        values[0] = 0;

        vector<int> sorted = coins;
        sort(sorted.begin(), sorted.end());

        for (int i = 1; i < amount; i++){
            values[i] = INT_MAX;
            for (int j = 0; j < coins.size(); j++){
                if (i - sorted[j] < 0){
                    break;
                }

                if (values[i - sorted[j] ] != INT_MAX){
                    values[i] = min(values[i], 1 + values[i - sorted[j] ]);
                }
            }
        }

        for (int i = 0; i < amount; i++){
            cout << values[i] << "\t";
        }
        return values[--amount] == INT_MAX ? -1 : values[amount];

        // if (amount == 0){
        //     return 0;
        // }
        // vector<int> sorted = coins;
        
        // sort(sorted.begin(), sorted.end(), greater<int>());
        // for (int i = 0; i < sorted.size(); i++){
        //     cout << sorted[i] << endl;
        // }

        // int sum = 0;
        // int coin_count = 0;

        // while(sum < amount && sorted.size() > 0){
        //     if (sum + sorted[0] <= amount){
        //         sum += sorted[0];
        //         coin_count++;
        //         if (sum == amount){
        //             break;
        //         }
        //     }
        //     else{
        //         sorted.erase(sorted.begin());
        //     }
        // }

        // if (sum < amount){
        //     return -1;
        // }

        // return coin_count;
    }
};