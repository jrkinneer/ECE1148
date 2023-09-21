//needs work, hits runtime exception, probably O(n^2) instead of O(n)

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int sum = 0;
        int min_window_size = INT_MAX;
        int j = 0;
        int window_size = 0;
        for (int i = 0; i < nums.size(); i++){
            sum = 0;
            j = i;
            sum = 0;
            while(j < nums.size()){
                sum += nums[j];
                j++;

                if (sum >= target){
                    break;
                }
            }
            window_size = j - i;
            if (window_size < min_window_size && sum >= target){
                min_window_size = window_size;
            }
        }
        if (min_window_size == INT_MAX){
            min_window_size = 0;
        }
        return min_window_size;
    }
};
