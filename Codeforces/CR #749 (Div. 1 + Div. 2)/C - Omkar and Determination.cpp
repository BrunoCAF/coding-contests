#include<bits/stdc++.h>
using namespace std;

#define MAX 1000000


int T;
int N, M;
int Q;

bool det;
int xl, xr;

bool a[MAX];
int e[MAX];
char grid;

int main(){
    //scanf("%d", &T);
    T = 1;
    for(int t = 1; t <= T; t++){
        scanf("%d %d", &N, &M);
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                cin >> grid;
                a[i*M+j] = (grid == '.');
                if(i*j == 0) e[i*M+j] = 1;
                else{
                    e[i*M+j] = max(e[(i-1)*M+j], e[i*M+j-1]);
                    if(!(a[(i-1)*M+j] || a[i*M+j-1]))
                        e[i*M+j] = j+1;
                }
            }
        }

        scanf("%d", &Q);
        for(int q = 0; q < Q; q++){
            scanf("%d %d", &xl, &xr);
            
            det = (xl >= e[(N-1)*M + xr-1]);

            printf("%s\n", det ? "YES" : "NO");
        }
    }
    
    return 0;
}