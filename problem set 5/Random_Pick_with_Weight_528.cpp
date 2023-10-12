class Solution {
public:
    vector<double> ranges;
    Solution(vector<int>& w) {
        vector<double> weights;

        double sum = 0;
        for (int j = 0; j < w.size(); j++){
            sum += w[j];
        }

        weights.push_back(w[0]/sum);
        ranges.push_back(w[0]/sum);

        for (int i = 1; i < w.size(); i++){
            weights.push_back(w[i]/sum);
            ranges.push_back(weights[i] + ranges[i-1]);
        }
    }
    
    int pickIndex() {
        if (ranges.size() == 1){
            return 0;
        }
        double r = ((double) rand() / (RAND_MAX));
        int curr_ind = 0;
        
        double range_lower = 0;
        double range_higher = ranges[0];

        for (int i = 0; i < ranges.size(); i++){
            if (r>range_lower && r < range_higher){
                curr_ind = i;
                return curr_ind;
            }
            else{
                range_lower = range_higher;
                range_higher = ranges[i + 1];
            }
        }
        
        return curr_ind;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */