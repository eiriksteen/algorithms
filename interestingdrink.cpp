//
// Created by Eirik Drage Steen on 16/06/2021.
//

// https://codeforces.com/contest/706/problem/B

#include "iostream"
using namespace std;

int binaryFind(int arr[], int val, int st, int en, int size){
    int m = (st + en) / 2;
    int mid = arr[m];
    int l = 0;

    if (m > 0) {
        l = arr[m - 1];
    }
    if (val >= l && val < mid){
        return m;
    }
    else if (m == size - 1 && val >= mid){
        return m + 1;
    }
    else if (m == 0){
        if (val <= mid){
            return 0;
        }
        return 1;
    }
    else if (val < mid){
        return binaryFind(arr, val, 0, m, size);
    }

    return binaryFind(arr, val, m + 1, en, size);
}

int main(){
    int size;
    int br;

    cin >> size;
    int brs[size];
    for (int i = 0; i < size; i++){
        cin >> br;
        brs[i] = br;
    }

    std::sort(brs, brs + size);

    int size2;
    int mon;

    cin >> size2;

    for (int i = 0; i < size2; i++){
        cin >> mon;
        cout << binaryFind(brs, mon, 0, size, size) << endl;
    }

    return 0;
}