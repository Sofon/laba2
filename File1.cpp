#include <vcl.h>
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

struct Child  //���������
{
 string fname;  //�������� ������
 double info[3];  //������ ������  0-����� ����� 1-������� 2-���������
};


void printChild(Child *children, int n);  	//����� ����������� ��������
void sortSr(Child *children, int n);  		//���������� �� �������� �����
void bezdvoek(Child *children, int n);  	//����� ����������� ������ ��������������� �� �������� �����
void Poisk(Child *children, int n,int ns);  //���������� ������� � ������� ��������
void srednee(Child *children, int n);
void main()
{
 int n,ns;
 cout<<" Vvedite kolichestvo detej:   ";
 cin>>n;
 cout<<" Vedite familiju rebenka o kotorom nado vvyvesti vse dannye:   ";
 cin>>ns;
 cout<<endl;
 if(n<=0)  //��������� ������ ��� ��������
 {
  cout<<" Vvedeno nevernoe kolichestvo."<<endl;
  system("pause");
  return;
 }

 Child *children;  //��������� �� ���������
 children=new Child[n];

 ifstream in;  //����� ��� ������
 in.open("Children.txt",ios::in);  //��������� ���� ��� ������

 if(in==NULL)  //��������� ������ ��� ��������
 {
  cout<<" Ne udalos' otkryt' fajl."<<endl;
  system("pause");
  return;
 }

 for(int i=0;i<n;i++)  //������ �� �����
 {
  in>>children[i].fname;
 for (int j=0;j<2;j++)
 {
  in>>children[i].info[j];

 }
 children[i].info[3]=children[i].info[1]+children[i].info[2];
 }


 in.close();  //��������� �����
 cout<<" Rezul'taty testov:"<<endl;
 printChild(children, n);
 cout<<endl;


 cout<<" Sortirovka po srednemu ballu:"<<endl;
 sortSr(children, n);
 cout<<endl;

 cout<<" Poisk po zadanoj familii:"<<endl;
 Poisk(children,n,ns);
 cout<<endl;
 cout<<" sdal bez 2:"<<endl;
 bezdvoek(children,n);
 cout<<endl;
 delete[] children;  //����������� ������

 system("pause");
}


void printChild(Child *children, int n)  //����� ����������� ������ �� �����
{
 cout<<"---------------------------------------------------------------------------------"<<endl;
 cout<<"    Familia   "<<"  Class  "<<"  Algebra  "<<"  Fizika  "<<endl;
 cout<<"---------------------------------------------------------------------------------"<<endl;
 for(int i=0;i<n;i++)
 {
  cout<<setw(11)<<children[i].fname<<"   ";
  for (int j=0;j<4;j++)
  {
   cout<<"  "<<setw(7)<<children[i].info[j]<<"  ";
  }
  cout<<endl;
 }
}

void sortSr(Child *children, int n)  //���������� �� �������� ����� � ������ �� ����� ����������
{
 Child Buf;
 double min,b;
 int minI;
 for(int i=0;i<n;i++)
 {
  min=children[i].info[3];
  minI=i;
  for(int j=i;j<n;j++)
  {
   if(children[j].info[3]<min)
   {
	minI=j;
	min=children[j].info[3];
   }
  }
  b=children[i].info[3];
  children[i].info[3]=children[minI].info[3];
  children[minI].info[3]=b;
  Buf=children[i];
  children[i]=children[minI];
  children[minI]=Buf;
  }
 cout<<"---------------------------------------------------------------------------------"<<endl;
 cout<<"    Familia   "<<"  Class  "<<"  Algebra  "<<"  Fizika  "<<"  Srednii ball  "<<endl;
 cout<<"---------------------------------------------------------------------------------"<<endl;
 for(int i=0;i<n;i++)
 {
  cout<<setw(11)<<children[i].fname<<"   ";
  for (int j=0;j<4;j++)
  {
   cout<<"  "<<setw(7)<<children[i].info[j]<<"  ";
  }
  cout<<endl;
 }
}


void bezdvoek(Child *children, int n)  //����� ����������� ������ ��������������� �� �������� �����
{bool flag=false;

 cout<<"-------------------------------------------------------------------------------------------------"<<endl;
 cout<<"    Familia   "<<endl;
 cout<<"-------------------------------------------------------------------------------------------------"<<endl;
 for(int i=0;i<n;i++)
 {

   if (children[i].info[2]>children[i].info[1])//�������� �� �������� ������ ������ 3 ��� 3 �� ������ � �������
   {
	cout<<setw(11)<<children[i].fname<<"   "<<endl;
	flag=false;
   }
   }
  if (flag==true) 	{
  cout<<"    net ditee s osenkoq boolee 3   "<<endl;
					}
 }




void Poisk(Child *children, int n,int ns)  //���������� ������� � ������� ��������
{int i;
bool flag=false; // ���� �� ������ ���� ��� ������ ������� �� �����
	cout<<"---------------------------------------------------------------------------------"<<endl;
	cout<<"    Familia   "<<"  Class  "<<"  Algebra  "<<"  Fizika  "<<endl;
	cout<<"---------------------------------------------------------------------------------"<<endl;
for (i=0; i < n; i++) {//����� �������� ���� ����� �� ���������� � ����� ��� ����������
if (children[i].info[0]==ns) {
 flag=false;
 {
  cout<<setw(11)<<children[i].fname<<"   ";
  for (int j=0;j<3;j++)
  {
   cout<<"  "<<setw(7)<<children[i].info[j]<<"  ";
  }
  cout<<endl;
 }
 }
 }
  if (flag==true) 	{
  cout<<"    net s takoi familiee   "<<endl;}
}





