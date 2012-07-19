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

void swap(int &x, int &y)
{
	int t;

	t = x;
	x = y;
	y = t;
}

void sort(int *a, int l, int r)
{
    int i = l, j = r, x = a[(r + l) /2];

    do
    {
	while(a[i]<x)
	    i++;r2++;
	while(a[j]>x)
	    j--;r2++;
	if(i<=j)
	    swap(a[i++], a[j--]); r1++;
    }while(i<=j);

    if (i < r)
	sort(a,i,r);
    if (l < j)
	sort(a,l,j);
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
 sort(a,0,N);
 end=clock();
 printf("Massive \tTime (sec) \tAppropriation \t   Compare\n\n");
 printf("Random: \t%10f \t%10ld \t%10ld \n",(end-start)/CLK_TCK,r1,r2);
 r1=0;r2=0;
 start=clock();
 sort(a,0,N);
 end=clock();
 printf("Increasing:   \t%10f \t%10ld \t%10ld \n",(end-start)/CLK_TCK,r1,r2);
 sort2(a);
 r1=0;r2=0;
 start=clock();
 sort(a,0,N);
 end=clock();
 printf("Recedes: \t%10f \t%10ld \t%10ld \n",(end-start)/CLK_TCK,r1,r2);

 getch();
}