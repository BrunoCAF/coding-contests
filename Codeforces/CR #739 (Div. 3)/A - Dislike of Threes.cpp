#include <bits/stdc++.h>

using namespace std;

int t, k, x;

int main() {
    cin >> t;

    for(int j = 0; j < t; j++){
        cin >> k;
        x = 30*((k-1)/18);
        k = (k-1) % 18 + 1;
        //12.45.78.1011..14.1617.1920.22..2526.2829.
        while(k) {
            k--;
            do {x++;} while(x%3 == 0 || x%10 == 3);
        }


        cout << x << endl;
    }
    
    

    return 0;
}