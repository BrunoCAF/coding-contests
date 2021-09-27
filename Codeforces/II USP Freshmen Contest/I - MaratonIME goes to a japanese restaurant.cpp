#include <stdio.h>

int main ()
{

    long int n;
    int T;
    scanf("%ld",&n);
    scanf("%d",&T);

    int p[n];
    int i;
for (i=0;i<n;i++)
{scanf("%d",&p[i]);}

long int sy=0,sn=0;
int cy=0, cn=0;

for (i=0;i<n;i++)
{
    if (sy+p[i]<=T){
        sy+=p[i];
        cy++;}

    else{
        break;
    }

}

for (i=0;i<n;i++)
{
    if (sn+p[n-1-i]<=T){
        sn+=p[n-1-i];
        cn++;}

    else{break;}
    }

    if(cn>cy) {printf("Nathan");}
    if(cn<cy) {printf("Yan");}
    if(cn==cy) {printf ("Empate");}

    return 0;
}
