///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "GUI.h"

///////////////////////////////////////////////////////////////////////////

MainFrame::MainFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );

	MainMenuBar = new wxMenuBar( 0 );
	m_menu3 = new wxMenu();
	MainMenuBar->Append( m_menu3, wxT("Exit") );

	this->SetMenuBar( MainMenuBar );

	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxVERTICAL );

	NoteBook = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	ConnectPanel = new wxPanel( NoteBook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer23;
	bSizer23 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer27;
	bSizer27 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer25;
	bSizer25 = new wxBoxSizer( wxVERTICAL );

	m_staticText181 = new wxStaticText( ConnectPanel, wxID_ANY, wxT("IP:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText181->Wrap( -1 );
	bSizer25->Add( m_staticText181, 0, wxALL, 5 );

	m_staticText191 = new wxStaticText( ConnectPanel, wxID_ANY, wxT("Port:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText191->Wrap( -1 );
	bSizer25->Add( m_staticText191, 0, wxALL, 5 );

	m_staticText21 = new wxStaticText( ConnectPanel, wxID_ANY, wxT("UserID:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText21->Wrap( -1 );
	bSizer25->Add( m_staticText21, 0, wxALL, 5 );


	bSizer27->Add( bSizer25, 1, 0, 5 );

	wxBoxSizer* bSizer24;
	bSizer24 = new wxBoxSizer( wxVERTICAL );

	IPfeild = new wxTextCtrl( ConnectPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer24->Add( IPfeild, 0, wxTOP, 5 );

	Portfeild = new wxTextCtrl( ConnectPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer24->Add( Portfeild, 0, 0, 5 );

	UIDfeild = new wxTextCtrl( ConnectPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer24->Add( UIDfeild, 0, 0, 5 );


	bSizer27->Add( bSizer24, 1, 0, 5 );


	bSizer23->Add( bSizer27, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer26;
	bSizer26 = new wxBoxSizer( wxVERTICAL );


	bSizer26->Add( 0, 0, 1, wxEXPAND, 5 );

	ConnStatus = new wxStaticText( ConnectPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	ConnStatus->Wrap( -1 );
	bSizer26->Add( ConnStatus, 0, wxALIGN_CENTER|wxALL, 5 );

	ConnectButton = new wxButton( ConnectPanel, wxID_ANY, wxT("Connect"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer26->Add( ConnectButton, 0, wxALIGN_CENTER|wxALL, 5 );


	bSizer26->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer23->Add( bSizer26, 1, wxEXPAND, 5 );


	ConnectPanel->SetSizer( bSizer23 );
	ConnectPanel->Layout();
	bSizer23->Fit( ConnectPanel );
	NoteBook->AddPage( ConnectPanel, wxT("Connect"), true );
	ComputersPanel = new wxPanel( NoteBook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer29;
	bSizer29 = new wxBoxSizer( wxVERTICAL );

	ComputersListBox = new wxListBox( ComputersPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	bSizer29->Add( ComputersListBox, 1, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer33;
	bSizer33 = new wxBoxSizer( wxHORIZONTAL );

	SelcetComputerButton = new wxButton( ComputersPanel, wxID_ANY, wxT("Select"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer33->Add( SelcetComputerButton, 0, wxALIGN_CENTER|wxALL, 5 );

	ConnectedLabel = new wxStaticText( ComputersPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	ConnectedLabel->Wrap( -1 );
	bSizer33->Add( ConnectedLabel, 0, wxALIGN_CENTER|wxALL, 5 );


	bSizer29->Add( bSizer33, 0, wxALIGN_CENTER, 5 );


	ComputersPanel->SetSizer( bSizer29 );
	ComputersPanel->Layout();
	bSizer29->Fit( ComputersPanel );
	NoteBook->AddPage( ComputersPanel, wxT("Computers"), false );
	LuaConsolePanel = new wxPanel( NoteBook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxVERTICAL );

	LuaHistoryHolder = new wxScrolledWindow( LuaConsolePanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxVSCROLL );
	LuaHistoryHolder->SetScrollRate( 5, 5 );
	LuaHistory = new wxBoxSizer( wxVERTICAL );


	LuaHistoryHolder->SetSizer( LuaHistory );
	LuaHistoryHolder->Layout();
	LuaHistory->Fit( LuaHistoryHolder );
	bSizer8->Add( LuaHistoryHolder, 5, wxALL|wxEXPAND, 5 );

	wxWrapSizer* wSizer1;
	wSizer1 = new wxWrapSizer( wxHORIZONTAL, wxWRAPSIZER_DEFAULT_FLAGS );

	CommandTypeSelector = new wxComboBox( LuaConsolePanel, wxID_ANY, wxT("Lua"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	CommandTypeSelector->Append( wxT("Lua") );
	CommandTypeSelector->Append( wxT("Shell") );
	CommandTypeSelector->SetSelection( 0 );
	wSizer1->Add( CommandTypeSelector, 0, wxALL, 5 );

	Commandfeild = new wxTextCtrl( LuaConsolePanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	wSizer1->Add( Commandfeild, 0, wxALL, 5 );

	m_button4 = new wxButton( LuaConsolePanel, wxID_ANY, wxT("Execute"), wxDefaultPosition, wxDefaultSize, 0 );
	wSizer1->Add( m_button4, 0, wxALL, 5 );


	bSizer8->Add( wSizer1, 1, wxEXPAND, 5 );


	LuaConsolePanel->SetSizer( bSizer8 );
	LuaConsolePanel->Layout();
	bSizer8->Fit( LuaConsolePanel );
	NoteBook->AddPage( LuaConsolePanel, wxT("Lua Console"), false );
	EditorPanel = new wxPanel( NoteBook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer321;
	bSizer321 = new wxBoxSizer( wxVERTICAL );

	m_splitter21 = new wxSplitterWindow( EditorPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3D );
	m_splitter21->Connect( wxEVT_IDLE, wxIdleEventHandler( MainFrame::m_splitter21OnIdle ), NULL, this );

	m_panel12 = new wxPanel( m_splitter21, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer341;
	bSizer341 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer44;
	bSizer44 = new wxBoxSizer( wxHORIZONTAL );

	EditorFile = new wxFilePickerCtrl( m_panel12, wxID_ANY, wxEmptyString, wxT("Select a file"), wxT("*.*"), wxDefaultPosition, wxDefaultSize, wxFLP_DEFAULT_STYLE );
	bSizer44->Add( EditorFile, 0, wxALL, 5 );

	m_button11 = new wxButton( m_panel12, wxID_ANY, wxT("Save"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer44->Add( m_button11, 0, wxALL, 5 );


	bSizer341->Add( bSizer44, 0, wxEXPAND, 5 );

	RichText = new wxRichTextCtrl( m_panel12, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0|wxVSCROLL|wxHSCROLL|wxNO_BORDER|wxWANTS_CHARS );
	bSizer341->Add( RichText, 1, wxEXPAND | wxALL, 5 );


	m_panel12->SetSizer( bSizer341 );
	m_panel12->Layout();
	bSizer341->Fit( m_panel12 );
	m_scrolledWindow18 = new wxScrolledWindow( m_splitter21, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	m_scrolledWindow18->SetScrollRate( 5, 5 );
	wxBoxSizer* EditorHistory;
	EditorHistory = new wxBoxSizer( wxVERTICAL );


	m_scrolledWindow18->SetSizer( EditorHistory );
	m_scrolledWindow18->Layout();
	EditorHistory->Fit( m_scrolledWindow18 );
	m_splitter21->SplitVertically( m_panel12, m_scrolledWindow18, 0 );
	bSizer321->Add( m_splitter21, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer332;
	bSizer332 = new wxBoxSizer( wxHORIZONTAL );

	m_button41 = new wxButton( EditorPanel, wxID_ANY, wxT("Run"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer332->Add( m_button41, 0, wxALL, 5 );


	bSizer321->Add( bSizer332, 0, wxEXPAND, 5 );


	EditorPanel->SetSizer( bSizer321 );
	EditorPanel->Layout();
	bSizer321->Fit( EditorPanel );
	NoteBook->AddPage( EditorPanel, wxT("Editor"), false );
	LocalFilesPanel = new wxPanel( NoteBook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer38;
	bSizer38 = new wxBoxSizer( wxVERTICAL );

	m_splitter3 = new wxSplitterWindow( LocalFilesPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3D );
	m_splitter3->Connect( wxEVT_IDLE, wxIdleEventHandler( MainFrame::m_splitter3OnIdle ), NULL, this );

	m_panel13 = new wxPanel( m_splitter3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer451;
	bSizer451 = new wxBoxSizer( wxVERTICAL );

	LocalFileFilePicker = new wxFilePickerCtrl( m_panel13, wxID_ANY, wxEmptyString, wxT("Select a file"), wxT("*.*"), wxDefaultPosition, wxDefaultSize, wxFLP_DEFAULT_STYLE );
	bSizer451->Add( LocalFileFilePicker, 0, wxALL, 5 );

	wxBoxSizer* bSizer40;
	bSizer40 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText27 = new wxStaticText( m_panel13, wxID_ANY, wxT("File Name:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText27->Wrap( -1 );
	bSizer40->Add( m_staticText27, 0, wxALIGN_CENTER|wxALL, 5 );

	LocalFileFileNameText = new wxTextCtrl( m_panel13, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer40->Add( LocalFileFileNameText, 0, wxALIGN_CENTER|wxALL, 5 );


	bSizer451->Add( bSizer40, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer39;
	bSizer39 = new wxBoxSizer( wxHORIZONTAL );

	m_button5 = new wxButton( m_panel13, wxID_ANY, wxT("Run"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer39->Add( m_button5, 0, wxALL, 5 );

	m_button6 = new wxButton( m_panel13, wxID_ANY, wxT("Upload"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer39->Add( m_button6, 0, wxALL, 5 );

	m_button10 = new wxButton( m_panel13, wxID_ANY, wxT("Edit"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer39->Add( m_button10, 0, wxALL, 5 );


	bSizer451->Add( bSizer39, 0, wxEXPAND, 5 );

	localFileStatusLable = new wxStaticText( m_panel13, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	localFileStatusLable->Wrap( -1 );
	bSizer451->Add( localFileStatusLable, 0, wxALL, 5 );


	m_panel13->SetSizer( bSizer451 );
	m_panel13->Layout();
	bSizer451->Fit( m_panel13 );
	m_panel14 = new wxPanel( m_splitter3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* LocalFileHist;
	LocalFileHist = new wxBoxSizer( wxVERTICAL );


	m_panel14->SetSizer( LocalFileHist );
	m_panel14->Layout();
	LocalFileHist->Fit( m_panel14 );
	m_splitter3->SplitVertically( m_panel13, m_panel14, 0 );
	bSizer38->Add( m_splitter3, 1, wxEXPAND, 5 );


	LocalFilesPanel->SetSizer( bSizer38 );
	LocalFilesPanel->Layout();
	bSizer38->Fit( LocalFilesPanel );
	NoteBook->AddPage( LocalFilesPanel, wxT("Local Files"), false );
	ComputerFilesPanel = new wxPanel( NoteBook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer42;
	bSizer42 = new wxBoxSizer( wxVERTICAL );

	m_splitter4 = new wxSplitterWindow( ComputerFilesPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3D );
	m_splitter4->Connect( wxEVT_IDLE, wxIdleEventHandler( MainFrame::m_splitter4OnIdle ), NULL, this );

	m_panel15 = new wxPanel( m_splitter4, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer47;
	bSizer47 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer45;
	bSizer45 = new wxBoxSizer( wxVERTICAL );

	CompFileDirList = new wxListBox( m_panel15, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	bSizer45->Add( CompFileDirList, 1, wxALL|wxEXPAND, 5 );


	bSizer47->Add( bSizer45, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer43;
	bSizer43 = new wxBoxSizer( wxHORIZONTAL );

	m_button7 = new wxButton( m_panel15, wxID_ANY, wxT("Run"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer43->Add( m_button7, 0, wxALL, 5 );

	m_button9 = new wxButton( m_panel15, wxID_ANY, wxT("Edit"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer43->Add( m_button9, 0, wxALL, 5 );

	CompDownloadPicker = new wxFilePickerCtrl( m_panel15, wxID_ANY, wxEmptyString, wxT("Select a file"), wxT("*.*"), wxDefaultPosition, wxDefaultSize, wxFLP_DEFAULT_STYLE );
	bSizer43->Add( CompDownloadPicker, 0, wxALL, 5 );

	m_button8 = new wxButton( m_panel15, wxID_ANY, wxT("Download"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer43->Add( m_button8, 0, wxALL, 5 );


	bSizer47->Add( bSizer43, 0, wxEXPAND, 5 );


	m_panel15->SetSizer( bSizer47 );
	m_panel15->Layout();
	bSizer47->Fit( m_panel15 );
	m_panel16 = new wxPanel( m_splitter4, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* CompFilesHist;
	CompFilesHist = new wxBoxSizer( wxVERTICAL );


	m_panel16->SetSizer( CompFilesHist );
	m_panel16->Layout();
	CompFilesHist->Fit( m_panel16 );
	m_splitter4->SplitVertically( m_panel15, m_panel16, 0 );
	bSizer42->Add( m_splitter4, 1, wxEXPAND, 5 );


	ComputerFilesPanel->SetSizer( bSizer42 );
	ComputerFilesPanel->Layout();
	bSizer42->Fit( ComputerFilesPanel );
	NoteBook->AddPage( ComputerFilesPanel, wxT("Computer Files"), false );
	InventoryPanel = new wxPanel( NoteBook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxVERTICAL );

	m_splitter2 = new wxSplitterWindow( InventoryPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3D );
	m_splitter2->Connect( wxEVT_IDLE, wxIdleEventHandler( MainFrame::m_splitter2OnIdle ), NULL, this );

	m_panel7 = new wxPanel( m_splitter2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* ToolSizer;
	ToolSizer = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer32;
	bSizer32 = new wxBoxSizer( wxVERTICAL );

	m_staticText25 = new wxStaticText( m_panel7, wxID_ANY, wxT("Left Equiped:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText25->Wrap( -1 );
	bSizer32->Add( m_staticText25, 0, wxALL, 5 );

	EquipedLeftbmp = new wxStaticBitmap( m_panel7, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer32->Add( EquipedLeftbmp, 0, wxALL, 5 );

	EquippedLeftLabel = new wxStaticText( m_panel7, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	EquippedLeftLabel->Wrap( -1 );
	bSizer32->Add( EquippedLeftLabel, 0, wxALL, 5 );


	ToolSizer->Add( bSizer32, 0, 0, 5 );

	wxBoxSizer* bSizer331;
	bSizer331 = new wxBoxSizer( wxVERTICAL );

	m_staticText26 = new wxStaticText( m_panel7, wxID_ANY, wxT("Right Equiped:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText26->Wrap( -1 );
	bSizer331->Add( m_staticText26, 0, wxALL, 5 );

	EquipedRightbmp = new wxStaticBitmap( m_panel7, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer331->Add( EquipedRightbmp, 0, wxALL, 5 );

	EquippedRightLabel = new wxStaticText( m_panel7, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	EquippedRightLabel->Wrap( -1 );
	bSizer331->Add( EquippedRightLabel, 0, wxALL, 5 );


	ToolSizer->Add( bSizer331, 0, 0, 5 );


	m_panel7->SetSizer( ToolSizer );
	m_panel7->Layout();
	ToolSizer->Fit( m_panel7 );
	m_panel8 = new wxPanel( m_splitter2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	InventoryGrid = new wxGridSizer( 4, 4, 0, 0 );

	m_scrolledWindow17 = new wxScrolledWindow( m_panel8, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	m_scrolledWindow17->SetScrollRate( 5, 5 );
	wxBoxSizer* ItemSizer;
	ItemSizer = new wxBoxSizer( wxVERTICAL );

	slot1bmp = new wxStaticBitmap( m_scrolledWindow17, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
	ItemSizer->Add( slot1bmp, 0, wxALL, 5 );

	InvSlot1 = new wxStaticText( m_scrolledWindow17, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	InvSlot1->Wrap( -1 );
	ItemSizer->Add( InvSlot1, 0, wxALL, 5 );


	m_scrolledWindow17->SetSizer( ItemSizer );
	m_scrolledWindow17->Layout();
	ItemSizer->Fit( m_scrolledWindow17 );
	InventoryGrid->Add( m_scrolledWindow17, 1, wxEXPAND | wxALL, 5 );

	m_scrolledWindow13 = new wxScrolledWindow( m_panel8, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	m_scrolledWindow13->SetScrollRate( 5, 5 );
	wxBoxSizer* ItemSizer1;
	ItemSizer1 = new wxBoxSizer( wxVERTICAL );

	slot2bmp = new wxStaticBitmap( m_scrolledWindow13, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
	ItemSizer1->Add( slot2bmp, 0, wxALL, 5 );

	InvSlot2 = new wxStaticText( m_scrolledWindow13, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	InvSlot2->Wrap( -1 );
	ItemSizer1->Add( InvSlot2, 0, wxALL, 5 );


	m_scrolledWindow13->SetSizer( ItemSizer1 );
	m_scrolledWindow13->Layout();
	ItemSizer1->Fit( m_scrolledWindow13 );
	InventoryGrid->Add( m_scrolledWindow13, 1, wxEXPAND | wxALL, 5 );

	m_scrolledWindow16 = new wxScrolledWindow( m_panel8, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	m_scrolledWindow16->SetScrollRate( 5, 5 );
	wxBoxSizer* ItemSizer2;
	ItemSizer2 = new wxBoxSizer( wxVERTICAL );

	slot3bmp = new wxStaticBitmap( m_scrolledWindow16, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
	ItemSizer2->Add( slot3bmp, 0, wxALL, 5 );

	InvSlot3 = new wxStaticText( m_scrolledWindow16, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	InvSlot3->Wrap( -1 );
	ItemSizer2->Add( InvSlot3, 0, wxALL, 5 );


	m_scrolledWindow16->SetSizer( ItemSizer2 );
	m_scrolledWindow16->Layout();
	ItemSizer2->Fit( m_scrolledWindow16 );
	InventoryGrid->Add( m_scrolledWindow16, 1, wxEXPAND | wxALL, 5 );

	m_scrolledWindow15 = new wxScrolledWindow( m_panel8, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	m_scrolledWindow15->SetScrollRate( 5, 5 );
	wxBoxSizer* ItemSizer3;
	ItemSizer3 = new wxBoxSizer( wxVERTICAL );

	slot4bmp = new wxStaticBitmap( m_scrolledWindow15, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
	ItemSizer3->Add( slot4bmp, 0, wxALL, 5 );

	InvSlot4 = new wxStaticText( m_scrolledWindow15, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	InvSlot4->Wrap( -1 );
	ItemSizer3->Add( InvSlot4, 0, wxALL, 5 );


	m_scrolledWindow15->SetSizer( ItemSizer3 );
	m_scrolledWindow15->Layout();
	ItemSizer3->Fit( m_scrolledWindow15 );
	InventoryGrid->Add( m_scrolledWindow15, 1, wxEXPAND | wxALL, 5 );

	m_scrolledWindow14 = new wxScrolledWindow( m_panel8, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	m_scrolledWindow14->SetScrollRate( 5, 5 );
	wxBoxSizer* ItemSizer4;
	ItemSizer4 = new wxBoxSizer( wxVERTICAL );

	slot5bmp = new wxStaticBitmap( m_scrolledWindow14, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
	ItemSizer4->Add( slot5bmp, 0, wxALL, 5 );

	InvSlot5 = new wxStaticText( m_scrolledWindow14, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	InvSlot5->Wrap( -1 );
	ItemSizer4->Add( InvSlot5, 0, wxALL, 5 );


	m_scrolledWindow14->SetSizer( ItemSizer4 );
	m_scrolledWindow14->Layout();
	ItemSizer4->Fit( m_scrolledWindow14 );
	InventoryGrid->Add( m_scrolledWindow14, 1, wxEXPAND | wxALL, 5 );

	m_scrolledWindow2 = new wxScrolledWindow( m_panel8, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	m_scrolledWindow2->SetScrollRate( 5, 5 );
	wxBoxSizer* ItemSizer5;
	ItemSizer5 = new wxBoxSizer( wxVERTICAL );

	slot6bmp = new wxStaticBitmap( m_scrolledWindow2, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
	ItemSizer5->Add( slot6bmp, 0, wxALL, 5 );

	InvSlot6 = new wxStaticText( m_scrolledWindow2, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	InvSlot6->Wrap( -1 );
	ItemSizer5->Add( InvSlot6, 0, wxALL, 5 );


	m_scrolledWindow2->SetSizer( ItemSizer5 );
	m_scrolledWindow2->Layout();
	ItemSizer5->Fit( m_scrolledWindow2 );
	InventoryGrid->Add( m_scrolledWindow2, 1, wxEXPAND | wxALL, 5 );

	m_scrolledWindow3 = new wxScrolledWindow( m_panel8, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	m_scrolledWindow3->SetScrollRate( 5, 5 );
	wxBoxSizer* ItemSizer6;
	ItemSizer6 = new wxBoxSizer( wxVERTICAL );

	slot7bmp = new wxStaticBitmap( m_scrolledWindow3, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
	ItemSizer6->Add( slot7bmp, 0, wxALL, 5 );

	InvSlot7 = new wxStaticText( m_scrolledWindow3, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	InvSlot7->Wrap( -1 );
	ItemSizer6->Add( InvSlot7, 0, wxALL, 5 );


	m_scrolledWindow3->SetSizer( ItemSizer6 );
	m_scrolledWindow3->Layout();
	ItemSizer6->Fit( m_scrolledWindow3 );
	InventoryGrid->Add( m_scrolledWindow3, 1, wxEXPAND | wxALL, 5 );

	m_scrolledWindow4 = new wxScrolledWindow( m_panel8, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	m_scrolledWindow4->SetScrollRate( 5, 5 );
	wxBoxSizer* ItemSizer7;
	ItemSizer7 = new wxBoxSizer( wxVERTICAL );

	slot8bmp = new wxStaticBitmap( m_scrolledWindow4, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
	ItemSizer7->Add( slot8bmp, 0, wxALL, 5 );

	InvSlot8 = new wxStaticText( m_scrolledWindow4, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	InvSlot8->Wrap( -1 );
	ItemSizer7->Add( InvSlot8, 0, wxALL, 5 );


	m_scrolledWindow4->SetSizer( ItemSizer7 );
	m_scrolledWindow4->Layout();
	ItemSizer7->Fit( m_scrolledWindow4 );
	InventoryGrid->Add( m_scrolledWindow4, 1, wxEXPAND | wxALL, 5 );

	m_scrolledWindow5 = new wxScrolledWindow( m_panel8, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	m_scrolledWindow5->SetScrollRate( 5, 5 );
	wxBoxSizer* ItemSizer8;
	ItemSizer8 = new wxBoxSizer( wxVERTICAL );

	slot9bmp = new wxStaticBitmap( m_scrolledWindow5, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
	ItemSizer8->Add( slot9bmp, 0, wxALL, 5 );

	InvSlot9 = new wxStaticText( m_scrolledWindow5, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	InvSlot9->Wrap( -1 );
	ItemSizer8->Add( InvSlot9, 0, wxALL, 5 );


	m_scrolledWindow5->SetSizer( ItemSizer8 );
	m_scrolledWindow5->Layout();
	ItemSizer8->Fit( m_scrolledWindow5 );
	InventoryGrid->Add( m_scrolledWindow5, 1, wxEXPAND | wxALL, 5 );

	m_scrolledWindow6 = new wxScrolledWindow( m_panel8, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	m_scrolledWindow6->SetScrollRate( 5, 5 );
	wxBoxSizer* ItemSizer9;
	ItemSizer9 = new wxBoxSizer( wxVERTICAL );

	slot10bmp = new wxStaticBitmap( m_scrolledWindow6, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
	ItemSizer9->Add( slot10bmp, 0, wxALL, 5 );

	InvSlot10 = new wxStaticText( m_scrolledWindow6, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	InvSlot10->Wrap( -1 );
	ItemSizer9->Add( InvSlot10, 0, wxALL, 5 );


	m_scrolledWindow6->SetSizer( ItemSizer9 );
	m_scrolledWindow6->Layout();
	ItemSizer9->Fit( m_scrolledWindow6 );
	InventoryGrid->Add( m_scrolledWindow6, 1, wxEXPAND | wxALL, 5 );

	m_scrolledWindow7 = new wxScrolledWindow( m_panel8, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	m_scrolledWindow7->SetScrollRate( 5, 5 );
	wxBoxSizer* ItemSizer10;
	ItemSizer10 = new wxBoxSizer( wxVERTICAL );

	slot11bmp = new wxStaticBitmap( m_scrolledWindow7, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
	ItemSizer10->Add( slot11bmp, 0, wxALL, 5 );

	InvSlot11 = new wxStaticText( m_scrolledWindow7, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	InvSlot11->Wrap( -1 );
	ItemSizer10->Add( InvSlot11, 0, wxALL, 5 );


	m_scrolledWindow7->SetSizer( ItemSizer10 );
	m_scrolledWindow7->Layout();
	ItemSizer10->Fit( m_scrolledWindow7 );
	InventoryGrid->Add( m_scrolledWindow7, 1, wxEXPAND | wxALL, 5 );

	m_scrolledWindow8 = new wxScrolledWindow( m_panel8, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	m_scrolledWindow8->SetScrollRate( 5, 5 );
	wxBoxSizer* ItemSizer11;
	ItemSizer11 = new wxBoxSizer( wxVERTICAL );

	slot12bmp = new wxStaticBitmap( m_scrolledWindow8, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
	ItemSizer11->Add( slot12bmp, 0, wxALL, 5 );

	InvSlot12 = new wxStaticText( m_scrolledWindow8, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	InvSlot12->Wrap( -1 );
	ItemSizer11->Add( InvSlot12, 0, wxALL, 5 );


	m_scrolledWindow8->SetSizer( ItemSizer11 );
	m_scrolledWindow8->Layout();
	ItemSizer11->Fit( m_scrolledWindow8 );
	InventoryGrid->Add( m_scrolledWindow8, 1, wxEXPAND | wxALL, 5 );

	m_scrolledWindow9 = new wxScrolledWindow( m_panel8, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	m_scrolledWindow9->SetScrollRate( 5, 5 );
	wxBoxSizer* ItemSizer12;
	ItemSizer12 = new wxBoxSizer( wxVERTICAL );

	slot13bmp = new wxStaticBitmap( m_scrolledWindow9, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
	ItemSizer12->Add( slot13bmp, 0, wxALL, 5 );

	InvSlot13 = new wxStaticText( m_scrolledWindow9, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	InvSlot13->Wrap( -1 );
	ItemSizer12->Add( InvSlot13, 0, wxALL, 5 );


	m_scrolledWindow9->SetSizer( ItemSizer12 );
	m_scrolledWindow9->Layout();
	ItemSizer12->Fit( m_scrolledWindow9 );
	InventoryGrid->Add( m_scrolledWindow9, 1, wxEXPAND | wxALL, 5 );

	m_scrolledWindow10 = new wxScrolledWindow( m_panel8, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	m_scrolledWindow10->SetScrollRate( 5, 5 );
	wxBoxSizer* ItemSizer13;
	ItemSizer13 = new wxBoxSizer( wxVERTICAL );

	slot14bmp = new wxStaticBitmap( m_scrolledWindow10, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
	ItemSizer13->Add( slot14bmp, 0, wxALL, 5 );

	InvSlot14 = new wxStaticText( m_scrolledWindow10, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	InvSlot14->Wrap( -1 );
	ItemSizer13->Add( InvSlot14, 0, wxALL, 5 );


	m_scrolledWindow10->SetSizer( ItemSizer13 );
	m_scrolledWindow10->Layout();
	ItemSizer13->Fit( m_scrolledWindow10 );
	InventoryGrid->Add( m_scrolledWindow10, 1, wxEXPAND | wxALL, 5 );

	m_scrolledWindow11 = new wxScrolledWindow( m_panel8, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	m_scrolledWindow11->SetScrollRate( 5, 5 );
	wxBoxSizer* ItemSizer14;
	ItemSizer14 = new wxBoxSizer( wxVERTICAL );

	slot15bmp = new wxStaticBitmap( m_scrolledWindow11, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
	ItemSizer14->Add( slot15bmp, 0, wxALL, 5 );

	InvSlot15 = new wxStaticText( m_scrolledWindow11, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	InvSlot15->Wrap( -1 );
	ItemSizer14->Add( InvSlot15, 0, wxALL, 5 );


	m_scrolledWindow11->SetSizer( ItemSizer14 );
	m_scrolledWindow11->Layout();
	ItemSizer14->Fit( m_scrolledWindow11 );
	InventoryGrid->Add( m_scrolledWindow11, 1, wxEXPAND | wxALL, 5 );

	m_scrolledWindow12 = new wxScrolledWindow( m_panel8, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	m_scrolledWindow12->SetScrollRate( 5, 5 );
	wxBoxSizer* ItemSizer15;
	ItemSizer15 = new wxBoxSizer( wxVERTICAL );

	slot16bmp = new wxStaticBitmap( m_scrolledWindow12, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
	ItemSizer15->Add( slot16bmp, 0, wxALL, 5 );

	InvSlot16 = new wxStaticText( m_scrolledWindow12, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	InvSlot16->Wrap( -1 );
	ItemSizer15->Add( InvSlot16, 0, wxALL, 5 );


	m_scrolledWindow12->SetSizer( ItemSizer15 );
	m_scrolledWindow12->Layout();
	ItemSizer15->Fit( m_scrolledWindow12 );
	InventoryGrid->Add( m_scrolledWindow12, 1, wxEXPAND | wxALL, 5 );


	m_panel8->SetSizer( InventoryGrid );
	m_panel8->Layout();
	InventoryGrid->Fit( m_panel8 );
	m_splitter2->SplitVertically( m_panel7, m_panel8, 0 );
	bSizer11->Add( m_splitter2, 1, wxEXPAND, 5 );


	InventoryPanel->SetSizer( bSizer11 );
	InventoryPanel->Layout();
	bSizer11->Fit( InventoryPanel );
	NoteBook->AddPage( InventoryPanel, wxT("Inventory"), false );
	StatusPanel = new wxPanel( NoteBook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer34;
	bSizer34 = new wxBoxSizer( wxVERTICAL );

	FuelText = new wxStaticText( StatusPanel, wxID_ANY, wxT("Fuel:"), wxDefaultPosition, wxDefaultSize, 0 );
	FuelText->Wrap( -1 );
	bSizer34->Add( FuelText, 0, wxALL, 5 );

	FuelGauge = new wxGauge( StatusPanel, wxID_ANY, 100, wxDefaultPosition, wxDefaultSize, wxGA_HORIZONTAL );
	FuelGauge->SetValue( 0 );
	bSizer34->Add( FuelGauge, 0, wxALL, 5 );


	StatusPanel->SetSizer( bSizer34 );
	StatusPanel->Layout();
	bSizer34->Fit( StatusPanel );
	NoteBook->AddPage( StatusPanel, wxT("Status"), false );
	WorldViewPanel = new wxPanel( NoteBook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	NoteBook->AddPage( WorldViewPanel, wxT("World View"), false );

	bSizer6->Add( NoteBook, 1, wxALL|wxEXPAND, 5 );


	this->SetSizer( bSizer6 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	NoteBook->Connect( wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGED, wxNotebookEventHandler( MainFrame::TabChanged ), NULL, this );
	ConnectButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::ConnectServer ), NULL, this );
	SelcetComputerButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::SelectComputer ), NULL, this );
	m_button4->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::ExecuteCommand ), NULL, this );
	m_button11->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnEditorSave ), NULL, this );
	RichText->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MainFrame::OnTextChanged ), NULL, this );
	m_button5->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::LocalFileRunOnClick ), NULL, this );
	m_button6->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::LocalFileUploadOnClick ), NULL, this );
	m_button10->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::LocalFileEditOnClick ), NULL, this );
	m_button7->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::CompFilesRun ), NULL, this );
	m_button9->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::CompFilesEdit ), NULL, this );
	m_button8->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::CompFilesDownload ), NULL, this );
	WorldViewPanel->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( MainFrame::KeyDownWorldView ), NULL, this );
	WorldViewPanel->Connect( wxEVT_KEY_UP, wxKeyEventHandler( MainFrame::KeyUpWorldView ), NULL, this );
}

MainFrame::~MainFrame()
{
	// Disconnect Events
	NoteBook->Disconnect( wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGED, wxNotebookEventHandler( MainFrame::TabChanged ), NULL, this );
	ConnectButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::ConnectServer ), NULL, this );
	SelcetComputerButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::SelectComputer ), NULL, this );
	m_button4->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::ExecuteCommand ), NULL, this );
	m_button11->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnEditorSave ), NULL, this );
	RichText->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MainFrame::OnTextChanged ), NULL, this );
	m_button5->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::LocalFileRunOnClick ), NULL, this );
	m_button6->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::LocalFileUploadOnClick ), NULL, this );
	m_button10->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::LocalFileEditOnClick ), NULL, this );
	m_button7->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::CompFilesRun ), NULL, this );
	m_button9->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::CompFilesEdit ), NULL, this );
	m_button8->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::CompFilesDownload ), NULL, this );
	WorldViewPanel->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( MainFrame::KeyDownWorldView ), NULL, this );
	WorldViewPanel->Disconnect( wxEVT_KEY_UP, wxKeyEventHandler( MainFrame::KeyUpWorldView ), NULL, this );

}
