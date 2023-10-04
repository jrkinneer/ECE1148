class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int count = 0;
        int i = 0, j = 0;
        vector<int> sum_array;

        int sum = 1;

        while (j < nums.size()){
            sum *= nums[j];

            while (i <= j && sum >= k){
                sum /= nums[i++];
            }

            count += j - i + 1;
            j++;
        }

        return count;
    }

};