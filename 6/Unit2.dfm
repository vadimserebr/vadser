object Form2: TForm2
  Left = 0
  Top = 0
  Caption = 'Form2'
  ClientHeight = 396
  ClientWidth = 636
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object LeftSideCountLabel: TLabel
    Left = 160
    Top = 296
    Width = 5
    Height = 19
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object LeftCountLabel: TLabel
    Left = 8
    Top = 279
    Width = 196
    Height = 19
    Caption = #1059#1079#1083#1086#1074' '#1074' '#1087#1088#1072#1074#1086#1084' '#1087#1086#1076#1076#1077#1088#1077#1074#1077':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object TreeMakedLabel: TLabel
    Left = 96
    Top = 248
    Width = 108
    Height = 19
    Caption = #1044#1077#1088#1077#1074#1086' '#1075#1086#1090#1086#1074#1086
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    Visible = False
  end
  object DataGrid: TStringGrid
    Left = 8
    Top = 8
    Width = 329
    Height = 209
    ColCount = 2
    DefaultColWidth = 150
    FixedCols = 0
    RowCount = 15
    ScrollBars = ssVertical
    TabOrder = 0
    OnKeyPress = DataGridKeyPress
    ColWidths = (
      150
      150)
    RowHeights = (
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24)
  end
  object TreeView: TTreeView
    Left = 368
    Top = 8
    Width = 249
    Height = 209
    Indent = 19
    TabOrder = 1
  end
  object TreeButton: TButton
    Left = 8
    Top = 248
    Width = 75
    Height = 25
    Caption = 'Make Tree'
    TabOrder = 2
    OnClick = TreeButtonClick
  end
  object ShowInfixButton: TButton
    Left = 240
    Top = 248
    Width = 97
    Height = 25
    Caption = 'Show Tree Infix'
    TabOrder = 3
    OnClick = ShowInfixButtonClick
  end
  object ShowPostfixButton: TButton
    Left = 240
    Top = 279
    Width = 97
    Height = 25
    Caption = 'Show Tree Postfix'
    TabOrder = 4
    OnClick = ShowPostfixButtonClick
  end
  object ShowTreePrefix: TButton
    Left = 240
    Top = 310
    Width = 97
    Height = 25
    Caption = 'Show Tree Prefix'
    TabOrder = 5
    OnClick = ShowTreePrefixClick
  end
  object TreeMemo: TMemo
    Left = 368
    Top = 246
    Width = 249
    Height = 142
    Lines.Strings = (
      'TreeMemo')
    ParentShowHint = False
    ShowHint = False
    TabOrder = 6
  end
  object Edit1: TEdit
    Left = 8
    Top = 336
    Width = 121
    Height = 21
    TabOrder = 7
    Text = 'Edit1'
  end
  object Search: TButton
    Left = 240
    Top = 341
    Width = 97
    Height = 25
    Caption = 'Search'
    TabOrder = 8
    OnClick = SearchClick
  end
  object Button2: TButton
    Left = 240
    Top = 372
    Width = 97
    Height = 25
    Caption = 'Delete'
    TabOrder = 9
    OnClick = Button2Click
  end
end
