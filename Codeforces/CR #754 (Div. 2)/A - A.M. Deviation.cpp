#include<bits/stdc++.h>
using namespace std;

#define MAX 1000000


int T;
int N;

int a[3];

int main(){
    scanf("%d", &T);
    for(int t = 1; t <= T; t++){
        scanf("%d %d %d", a, a+1, a+2);

        N = abs(a[0]+a[2] - 2*a[1]);


        printf("%d\n", N % 3 ? 1 : 0);
    }
    
    return 0;
}