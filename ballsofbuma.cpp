//
// Created by Eirik Drage Steen on 14/06/2021.
//

//https://codeforces.com/contest/1267/problem/B

#include "iostream"
#include <map>
using namespace std;


int bob(const string& s){
    int ctr = 0;
    char c;
    int i = 0;
    int j = s.length() - 1;

    while (i < j && s[i] == s[j]){
        ctr = 0;
        c = s[i];
        while (s[i] == c && i <= j){
            ctr++;
            i++;
        }
        while (s[j] == c && j > i){
            ctr++;
            j--;
        }
        if (i > j){
            if (ctr < 2){
                return 0;
            }
            else{
                return ctr + 1;
            }
        }
        else if (ctr < 3){
            return 0;
        }
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    cout << bob(s) << endl;

    return 0;
}