#ifndef GUI_H
#define GUI_H

#include <gtkmm.h>
#include <vector>
#include <memory>
#include "thn9732_media.h"
#include "thn9732_Bundle.h"
#include "thn9732_Transaction.h"

class gui
{
public:
	//opens the start menu
	static int start(); 
	//opens the project manager menu
	static int project_manager();
	//opens the customer menu 
	static int customer();
	static int librarian();
	//opens menu for creating media
	static int create_media_options();
	static int check_out_options();
	static int check_in_options();
	//prompts for text input
	static std::string create_prompt(std::string title, std::string prompt);
	//prompts for multiple consecutive inputs
	static std::string multiple_prompts(std::string title, std::string prompt);
	//opens dialog box with list of all media
	static void list_media(std::vector<shared_ptr<Media>>& mlist);
	//opens a message dialog with an error message
	static void message(std::string title, std::string msg);
	//similar to list_media, but applies to both media and bundles
	static void show_catalog(std::vector<shared_ptr<Media>>& mlist, std::vector<Bundle>& blist);

	static void list_checked_out(std::vector<Transaction>& tlist);

};

#endif
