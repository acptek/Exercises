#include <bits/stdc++.h>
using namespace std;

int myAtoi(string str) {
    int flag = 0, num = 0, tag = 1, plust = 0; //-1
    string sub;
    int tt = 0;
    for(int i = 0; i < str.length(); i++){
        if(str[i] >= '0' && str[i] <= '9'){
            flag = 1;
            sub += str[i];
        }else if(str[i] == ' ' && !flag && !plust && tag != -1) continue;
        else if(str[i] == '+' && sub.length() == 0 && tag != -1 && !plust) plust = 1;
        else if(str[i] == '-' && sub.length() == 0 && !plust && tag != -1) tag = -1;
        else break;
    }
    long long res = 0;
    if(sub.length() == 0) res = 0;
    else{
        long long base = 1;
        int kk = 0;
        for(int i = sub.length()-1; i >= 0; i--){
            res += (sub[i] - '0')*base;
            if(res >= 2147483648){
                kk = 1;
                break;
            }
            if(base < 1e15) base *= 10;
        }
        if(kk){
            if(tag == -1){
                res = -2147483648;
            }else{
                res = 2147483648-1;
            }
        }else{
            res = tag*res;
        }
    }
    return res;
}

int main()
{
    string s;
    cin>>s;
    long long t = myAtoi(s);
    cout<<t<<endl;
    return 0;
}
