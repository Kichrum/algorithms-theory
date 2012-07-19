#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
int N;

int create(int *a)
{
 int i;
 randomize();
 for(i=0;i<N;i++) {
   a[i]=random(N);
  }
 return 0;
}

int sort1(int *a, long &b1, long &b2)
{
 b1=0;
 b2=0;
 int i,j,c;
 for(i=1;i<N;i++)
  {
  c=a[i];
  for (j=i-1;j>=0 && a[j]>c;j--)
    {a[j+1]=a[j]; b1++; b2++;}
   a[j+1]=c;
   b2++;

  }
 return 0;
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
 long b1,b2;
 clock_t start, end;

 create(a);
 start=clock();
 sort1(a,b1,b2);
 end=clock();
 printf("Massive \tTime (sec) \tAppropriation \t   Compare\n\n");
 printf("Random: \t%10f \t%10ld \t%10ld \n",(end-start)/CLK_TCK,b1,b2);

 start=clock();
 sort1(a,b1,b2);
 end=clock();

 printf("Increasing:   \t%10f \t%10ld \t%10ld \n",(end-start)/CLK_TCK,b1,b2);

 create(a);

 sort2(a);
 start=clock();
 sort1(a,b1,b2);
 end=clock();

 printf("Recedes: \t%10f \t%10ld \t%10ld \n",(end-start)/CLK_TCK,b1,b2);

 getch();
}