#include <stdio.h>
#include <math.h>

int main()
{


long int n;
scanf("%ld",&n);

long int i;

int floor[n];
for (i=0;i<n;i++)
{scanf("%d",&floor[i]);}

int foot[n];
for (i=0;i<n;i++)
{scanf("%d",&foot[i]);}

int chain[n];
for (i=0;i<n;i++)
{scanf("%d",&chain[i]);}

long int dfc,dff;
long long int raiz1=0,raiz2=0;

for (i=0;i<n;i++) {
raiz1+=(floor[i]-chain[i])*(floor[i]-chain[i]); }

for (i=0;i<n;i++) {
raiz2+=(floor[i]-foot[i])*(floor[i]-foot[i]); }

dfc= sqrt(raiz1);
dff= sqrt(raiz2);

if (dff<=dfc) {printf("Yan");}
else {printf("MaratonIME");}

return 0;
}
