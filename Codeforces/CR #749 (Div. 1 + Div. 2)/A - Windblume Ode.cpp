#include<bits/stdc++.h>
using namespace std;

#define Nmax 100


int T;
int N;
int A[Nmax];

bool num[Nmax];

int sum(int a[], bool subset[], int N){
    int s = 0;
    for(int n = N; n--;) s += a[n]*subset[n];
    return s;
}

int isprime(int n){
    for(int d = 2; d <= (int) sqrt(n); d++)
        if(n % d == 0) return false;
    return true;
}

int x;
int k, j;

int main(){
    scanf("%d", &T);
    for(int t = 1; t <= T; t++){
        scanf("%d", &N);
        for(int n = 0; n < N; n++) scanf("%d", A+n);

        for(int n = 0; n < N; n++) num[n] = true;
        k = N; j = 0;
        while(k){
            x = sum(A, num, N);
            
            //for(int i = 0; i < N;) cout << num[i++]; cout << endl;


            if(!isprime(x)) break;

            if(k == N){
                k--;
                num[0] = false;
            }else{
                if(num[k] == false){
                    k--; j = 0;
                    num[j] = false;
                }else{
                    num[j++] = true;
                    num[j] = false;
                }
            }
        }

        printf("%d\n", k);
        for(int i = N; i--;)
            if(num[N-1-i])
                printf("%d%c", N-i, i ? ' ' : '\n');
        
    }
    
    return 0;
}