#include<bits/stdc++.h>
using namespace std;

// 1. Brute Force Approach
void sortArray(vector<int> &arr, int n){
    sort(arr.begin(), arr.end());
}

// 2. Better Approach
void sortArrayBetter(vector<int> &arr, int n){
    int cnt_0=0, cnt_1=0, cnt_2=0;
    for(int i=0;i<n;i++){
        if(arr[i]==0) cnt_0++;
        else if(arr[i]==1) cnt_1++;
        else cnt_2++;
    }
    for(int i=0;i<cnt_0;i++){
        arr[i]=0;
    }
    for(int i=cnt_0;i<cnt_0+cnt_1;i++){
        arr[i]=1;
    }
    for(int i=cnt_0+cnt_1;i<cnt_0+cnt_1+cnt_2;i++){
        arr[i]=2;
    }
}

// Swap helper function
void swap(int &a, int &b){
    int temp = b;
    b = a;
    a = temp;
}

// 3. Optimal Approach
void sortArrayOptimal(vector<int> &arr, int n){
    int low = 0, mid = 0, high = n-1;
    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[mid], arr[low]);
            low++;
            mid++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else{
            swap(arr[mid], arr[high]);
            high--;
        }
    }
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
    // Uncomment any one of the following based on the approach you want to test:
    // sortArray(arr, n);        // Brute force
    // sortArrayBetter(arr, n); // Counting sort
    sortArrayOptimal(arr, n);   // Dutch National Flag
    for(auto i:arr){
        cout<<i<<" ";
    }
}
