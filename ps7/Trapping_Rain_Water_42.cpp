class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> water(height.size(), 0);
        int water_sum = 0;

        for (int i = 1; i < height.size() - 1; i++){
            vector<int> left(&height[0], &height[i]);
            sort(left.begin(), left.end());
            // cout << "left vector" << endl;
            // for (int l: left){
            //     cout << l << "\t";
            // }

            vector<int> right(&height[i+1], &height[height.size()]);
            sort(right.begin(), right.end());

            // cout << "\n" << "right vector" << endl;
            // for (int r: right){
            //     cout << r << "\t";
            // }
            // cout << "\n";
            water[i] = min(left[left.size()-1], right[right.size()-1]) - height[i];
            if (water[i] > 0){
                water_sum += water[i];
            }
            // cout << "water sum = " << water_sum << " water[i] = " << water[i] <<endl;
        }
        

        // int start = 0;
        // while (height[start] < 1){
        //     start++;
        // }

        // int index = start + 1;
        // int bucket_left = height[start];
        // int bucket_left_ind = start;

        // int water = 0;
        // while (index < height.size()){
        //     while(height[index] <= bucket_left && index < height.size()){
        //         index++;
        //     }
        //     for (int i = bucket_left_ind + 1; i < index; i++){
        //         water += bucket_left - height[i];
        //     }
        //     bucket_left = height[index];
        //     bucket_left_ind = index;
        //     cout << "main loop index" << index << " water = " << water << endl;

        // }
        return water_sum;
    }
};