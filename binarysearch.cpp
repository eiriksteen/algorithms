#include <iostream>
#include <vector>
using namespace std;

int binarySearch(int target, int start, int end, vector<int> v){
    int i = (start + end)/2;

    if (target < v[i]){
        return binarySearch(target, start, i, v);
    }
    if (target > v[i]){
        return binarySearch(target, i, end, v);
    }
    else{
        return i;
    }
}

int main(){
    return 0;
}
