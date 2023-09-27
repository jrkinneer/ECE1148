#include <bits/stdc++.h>
using namespace std;


int partition(vector <int> &arr, int start, int end){
    int pivot_ind = 0, count = 0;
    int p = arr[start];
    vector<int> left, right, equal, temp;
  
    for (int i = start + 1; i <= end; i++){
        if (arr[i] < p){
            left.push_back(arr[i]);
            count++;
        }
        else{
            right.push_back(arr[i]);
        }
    }
    pivot_ind = start + count;
    
    
    int l = 0, r = 0;
    for (int i = start; i <= end; i++){
        if (i < pivot_ind){
            arr[i] = left[l];
            l++;
        }
        else if(i == pivot_ind){
            arr[i] = p;
        }
        else{
            arr[i] = right[r];
            r++;
        }
    }
    
    return pivot_ind;
}

void quickSortHelper(vector <int> &arr, int start_index, int end_index){
    // base case
    if (start_index >= end_index){
        return;
    }
 
    // partitioning the array
    int p = partition(arr, start_index, end_index);
 
    // Sorting the left part
    quickSortHelper(arr, start_index, p - 1);
 
    // Sorting the right part
    quickSortHelper(arr, p + 1, end_index);
    
    for (int i = start_index; i <= end_index; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
    
}

void quickSort(vector <int> &arr) {
	quickSortHelper(arr, 0, arr.size() - 1);
}

int main()
{
    int n;
    cin >> n;

    vector <int> arr(n);
    for(int i = 0; i < (int)n; ++i) {
        cin >> arr[i];
    }

    quickSort(arr);

    return 0;
}
