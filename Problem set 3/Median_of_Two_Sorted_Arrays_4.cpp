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

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double median = 0;

        vector<int> sorted = nums1;
        sorted.insert(sorted.end(), nums2.begin(), nums2.end());

        quickSort(sorted);

        //even length vector
        if (sorted.size() % 2 == 0){
            int m = int(sorted.size()/2) - 1;
            int m2 = m + 1;
            median = (sorted[m] + sorted[m2])/2.;
        }
        else{
            int m = int(sorted.size()/2);
            median = sorted[m];
        }

        return median;
    }
};