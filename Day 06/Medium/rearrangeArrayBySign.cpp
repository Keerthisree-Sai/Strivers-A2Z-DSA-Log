#include<bits/stdc++.h>
using namespace std;

// Variety 1

//Brute Force Approach
void rearrangeBrute(vector<int> &arr){
    int n = arr.size();
    vector<int> pos, neg;
    for(int i=0;i<n;i++){
        if(arr[i]>=0){
            pos.push_back(arr[i]);
        }
        else{
            neg.push_back(arr[i]);
        }
    }
    for(int i=0;i<(n/2);i++){
        arr[2*i] = pos[i];
        arr[2*i+1] = neg[i];
    }
}

//Optimal
vector<int> rearrangeOptimal(vector<int> &arr){
    int n = arr.size();
    vector<int> ans(n);
    int posInd = 0, negInd = 1;
    for(int i=0;i<n;i++){
        if(arr[i]>=0){
            ans[posInd] = arr[i];
            posInd+=2;
        } 
        else{
            ans[negInd] = arr[i];
            negInd+=2;
        } 
    }
    return ans;
}

// Variety 2

void rearrangeUnequal(vector<int> &arr){
    int n = arr.size();
    vector<int> pos;
    vector<int> neg;
    for(int i=0;i<n;i++){
        if(arr[i]>=0) pos.push_back(arr[i]);
        else neg.push_back(arr[i]);
    }
    int poslen = pos.size();
    int neglen = neg.size();
    if(poslen>neglen){
        for(int i=0;i<neglen;i++){
            arr[2*i] = pos[i];
            arr[2*i+1] = neg[i];
        }
        int index = neglen*2;
        for(int i=neglen;i<n;i++){
            arr[index] = pos[i];
            index++;
        }
    }
    else{
        for(int i=0;i<poslen;i++){
            arr[2*i] = pos[i];
            arr[2*i+1] = neg[i];
        }
        int index = poslen*2;
        for(int i=poslen;i<n;i++){
            arr[index] = neg[i];
            index++;
        }
    }
}

void printArray(vector<int>& arr) {
    for(int num : arr) cout << num << " ";
    cout << endl;
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
    //uncomment the desired variety and desired approach
    // For Variety 1 - equal number of positive and negative elements.
    /*rearrangeBrute(arr);
    printArray(arr);*/
    /*vector<int> ans = rearrangeOptimal(arr);
    printArray(ans);*/
    // For Variety 2 - the elements are not necessarily equal.
    rearrangeUnequal(arr);
    printArray(arr);
}
