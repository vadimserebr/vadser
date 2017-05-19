//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

#include <string>

TForm2 *Form2;

__fastcall TForm2::TForm2(TComponent* Owner) : TForm(Owner) {
	DataGrid->Cells[0][0] = "Ключ";
	DataGrid->Cells[1][0] = "Данные";

	TreeMemo->Text = "";
}

void __fastcall TForm2::DataGridKeyPress(TObject *Sender, System::WideChar &Key) {
	if (Key == 8) {
		AnsiString string = DataGrid->Cells[DataGrid->Col][DataGrid->Row];
		string = string.SubString(0, string.Length()-1);
		DataGrid->Cells[DataGrid->Col][DataGrid->Row] = string;
		return;
	}

	if (DataGrid->Col == 0) {
		if (Key < '0' || Key > '9') {
            return;
		} else {
			DataGrid->Cells[0][DataGrid->Row] = DataGrid->Cells[0][DataGrid->Row] + Key;
		}
	} else {
		DataGrid->Cells[1][DataGrid->Row] = DataGrid->Cells[1][DataGrid->Row] + Key;
	}
}


void __fastcall TForm2::TreeButtonClick(TObject *Sender) {
	mTree.clear(0);

	for (int i = 1; i < DataGrid->RowCount; i++) {
		AnsiString key = DataGrid->Cells[0][i];
		AnsiString value = DataGrid->Cells[1][i];
		if (key.Length() != 0 && value.Length() != 0) {
			mTree.insertData(StrToInt(key), value.c_str());
		}
	}

	TreeMakedLabel->Visible = true;

	int count = 0;
	mTree.leftCount(0,count);
	LeftSideCountLabel->Caption = count;
}


void __fastcall TForm2::ShowInfixButtonClick(TObject *Sender)
{
	TreeView->Items->Clear();
	mTree.infixTraverseDataList(0, TreeView);

	TreeMemo->Text = "";
	mTree.infixTraverseDataList(0, TreeMemo);
}


void __fastcall TForm2::ShowPostfixButtonClick(TObject *Sender)
{
	TreeView->Items->Clear();
	mTree.postfixTraverseDataList(0, TreeView);

	TreeMemo->Text = "";
	mTree.postfixTraverseDataList(0, TreeMemo);
}


void __fastcall TForm2::ShowTreePrefixClick(TObject *Sender)
{
	TreeView->Items->Clear();
	mTree.prefixTraverseDataList(0, TreeView);

	TreeMemo->Text = "";
	mTree.prefixTraverseDataList(0, TreeMemo);
}


void __fastcall TForm2::SearchClick(TObject *Sender)
{
	  TreeMemo->Clear();
	 int a=StrToInt(Edit1->Text);
     TreeMemo->Lines->Add(mTree.findData(a).c_str());
}
//---------------------------------------------------------------------------


void __fastcall TForm2::Button2Click(TObject *Sender)
{
   int a=StrToInt(Edit1->Text);
   bool i=mTree.deleteData(a);
}
//---------------------------------------------------------------------------

