class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> sol;
        vector<int> curr = nums;
        helper(curr, 0, nums.size()-1, sol);
        return sol;
    }

    void helper(vector<int> &nums, int left, int right, vector<vector<int>> &sol){
        if (left == right){
            sol.push_back(nums);
        }
        else{
            for (int i = left; i <= right; i++){
                swap(nums[left], nums[i]);

                helper(nums, left + 1, right, sol);

                swap(nums[left], nums[i]);
            }
        }
    }
};