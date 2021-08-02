//
// Created by Eirik Drage Steen on 01/08/2021.
//

#include "iostream"
#include "algorithm"
using namespace std;

#define FOR(i,a,b) for (int (i) = a; (i) < (b); (i)++)

// https://codeforces.com/contest/550/problem/A

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int pos1, pos2;
    string s;
    cin >> s;

    pos1 = s.find("AB", 0);
    pos2 = s.rfind("BA");

    if (!(pos1 == string::npos || pos2 == string::npos)){
        if (abs(pos1 - pos2) > 1){
            cout << "YES" << endl;
            return 0;
        }

        pos1 = s.find("BA", 0);
        pos2 = s.rfind("AB");
        if (abs(pos1 - pos2) > 1){
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;

    return 0;
}
