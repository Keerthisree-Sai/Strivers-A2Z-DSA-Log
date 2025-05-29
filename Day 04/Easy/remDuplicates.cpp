#include<bits/stdc++.h>
using namespace std;

// 1. Brute Force Approach
int removeDuplicates(vector<int> &arr, int n){
    set<int> hashSet;
    for(int i=0;i<n;i++){
        hashSet.insert(arr[i]);
    }
    int j=0;
    for(auto i:hashSet){
        arr[j++]=i;
    }
    return hashSet.size();
}

// 2. Optimal Approach
int removeDuplicatesOptimal(vector<int> &arr, int n){
    int i = 0;
    for(int j=1;j<n;j++){
        if(arr[j]!=arr[i]){
            arr[i+1]=arr[j];
            i++;
        }
    }
    return i+1;
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
    //uncomment the desired approach - Brute Force, Optimal
    //cout<<"The no. of unique elements are: "<<removeDuplicates(arr, n)<<endl;         //Brute Force
    cout<<"The no. of unique elements are: "<<removeDuplicatesOptimal(arr, n)<<endl;    //Optimal
}
