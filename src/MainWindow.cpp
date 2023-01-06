#include "MainWindow.h"

#include <Application.h>
#include <Menu.h>
#include <MenuBar.h>
#include <MenuField.h>
#include <MenuItem.h>
#include <View.h>

enum
{
	GITHUB_PAGE 	=	'ghpg',
	NEW_WINDOW 		=	'nwin',
	SAVE_RESULTS 	=	'savr',
	PREFERENCES 	=	'pref',
	HELP_MSG 		=	'hlpm',
	QUIT_APP 		=	'qapp'
};

MainWindow::MainWindow(void)
	:	BWindow(BRect(100,100,2000,1500),"BeLingual",B_TITLED_WINDOW, B_ASYNCHRONOUS_CONTROLS)
{
	/*---- MENU BAR ----*/
	BRect r(Bounds());
	r.bottom = 20;
	fMenuBar = new BMenuBar(r,"menubar");
	AddChild(fMenuBar);
	
	// ---- File Menu ----
	fFileMenu = new BMenu("File");
	fFileMenu->AddItem(new BMenuItem("New Window", new BMessage(NEW_WINDOW),'N', B_COMMAND_KEY));
	fFileMenu->AddItem(new BMenuItem("Save Results...", new BMessage(SAVE_RESULTS),'S', B_COMMAND_KEY));
	fFileMenu->AddSeparatorItem();
	fFileMenu->AddItem(new BMenuItem("About BeLingual", new BMessage(B_ABOUT_REQUESTED)));	
	fFileMenu->AddSeparatorItem();
	fFileMenu->AddItem(new BMenuItem("Close", new BMessage(B_QUIT_REQUESTED),'W', B_COMMAND_KEY));
	fFileMenu->AddItem(new BMenuItem("Quit", new BMessage(QUIT_APP),'Q', B_COMMAND_KEY));

	// ---- Edit Menu ----
	fEditMenu = new BMenu("Edit");
	BMenuItem *txt;
	fEditMenu->AddItem(txt = new BMenuItem("Copy", new BMessage(B_COPY), 'C'));
	txt->SetTarget(NULL, this);	
	fEditMenu->AddItem(txt = new BMenuItem("Paste", new BMessage(B_PASTE), 'V'));
	txt->SetTarget(NULL, this);	
	fEditMenu->AddItem(txt = new BMenuItem("Select All",	new BMessage(B_SELECT_ALL), 'A'));
	txt->SetTarget(NULL, this);	
	fEditMenu->AddSeparatorItem();
	fEditMenu->AddItem(new BMenuItem("Preferences...", new BMessage(PREFERENCES), 'P', B_COMMAND_KEY));
	
	/*---- HELP MENU ----*/
	fHelpMenu = new BMenu("Help");
	fHelpMenu->AddItem(new BMenuItem("Documentation...", new BMessage(HELP_MSG)));
	fHelpMenu->AddSeparatorItem();
	fHelpMenu->AddItem(new BMenuItem("GitHub Page", new BMessage(GITHUB_PAGE)));
	
	/*---- ADD ITEMS TO MENU ----*/
	fMenuBar->AddItem(fFileMenu);
	fMenuBar->AddItem(fEditMenu);
	fMenuBar->AddItem(fHelpMenu);
	
	
	
	/*---- SHOW MENU ----*/
	
	Show();
}


void
MainWindow::MessageReceived(BMessage *msg)
{
	switch (msg->what)
	{
		default:
		{
			BWindow::MessageReceived(msg);
			break;
		}
	}
}


bool
MainWindow::QuitRequested(void)
{
	be_app->PostMessage(B_QUIT_REQUESTED);
	return true;
}
