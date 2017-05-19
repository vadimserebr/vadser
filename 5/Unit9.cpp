//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit9.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
struct Node
{
	int x;
	Node *Next,*Prev;
};
struct Node1
{
	int x1;
	Node1 *Next1,*Prev1;
};
class Queue
{
	Node *Head,*Tail;
	Node1 *Head1,*Tail1;
public:
	Queue():Head(NULL), Tail(NULL),Head1(NULL), Tail1(NULL) {}//Конструктор
	~Queue();//Деструктор
	void Show(); //Функция отображения списка на экране
	void Show1();//Функция отображения разделенных списков
	void Add(int x); //Функция добавления элементов в список
	void Devide(); //Функция разделения списка на два
	void delete_unit(Node* temp);//Функция удаления элемнта из списка
};
Queue::~Queue()
{
	while (Head)
	{
	   Tail=Head->Next;
	   delete Head;
	   Head=Tail;
	}
}
void Queue::Add(int x)
{
	Node *temp=new Node;
	temp->Next=NULL;
	temp->x=x;
	if (Head!=NULL)
	{
	   temp->Prev=Tail;
	   Tail->Next=temp;
	   Tail=temp;
	}
	else
	{
	   temp->Prev=NULL;
	   Head=Tail=temp;
	}
}
void Queue::Show()
{
	Node *temp=Tail;
	temp=Head;
	while (temp!=NULL)
	{
	   Form1->Memo1->Lines->Add(temp->x);
	   temp=temp->Next;
	}
}
void Queue::Devide()
{
	Node *temp=Tail;
	temp=Head;
	while (temp!=NULL)
	{
	  if((temp->x)<0)
	  {
		 Node1 *temp1=new Node1;
		 temp1->Next1=NULL;
		 temp1->x1=temp->x;
		 if (Head1!=NULL)
		 {
			 temp1->Prev1=Tail1;
			 Tail1->Next1=temp1;
			 Tail1=temp1;
		 }
		else
		{
			 temp1->Prev1=NULL;
			 Head1=Tail1=temp1;
		}
		delete_unit(temp);
	  }
	  temp=temp->Next;
	}
}
void Queue::Show1()
{
	Node *temp=Tail;
	Node1 *temp1=Tail1;
	temp=Head;
	while (temp!=NULL)
	{
	   Form1->Memo1->Lines->Add(temp->x);
	   temp=temp->Next;
	}
	temp1=Head1;
	while (temp1!=NULL)
	{
	   Form1->Memo2->Lines->Add(temp1->x1);
	   temp1=temp1->Next1;
	}
}
void Queue::delete_unit(Node* temp)
{
	if(temp==Head)
	{
		Head=Head->Next;
		Head->Prev=NULL;
	}
	else if (temp==Tail)
	{
		Tail=Tail->Prev;
		Tail->Next=NULL;
	}
	else
	{
		temp->Prev->Next=temp->Next;
		temp->Next->Prev=temp->Prev;
	}
}
int n;
Queue ob;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)//При нажатии кнопки заполняет список рандомными числами
{
	   int n= StrToInt(Edit1->Text);
	   for(int i=0;i<n;i++)
	   {
			int x = float (rand()%20000)/100-100;
			ob.Add(x);
	   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)//При нажатии кнопки выводит изначальный список
{
	   Memo1->Clear();
	   ob.Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)//При нажатии кнопки выводит разделенный список
{
	   Memo1->Clear();
	   Memo2->Clear();
	   ob.Show1();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)//При нажатии кнопки разделяет изначальный список на два
{
	   ob.Devide();
}
//---------------------------------------------------------------------------

