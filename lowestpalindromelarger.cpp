//
// Created by Eirik Drage Steen on 08/05/2021.
//

// https://www.spoj.com/problems/PALIN/
// algorithm to find smallest palindrome larger than the input number


#include "iostream"
using namespace std;

void stringExpAddition(string& num, int addIndex){
    // adds 10 ^ (len(num) - 1 - addIndex) to number num
    // needs to be done this way since num can be too large for normal mathematical computation
    
    if (num[addIndex] < '9' && num[addIndex] >= '0'){
        ++num[addIndex];
        return;
    }

    else if (addIndex == 0){
        num.erase(0, 1);
        num = "10" + num;
        return;
    }

    num[addIndex] = '0';
    return stringExpAddition(num, addIndex - 1);
}


string lpl(string snum) {
    int start = 0;
    stringExpAddition(snum, snum.length() - 1);
    int end = snum.length() - 1;

    while (start < end){
        char l = snum[start];
        char r = snum[end];

        // continue if digits already mirror each other
        if (l == r){
            ++start;
            --end;
            continue;
        }

        // set right side digit equal to left side digit if l > r (otherwise the result decreases in size)
        else if (l > r){
            snum[end] = l;
        }

        // inorder to keep left side digit (higher decimal place is prioritized -> result should be as small as possible), digit 
        // to the left of right side digit needs to increase by one (apply recursively if digit already is 9) 
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
