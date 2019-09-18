#include <bits/stdc++.h>
using namespace std;

string convert(string s, int numRows) {
    if(numRows == 1) return s;
    int cnt = 0, k = 0;
    int n1, n2;
    int n = s.length();
    string res;
    for(int i = 1; i <= numRows; i++){
        if(i == 1 || i == numRows){
            n1 = n2 = (numRows-1)*2;
        }else{
            n1 = (numRows-i)*2;
            n2 = (i-1)*2;
        }
        int st = i, times = 0;
        while(st <= n){
            res += s[st-1];
            times++;
            st += times%2?n1:n2;
        }
    }
    return res;
}

int main()
{
    string s;
    int n;
    cin>>s>>n;
    string t = convert(s, n);
    cout<<t<<endl;
    return 0;
}

/*
L   C   I   R
E T O E S I I G
E   D   H   N
*/
