//
// Created by Eirik Drage Steen on 11/07/2021.
//

// https://codeforces.com/contest/1512/problem/D

#include "iostream"
#include "algorithm"
using namespace std;

#define FOR(i,a,b) for (int (i) = a; (i) < (b); (i)++)
typedef long long int lli;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    lli n, m;
    cin >> n;

    while(n--){
        lli sum = 0;
        cin >> m;
        lli arr[m + 2];
        FOR(i, 0, m + 2){
            cin >> arr[i];
            sum += arr[i];
        }

        std::sort(arr, arr + m + 2);

        if (sum - arr[m] - arr[m + 1] == arr[m]){
            FOR(j, 0, m){
                cout << arr[j] << " ";
            }
            cout << endl;
            continue;
        }

        bool c = false;
        lli actsum = arr[m + 1];
        sum -= actsum;

        FOR(j, 0, m + 1){
            if (sum - arr[j] == actsum){
                FOR(k, 0, m + 1){
                    if (k != j){
                        cout << arr[k] << " ";
                    }
                }

                cout << endl;
                c = true;
                break;
            }
        }

        if (!c) {
            cout << -1 << endl;
        }
    }

    return 0;
}