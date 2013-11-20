#include <vcl.h>
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

struct Child  //Структура
{
 string fname;  //Название района
 double info[3];  //Массив оценок  0-Номер школы 1-девочек 2-Мальчиков
};


void printChild(Child *children, int n);  	//Вывод результатов проверки
void sortSr(Child *children, int n);  		//Сортировка по среднему баллу
void bezdvoek(Child *children, int n);  	//Вывод результатов тестов отсортированных по среднему баллу
void Poisk(Child *children, int n,int ns);  //Нахождение ребенка с заданой фамилией
void srednee(Child *children, int n);
void main()
{
 int n,ns;
 cout<<" Vvedite kolichestvo detej:   ";
 cin>>n;
 cout<<" Vedite familiju rebenka o kotorom nado vvyvesti vse dannye:   ";
 cin>>ns;
 cout<<endl;
 if(n<=0)  //Проверяем ошибки при открытии
 {
  cout<<" Vvedeno nevernoe kolichestvo."<<endl;
  system("pause");
  return;
 }

 Child *children;  //Указатель на структуру
 children=new Child[n];

 ifstream in;  //Поток для чтения
 in.open("Children.txt",ios::in);  //Открываем файл для чтения

 if(in==NULL)  //Проверяем ошибки при открытии
 {
  cout<<" Ne udalos' otkryt' fajl."<<endl;
  system("pause");
  return;
 }

 for(int i=0;i<n;i++)  //Читаем из фалйа
 {
  in>>children[i].fname;
 for (int j=0;j<2;j++)
 {
  in>>children[i].info[j];

 }
 children[i].info[3]=children[i].info[1]+children[i].info[2];
 }


 in.close();  //Закрываем поток
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
 delete[] children;  //Освобождаем память

 system("pause");
}


void printChild(Child *children, int n)  //Вывод результатов тестов на экран
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

void sortSr(Child *children, int n)  //Сортировка по среднему баллу и ввывод на экран результата
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


void bezdvoek(Child *children, int n)  //Вывод результатов тестов отсортированных по среднему баллу
{bool flag=false;

 cout<<"-------------------------------------------------------------------------------------------------"<<endl;
 cout<<"    Familia   "<<endl;
 cout<<"-------------------------------------------------------------------------------------------------"<<endl;
 for(int i=0;i<n;i++)
 {

   if (children[i].info[2]>children[i].info[1])//проверка на устовиет оценка больше 3 или 3 по физики и алгебре
   {
	cout<<setw(11)<<children[i].fname<<"   "<<endl;
	flag=false;
   }
   }
  if (flag==true) 	{
  cout<<"    net ditee s osenkoq boolee 3   "<<endl;
					}
 }




void Poisk(Child *children, int n,int ns)  //Нахождение ребенка с заданой фамилией
{int i;
bool flag=false; // флаг на случий того что такого ребенка не будет
	cout<<"---------------------------------------------------------------------------------"<<endl;
	cout<<"    Familia   "<<"  Class  "<<"  Algebra  "<<"  Fizika  "<<endl;
	cout<<"---------------------------------------------------------------------------------"<<endl;
for (i=0; i < n; i++) {//цикол проверки всех дитей на совподение и вывод при нахождении
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





