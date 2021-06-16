//
// Created by Eirik Drage Steen on 16/06/2021.
//

// https://codeforces.com/problemset/problem/90/A

#include "iostream"
using namespace std;

int cwUtil(int r, int g, int b) {
    if (r > 0 || g > 0 || b > 0) {
        int studs[] = {r, g, b};
        int res;
        for (int i = 0; i < 3; i++) {
            if (studs[i] != 0) {
                res = i + 1;
                if (studs[i] > 1){
                    studs[i] -= 2;
                }
                else{
                    studs[i] = 0;
                }
            }
        }

        if (studs[0] > 0 || studs[1] > 0 || studs[2] > 0){
            res = 3;
        }

        return res + cwUtil(studs[0], studs[1], studs[2]);
    }

    return 0;
}

int cw(int r, int g, int b){
    if (r > 0 || g > 0 || b > 0) {
        return 29 + cwUtil(r, g, b);
    }
    
    return 0;
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int r, g, b;
    cin >> r >> g >> b;

    cout << cw(r, g, b) << endl;

    return 0;
}
