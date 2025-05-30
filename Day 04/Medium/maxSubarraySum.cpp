#include<bits/stdc++.h>
using namespace std;

// 1. Brute Force Approach
int maxSubarraySumBrute(vector<int> &arr, int n){
    int maxi = INT_MIN;
    int ansStart = -1, ansEnd = -1;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sum = 0;
            for(int k=i;k<=j;k++){
                sum+=arr[k];
            }
            if(sum>maxi){
                ansStart = i;
                ansEnd = j;
                maxi = sum;
            }
        }
    }
    for(int i=ansStart;i<=ansEnd;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return maxi;
}

// 2. Better Approach
int maxSubarraySumBetter(vector<int> &arr, int n){
    int maxi = INT_MIN;
    int ansStart = -1, ansEnd = -1;
    for(int i=0;i<n;i++){
        int start = i;
        int sum = 0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            if(sum>maxi){
                ansStart = start;
                ansEnd = j;
                maxi = sum;
            }
        }
    }
    for(int i=ansStart;i<=ansEnd;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return maxi;
}

// 3. Optimal Approach
int maxSubarraySumOptimal(vector<int> &arr, int n){
    int maxi = INT_MIN;
    int sum = 0;
    int start = -1, ansStart = -1, ansEnd = -1;
    for(int i=0;i<n;i++){
        if(sum==0) start = i;
        sum = sum + arr[i];
        if(sum>maxi){
            maxi = sum;
            ansStart = start;
            ansEnd = i;
        }
        if(sum<0){
            sum = 0;
        }
    }
    for(int i=ansStart;i<=ansEnd;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return maxi;
}

int main(){
    int n,ele;
    vector<int> arr;
    cout<<"Enter the size of the array: ";
    cin>>n;
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin>>ele;
        arr.push_back(ele);
    }
    //uncomment the desired approach - Brute Force, Better, Optimal
    int maxSum = maxSubarraySumBrute(arr, n);
    //int maxSum = maxSubarraySumBetter(arr, n);
    //int maxSum = maxSubarraySumOptimal(arr, n);
    cout<<"The maximum sum is: "<<maxSum<<endl;
}
