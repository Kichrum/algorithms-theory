#include "stdafx.h"
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
  int A[] = {3, 6, 8, 9, 12, 13, 15};
  int B[] = {1, 2, 3, 4, 5}; 
  int C[] = {2, 3, 4, 5, 6, 7};
  int BiC[30]={NULL}, res1[30]={NULL}, AdB[30]={NULL}, AdC[30]={NULL}, res2[30]={NULL}, i;
  int Nbic, Nr1, Nadb, Nadc, Nr2;

  cout << "A = { ";
  for(i=0; i<7 ; i++)
	cout << A[i] << " ";
  cout << "}" << endl;

    cout << "B = { ";
  for(i=0; i<5 ; i++)
	cout << B[i] << " ";
  cout << "}" << endl;

    cout << "C = { ";
  for(i=0; i<6 ; i++)
	cout << C[i] << " ";
  cout << "}" << endl;


  cout << endl << "left:" << endl << "B intersection C = { ";
  set_intersection(B, B + 5, C, C + 6, BiC);
  for(i=0,Nbic=0; BiC[i]!=NULL; i++,Nbic++)
	cout << BiC[i] << " ";
  cout << "}" << endl;

  cout << "A\\(B intersection C) = { ";
  set_difference(A, A + 7, BiC, BiC + Nbic, res1);
  for(i=0, Nr1=0; res1[i]!=NULL; i++, Nr1++)
	cout << res1[i] << " ";
  cout << "}" << endl;

  cout << endl << "right:" << endl << "A\\B = { ";
  set_difference(A, A + 7, B, B + 5, AdB);
  for(i=0, Nadb=0; AdB[i]!=NULL; i++, Nadb++)
	cout << AdB[i] << " ";
  cout << "}" << endl;

  cout << "A\\C = { ";
  set_difference(A, A + 7, C, C + 6, AdC);
  for(i=0, Nadc=0; AdC[i]!=NULL; i++, Nadc++)
	cout << AdC[i] << " ";
  cout << "}" << endl;

  cout << "(A\\B)U(A\\C) = { ";
  set_union(AdB, AdB + Nadb, AdC, AdC + Nadc, res2);
  for(i=0, Nr2=0; res2[i]!=NULL; i++, Nr2++)
	cout << res2[i] << " ";
  cout << "}" << endl;

  char *result;
  for(i=0;res1[i]!=NULL;i++)
	  if(res1[i]!=res2[i]) {result="Ne rivni!"; break;}
	  else result="Rivni!";
	  cout << endl << "Vidpovid': " << result << endl;

  getch();

  return 0;
}