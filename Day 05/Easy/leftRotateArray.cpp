#include<iostream>
using namespace std;

// 1. Brute Force Approach
void leftRotateBrute(int arr[], int n){
    int temp[n];
    for (int i=1;i<n;i++) {
        temp[i-1] = arr[i];
    }
    temp[n-1] = arr[0];
    for (int i=0; i<n; i++) {
        cout << temp[i] << " ";
    }
    cout << endl;
}

// 2. Optimal Approach
void leftRotateOptimal(int arr[], int n){
    int first = arr[0];
    for(int i=0;i<n-1;i++){
        arr[i] = arr[i+1];
    }
    arr[n-1] = first;
    for (int i=0;i<n;i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    //uncomment the desired approach - Brute Force, Optimal
    //leftRotateBrute(arr, n);  //Brute Force
    leftRotateOptimal(arr, n);  //Optimal
}
