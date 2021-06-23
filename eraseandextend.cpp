//
// Created by Eirik Drage Steen on 22/06/2021.
//

// https://codeforces.com/contest/1537/problem/E1

#include "iostream"
using namespace std;

#define FOR(i,a,b) for (int (i) = a; (i) < (b); (i)++)

string eraseandextend2(string s, int cs, int fs){
    FOR(i, 1, cs){
        string pref = s.substr(0, i);
        string dpref = pref + pref;

        if ((dpref < s || dpref < s + s) && mismatch(dpref.begin(), dpref.end(), s.begin()).first != dpref.end()){
            s = dpref;
            cs = dpref.size();
            break;
        }
    }

    while (cs < fs){
        s += s;
        cs = s.size();
    }

    return s.substr(0, fs);
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int cs, fs;
    string s;
    cin >> cs >> fs;
    cin >> s;

    cout << eraseandextend2(s, cs, fs) << endl;

    return 0;
}
