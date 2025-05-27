#include<bits/stdc++.h>
using namespace std;

// 1. Brute Force Approach
vector<int> findEleBrute(vector<int> &arr, int n){
    vector<int> res;
    for(int i=0;i<n;i++){
        if(res.size()==0 || res[0]!=arr[i]){
            int cnt = 0;
            for(int j=0;j<n;j++){
                if(arr[i]==arr[j]){
                    cnt++;
                }
            }
            if(cnt>(n/3)) res.push_back(arr[i]);
        }
        if(res.size()==2) break;
    }
    return res;
}

// 2. Better Approach
vector<int> findEleBetter(vector<int> &arr, int n){
    unordered_map<int, int> mp;
    vector<int> res;
    int minimum = int(n/3)+1;
    for (int i = 0; i < n; i++) {
        mp[arr[i]]++;
        if (mp[arr[i]] == minimum) {
            res.push_back(arr[i]);
        }
        if (res.size() == 2) break;
    }
    return res;
}

// 3. Optimal Approach
vector<int> findEleOptimal(vector<int> &arr, int n){
    int cnt1=0, cnt2=0, ele1, ele2;
    vector<int> res;
    for(int i=0;i<n;i++){
        if(cnt1==0 && arr[i]!=ele2){
            cnt1=1;
            ele1=arr[i];
        }
        else if(cnt2==0 && arr[i]!=ele1){
            cnt2=1;
            ele2=arr[i];
        }
        else if(arr[i]==ele1){
            cnt1++;
        }
        else if(arr[i]==ele2){
            cnt2++;
        }
        else{
            cnt1--;
            cnt2--;
        }
    }
    int count1=0, count2=0;
    for(int i=0;i<n;i++){
        if(arr[i]==ele1){
            count1++;
        }
        else if(arr[i]==ele2){
            count2++;
        }
    }
    int minimum = int(n/3)+1;
    if(count1>=minimum) res.push_back(ele1);
    if(count2>=minimum) res.push_back(ele2);
    return res;
}

int main(){
    int n,ele;
    vector<int> arr;
    cout<<"Enter the size of array: ";
    cin>>n;
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin>>ele;
        arr.push_back(ele);
    }
    vector<int> res;
    //res = findEleBrute(arr, n);
    //res = findEleBetter(arr, n);
    res = findEleOptimal(arr, n);
    if (res.size() == 0) {
        cout << "No element appears more than n/3 times." << endl;
    }
    else {
        cout << "The elements are: ";
        for (int i = 0; i < res.size(); i++) {
            cout << res[i]<<" ";
        }
        cout << endl;
    }
}
