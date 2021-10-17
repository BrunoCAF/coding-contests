#include<bits/stdc++.h>
using namespace std;

#define Kmax 100000


int T;
int K;
typedef pair<long,long> pp;
typedef vector<pp> vpp;
vpp lcorners, rcorners;
long x[3], y[3];

bool compx(pp a, pp b){ return a.first < b.first;}
bool compy(pp a, pp b){ return a.second < b.second;}

int a, b;

vpp::iterator lcorner, rcorner;

int main(){
    scanf("%d", &T);
    for(int t = 1; t <= T; t++){
        scanf("%d", &K);
        lcorners.resize(K); rcorners.resize(K);
        for(int k = 0; k < K; k++){
            scanf("%ld %ld %ld %ld", x+1, y+1, x+2, y+2);
            lcorners[k] = make_pair(x[1], y[1]); 
            rcorners[k] = make_pair(x[2], y[2]);
        }
        sort(lcorners.begin(), lcorners.end(), compx);
        sort(rcorners.begin(), rcorners.end(), compx);
        lcorner = lcorners.begin(); a = K;
        rcorner = rcorners.begin(); b = 0;
        for(x[0] = lcorner->first; a-b > 0; ){
            x[0] = min(lcorner->first, rcorner->first);
            while(x[0] == lcorner->first) {lcorner++; a--;}
            while(x[0] == rcorner->first) {rcorner++; b++;}
            //printf("a = %d, b = %d, x = %ld\n", a, b, x[0]);
        }
        
        

        sort(lcorners.begin(), lcorners.end(), compy);
        sort(rcorners.begin(), rcorners.end(), compy);
        lcorner = lcorners.begin(); a = K;
        rcorner = rcorners.begin(); b = 0;
        for(y[0] = lcorner->second; a-b > 0; ){
            y[0] = min(lcorner->second, rcorner->second);
            while(y[0] == lcorner->second) {lcorner++; a--;}
            while(y[0] == rcorner->second) {rcorner++; b++;}
            //printf("a = %d, b = %d, y = %ld\n", a, b, y[0]);
        }
        

        printf("Case #%d: %ld %ld\n", t, x[0], y[0]);
    }
    
    return 0;
}