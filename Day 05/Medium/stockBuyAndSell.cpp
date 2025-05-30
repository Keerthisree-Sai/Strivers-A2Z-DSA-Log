#include<bits/stdc++.h>
using namespace std;

// 1. Brute Force Approach
int stockProfitBrute(vector<int> &arr){
    int n = arr.size();
    int profit = INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[j]>arr[i]){
                profit = max(arr[j]-arr[i], profit);
            }
        }
    }
    return max(0, profit);
}

int stockProfitOptimal(vector<int> &arr){
    int n = arr.size();
    int minimum = INT_MAX;
    int profit = 0;
    for(int i=0;i<n;i++){
        minimum = min(arr[i], minimum);
        profit = max(profit, arr[i]-minimum);
    }
    return profit;
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
    //cout<<"The profit is: "<<stockProfitBrute(arr)<<endl;      //Brute Force
    cout<<"The profit is: "<<stockProfitOptimal(arr)<<endl;      //Optimal
}
