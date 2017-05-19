//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.ComCtrls.hpp>

#include "Tree.h"

class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TStringGrid *DataGrid;
	TTreeView *TreeView;
	TButton *TreeButton;
	TButton *ShowInfixButton;
	TButton *ShowPostfixButton;
	TButton *ShowTreePrefix;
	TLabel *LeftSideCountLabel;
	TLabel *LeftCountLabel;
	TLabel *TreeMakedLabel;
	TMemo *TreeMemo;
	TEdit *Edit1;
	TButton *Search;
	TButton *Button2;
   	void __fastcall DataGridKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall TreeButtonClick(TObject *Sender);
	void __fastcall ShowInfixButtonClick(TObject *Sender);
	void __fastcall ShowPostfixButtonClick(TObject *Sender);
	void __fastcall ShowTreePrefixClick(TObject *Sender);
	void __fastcall SearchClick(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
private:	// User declarations

    Tree mTree;

public:		// User declarations
	__fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
