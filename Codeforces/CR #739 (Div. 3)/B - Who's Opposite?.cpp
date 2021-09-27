#include <bits/stdc++.h>

using namespace std;

int t, a, b, c, d;
int n;
int main() {
    cin >> t;

    for(int j = 0; j < t; j++){
        cin >> a >> b >> c;
        //N = 2n
        //1 <-> n+1
        //a <-> b => b-a = n
        //1 <= min(a,b) <= n; n+1 <= max(a,b) <= 2n
        
        n = abs(b-a); d = -1;
        if((1 <= min(a,b) && min(a,b) <= n) && (n+1 <= max(a,b) && max(a,b) <= n+n)){
            if(c <= n) d = n+c;
            else if(c <= 2*n) d = c-n;
            else d = -1;
        }

        cout << d << endl;
    }
    
    

    return 0;
}