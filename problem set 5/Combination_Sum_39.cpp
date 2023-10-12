class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        sort(candidates.begin(), candidates.end());
        vector<int> curr_combo;
        helper(ret, candidates, 0, target, curr_combo);
        return ret;
    }

    void helper(vector<vector<int>> &ret, vector<int> candidates, int next, int remainder,  vector<int> &curr_combo){
        if (remainder == 0){
            ret.push_back(curr_combo);
            return;
        }

        if (next == candidates.size() || remainder - candidates[next] < 0){
            return;
        }

        curr_combo.push_back(candidates[next]);
        helper(ret, candidates, next, remainder - candidates[next], curr_combo);
        curr_combo.pop_back();

        helper(ret, candidates, next + 1, remainder, curr_combo);
    }

};