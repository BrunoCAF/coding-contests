#include <bits/stdc++.h>

using namespace std;

int t;
long int c, d;
int n;

int main() {
    scanf("%d", &t);
    
    for(int j = 0; j < t; j++){
        scanf("%ld %ld", &c, &d);
        
        printf("%s\n", ((c+d) % 2) ? "-1" : (c == d ? (c+d ? "1" : "0") : "2"));
    }
    
    

    return 0;
}