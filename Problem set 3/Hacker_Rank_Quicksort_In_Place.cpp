#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

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
    
    for (int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
    
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