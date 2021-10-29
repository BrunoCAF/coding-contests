#include<bits/stdc++.h>
using namespace std;

#define MAX 1000000


int T;
string s;

int main(){
    scanf("%d", &T);
    for(int t = 1; t <= T; t++){
        cin >> s;
        if(s.front() != s.back())
            s.front() = s.back();

        cout << s << endl;
    }
    
    return 0;
}