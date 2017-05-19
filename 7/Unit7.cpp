//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit7.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
class hash
{
private:
	static const int tableSize = 10;
	struct item
	{
		int number;
		item* next;
	};
	item *HashTable[tableSize];
public:
	hash()
	{
		for (int i = 0; i < tableSize; i++)
		{
			HashTable[i] = NULL;
		}
	}
	int Hash(int n)
	{
		int index = n % 10;
		return index;
	}

	void Add(int n)
	{
		int index = Hash(n);
		if (HashTable[index] == NULL)
		{
			HashTable[index] = new item;
			HashTable[index]->number = n;
			HashTable[index]->next = NULL;
		}
		else
		{
			item *p = HashTable[index];
			item *temp = new item;
			temp->number = n;
			temp->next = NULL;
			while (p->next != NULL)
			{
				p = p->next;
			}
			p->next = temp;
		}

	}

	void Print()
	{
		int num;
		item *p;
		for (int i = 0; i < tableSize; i++)
		{
			if (HashTable[i] != NULL)
			{
				p = HashTable[i];

				while (p != NULL)
				{

				   Form1->Memo1->Lines->Add(p->number);
				   p = p->next;
				}

			}
		}
	}
	void Search(int n)
	{
		item *p;
		int index = Hash(n);
		p = HashTable[index];
		while (p != NULL)
		{
			if (p->number == n)
			{
				 Form1->Memo1->Lines->Add(p->number);
			}
			p = p->next;
		}
	}
	void Delete(int n)
	{
		item *del;
		item *p1;
		item *p2;
		int index = Hash(n);
		if (HashTable[index] == NULL)
		{
			Form1->Memo1->Lines->Add(AnsiString("Hash doesn't have ")+ n +AnsiString(" number"));
		}
		else if (HashTable[index]->number == n && HashTable[index]->next == NULL)
		{
			del = HashTable[index];
			HashTable[index] = NULL;
			delete del;
		}
		else if (HashTable[index]->number == n)
		{
			del = HashTable[index];
			HashTable[index] = HashTable[index]->next;
			delete del;
		}
		else
		{
			p1 = HashTable[index]->next;
			p2 = HashTable[index];
			while (p1 != NULL && p1->number != n)
			{
				p2 = p1;
				p1 = p1->next;
			}
			if (p1 == NULL)
			{
					Form1->Memo1->Lines->Add(AnsiString("Hash doesn't have ")+ n +AnsiString(" number"));
			}
			else
			{
				del = p1;
				p1 = p1->next;
				p2->next = p1;
				delete del;
			}
		}
	}

	void Find()
	{
		item *p;
		item *temp;
		for (int i = 0; i < tableSize; i++)
		{
			if (HashTable[i] != NULL)
			{
				p = HashTable[i];
				while (p != NULL && p->number % 2 == 0)
				{
					temp = p->next;
					Delete(p->number);
					p = temp;
				}

			}
		}
	}
};
hash a;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	 Memo1->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	int r;
	randomize();
	for(int i = 0; i < 10; i++)
	{
	   r = rand()%100;
	   a.Add(r);
	}
	a.Print();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	int n = StrToInt(Edit1->Text);
	a.Add(n);
	Memo1->Clear();
	a.Print();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
	int n = StrToInt(Edit2->Text);
	Memo1->Clear();
	a.Search(n);

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
	int n = StrToInt(Edit3->Text);
	Memo1->Clear();
	a.Delete(n);
	a.Print();

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
	Memo1->Clear();
	a.Print();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
	Memo1->Clear();
	a.Find();
    a.Print();
}
//---------------------------------------------------------------------------
