#include<bits/stdc++.h>
using namespace std;

// Brute Force Approach

/*int findLargest(vector<int> &vec){
    sort(vec.begin(), vec.end());
    return vec[vec.size()-1];
}*/

// Optimal Approach

int findLargest(vector<int> &vec){
    int largest = INT_MIN;
    for(int i=0; i<vec.size(); i++){
        if(vec[i]>largest){
            largest = vec[i];
        }
    }
    return largest;
}

int main(){
    int n,ele;
    cout<<"Enter the size of the array: ";
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        cin>>ele;
        v.push_back(ele);
    }
    cout<<"The largest element of the array is: "<<findLargest(v)<<endl;
}
