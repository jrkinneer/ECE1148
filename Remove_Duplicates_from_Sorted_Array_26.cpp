//runtime 6ms, beats 82.16% of users
//memory 19.02MB, beats 11.74% of users

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 1;
        
        int previous_unique = nums[0];
        for (int i = 1; i < nums.size(); i++){
            if (nums[i] != previous_unique){
                nums[k] = nums[i];
                k++;
                previous_unique = nums[i];
            }
        }
        
        nums.resize(k);
        return k;
    }
};
