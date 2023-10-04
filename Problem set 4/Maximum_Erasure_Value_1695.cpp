class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {

        int start = 0, end = 0;
        int sum = 0, max_sum = 0;

        unordered_set<int> s;

        while (end < nums.size()){
            while(s.count(nums[end]) > 0){
                s.erase(nums[start]);
                sum -= nums[start];
                start++;
            }

            sum += nums[end];
            s.insert(nums[end++]);
            
            max_sum = max(max_sum, sum);
        }

        return max_sum;

    }
};