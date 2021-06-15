//
// Created by Eirik Drage Steen on 14/06/2021.
//

//https://codeforces.com/contest/742/problem/A

#include "iostream"
using namespace std;
typedef long long int lli;

const int nums[] = {4, 2, 6, 8};

int arpa(const lli& n){
    if (n == 1){
        return 8;
    }
    else if (n == 0){
        return 1;
    }

    return nums[(n - 2) % 4];
}

int main(){
    lli n;
    cin >> n;
    cout << arpa(n) << endl;

    return 0;
}