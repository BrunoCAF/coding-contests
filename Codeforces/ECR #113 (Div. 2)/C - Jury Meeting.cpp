#include <bits/stdc++.h>

using namespace std;

#define M 998244353
#define Nmax 200000

int t;
int n;
long int A[Nmax] = {0, };


int cont;
long int maior;

long int nfat = 1;
long int n_cfat = 1;
long int S = 0;

long int a[Nmax] = {0, }, b[Nmax] = {0, };

int main() {
    scanf("%d", &t);
    for(;t--;){
        scanf("%d", &n);

        maior = 0;
        cont = 0;
        for(int i = 0; i < n; i++) {
            scanf("%ld", A+i);
            if(A[i] > maior){
                maior = A[i];
                cont = 1;
            }else if(A[i] == maior) cont++;
        }

        //cout << "Contei os maior: "  << cont << endl;

        nfat = 1;
        for(int N = n; --N; nfat = (long long) nfat*(N+1) % M);

        if(cont > 1) 
            printf("%ld\n", nfat);
        else {
            

            //cout << n << "! = "  << nfat << endl;

            cont = 0;
            for(int i = 0; i < n; i++)
                if(A[i] <= maior-2) cont++;
            
            //cout << "Contei os cara menor que o max-1: "  << cont << endl;

            if(cont+1 == n) {
                printf("%d\n", 0);
                continue;
            }

            n_cfat = 1;
            for(int N = n-cont-1; N--; n_cfat = (long long) n_cfat*(N+1) % M);

            S = 0;

            a[0] = 1; 
            for(int j = 1; j <= cont; j++) a[j] = (long long) a[j-1] * (cont-j+1) % M;

            b[cont] = n_cfat;
            for(int j = cont-1; j >= 0; j--) b[j] = (long long) b[j+1] * (n-j-1) % M;

            for(int j = 0; j <= cont; j++) S = (S + ((long long) a[j]*b[j]) % M) % M;

            printf("%ld\n", (nfat-S) + ((nfat - S) < 0 ? M : 0));

        }

    }

    return 0;
}