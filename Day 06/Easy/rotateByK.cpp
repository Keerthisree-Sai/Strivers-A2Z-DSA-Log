#include<bits/stdc++.h>
using namespace std;

void rotateByKBrute(vector<int> &arr, int k, string dir){
    int n = arr.size();
    if(n==0) return;
    k = k%n;
    if(k==0) return;
    vector<int> temp(k);
    if(dir == "right"){
        for(int i=n-k;i<n;i++){
            temp[i-n+k] = arr[i];
        }
        for (int i = n - k - 1; i >= 0; i--)
        {
            arr[i + k] = arr[i];
        }
        for(int i=0;i<k;i++){
            arr[i] = temp[i];
        }
    }
    if(dir == "left"){
        for(int i=0;i<k;i++){
            temp[i] = arr[i];
        }
        for(int i=0;i<n-k;i++){
            arr[i] = arr[i+k];
        }
        for(int i=n-k;i<n;i++){
            arr[i] = temp[i-n+k];
        }
    }
}

void reverse(vector<int> &arr, int start, int end){
    while(start<=end){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void rotateByKOptimal(vector<int> &arr, int k, string dir){
    int n = arr.size();
    if(n==0) return;
    k = k%n;
    if(k==0) return;
    if(dir == "right"){
        reverse(arr, 0, n-k-1);
        reverse(arr, n-k, n-1);
        reverse(arr, 0, n-1);
    }
    if(dir == "left"){
        reverse(arr, 0, k-1);
        reverse(arr, k, n-1);
        reverse(arr, 0, n-1);
    }
}

int main(){
    int n, ele, k;
    vector<int> arr;
    string dir;
    cout<<"Enter the size of the array: ";
    cin>>n;
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin>>ele;
        arr.push_back(ele);
    }
    cout<<"Enter by how many places the array to be rotated: ";
    cin>>k;
    cout<<"Enter the direction in which array to be rotated (left or right): ";
    cin>>dir;
    //uncomment the desired approach - Brute Force, Optimal
    //rotateByKBrute(arr, k, dir);
    rotateByKOptimal(arr, k, dir);
    for(auto i:arr){
        cout<<i<<" ";
    }
    cout<<endl;
}
