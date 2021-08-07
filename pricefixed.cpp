//
// Created by Eirik Drage Steen on 04/08/2021.
//

// https://codeforces.com/contest/1539/problem/D

#include "iostream"
#include "queue"
using namespace std;

typedef long long int lli;
typedef pair<lli, lli> pii;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    lli a, b, sum, prdcnt;
    prdcnt = 0;
    sum = 0;
    cin >> n;
    priority_queue<pii> pq;

    while (n--){
        cin >> a >> b;
        pq.push({b, a});
        prdcnt += a;
    }

    while (!pq.empty()){
        pii p = pq.top();
        pq.pop();
        if (p.first <= prdcnt - 1){
            lli diff = prdcnt - p.first;
            if (diff >= p.second){
                sum += p.second;
                prdcnt -= p.second;
            }
            else{
                sum += diff + 2*(p.second - diff);
                prdcnt -= diff;
            }
        }
        else{
            sum += p.second*2;
        }
    }

    cout << sum << endl;

    return 0;
}
