#include <bits/stdc++.h>

using namespace std;

int t;
int n;
int cont;

string s = {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 
            'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a',
            'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a',
            'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a',
            'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'};

bool possible;

char matrix[50][50];
int humble[50];

int main() {
    for(int i = 0; i < 50; i++) {matrix[i][i] = 'X'; humble[i] = -1;}
    
    scanf("%d", &t);
    for(;t--;){
        scanf("%d", &n);

        for(int i = 0; i < n; i++) for(int j = i+1; j < n; j++) matrix[i][j] = matrix[j][i] = '=';

        cin >> s;
        cont = 0;
        for(int i = 0; i < n; i++) if(s[i] == '2') humble[cont++] = i;
        
        possible = (cont == 0) || (cont > 2);
        
        printf("%s\n", possible ? "YES" : "NO");
        if(possible){
            if(cont){
                for(int k = 0; k < cont; k++){
                    matrix[humble[k]][humble[(k+1) % cont]] = '+';
                    matrix[humble[(k+1) % cont]][humble[k]] = '-';
                }
            }

            for(int i = 0; i < n; i++) 
                for(int j = 0; j <= n; j++) 
                    printf("%c", j==n ? '\n' : matrix[i][j]);
        }
    }

    return 0;
}