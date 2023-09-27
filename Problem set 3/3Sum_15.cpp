#include <unordered_map>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

class Solution {
public:
    int partition(vector <int> &arr, int start_index, int end_index){
        //pivot is last index
        int p = arr[end_index];
        
        //we use l to index where we will eventually swap the pivot into
        int l = start_index; 
        
        for (int i=start_index; i < end_index; i++){
            if (arr[i] < p){
                swap(arr[l], arr[i]);
                l++;
            }
        }
        
        swap(arr[l], arr[end_index]);
        
        return l;
    }

    void quickSortHelper(vector <int> &arr, int start_index, int end_index){
        if (start_index >= end_index)
            return;
        
        int p = partition(arr, start_index, end_index);
        quickSortHelper(arr, start_index, p-1);
        quickSortHelper(arr, p+1, end_index);
        
    }

    void quickSort(vector <int> &arr) {
        quickSortHelper(arr, 0, arr.size() - 1);
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        //return value
        vector<vector<int>> ret;

        int first, second, sum, last;

        //sort nums
        quickSort(nums);

        //check edge case of nums being only three elements
        if (int(nums.size()) == 3){
            if (nums[0] + nums[1] + nums[2] == 0){
                ret.push_back(nums);
            }
            return ret;
        }

        //iterate through sorted nums
        for (int i = 0; i < nums.size(); i++){
            
            //first pointer is just after i
            //and second pointer is last element
            first = i + 1;
            second = nums.size() - 1;

            //check for repition of nums[i] because we want unique solutions
            if (i > 0 && nums[i] == nums[i-1]){
                continue;
            }

            //iterate first and second pointers until they catch eachother
            while (first < second){
                //calculate sum
                sum = nums[i] + nums[first] + nums[second];
                //if sum is good
                if (sum == 0){
                    vector<int> a = {nums[i], nums[first], nums[second]};
                    ret.push_back(a);

                    //set int last = first
                    last = first;
                    //increment first until it hits second or no longer equals its previous value
                    while (first < second && nums[first] == nums[last]){
                        first++;
                    }

                    //decrement second until it hits first or it is no longer its previous value
                    last = second;
                    while (first < second && nums[second] == nums[last]){
                        second--;
                    }
                }
                else if(sum < 0){
                    //if sum is less than zero, we increment first
                    //this is because moving first to the right is going to increase the sum, as the array is sorted in increasing order
                    first++;
                }
                else{
                    //if sum is greater than zero, decrement second, to decrease sum
                    //this is because all elements left of second are lower than it.
                    second--;
                }
            }

        }

        return ret;
    }
};