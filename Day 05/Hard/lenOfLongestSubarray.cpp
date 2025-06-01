#include<bits/stdc++.h>
using namespace std;

// 1. Brute Force Approach
int findLongestLengthBrute(vector<int> &arr){
    int n = arr.size();
    int maxLen = 0;
    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            if(sum == 0){
                maxLen = max(maxLen, j-i+1);
            }
        }
    }
    return maxLen;
}

// 2. Optimal Approach
int findLongestLengthOptimal(vector<int> &arr){
    int n = arr.size();
    unordered_map<int, int> mp;
    int sum = 0, maxLen = 0;
    for(int i=0;i<n;i++){
        sum += arr[i];
        if(sum == 0) maxLen = max(maxLen, i+1);
        else{
            if(mp.find(sum)!=mp.end()){
                maxLen = max(maxLen, i - mp[sum]);
            }
            else{
                mp[sum] = i;
            }
        }
    }
    return maxLen;
}

int main(){
    int n, ele;
    vector<int> arr;
    cout<<"Enter the size of the array: ";
    cin>>n;
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin>>ele;
        arr.push_back(ele);
    }
    //uncomment the desired approach - Brute Force, Optimal
    //cout<<"The length of the longest subarray is: "<<findLongestLengthBrute(arr)<<endl;      //Brute Force
    cout<<"The length of the longest subarray is: "<<findLongestLengthOptimal(arr)<<endl;      //Optimal
}
