//
// Created by Eirik Drage Steen on 20/06/2021.
//

// https://codeforces.com/problemset/problem/1335/C

#include "iostream"
#include "algorithm"
#include "map"
using namespace std;

typedef unsigned int ui;
#define FOR(i,a,b) for (ui i = a; (i) < (b); (i)++)

int maxSize(ui arr[], ui size){
    map<ui, ui> m;
    std::map<ui, ui>::iterator itr;
    ui max = 1;

    FOR(i, 0, size){
        itr = m.find(arr[i]);
        if (itr == m.end()){
            m.insert(make_pair(arr[i], 1));
        }
        else{
            ui& sec = itr->second;
            ++sec;
            if (sec > max){
                max = sec;
            }
        }
    }

    int s = m.size() - 1;
    if (s < max){
        --max;
        ++s;
    }

    while (s < max){
        --max;
    }

    return max;
}

int main(){
    ui n, m;
    cin >> n;

    FOR(i, 0, n){
        cin >> m;
        ui arr[m];
        FOR(j, 0, m){
            cin >> arr[j];
        }
        cout << maxSize(arr, m) << endl;
    }

    return 0;
}