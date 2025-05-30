#include<bits/stdc++.h>
using namespace std;

// 1. Brute Force Approach
vector<vector<int>> fourSumBrute(vector<int> &arr, int n, int target){
    set<vector<int>> res;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                for(int l=k+1;k<n;k++){
                    long long sum = arr[i]+arr[j];
                    sum+=arr[k];
                    sum+=arr[l];
                    if(sum==target){
                        vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
                        sort(temp.begin(), temp.end());
                        res.insert(temp);
                    }
                }
            }
        }
    }
    vector<vector<int>> ans(res.begin(), res.end());
    return ans;
}

// 2. Better Approach
vector<vector<int>> fourSumBetter(vector<int> &arr, int n, int target){
    set<vector<int>> res;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            set<int> hashSet;
            for(int k=j+1;k<n;k++){
                long long sum = arr[i]+arr[j]+arr[k];
                long long fourth = target - sum;
                if(hashSet.find(fourth)!=hashSet.end()){
                    vector<int> temp = {arr[i], arr[j], arr[k], (int)fourth};
                    sort(temp.begin(), temp.end());
                    res.insert(temp);
                }
                hashSet.insert(arr[k]);
            }
        }
    }
    vector<vector<int>> ans(res.begin(), res.end());
    return ans;
}

// 3. Optimal Approach
vector<vector<int>> fourSumOptimal(vector<int> &arr, int n, int target){
    sort(arr.begin(), arr.end());
    int k, l;
    vector<vector<int>> ans;
    for(int i=0;i<n;i++){
        if(i>0 && arr[i]==arr[i-1]) continue;
        for(int j=i+1;j<n;j++){
            if(j>i+1 && arr[j]==arr[j-1]) continue;
            k = j+1;
            l = n-1;
            while(k<l){
                long long sum = arr[i];
                sum+=arr[j];
                sum+=arr[k];
                sum+=arr[l];
                if(sum<target){
                    k++;
                }
                else if(sum>target){
                    l--;
                }
                else{
                    vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
                    ans.push_back(temp);
                    k++;
                    l--;
                    while(k<l && arr[k]==arr[k-1]) k++;
                    while(k<l && arr[l]==arr[l+1]) l--;
                }
            }
        }
    }
    return ans;
}

int main(){
    int n, ele, target;
    vector<int> arr;
    cout<<"Enter the size of the array: ";
    cin>>n;
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin>>ele;
        arr.push_back(ele);
    }
    cout<<"Enter the target: ";
    cin>>target;
    vector<vector<int>> ans;
    //uncomment the desired approach - Brute Force, Better, Optimal
    //ans = fourSumBrute(arr, n, target);         //Brute Force
    //ans = fourSumBetter(arr, n, target);      //Better
    ans = fourSumOptimal(arr, n, target);     //Optimal
    for (auto quad: ans) {
        cout << "[ ";
        for (int i = 0; i < quad.size(); ++i) {
            cout << quad[i];
            if (i < quad.size() - 1) cout << ", ";
        }
        cout << " ]" << endl;
    }
}
