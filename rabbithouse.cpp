//
// Created by Eirik Drage Steen on 25/06/2021.
//

// https://codingcompetitions.withgoogle.com/kickstart/round/0000000000436140/000000000068cb14#problem

#include "iostream"
#include "map"
#include "vector"
using namespace std;

#define FOR(i,a,b) for (int (i) = a; (i) < (b); (i)++)
typedef long long int lli;

void removePair(vector<pair<int, int>>& v, int i, int j){
    int it = 0;
    for (pair<int, int> p : v){
        if (i == p.first && j == p.second){
            v.erase(v.begin() + it);
        }
        ++it;
    }
}

void insertKey(map<lli, vector<pair<int, int>>>& m, map<lli, vector<pair<int, int>>>::iterator& itr, lli& val, int i, int j){
    itr = m.find(val);
    if (itr == m.end()){
        m.insert(pair<int, vector<pair<int,int>>> (val, {make_pair(i, j)}));
    }
    else{
        itr->second.emplace_back(i, j);
    }
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    FOR(k, 0, n){
        int r, c;
        lli res = 0;
        cin >> r >> c;
        lli arr[r][c];
        map<lli, vector<pair<int, int>>> m;
        map<lli, vector<pair<int, int>>>::iterator itr;

        FOR(i, 0, r){
            FOR(j, 0, c){
                cin >> arr[i][j];
                lli &val = arr[i][j];
                insertKey(m, itr, val, i, j);
            }
        }


        for(auto x = m.rbegin(); x != m.rend(); x++) {
            for (pair<int, int> p : x->second) {
                int i = p.first;
                int j = p.second;
                lli cur = arr[i][j];

                lli &up = (i > 0 ? arr[i - 1][j] : cur);
                lli &down = (i < r - 1 ? arr[i + 1][j] : cur);
                lli &right = (j < c - 1 ? arr[i][j + 1] : cur);
                lli &left = (j > 0 ? arr[i][j - 1] : cur);

                if (up < cur - 1) {
                    itr = m.find(up);
                    removePair(itr->second, i - 1, j);
                    res += cur - 1 - up;
                    up = cur - 1;
                    insertKey(m, itr, up, i - 1, j);
                }
                if (down < cur - 1) {
                    itr = m.find(down);
                    removePair(itr->second, i + 1, j);
                    res += cur - 1 - down;
                    down = cur - 1;
                    insertKey(m, itr, down, i + 1, j);
                }
                if (right < cur - 1) {
                    itr = m.find(right);
                    removePair(itr->second, i, j + 1);
                    res += cur - 1 - right;
                    right = cur - 1;
                    insertKey(m, itr, right, i, j + 1);
                }
                if (left < cur - 1) {
                    itr = m.find(left);
                    removePair(itr->second, i, j - 1);
                    res += cur - 1 - left;
                    left = cur - 1;
                    insertKey(m, itr, left, i, j - 1);
                }
            }
        }

        cout << "Case #"<< k + 1 << ": " << res << endl;
    }

    return 0;
}
