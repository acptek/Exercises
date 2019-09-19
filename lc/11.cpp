#include <bits/stdc++.h>
using namespace std;
int maxArea(vector<int>& height) {
    int i = 0, j = height.size()-1;
    int res = 0;
    while(i<j){
        res = max(res, min(height[i], height[j])*(j-i));
        if(height[i] < height[j]) i++;
        else j--;
    }
    return res;
}
int main()
{
    int n; cin>>n;
    vector<int> a;
    for(int i = 0; i < n; i++){
        int t; cin>>t;
        a.push_back(t);
    }
    cout<<maxArea(a)<<endl;
    return 0;
}

//#include <bits/stdc++.h>
//using namespace std;
//
//int maxArea(vector<int>& height){
//    int l[10010] = {0}, r[10010] = {0};
//    stack<int> s;
//    // L to R
//    for(int i = 0; i < height.size(); ++i){
//        if(s.empty()) s.push(height[i]);
//        else{
//            if(height[i] >= height[s.top()]) s.push(i);
//            else{
//                while(!s.empty() && height[i] < height[s.top()]){
//                    r[s.top()] = i-1;
//                    s.pop();
//                }
//                s.push(i);
//            }
//        }
//    }
//    while(!s.empty()){
//        r[s.top()] = height.size()-1;
//        s.pop();
//    }
//    // R to L
//    for(int i = height.size(); i >= 0; --i){
//        if(s.empty()) s.push(height[i]);
//        else{
//            if(height[i] >= height[s.top()]) s.push(i);
//            else{
//                while(!s.empty() && height[i] < height[s.top()]){
//                    l[s.top()] = i+1;
//                    s.pop();
//                }
//                s.push(i);
//            }
//        }
//    }
//    while(!s.empty()){
//        l[s.top()] = 0;
//        s.pop();
//    }
//    int res = 0;
//    for(int i = 0; i < height.size(); i++){
//        res = max(res, (r[i]-l[i])*height[i]);
//    }
//    return res;
//}
//
//int main()
//{
//    int n;
//    cin>>n;
//    vector<int> a;
//    for(int i = 0; i < n; ++i){
//        int t; cin>>t;
//        a.push_back(t);
//    }
//    cout<<maxArea(a)<<endl;
//    return 0;
//}
//
/*
9
1 8 6 2 5 4 8 3 7
*/
