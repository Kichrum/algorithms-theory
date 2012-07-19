#include <stdio.h>
#include <conio.h>
#include <stdlib.h>


int n;
int *elements;
int iter;

int Add(int key){
  int f=0;
  int value = key % n;
  if (elements[value] == -1)
  {
    elements[value] = key;
    f = 1;
    iter++;
  }
  else
  {
     int i = value + 1;
     while (i < n)
     {
	if (elements[i] == -1)
	{
	  elements[i] = key;
	  f=1;
	  iter++;
	  break;
	}
	else
	  {i++;
	  iter++;}
	iter++;
     }

     if (!f)
     {
	i = 0;
	while (i<value)
	{
	  if (elements[i] == -1)
	  {
	    elements[i] = key;
	    f = 1;
	    iter++;
	    break;
	  }
	  else
	    {i++;
	    iter++;}
	  iter++;
	}
      iter++;
     }
    iter++;
  }
 return f;
}

void Search()
{
  clrscr();
  int f = 0;
  int key = 0;
  printf("Enter key to search: ");
  scanf("%d", &key);
  for (int i=0; i<n; i++)
    if (elements[i] == key)
    {
      printf("Key found at string No. %d\n", i);
      f = 1;
    }
  if (!f)
    printf("Key not found!\n");

  getch();
}

void Print()
{
  clrscr();
  FILE *f=fopen("table.txt","w");
  for (int i=0; i<n; i++)
    {
     fprintf(f,"%d:\t%d\n",i, elements[i]);
    }
   puts("Saved to 'TABLE.TXT'!");
   fclose(f);

  getch();
}


void main()
{
  randomize();
  n=1000;
  float w; sscanf("1","%f",&w);
  int i,p,f=0,k;
    clrscr();
    printf("Protsent zapovnennya: "); scanf("%d",&p);

  char c = '1';

  k=(int)(n*(float)p/100);

  elements = new int[n];
  for (i=0; i<n; i++)
    elements[i] = -1;

  while (c != 'q')
  {
    clrscr();
    printf("Menue:\n\n");
    printf("1. Zapovnyty\n");
    printf("2. Poshuk\n");
    printf("3. '+25 elements'\n");
    printf("4. Print to 'TABLE.TXT'\n");
    printf("q. Quit\n\n");
    printf(">> ");

    c = getch();

    switch(c)
    {
      case '1':
	for(i=0; i<k; i++)
	 f=Add(random(29999)+1);
	if (f==1)
	 printf("%d elements added!",k);
	else printf("Very Small or Big percent (hash-table is full)!");
	getch();

	break;

      case '2':
	Search();
	break;

      case '3':
	//Print();
	iter=0;
//	Begin=clock();
	for(i=0; i<25; i++)
	 f=Add(random(29999)+1);
//	End=clock();
	if (f==1)
	 printf("%d elements added!\n",25);
	else printf("Small percent or hash-table is full!\n");
	printf("Iteratsiy: %d\n",iter);
	getch();

	break;
      case '4':
	Print();
	break;

      case 'q':
	break;

      default:
	printf("Wrong choise!\n");
	getch();
	break;
    }
  }
}
