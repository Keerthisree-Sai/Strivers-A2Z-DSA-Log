#include<bits/stdc++.h>
using namespace std;

// 1. Brute Force Approach
vector<vector<int>> threeSumBrute(vector<int> &arr, int n){
    set<vector<int>> res;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(arr[i]+arr[j]+arr[k]==0){
                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    sort(temp.begin(), temp.end());
                    res.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> ans(res);
    return ans;
}

// 2. Better Approach
vector<vector<int>> threeSumBetter(vector<int> &arr, int n){
    set<vector<int>> res;
    for (int i = 0; i < n; i++) {
        set<int> hashset;
        for (int j = i + 1; j < n; j++) {
            int third = -(arr[i] + arr[j]);
            if (hashset.find(third) != hashset.end()) {
                vector<int> temp = {arr[i], arr[j], third};
                sort(temp.begin(), temp.end());
                res.insert(temp);
            }
            hashset.insert(arr[j]);
        }
    }
    vector<vector<int>> ans(res);
    return ans;
}

// 3. Optimal Approach
vector<vector<int>> threeSumOptimal(vector<int> &arr, int n){
    vector<vector<int>> res;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++) {
        if (i != 0 && arr[i] == arr[i - 1]) continue;
        int j = i + 1;
        int k = n - 1;
        while (j < k) {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum < 0) {
                j++;
            }
            else if (sum > 0) {
                k--;
            }
            else {
                vector<int> temp = {arr[i], arr[j], arr[k]};
                res.push_back(temp);
                j++;
                k--;
                while (j < k && arr[j] == arr[j - 1]) j++;
                while (j < k && arr[k] == arr[k + 1]) k--;
            }
        }
    }
    return res;
}

int main(){
    int n,ele;
    vector<int> arr;
    vector<vector<int>> ans;
    cout<<"Enter the size of the array: ";
    cin>>n;
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin>>ele;
        arr.push_back(ele);
    }
    //uncomment the desired approach - Brute Force, Better, Approach
    //ans = threeSumBrute(arr, n);  //Brute Force
    //ans = threeSumBetter(arr, n); //Better
    ans = threeSumOptimal(arr, n);  //Optimal
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}
