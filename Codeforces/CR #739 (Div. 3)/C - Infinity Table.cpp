#include <bits/stdc++.h>

using namespace std;

int t, k;
int r, c, x;
int main() {
    cin >> t;

    for(int j = 0; j < t; j++){
        cin >> k;
        
        x = (int) sqrt(k-1);
        //x²+1, ..., (x+1)²: 2x+1
        k -= x*x;
        if(k <= x+1) {c = x+1; r = k;}
        else {r = x+1; c = 2*(x+1) - k;}


        cout << r << ' ' << c << endl;
    }
    
    

    return 0;
}