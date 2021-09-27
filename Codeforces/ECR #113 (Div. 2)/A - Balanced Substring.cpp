#include <bits/stdc++.h>

using namespace std;

int t;
int r, l;
int n;
int cb = 0;

string s = {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 
            'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a',
            'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a',
            'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a',
            'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'};

bool found;

int main() {
    scanf("%d", &t);
    for(;t--;){
        scanf("%d", &n);
        cin >> s;
        for(int i = 0; i < n; i++) s[i] -= 'a';
        r = l = -1;
        
        found = false;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j+=2){
                cb = 0;
                for(int k = i; k <= j; k++) cb += s[k];
                
                if(2*cb == j-i+1) {
                    r = i+1; l = j+1;
                    found = true;
                    break;
                }
            }
            if(found) break;
        }
        cout << r << " " << l << endl;
    }

    return 0;
}