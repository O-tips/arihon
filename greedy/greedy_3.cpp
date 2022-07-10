#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0; i<(n); i++)
const long long INF = numeric_limits<long long>::max();

string rev(string s){
    string t = "";
    for(int i = 0;i < s.size();i++) t += s[i];
    return t;
}

string el_head(string s){
    string t = "";
    for(int i = 1;i < s.size();i++) t += s[i];
    return t;
}

string solution(int n, string s){
    string t = "";
    
    for(int i = 0;i < n;i++){
        string sub_s = rev(s);
        if(s < sub_s){
            t += s[i];
            s = el_head(s);
        }
        else{
            t += sub_s[0];
            s = el_head(sub_s);
        }
    }

    return t;
}

int main()
{
    string ans = solution(6, "ACDBCB");
    cout << "ans : ACDBCB" << " " << ans << endl;
    return 0;
}