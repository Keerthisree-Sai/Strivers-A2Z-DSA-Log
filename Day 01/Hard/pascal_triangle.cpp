#include<bits/stdc++.h>
using namespace std;

// 1. Finding the value at given row and column
long long numAtRnC(int row, int col){
    long long res = 1;
    for(int i=0;i<col;i++){
        res = res*(row-i);
        res = res/(i+1);
    }
    return res;
}

// 2. Printing the nth row
void findNthRow(int row){
    cout<<1<<" ";
    long long res = 1;
    for(int col=1;col<row;col++){
        res = res*(row-col);
        res = res/col;
        cout<<res<<" ";
    }
    cout << endl;
}

// 3. Printing first n rows of the Pascal Triangle
void printTriangle(int rows) {
    for (int i = 0; i < rows; i++) {
        long long res = 1;
        cout << res << " ";
        for (int col = 1; col <= i; col++) {
            res = res * (i - col + 1);
            res = res / col;
            cout << res << " ";
        }
        cout << endl;
    }
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
            findNthRow(row);
            break;
        }
        case 3:{
            int rows;
            cout<<"Enter number of the rows you want to print: ";
            cin>>rows;
            printTriangle(rows);
            break;
        }
    }
}
