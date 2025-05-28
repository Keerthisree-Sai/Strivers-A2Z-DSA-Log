#include<bits/stdc++.h>
using namespace std;

// 1. Brute Force Approach
bool isSortedBruteForce(const vector<int>& arr) {
    int n = arr.size();
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(arr[i] > arr[j]) {
                return false;
            }
        }
    }
    return true;
}

// 2. Optimal Approach
bool isSorted(const vector<int>& arr) {
    for(int i = 1; i < arr.size(); i++) {
        if(arr[i - 1] > arr[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    // Uncomment the section you want to test (Brute Force or Optimal)
    // Brute Force
    /*if(isSortedBruteForce(arr)) {
        cout << "The array is sorted"<<endl;
    } else {
        cout << "The array is not sorted"<<endl;
    }*/
    // Optimal
    if(isSorted(arr)) {
        cout << "The array is sorted"<<endl;
    } else {
        cout << "The array is not sorted"<<endl;
    }
    return 0;
}
