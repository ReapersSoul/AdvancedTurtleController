///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/menu.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/stattext.h>
#include <wx/sizer.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/panel.h>
#include <wx/listbox.h>
#include <wx/scrolwin.h>
#include <wx/combobox.h>
#include <wx/wrapsizer.h>
#include <wx/filepicker.h>
#include <wx/richtext/richtextctrl.h>
#include <wx/splitter.h>
#include <wx/statbmp.h>
#include <wx/gauge.h>
#include <wx/notebook.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MainFrame
///////////////////////////////////////////////////////////////////////////////
class MainFrame : public wxFrame
{
	private:

	protected:
		wxMenuBar* MainMenuBar;
		wxMenu* m_menu3;
		wxNotebook* NoteBook;
		wxPanel* ConnectPanel;
		wxStaticText* m_staticText181;
		wxStaticText* m_staticText191;
		wxStaticText* m_staticText21;
		wxTextCtrl* IPfeild;
		wxTextCtrl* Portfeild;
		wxTextCtrl* UIDfeild;
		wxStaticText* ConnStatus;
		wxButton* ConnectButton;
		wxPanel* ComputersPanel;
		wxListBox* ComputersListBox;
		wxButton* SelcetComputerButton;
		wxStaticText* ConnectedLabel;
		wxPanel* LuaConsolePanel;
		wxBoxSizer* LuaHistory;
		wxComboBox* CommandTypeSelector;
		wxTextCtrl* Commandfeild;
		wxButton* m_button4;
		wxPanel* EditorPanel;
		wxSplitterWindow* m_splitter21;
		wxPanel* m_panel12;
		wxFilePickerCtrl* EditorFile;
		wxButton* m_button11;
		wxRichTextCtrl* RichText;
		wxScrolledWindow* m_scrolledWindow18;
		wxButton* m_button41;
		wxPanel* LocalFilesPanel;
		wxSplitterWindow* m_splitter3;
		wxPanel* m_panel13;
		wxFilePickerCtrl* LocalFileFilePicker;
		wxStaticText* m_staticText27;
		wxTextCtrl* LocalFileFileNameText;
		wxButton* m_button5;
		wxButton* m_button6;
		wxButton* m_button10;
		wxStaticText* localFileStatusLable;
		wxPanel* m_panel14;
		wxPanel* ComputerFilesPanel;
		wxSplitterWindow* m_splitter4;
		wxPanel* m_panel15;
		wxListBox* CompFileDirList;
		wxButton* m_button7;
		wxButton* m_button9;
		wxFilePickerCtrl* CompDownloadPicker;
		wxButton* m_button8;
		wxPanel* m_panel16;
		wxPanel* InventoryPanel;
		wxSplitterWindow* m_splitter2;
		wxPanel* m_panel7;
		wxStaticText* m_staticText25;
		wxStaticBitmap* EquipedLeftbmp;
		wxStaticText* EquippedLeftLabel;
		wxStaticText* m_staticText26;
		wxStaticBitmap* EquipedRightbmp;
		wxStaticText* EquippedRightLabel;
		wxPanel* m_panel8;
		wxGridSizer* InventoryGrid;
		wxScrolledWindow* m_scrolledWindow17;
		wxStaticBitmap* slot1bmp;
		wxStaticText* InvSlot1;
		wxScrolledWindow* m_scrolledWindow13;
		wxStaticBitmap* slot2bmp;
		wxStaticText* InvSlot2;
		wxScrolledWindow* m_scrolledWindow16;
		wxStaticBitmap* slot3bmp;
		wxStaticText* InvSlot3;
		wxScrolledWindow* m_scrolledWindow15;
		wxStaticBitmap* slot4bmp;
		wxStaticText* InvSlot4;
		wxScrolledWindow* m_scrolledWindow14;
		wxStaticBitmap* slot5bmp;
		wxStaticText* InvSlot5;
		wxScrolledWindow* m_scrolledWindow2;
		wxStaticBitmap* slot6bmp;
		wxStaticText* InvSlot6;
		wxScrolledWindow* m_scrolledWindow3;
		wxStaticBitmap* slot7bmp;
		wxStaticText* InvSlot7;
		wxScrolledWindow* m_scrolledWindow4;
		wxStaticBitmap* slot8bmp;
		wxStaticText* InvSlot8;
		wxScrolledWindow* m_scrolledWindow5;
		wxStaticBitmap* slot9bmp;
		wxStaticText* InvSlot9;
		wxScrolledWindow* m_scrolledWindow6;
		wxStaticBitmap* slot10bmp;
		wxStaticText* InvSlot10;
		wxScrolledWindow* m_scrolledWindow7;
		wxStaticBitmap* slot11bmp;
		wxStaticText* InvSlot11;
		wxScrolledWindow* m_scrolledWindow8;
		wxStaticBitmap* slot12bmp;
		wxStaticText* InvSlot12;
		wxScrolledWindow* m_scrolledWindow9;
		wxStaticBitmap* slot13bmp;
		wxStaticText* InvSlot13;
		wxScrolledWindow* m_scrolledWindow10;
		wxStaticBitmap* slot14bmp;
		wxStaticText* InvSlot14;
		wxScrolledWindow* m_scrolledWindow11;
		wxStaticBitmap* slot15bmp;
		wxStaticText* InvSlot15;
		wxScrolledWindow* m_scrolledWindow12;
		wxStaticBitmap* slot16bmp;
		wxStaticText* InvSlot16;
		wxPanel* StatusPanel;
		wxStaticText* FuelText;
		wxGauge* FuelGauge;
		wxPanel* WorldViewPanel;

		// Virtual event handlers, override them in your derived class
		virtual void TabChanged( wxNotebookEvent& event ) { event.Skip(); }
		virtual void ConnectServer( wxCommandEvent& event ) { event.Skip(); }
		virtual void SelectComputer( wxCommandEvent& event ) { event.Skip(); }
		virtual void ExecuteCommand( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnEditorSave( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnTextChanged( wxCommandEvent& event ) { event.Skip(); }
		virtual void LocalFileRunOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void LocalFileUploadOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void LocalFileEditOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void CompFilesRun( wxCommandEvent& event ) { event.Skip(); }
		virtual void CompFilesEdit( wxCommandEvent& event ) { event.Skip(); }
		virtual void CompFilesDownload( wxCommandEvent& event ) { event.Skip(); }
		virtual void KeyDownWorldView( wxKeyEvent& event ) { event.Skip(); }
		virtual void KeyUpWorldView( wxKeyEvent& event ) { event.Skip(); }


	public:
		wxScrolledWindow* LuaHistoryHolder;

		MainFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 1075,672 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~MainFrame();

		void m_splitter21OnIdle( wxIdleEvent& )
		{
			m_splitter21->SetSashPosition( 0 );
			m_splitter21->Disconnect( wxEVT_IDLE, wxIdleEventHandler( MainFrame::m_splitter21OnIdle ), NULL, this );
		}

		void m_splitter3OnIdle( wxIdleEvent& )
		{
			m_splitter3->SetSashPosition( 0 );
			m_splitter3->Disconnect( wxEVT_IDLE, wxIdleEventHandler( MainFrame::m_splitter3OnIdle ), NULL, this );
		}

		void m_splitter4OnIdle( wxIdleEvent& )
		{
			m_splitter4->SetSashPosition( 0 );
			m_splitter4->Disconnect( wxEVT_IDLE, wxIdleEventHandler( MainFrame::m_splitter4OnIdle ), NULL, this );
		}

		void m_splitter2OnIdle( wxIdleEvent& )
		{
			m_splitter2->SetSashPosition( 0 );
			m_splitter2->Disconnect( wxEVT_IDLE, wxIdleEventHandler( MainFrame::m_splitter2OnIdle ), NULL, this );
		}

};

