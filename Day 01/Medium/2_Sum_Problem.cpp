#include<bits/stdc++.h>
using namespace std;

// Brute Force Approach
/*vector<int> findPair(int arr[], int n, int target){
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i]+arr[j]==target){
                return {i,j};
            }
        }
    }
    return {-1,-1};
}*/

// Optimal Approach
vector<int> findPair(int arr[], int n, int target){
    unordered_map<int, int> mp;
    for(int i=0; i<n; i++){
        int num = arr[i];
        int neededNum = target - num;
        if(mp.find(neededNum)!=mp.end()){
            return {mp[neededNum], i};
        }
        mp[num] = i;
    }
    return {-1,-1};
}

int main(){
    int n,target;
    cout<<"Enter the size of array: ";
    cin>>n;
    cout<<"Enter the target: ";
    cin>>target;
    int arr[n];
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> res = findPair(arr, n, target);
    if(res[0] == -1) {
        cout << "No pair found that sums to the target." << endl;
    }else {
        cout << "The indices of the elements are: " << res[0] << ", " << res[1] << endl;
    }
}
