#include<bits/stdc++.h>
using namespace std;

// 1. Brute Force Approach (Works only if there are no duplicate values in the array)
void findElementsBruteForce(int arr[], int n){
    if(n==0 || n==1){
        cout<<-1<<" "<<-1<<endl;
        return;
    }
    sort(arr, arr+n);
    cout<<"The second largest element is: "<<arr[n-2]<<endl;
    cout<<"The second smallest element is: "<<arr[1]<<endl;
}

// 2. Better Approach
void findElementsBetter(int arr[], int n){
    if(n==0 || n==1){
        cout<<-1<<" "<<-1<<endl;
        return;
    }
    int largest = INT_MIN;
    int smallest = INT_MAX;
    for(int i=0; i<n; i++){
        if(arr[i]>largest){
            largest = arr[i];
        }
        if(arr[i]<smallest){
            smallest = arr[i];
        }
    }
    int slargest = INT_MIN;
    int ssmallest = INT_MAX;
    for(int i=0;i<n;i++){
        if(arr[i]>slargest && arr[i]!=largest){
            slargest = arr[i];
        }
        if(arr[i]<ssmallest && arr[i]!=smallest){
            ssmallest = arr[i];
        }
    }
    cout<<"The second largest element is: "<<slargest<<endl;
    cout<<"The second smallest element is: "<<ssmallest<<endl;
}

//  3. Optimal Approach
void findElementsOptimal(int arr[], int n){
    if(n==0 || n==1){
        cout<<-1<<" "<<-1<<endl;
        return;
    }
    int largest = INT_MIN, slargest = INT_MIN;
    int smallest = INT_MAX, ssmallest = INT_MAX;
    // Find second largest
    for(int i=0;i<n;i++){
        if(arr[i]>largest){
            slargest = largest;
            largest = arr[i];
        }
        else if(arr[i]!=largest && arr[i]>slargest){
            slargest = arr[i];
        }
    }
    //Find second smallest
    for(int i=0; i<n; i++){
        if(arr[i]<smallest){
            ssmallest = smallest;
            smallest = arr[i];
        }
        else if(arr[i]!=smallest && arr[i]<ssmallest){
            ssmallest = arr[i];
        }
    }
    cout<<"The second largest element is: "<<slargest<<endl;
    cout<<"The second smallest element is: "<<ssmallest<<endl;
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
    cout<<"\nBrute Force Solution:"<<endl;
    findElementsBruteForce(arr, n);
    cout<<"\nBetter Solution:"<<endl;
    findElementsBetter(arr, n);
    cout<<"\nOptimal Solution:"<<endl;
    findElementsOptimal(arr, n);
}
