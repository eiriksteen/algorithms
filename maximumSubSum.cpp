//
// Created by Eirik Drage Steen on 11/06/2021.
//

// https://www.spoj.com/problems/GSS1/

#include "iostream"
using namespace std;

const int maxSize = 50000;

struct data{
    int sum, pref, suff, ans;

    data(int ans){
        this->ans = ans;
    }
    data()= default;
};

data t[4 * maxSize];

data combine(data left, data right){
    data res = data();

    res.sum = left.sum + right.sum;
    res.pref = max(left.pref, left.sum + right.pref);
    res.suff = max(right.suff, right.sum + left.suff);
    res.ans = max(max(left.pref, right.suff), left.suff + right.pref);

    return res;
}

void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        int s = a[tl];
        data& n = t[v];
        n.sum = s;
        //if (s > 0){
            n.ans = s;
            n.pref = s;
            n.suff = s;
        //}
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2 + 1, tl, tm);
        build(a, v*2 + 2, tm + 1, tr);
        t[v] = combine(t[v*2 + 1], t[v*2 + 2]);
    }
}

data query(int v, int l, int r, int tl, int tr){
    if (l > r){
        return data(0);
    }
    if (l == tl && r == tr){
        return t[v];
    }
    int mid = (tl + tr)/2;
    if (l >= tl && r <= mid){
        return query(2*v + 1, l, r, tl, mid);
    }
    else if (r <= tr && l >= mid + 1){
        return query(2*v + 2, l, r, mid + 1, tr);
    }

    return combine(query(v*2, l, min(r, mid), tl, mid),
                   query(v*2+1, max(l, mid+1), r, mid+1, tr));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int size;
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++){
        cin >> arr[i];
    }

    build(arr, 0, 0, size - 1);

    int amount;
    cin >> amount;
    for (int i = 0; i < amount; i++){
        int st;
        int en;
        cin >> st;
        cin >> en;
        cout << query(0, st - 1, en - 1, 0, size - 1).ans << endl;
    }

    return 0;
}
