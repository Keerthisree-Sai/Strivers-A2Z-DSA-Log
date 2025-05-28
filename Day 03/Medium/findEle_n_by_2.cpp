#include<bits/stdc++.h>
using namespace std;

// 1. Brute Force Approach
int findEleBruteForce(vector<int> &arr, int n){
    for(int i=0;i<n;i++){
        int count = 0;
        for(int j=0;j<n;j++){
            if(arr[i]==arr[j]){
                count++;
            }
        }
        if(count>(n/2)){
            return arr[i];
        }
    }
    return -1;
}

// 2. Better Approach
int findEleBetter(vector<int> &arr, int n){
    unordered_map<int, int> mp;
    for(int i=0;i<n;i++){
            mp[arr[i]]++;
    }
    for(auto i:mp){
        if(i.second>(n/2)){
            return i.first;
        }
    }
    return -1;
}

// 3. Optimal Approach
int findEleOptimal(vector<int> &arr, int n){
    int cnt = 0, ele;
    for(int i=0;i<n;i++){
        if(cnt == 0){
            ele = arr[i];
            cnt = 1;
        }
        else if(arr[i]==ele){
                cnt++;
        }
        else{
            cnt--;
        }
    }
    int count = 0;
    for(int i=0;i<n;i++){
        if(arr[i]==ele){
            count++;
        }
    }
    if(count>(n/2)){
        return ele;
    }
    return -1;
}

int main(){
    int n, ele, ans;
    vector<int> arr;
    cout<<"Enter the size of the array: ";
    cin>>n;
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin>>ele;
        arr.push_back(ele);
    }
    //uncomment the desired approach - Brute Force, Better, Optimal
    //ans = findEleBruteForce(arr, n);  //Brute Force
    //ans = findEleBetter(arr, n);      //Better
    ans = findEleOptimal(arr, n);       //Optimal
    cout<<"The element is: "<<ans<<endl;
}
