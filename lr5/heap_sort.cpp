#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
int N;
long r1,r2;

int create(int *a)
{
 int i;
 randomize();
 for(i=0;i<N;i++) {
   a[i]=random(N);
  }
 return 0;
}
void postroyka ( int *a, int n)
{
  int b, c, k=0;
  c = (n-1)/2;
  while(c>=0 && !k)
  {
    if(a[n]>a[c])
     {
       b = a[n];
       a[n]=a[c];
       a[c]=b;
       n=c;
       c=c/2;
  r1++;
     }
     else
       k=1;
  r2++;
  }
}

void sort(int *a)
{
   int i,b,n;
  r1=0; r2=0;
   for(i=0;i<N;i++)
    postroyka(a,i);
   n=N-1;
   while(n>0)
   {
   b=a[0];
   a[0]=a[n];
   a[n]=b;
  r1++;
   for(i=0;i<n;i++)
    postroyka(a,i);
   n--;
   }
}
int sort2(int *a)
{
 int i,j,c;
 for(i=1;i<N;i++)
  {
  c=a[i];
  for (j=i-1;j>=0 && a[j]<c;j--)
    a[j+1]=a[j];
   a[j+1]=c;
   }
 return 0;
}
void main()
{
 clrscr();
 int a[10000], i;
 printf("N=");scanf("%d",&N);
 clock_t start, end;
 create(a);
 r1=0; r2=0;
 start=clock();
 sort(a);
 end=clock();
 printf("Massive \tTime (sec) \tAppropriation \t   Compare\n\n");
 printf("Random: \t%10f \t%10ld \t%10ld \n",(end-start)/CLK_TCK,r1,r2);
 start=clock();
 sort(a);
 end=clock();
 printf("Increasing:   \t%10f \t%10ld \t%10ld \n",(end-start)/CLK_TCK,r1,r2);
 sort2(a);
 start=clock();
 sort(a);
 end=clock();
 printf("Recedes: \t%10f \t%10ld \t%10ld \n",(end-start)/CLK_TCK,r1,r2);
 getch();
}