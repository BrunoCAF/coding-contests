#include<bits/stdc++.h>
using namespace std;

#define Nmax 100000


int T;
int N, M;
int a, b, c;

bool restr[Nmax];


int main(){
    scanf("%d", &T);
    for(int t = 1; t <= T; t++){
        scanf("%d %d", &N, &M);
        for(int n = 0; n < N; n++) restr[n] = true;
        for(int m = 0; m < M; m++) {scanf("%d %d %d", &a, &b, &c); restr[b-1] = false;}

        for(int i = 0; i < N; i++){
            if(restr[i]){
                b = i+1;
                break;
            }
        }

        for(int i = 0; i < N; i++)
            if(b != i+1) 
                printf("%d %d\n", b, i+1);
        
        
    }
    
    return 0;
}