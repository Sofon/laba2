#pragma hdrstop
#pragma argsused

#include <tchar.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "stdio.h"

using namespace std;

struct Node //Структура являющаяся звеном списка
{
double price;
int god, kolvo, oprice;
char* fam, *name;
Node *Next,*Prev; //Указатели на адреса следующего и предыдущего элементов списка

};
int kolvoelm=0;

class List //Создаем тип данных Список
{
Node *Tail, *cur; //Указатели на адреса начала списка и его конца
public:

Node *Head;
List():Head(NULL),Tail(NULL){}; //Инициализируем адреса как пустые
~List(); //Деструктор
void Show(); //Функция отображения списка на экране
void Add(char* fam, char* name, int god, int kolvo, int oprice); //Функция добавления элементов в список
void Poisk(char* fam);
void delElem(int numb); // удаление одного елемента из списка
};

List::~List() //Деструктор
{
while (Head) //Пока по адресу на начало списка что-то есть
{
Tail=Head->Next; //Резервная копия адреса следующего звена списка
delete Head; //Очистка памяти от первого звена
Head=Tail; //Смена адреса начала на адрес следующего элемента
}
}

void List::Add(char* fam, char* name, int god, int kolvo, int oprice)
{
Node *temp=new Node; //Выделение памяти под новый элемент структуры
temp->Next=NULL; //Указываем, что изначально по следующему адресу пусто
temp->fam=fam;//Записываем значение в структуру
temp->name=name;
temp->god=god;
temp->kolvo=kolvo;
temp->oprice=oprice;
temp->price = oprice/kolvo;
kolvoelm++;
if (Head!=NULL) //Если список не пуст
{
temp->Prev=Tail; //Указываем адрес на предыдущий элемент в соотв. поле
Tail->Next=temp; //Указываем адрес следующего за хвостом элемента
Tail=temp; //Меняем адрес хвоста
}
else //Если список пустой
{
temp->Prev=NULL; //Предыдущий элемент указывает в пустоту
Head=Tail=temp; //Голова=Хвост=тот элемент, что сейчас добавили
}
}

void List::Show()
{

Node *temp=Tail;

//ВЫВОДИМ СПИСОК С НАЧАЛА
temp=Head; //Временно указываем на адрес первого элемента
while (temp!=NULL) //Пока не встретим пустое значение
{
cout«temp->fam«"\t"; //Выводить значение на экран
cout«temp->name«"\t";
cout«temp->god«"\t";
cout«temp->price«"\t";
cout«temp->kolvo«"\t";
cout«temp->oprice«"\t";
temp=temp->Next; //Смена адреса на адрес следующего элемента
cout«"\n";
}

}

void vvod(){
char c;
FILE *fd;
fd=fopen("1.txt","r");
if(fd==NULL)
{ printf("\n Ошибка открытия файла");
return;}
c=getc(fd);
while(c!=EOF) // – сравниваем c с константой – конец файла
{ printf("%c",c);
c=getc(fd);
}
fclose(fd);
}

int _tmain(int argc, _TCHAR* argv[])
{
system("CLS");
setlocale(0, "russian");

List lst; //Объявляем переменную, тип которой есть список
cout«"Автор\t"«"Название\t"«"Год\t"«"Цена\t"«"Кол-во\t"«"Общ. стоим.\t"«endl;

//vvod();
lst.Add("Pushkin", "Evgeny Onegin", 1845, 14, 1800 ); //Добавляем в список элементы
lst.Add("Lermontov", "Mciri", 2045, 9, 2000 );
lst.Show(); //Отображаем список на экране
cout«endl;
cout«"Задание №1"«endl;
// вывод на экран больше 2000 меньше 500
Node* cur = lst.Head;
while (true)
{
if ((cur->god > 2000) & (cur->price < 500)) {
cout«cur->fam«"\t"; //Выводить значение на экран
cout«cur->name«"\t";
cout«cur->god«"\t";
cout«cur->price«"\t";
cout«cur->kolvo«"\t";
cout«cur->oprice«"\t";
cout«endl;
}
if (cur->Next == NULL) break;
cur = cur->Next;
}
cout«endl;
cout«"Задание №2"«endl;
//задание №2
cout«"Введите фамилию автора произведене которого Вы хотите найти:"«endl;
char famololo[128];
cin»famololo;
cur = lst.Head;
while (true)
{
if (strcmp(cur->fam,famololo)==0) {
cout«cur->fam«"\t"; //Выводить значение на экран
cout«cur->name«"\t";
cout«cur->god«"\t";
cout«cur->price«"\t";
cout«cur->kolvo«"\t";
cout«cur->oprice«"\t";
cout«endl;
}
if (cur->Next == NULL) break;
cur = cur->Next;
14.11.13	
}

cout«endl;
cout«"Задание №3"«endl;
int *P;
P=new int[kolvoelm];
int i=0;
cur = lst.Head; //загоняем в массив для последующей сорировки
while (true){
P[i]=cur->kolvo;
cout«P[i]«" ";
i++;
if (cur->Next == NULL) break;
cur = cur->Next;
}
cout«endl;
//сортировка
for (int i = 0; i < kolvoelm; i++)
{
// Массив просматривается с конца до
// позиции i и "легкие элементы всплывают"
for (int j = 0; j < kolvoelm - i; j++)
{
// Если соседние элементы расположены
// в неправильном порядке, то меняем
// их местами
if (P[j] < P[j - 1])
{
swap (P[j-1], P[j]);
}
}
}
for (i=0;i<kolvoelm;i++){
cout«P[i]«" ";
}

for (int j=0; j<kolvoelm; j++){
cur = lst.Head;
while (true){

if (cur->kolvo==P[j]) {
cout«cur->fam«"\t"; //Выводить значение на экран
cout«cur->name«"\t";
cout«cur->god«"\t";
cout«cur->price«"\t";
cout«cur->kolvo«"\t";
cout«cur->oprice«"\t";
}cout«endl;
if (cur->Next == NULL) break;
cur = cur->Next;
}

}
system("PAUSE");
}
