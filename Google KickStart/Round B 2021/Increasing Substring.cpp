#include<iostream>
#include<cstdlib>
#include<string>

#define Nmax 2*10^5

using namespace std;

int T, N, y = 1;
string S;

int main(){
    cin >> T;
    for(int i = 0; i < T; i++){
        cin >> N;
        cin >> S;
        y=1;
        cout << "Case #" << i+1 << ": 1 ";
        for(int j=1; j<N; j++){
            (S[j] > S[j-1]) ? (y++) : (y=1);
            cout << y << " ";
        }
        cout << endl;
    }
    return 0;
}