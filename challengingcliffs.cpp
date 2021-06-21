//
// Created by Eirik Drage Steen on 21/06/2021.
//

// https://codeforces.com/contest/1537/problem/C

// hei hei denne koden er ulesbar

#include "iostream"
#include "algorithm"
using namespace std;

#define FOR(i,a,b) for (int (i) = a; (i) < (b); (i)++)

int main(){
    int n, m;
    cin >> n;

    FOR(i, 0, n){
        cin >> m;
        int arr[m];
        FOR(j, 0, m){
            cin >> arr[j];
        }
        std::sort(arr, arr + m);
        int t1 = 0, t2 = 1;
        int dist = arr[1] - arr[0];
        FOR(k, 1, m){
            if (arr[k] == arr[k - 1]){
                t1 = k - 1;
                t2 = k;
                break;
            }
            else if (arr[k] - arr[k - 1] < dist){
                dist = arr[k] - arr[k - 1];
                t1 = k - 1;
                t2 = k;
            }
        }
        int res[m];
        res[0] = arr[t1];
        res[m - 1] = arr[t2];

        int i2 = 1;
        FOR(k, t1 + 1, m){
            if (k != t1 && k != t2) {
                res[i2] = arr[k];
                ++i2;
            }
        }
        FOR(k, 0, t1){
            if (k != t1 && k != t2) {
                res[i2] = arr[k];
                ++i2;
            }
        }

        FOR(k, 0, m){
            cout << res[k] << " ";
        }
        cout << endl;
    }

    return 0;
}
