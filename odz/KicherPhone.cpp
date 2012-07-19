#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Abonent
    {
      long nmbr;
      char name[20];
      char adrs[50];
      Abonent *next;
    };

    Abonent *ht;
	int mod = 100;
	FILE *f;

void Hash(int);
void xAdd(long,char[],char[]);
void ReadFile(void);
void Add(void);
void Menue(void);
void Search(void);
void Del(void);
void PrintFile(void);
void Clear(void);
void KichLogo(void);

void main()
{
	clrscr();
	Hash(mod);
	if ((f=fopen("PHONES.DB","r+"))==NULL)
	{
		KichLogo();
		fclose(f);
	}
	else
	{
		ReadFile();
		fclose(f);
	}
	Menue();
	f=fopen("PHONES.DB","wt");
	PrintFile();
	fclose(f);
	Clear();
}

void Hash(int module)
{
	ht = NULL;
	mod = module;
	ht = new Abonent[mod];
	for (int i=0; i<mod; i++)
	{
		ht[i].nmbr = -1;
		strcpy(ht[i].name,NULL);
		strcpy(ht[i].adrs,NULL);
		ht[i].next = NULL;
	}
}





void xAdd(long nmbr,char name[20],char adrs[50])
{
	int pos = nmbr % mod;
	if (ht[pos].nmbr == -1)
	{
		Abonent e;
		e.nmbr = nmbr;
		strcpy(e.name,name);
		strcpy(e.adrs,adrs);
		e.next = NULL;
		ht[pos] = e;
	}
	else
	{
		Abonent *e = new Abonent;
		e->nmbr = nmbr;
		strcpy(e->name,name);
		strcpy(e->adrs,adrs);
		e->next = NULL;
		Abonent *elements = &ht[pos];
		while (elements->next != NULL)
			elements = elements->next;
		elements->next = e;
	}
}

void ReadFile(void)
{
	long nmbr;
	char name[20], adrs[50];
	while (!feof(f))
	{
		fscanf(f,"%ld %s %s",&nmbr,&name,&adrs);
		xAdd(nmbr,name,adrs);
	}
}

void Add(void)
{
	clrscr();
	long nmbr = 0;
	char name[20],adrs[50];
	printf("Enter number: ");
	scanf("%ld", &nmbr);
	printf("Enter last name: ");
	scanf("%s",&name);
	printf("Enter adress: ");
	scanf("%s",&adrs);
	xAdd(nmbr,name,adrs);
	printf("Abonent added!\n");
	getch();
}

void Search(void)
{
  clrscr();
  long nmbr = 0;
  char name[20];
  char c = '1';
  while (c != 'q')
  {
    clrscr();
    printf("Search:\n\n");
    printf("1. by phone number\n");
    printf("2. by last name\n");
    printf("q. Back to main menue\n\n");
    printf(">> ");
    c = getch();
     switch(c)
     {
       case '1':
       {
	int f = 0;

	printf("Enter phone number to find: ");
	scanf("%ld", &nmbr);

	int pos = nmbr % mod;
	Abonent *elements = &ht[pos];

	if (elements->nmbr == nmbr)
	{
		printf("Found: [%ld, %s (%s)]",elements->nmbr,elements->name,elements->adrs);
		f = 1;
	}
	else
	{
		elements = elements->next;
		while (elements != NULL)
		{
			if (elements->nmbr == nmbr)
			{
			 printf("Found: [%ld, %s (%s)]",elements->nmbr,elements->name,elements->adrs);
			 f = 1;
			}
			elements = elements->next;
		}
	}

	if (!f)
	 printf("Abonent not found!\n");

	getch();
	}
	 break;

	case '2':
	{
	  int f = 0;
	  printf("Enter last name to find: ");
	  scanf("%s",&name);
	  for(int pos=0;pos<mod;pos++)
	  {
	   Abonent *elements = &ht[pos];
	   if (elements->nmbr != -1)
	   {
	    if (!strcmp(elements->name,name))
	    {
		 printf("Found: [%ld, %s]",elements->nmbr,elements->name);
		 f = 1;
	    }
	    else
	    {
		elements = elements->next;
		while (elements != NULL)
		{
			if(!strcmp(elements->name,name))
			{
			 printf("Found: [%ld, %s]",elements->nmbr,elements->name);
			 f = 1;
			}
			elements = elements->next;
		}
	    }
	   }

	  }
	  if (!f)
	   printf("Abonent not found!\n");
	  getch();
	}
	 break;

       case 'q':
	 Menue();
	 break;
       default:
	 printf("Wrong choise!");
	 getch();
	 break;
	     }
  }
}


void Del(void)
{
	clrscr();
	long nmbr = 0;
	int f = 0;
	printf("Enter number to delete: ");
	scanf("%ld", &nmbr);
	int pos = nmbr % mod;
	Abonent *elements = &ht[pos];
	Abonent *prev = elements;
	if (elements->nmbr == nmbr)
	{
		printf("Deleted [%ld,%s,%s]\n", elements->nmbr,elements->name,elements->adrs);
		if (elements->next != NULL)
		{
			ht[pos] = *elements->next;
			free(elements);
		}
		else
		{
			ht[pos].nmbr = -1;
			strcpy(ht[pos].name,NULL);
			strcpy(ht[pos].adrs,NULL);
		}
		f = 1;
	}
	else
	{
		elements = elements->next;
		while (elements != NULL) {
			if (elements->nmbr == nmbr) {
				prev->next = elements->next;
				free(elements);
			}
			prev = elements;
			elements = elements->next;
		}
	}
	if (!f)
		printf("Abonent not found!\n");
	getch();
}

void PrintFile(void)
{
	int k = 0;
	for (int i=0; i<mod; i++)
	{
		if(ht[i].nmbr != -1)
			{
			 if(k)
			  fprintf(f,"\n");
			 fprintf(f,"%ld %s %s", (ht+i)->nmbr,(ht+i)->name,(ht+i)->adrs);
			 k = 1;
			}
		if (ht[i].next != NULL)
		{
			Abonent *e = &ht[i];
			while (e->next != NULL)
			{
				e = e->next;
				fprintf(f,"\n%ld %s %s", e->nmbr,e->name,e->adrs);
			}
		}
	}
}

void Clear(void)
{
	Abonent *q;
	while(ht != NULL)
	{
	 q=ht;
	 ht=q->next;
	 free(q);
	}
}

void Menue()
{
  clrscr();
  char c = '1';
  while (c != 'q')
  {
     clrscr();
     printf("Operations:\n\n");
     printf("1. Add\n");
     printf("2. Search\n");
     printf("3. Delete\n");
     printf("q. Quit\n\n");
     printf(">> ");
     c = getch();
     switch(c)
     {
       case '1':
	 Add();
	 break;

       case '2':
	 Search();
	 break;

       case '3':
	 Del();
	 break;

       case 'q':
	 break;

       default:
	 printf("Wrong choise!");
	 getch();
	 break;
     }
  }
}

void KichLogo(void)
{
 textmode(LASTMODE);
 clrscr();
 textcolor(5);
  cprintf("K    K    i     CCC    H     H  RRRRR    U    U  M       M\n\r");
  cprintf("K   K         C     C  H     H  R    R   U    U  M M   M M\n\r");
  cprintf("K  K      I   C        H     H  R     R  U    U  M  M M  M\n\r");
  cprintf("K K       I   C        H     H  R    R   U    U  M   M   M\n\r");
  cprintf("K  K      I   C        H HHH H  R RR     U    U  M       M\n\r");
  cprintf("K   K     I   C        H     H  R    R   U    U  M       M\n\r");
  cprintf("K    K    I   C     C  H     H  R     R  U    U  M       M\n\r");
  cprintf("K     K   I     CCC    H     H  R     R   UUUU   M       M\n\r\n\r");
 textcolor(9);
  cprintf("   w  w  w  .  k  i  c  h  r  u  m  .  o  r  g  .  u  a\n\r\n\r");
 textcolor(1);
  cprintf("    Vitaemo! Tse Vash pershiy zapusk programy dlya\n\r               stvorennya telefonnoyi knygy\n\r                       \"KicherPhone\"!\n\r                     Natyskayte ENTER!");
 textcolor(15);
getch();
}
