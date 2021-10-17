#include<bits/stdc++.h>
using namespace std;

#define Nmax 5000


int T;
int N, K;
int B[Nmax];
long Bcum[Nmax+1];

bool possible;
int n;

int r1,l1,r2,l2;

int main(){
    scanf("%d", &T);
    for(int t = 1;t <= T; t++){
        scanf("%d %d", &N, &K);
        Bcum[0] = 0;
        for(int i = 0; i < N; i++){
            scanf("%d", B+i);
            Bcum[i+1] = B[i]+Bcum[i];
        }
        n = N; possible = false;
        for(r1=0; r1<N; r1++){
            for(l1=r1; l1<=N; l1++){
                for(r2=l1; r2<=N; r2++){
                    for(l2=r2; l2<=N; l2++){
                        if(Bcum[l1] - Bcum[r1] + Bcum[l2] - Bcum[r2] == K){
                            possible = true;
                            n = min(n, l1-r1+l2-r2);
                        }
                    }
                }
            }
        }
        
        
        printf("Case #%d: %d\n", t, possible ? n : -1);
    }
    
    return 0;
}