#include <iostream>
#include <cstdlib>
#include <cstdio>

#define MEX 100000

using namespace std;

int main(){
    int x[3];
    int u, v;
    int *pilha;
    cin >> x[1] >> x[2];
    enum{
        e = 1, d
    };
    do{
        pilha = (x[e] > x[d]) ? &x[e] : &x[d];
        cout << ((x[e]>x[d]) ? e : d) << " " << ((x[e] > x[d]) ? x[e]-x[d] : x[d]-x[e]) << endl;
        *pilha -= ((x[e] > x[d]) ? x[e]-x[d] : x[d]-x[e]);
        //cout << "Pilhas: (" << x[e] << ", " << x[d] << ")"<< endl;
        if(x[e] == 0 && x[d] == 0){
            //cout << "Wins!" << endl;
            break;
            //return 0;
        }
        cout.flush();
        cin >> u >> v;
        x[u] -= v;
        //cout << "Pilhas: (" << x[e] << ", " << x[d] << ")"<< endl;
    }while(x[e] != 0 || x[d] != 0);
    //cout << "Loss!" << endl;
    return 0;
}

