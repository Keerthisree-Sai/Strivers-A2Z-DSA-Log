#include<bits/stdc++.h>
using namespace std;

// 1. Finding the number at given row and column
long long numAtRnC(int row, int col){
    long long res = 1;
    for(int i=0;i<col;i++){
        res = res*(row-i);
        res = res/(i+1);
    }
    return res;
}

// 2. Printing the nth row
vector<int> findNthRow(int row){
    vector<int> v;
    v.push_back(1);
    long long res = 1;
    for(int col=1;col<row;col++){
        res = res*(row-col);
        res = res/col;
        v.push_back(res);
    }
    return v;
}

// 3. Printing n rows of the Pascal Triangle
vector<vector<int>> printTriangle(int row){
    vector<vector<int>> ans;
    for(int i=0;i<row;i++){
        ans.push_back(findNthRow(i+1));
    }
    return ans;
}

int main(){
    int choice;
    cout<<"Enter\n1. Printing the value at given row and column\n2. Printing the nth row\n3. Printing n rows:\n";
    cin>>choice;
    switch(choice){
        case 1:{
            int row,col;
            cout<<"Enter the row number: ";
            cin>>row;
            cout<<"Enter the column number: ";
            cin>>col;
            cout<<"The value at "<<row<<" row and "<<col<<" col is: "<<numAtRnC(row-1, col-1);
            break;
        }
        case 2:{
            int row;
            cout<<"Enter the number of the row you want to print: ";
            cin>>row;
            vector<int> ans = findNthRow(row);
            for(auto i:ans){
                cout<<i<<" ";
            }
            break;
        }
        case 3:{
            int rows;
            cout<<"Enter number of the rows you want to print: ";
            cin>>rows;
            vector<vector<int>> ans = printTriangle(rows);
            for(auto row:ans){
                for(int ele:row){
                    cout<<ele<<" ";
                }
                cout<<endl;
            }
        }
    }
}
