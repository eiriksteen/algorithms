//
// Created by Eirik Drage Steen on 08/05/2021.
//

// https://www.spoj.com/problems/PALIN/
// algorithm to find smallest palindrome larger than the input number


#include "iostream"
using namespace std;

void stringExpAddition(string& num, int add){
    if (num[add] < '9' && num[add] >= '0'){
        ++num[add];
        return;
    }

    else if (add == 0){
        num.erase(0, 1);
        num = "10" + num;
        return;
    }

    num[add] = '0';
    return stringExpAddition(num, add - 1);
}


string lpl(string snum) {
    int start = 0;
    stringExpAddition(snum, snum.length() - 1);
    int end = snum.length() - 1;

    while (start < end){
        char l = snum[start];
        char r = snum[end];

        if (l == r){
            ++start;
            --end;
            continue;
        }

        else if (l > r){
            snum[end] = l;
        }

        else{
            stringExpAddition(snum, end - 1);
            snum[end] = snum[start];
        }

        ++start;
        --end;
    }

    return snum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i;
    string num;
    cin >> i;

    for (int x = 0; x < i; x++){
        cin >> num;
        cout << lpl(num) << "\n";
    }
}
