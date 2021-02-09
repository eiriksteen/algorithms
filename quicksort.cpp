#include <iostream>
#include <vector>
using namespace std;

int lomutoPartition(int lo, int hi, vector<int>& v){
    int piv = v[hi];
    int i = lo;
    for (int j = lo; j < hi; j++){
        if (v[j] < piv){
            swap(v[i], v[j]);
            ++i;
        }
    }
    swap(v[i], v[hi]);
    return i;
}

void lomutoQuicksort(int lo, int hi, vector<int>& v){
    if (lo < hi){
        int p = lomutoPartition(lo, hi, v);

        lomutoQuicksort(lo, p-1, v);
        lomutoQuicksort(p+1, hi, v);
    }
}

int main(){
    return 0;
}
