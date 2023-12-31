#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'findMedian' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

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

int findMedian(vector<int> arr) {
    vector<int> sorted = arr;
    int m = int(arr.size()/2);
    cout << "median index: " << m << endl;
    
    quickSort(sorted);
    
    cout<< "sorted[m] after quickSort: " << sorted[m] << endl;
    
    return sorted[m];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = findMedian(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
