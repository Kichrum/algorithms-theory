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

void sortdop(int *a, int b, int c, int d)
{
int n1=c-b+1;
int n2=d-c;

int *left=(int*)malloc((n1+1)*sizeof(int));
int *right=(int*)malloc((n2+1)*sizeof(int));

int i,j,k;

for(i=0;i<n1;i++)
 {left[i]=a[b+i];r1++;}

for(j=0;j<n2;j++)
 {right[j]=a[c+j+1];r1++;}

left[n1]=int((long)((1<<15)-1));
right[n2]=int((long)((1<<15)-1));

for(k=b,i=0,j=0;k<=d;k++)
 if ((++r2)&&left[i]<=right[j])
  {a[k]=left[i];i++;r1++;}
   else {a[k]=right[j];j++;r1++;}

free(left); free(right);
}


void sort(int *a,int b, int d)
{
int c;
if (b<d)
 {
  c=(b+d)/2;
  sort(a,b,c);
  sort(a,c+1,d);
  sortdop(a,b,c,d);
 }
}


void sort2(int *a)
{
int i,j,buf;

  for(i=1;i<N;i++) {
    buf=a[i];
    for(j=i-1;j>=0&&buf>a[j];j--)
     a[j+1]=a[j];
  a[j+1]=buf;
  }
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
 sort(a,0,N-1);
 end=clock();
 printf("Massive \tTime (sec) \tAppropriation \t   Compare\n\n");
 printf("Random: \t%10f \t%10ld \t%10ld \n",(end-start)/CLK_TCK,r1,r2);

 r1=0; r2=0;
 start=clock();
 sort(a,0,N-1);
 end=clock();

 printf("Increasing:   \t%10f \t%10ld \t%10ld \n",(end-start)/CLK_TCK,r1,r2);


 sort2(a);
 r1=0; r2=0;
 start=clock();
 sort(a,0,N-1);
 end=clock();

 printf("Recedes: \t%10f \t%10ld \t%10ld \n",(end-start)/CLK_TCK,r1,r2);


 getch();
}