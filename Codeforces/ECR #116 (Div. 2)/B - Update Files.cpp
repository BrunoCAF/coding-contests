#include<bits/stdc++.h>
using namespace std;

#define MAX 1000000


int T;
long long N, K;

long long h;
int tstar;
long long k, x;

int main(){
    scanf("%d", &T);
    for(int t = 1; t <= T; t++){
        scanf("%lld %lld", &N, &K);
        k = K; x = 1;
        for(tstar = 0; k; tstar++, k >>= 1, x <<= 1);
        
        if(x >= N){
            for(h = 0, x = 1; x < N; h++, x <<= 1);
        }else{
            h = tstar;
            N -= x;
            h += ((N % K) ? 1 : 0) + N/K;
        }
        printf("%lld\n", h);
    }
    
    return 0;
}