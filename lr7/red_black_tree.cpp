#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Abonent
{
 long nmbr;
 char name[20];
 char color[10];
 struct Abonent *right,*left,*p;
}  entry;

entry *NIL=(entry*)malloc(sizeof(entry));
entry *root=NIL;

FILE *f;

void Menue(void);
void ReadFile();
void Add(long,char*);
void  xAdd(entry*);
entry* Del(entry*);
void xDel(entry*);
entry* Search(entry*,long);
void PrintFile(entry*);
entry* Min(entry*);
entry* Successor(entry*);
void toLeft(entry*);
void toRight(entry*);
void KichLogo(void);

void main()
{
clrscr();
	strcpy(NIL->color,"black");
	if ((f=fopen("PHONES.DB","r"))==NULL)
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
	PrintFile(root);
	fclose(f);
}

void ReadFile()
{
long nmbr;
char name[20];

while (!feof(f)) {
 fscanf(f,"%ld",&nmbr);
 fscanf(f,"%s",&name);
 Add(nmbr,name);
}
}

void Add(long nmbr,char name[])
{
 entry *y=NIL,*x=root;
 entry *z=(entry*)malloc(sizeof(entry));

 z->left=NIL;
 z->right=NIL;
 z->nmbr=nmbr;
 strcpy(z->name,name);

 while (x!=NIL) {
   y=x;
   if ( z->nmbr < x->nmbr ) x=x->left;
     else x=x->right;
 }
 z->p=y;
 if (y==NIL) root=z;
  else if (z->nmbr < y->nmbr) y->left=z;
	  else y->right=z;

 z->left=NIL;
 z->right=NIL;
 strcpy(z->color,"red");
 xAdd(z);
}

void  xAdd(entry *z)
{
 entry *y=NIL;

 while ( strcmp( (z->p)->color,"red" ) == 1 ) {

   if ( z->p == ((z->p)->p)->left ) {

     y=((z->p)->p)->right;

     if ( strcmp(y->color,"red") == 1 ) {
	strcpy( (z->p)->color , "black" );
	strcpy( y->color , "black" );
	strcpy( ((z->p)->p)->color , "red" );
	z=(z->p)->p;
     }   else {
	   if ( z == (z->p)->right ) {
	     z=z->p;
	     toLeft(z);
	   }
	   strcpy( (z->p)->color , "black" );
	   strcpy( ((z->p)->p)->color , "red" );
	   toRight((z->p)->p);
	 }
   }
     else {
	y=((z->p)->p)->left;

	if ( strcmp(y->color,"red") == 1 ) {
	     strcpy( (z->p)->color , "black" );
	     strcpy( y->color , "black" );
	     strcpy( ((z->p)->p)->color , "red" );
	     z=(z->p)->p;
	} else {
	    if ( z == (z->p)->left ) {
	    z=z->p;
	    toLeft(z);
	   }
	   strcpy( (z->p)->color , "black" );
	   strcpy( ((z->p)->p)->color , "red" );
	   toRight((z->p)->p);
	 }
     }
 }

}

entry* Del(entry *z)
{
 entry *y,*x;

 if (z->left==NIL||z->right==NIL)
  y=z;
   else y=Successor(z);

 if (y->left!=NIL) x=y->left;
  else x=y->right;

 if (x!=NIL) x->p=y->p;

 if (y->p==NIL) root=x;
  else if (y==(y->p)->left) (y->p)->left=x;
	 else (y->p)->right=x;

 if (y!=z) {z->nmbr=y->nmbr; strcpy(z->name,y->name);}

 if ( strcmp( y->color,"black" ) == 1)
   xDel(x);

 return y;
}

void xDel(entry *x)
{
 entry *w=NIL;

 while ( x!=root && strcmp(x->color,"black") == 1 ) {

   if (x==(x->p)->left) {

     w=(x->p)->right;

     if ( strcmp(w->color,"red") == 1 ) {
     strcpy(w->color,"black");
     strcpy((x->p)->color,"red");
     toLeft(x->p);
     w=(x->p)->right;
     }

     if ( strcmp((w->left)->color,"black") && strcmp((w->right)->color,"black") ) {
     strcpy(w->color,"red");
     x=x->p;
     } else {
	 if ( strcmp((w->right)->color,"black") ) {
	  strcpy((w->left)->color,"black");
	  strcpy(w->color,"red");
	  toRight(w);
	  w=(x->p)->right;
	 }
       strcpy(w->color,(x->p)->color);
       strcpy((x->p)->color,"black");
       strcpy((w->right)->color,"black");
       toLeft(x->p);
       x=root;
       }
 } else {

     w=(x->p)->left;

     if ( strcmp(w->color,"red") == 1 ) {
     strcpy(w->color,"black");
     strcpy((x->p)->color,"red");
     toRight(x->p);
     w=(x->p)->left;
     }

     if ( strcmp((w->right)->color,"black") && strcmp((w->left)->color,"black") ) {
     strcpy(w->color,"red");
     x=x->p;
     } else {
	 if ( strcmp((w->left)->color,"black") ) {
	  strcpy((w->right)->color,"black");
	  strcpy(w->color,"red");
	  toLeft(w);
	  w=(x->p)->left;
	 }
       strcpy(w->color,(x->p)->color);
       strcpy((x->p)->color,"black");
       strcpy((w->left)->color,"black");
       toRight(x->p);
       x=root;
       }
   }
 }
}

entry* Search(entry *x,long nmbr)
{
if (x==NIL||(nmbr==x->nmbr))
  return x;

if (nmbr< x->nmbr) Search(x->left,nmbr);
 else Search(x->right,nmbr);
}

entry* Min(entry *x)
{
 while (x->left!=NIL)
   x=x->left;

return x;
}

void PrintFile(entry *a)
{
 if (a!=NIL) {
   PrintFile(a->left);
   fprintf(f,"\n%ld %s",a->nmbr,a->name);
   PrintFile(a->right);
 }
}

entry* Successor(entry *x)
{
 entry *y;
 if (x->right!=NIL)
  return Min(x->right);

 y=x->p;
 while (y!=NIL&&x==(x->right)) {
   x=y;
   y=y->p;
 }
return y;
}

void toLeft(entry *x)
{
entry *y=x->right;
x->right=y->left;

if (y->left!=NIL) (y->left)->p=x;

y->p=x->p;
if (x->p==NIL) root=y;
 else if (x==(x->p)->left) (x->p)->left=y;
       else (x->p)->right=y;

y->left=x;
x->p=y;
}

void toRight(entry *x)
{
entry *y=x->left;
x->left=y->right;

if (y->right!=NIL) (y->right)->p=x;

y->p=x->p;
if (x->p==NIL) root=y;
 else if (x==(x->p)->right) (x->p)->right=y;
       else (x->p)->left=y;

y->right=x;
x->p=y;
}



void Menue()
{
  clrscr();
	long nmbr;
	char name[20];
	entry *buf;
	char c = '1';
 while (c != '4')
  {
     clrscr();
     printf("Operations:\n\n");
     printf("1. Add\n");
     printf("2. Search\n");
     printf("3. Delete\n");
     printf("4. Quit\n\n");
     printf(">> ");
     c = getch();
     switch(c)
     {
  case '1':{
	  printf("\nEnter number: "); scanf("%ld",&nmbr);
      printf("\nEnter name:"); scanf("%s",&name);
    Add(nmbr,name);
    printf("\nAbonent added!");
	getch();
  }break;
  case '2': {
    printf("\nEnter phone number:");
    scanf("%ld",&nmbr);
    buf=Search(root,nmbr);
    if (buf==NIL) printf("\nAbonent not found!");
    else printf("\n%ld - %s",buf->nmbr,buf->name);
	getch();
  } break;

  case '3':{
    printf("\nEnter phone number to delete:");
    scanf("%ld",&nmbr);
    buf=Search(root,nmbr);
    if (buf!=NIL)  {Del(buf); printf("\nAbonent was deleted!");}
     else printf("\nAbonent not found!");
	getch();
  }break;

  case '4':break;
  default:
	  {printf("Wrong choise!");getch();}break;
 }
 }
}

void KichLogo(void)
{
 textmode(LASTMODE);
 clrscr();
 textcolor(14);
  cprintf("K    K    i     CCC    H     H  RRRRR    U    U  M       M\n\r");
  cprintf("K   K         C     C  H     H  R    R   U    U  M M   M M\n\r");
  cprintf("K  K      I   C        H     H  R     R  U    U  M  M M  M\n\r");
  cprintf("K K       I   C        H     H  R    R   U    U  M   M   M\n\r");
  cprintf("K  K      I   C        H HHH H  R RR     U    U  M       M\n\r");
  cprintf("K   K     I   C        H     H  R    R   U    U  M       M\n\r");
  cprintf("K    K    I   C     C  H     H  R     R  U    U  M       M\n\r");
  cprintf("K     K   I     CCC    H     H  R     R   UUUU   M       M\n\r\n\r");
 textcolor(13);
  cprintf("   w  w  w  .  k  i  c  h  r  u  m  .  o  r  g  .  u  a\n\r\n\r");
 textcolor(10);
  cprintf("    Vitaemo! Tse Vash pershiy zapusk programy dlya\n\r               stvorennya telefonnoyi knygy\n\r                      \"KicherPhone-2\"!\n\r                     Natyskayte ENTER!");
 textcolor(15);
getch();
}