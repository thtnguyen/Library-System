#include "thn9732_gui.h"
#include <sstream>
#include <iomanip>

/*int gui::start()
{
	Gtk::Dialog menu = Gtk::Dialog();
	Gtk::Label label = Gtk::Label("What type of user are you?");

	menu.set_title("Library System - Start");
	menu.get_content_area()->pack_start(label);
	label.show();

	menu.add_button("Exit", 0);
	menu.add_button("Project Manager", 1);
	menu.add_button("Librarian", 2);
	menu.add_button("Customer", 3);
	menu.set_default_response(0);
	menu.set_default_size(200,200);

	int choice = menu.run();

	menu.close();
	while(Gtk::Main::events_pending())
		Gtk::Main::iteration();

	return choice;
}

int gui::project_manager()
{
	Gtk::Dialog *menu = new Gtk::Dialog();
	Gtk::Label *label = new Gtk::Label("What would you like to do?");

	menu->set_title("Library System - Project Manager");
	menu->get_content_area()->pack_start(*label);
	label->show();

	menu->add_button("Back", 0);
	menu->add_button("Create Librarian", 1);
	menu->add_button("Load Data", 2);
	menu->add_button("Save Data", 3);
	menu->add_button("Create New Media", 4);
	menu->add_button("Create New Bundle", 5);
	menu->set_default_size(200,200);

	int choice = menu->run();

	menu->close();
	while(Gtk::Main::events_pending())
		Gtk::Main::iteration();

	delete menu;
	delete label;

return choice;
}

int gui::customer()
{
	Gtk::Dialog *menu = new Gtk::Dialog();
	Gtk::Label *label = new Gtk::Label("What would you like to do?");

	menu->set_title("Library System - Customer");
	menu->get_content_area()->pack_start(*label);
	label->show();

	menu->add_button("Back", 0);
	menu->add_button("View Catalog", 1);
	menu->add_button("Pay Balance", 2);
	menu->set_default_response(0);
	menu->set_default_size(200,200);

	int choice = menu->run();

	menu->close();
	while(Gtk::Main::events_pending())
		Gtk::Main::iteration();

	delete menu;
	delete label;

	return choice;
}

int gui::librarian()
{
	Gtk::Dialog *menu = new Gtk::Dialog();
	Gtk::Label *label = new Gtk::Label("What would you like to do?");

	menu->set_title("Library System - Librarian");
	menu->get_content_area()->pack_start(*label);
	label->show();

	menu->add_button("Back", 0);
	menu->add_button("Check out media/bundles", 1);
	menu->add_button("Check in media/bundles", 2);
	menu->add_button("Create a customer", 3);
	menu->set_default_size(200,200);

	int choice = menu->run();

	menu->close();
	while(Gtk::Main::events_pending())
		Gtk::Main::iteration();

	delete menu;
	delete label;

return choice;
}*/


int gui::create_media_options()
{
	Gtk::Dialog *menu = new Gtk::Dialog();
	Gtk::Label *label = new Gtk::Label("What type of media would you like to create?");

	menu->set_title("Library System - Create New Media");
	menu->get_content_area()->pack_start(*label);
	label->show();

	menu->add_button("Book", 1);
	menu->add_button("Back", 0);
	menu->add_button("Movie", 2);
	menu->add_button("TV Show Season", 3);
	menu->add_button("Video Game", 4);
	menu->add_button("Music Album", 5);
	menu->set_default_size(200,200);

	int choice = menu->run();

	menu->close();
	while(Gtk::Main::events_pending())
		Gtk::Main::iteration();

	delete menu;
	delete label;

return choice;
}

int gui::check_out_options()
{
	Gtk::Dialog *menu = new Gtk::Dialog();
	Gtk::Label *label = new Gtk::Label("What would you like to check out?");

	menu->set_title("Library System - Check Out");
	menu->get_content_area()->pack_start(*label);
	label->show();

	menu->add_button("Back", 0);
	menu->add_button("Media", 1);
	menu->add_button("Bundle", 2);
	menu->set_default_size(200,200);

	int choice = menu->run();

	menu->close();
	while(Gtk::Main::events_pending())
		Gtk::Main::iteration();

	delete menu;
	delete label;

	return choice;

}

int gui::check_in_options()
{
	Gtk::Dialog *menu = new Gtk::Dialog();
	Gtk::Label *label = new Gtk::Label("What would you like to check in?");

	menu->set_title("Library System - Check Out");
	menu->get_content_area()->pack_start(*label);
	label->show();

	menu->add_button("Back", 0);
	menu->add_button("Media", 1);
	menu->add_button("Bundle", 2);
	menu->set_default_size(200,200);

	int choice = menu->run();

	menu->close();
	while(Gtk::Main::events_pending())
		Gtk::Main::iteration();

	delete menu;
	delete label;

	return choice;

}

std::string gui::create_prompt(std::string title, std::string prompt)
{
	Gtk::Dialog *menu = new Gtk::Dialog();
	Gtk::Label *label = new Gtk::Label(prompt);
	Gtk::Entry *entry = new Gtk::Entry();

	menu->add_button("Next", 1);
	menu->get_vbox()->pack_start(*entry);

	entry->set_max_length(50);
	entry->show();

	menu->set_title(title);
	menu->get_content_area()->pack_start(*label);
	label->show();

	menu->run();
	std::string text = entry->get_text();
	menu->close();
	while(Gtk::Main::events_pending())
		Gtk::Main::iteration();

	delete menu;
	delete label;
	delete entry;

	return text;
}

std::string gui::multiple_prompts(std::string title, std::string prompt)
{
	Gtk::Dialog *menu = new Gtk::Dialog();
	Gtk::Label *label = new Gtk::Label(prompt);
	Gtk::Entry *entry = new Gtk::Entry();

	menu->add_button("Add", 1);
	menu->get_vbox()->pack_start(*entry);

	menu->add_button("Done", 2);
	menu->get_vbox()->pack_start(*entry);

	entry->set_max_length(50);
	entry->show();

	menu->set_title(title);
	menu->get_content_area()->pack_start(*label);
	label->show();

	int choice = menu->run();

	std::string text = entry->get_text();

	menu->close();
	while(Gtk::Main::events_pending())
		Gtk::Main::iteration();

	if(choice == 2)
		return "null";

	delete menu;
	delete label;
	delete entry;
	
	return text;
}
void gui::list_media(std::vector<shared_ptr<Media>>& mlist)
{
	Gtk::Dialog box = Gtk::Dialog("Media List");
	box.set_default_size(400,400);
	box.add_button("Close", 0);

	std::string media_list = "Existing Media:\n";
	std::string status;
	for(shared_ptr<Media> m : mlist)
	{
		if(m->is_available())
			status = " - AVAILABLE\n";
		else
			status = " - NOT AVAILABLE\n";

		media_list += m->to_string()+status;
	}
	
	Gtk::Label media_label = Gtk::Label(media_list);

	Gtk::ScrolledWindow *sw = new Gtk::ScrolledWindow;
	sw->set_border_width(5);
	sw->set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_ALWAYS);
	sw->add(media_label);

	box.get_content_area()->pack_start(*sw);
	sw->show_all();


	box.run();
	while(Gtk::Main::events_pending())
		Gtk::Main::iteration();
	box.close();
}

void gui::message(std::string title,std::string msg)
{
	Gtk::MessageDialog dialog = Gtk::MessageDialog(title);
	dialog.set_secondary_text(msg, true);

	dialog.run();
	dialog.close();
 	while(Gtk::Main::events_pending())
		Gtk::Main::iteration();
}

void gui::show_catalog(std::vector<shared_ptr<Media>>& mlist, std::vector<Bundle>& blist)
{
	Gtk::Dialog box = Gtk::Dialog("Catalog");
	box.set_default_size(400,400);

	int i = 0;
	std::string status;
	std::string catalog = "MEDIA:\n";
	for(shared_ptr<Media> m : mlist)
	{
		if(m->is_available())
			status = " - AVAILABLE\n";
		else
			status = " - NOT AVAILABLE\n";

		catalog += m->to_string()+status;
	}

	catalog += "\nBUNDLES:\n";
	vector<Bundle>::iterator it = blist.begin();
	it = blist.begin();
	while(it != blist.end())
		{
			catalog += "\n"+it->to_string()+"\n";
			for(shared_ptr<Media> m : it->medias)
			{
				catalog += "--"+m->to_string()+"\n";
			}
			it++;
		}
	
	Gtk::Label catalog_label = Gtk::Label(catalog);
	Gtk::ScrolledWindow *sw = new Gtk::ScrolledWindow;
	sw->set_border_width(5);
	sw->set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_ALWAYS);
	sw->add(catalog_label);

	box.get_content_area()->pack_start(*sw);
	sw->show_all();

	//adding close button
	box.add_button("Close", 0);
	box.set_default_response(0);

	box.run();

	while(Gtk::Main::events_pending())
		Gtk::Main::iteration();
	box.close();

	return;
}

void gui::list_checked_out(std::vector<Transaction>& tlist)
{
	Gtk::Dialog box = Gtk::Dialog("Checked-out list");
	box.set_default_size(400,400);
	box.add_button("Close", 0);

	std::string list = "Checked out items:\n";
	std::string status;
	for(Transaction t : tlist)
	{
		for(shared_ptr<Media> m : t.media)
			if(!m->is_available())
			{
				
				stringstream ss;
				ss <<"Media: " << setw(5) << setfill('0') << m->get_id() << " - " << m->get_call_num() << " - " << m->get_title()+", checked out to "+ (t.customer).get_name()+" "+(t.customer).get_id(); 
				std::string item_info;
				getline(ss, item_info);
				list += item_info+"\n";
			}
		for(Bundle b : t.bundles)
			if(!b.is_available())
			{
				stringstream ss;
				ss << "Bundle: " <<setw(5) << setfill('0') << b.get_id() << " - " << b.get_name()+", checked out to "+ (t.customer).get_name()+" "+(t.customer).get_id(); 
				std::string item_info;
				getline(ss, item_info);
				list += item_info+"\n";
			}
	}
	
	Gtk::Label label = Gtk::Label(list);
	Gtk::ScrolledWindow *sw = new Gtk::ScrolledWindow;
	sw->set_border_width(5);
	sw->set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_ALWAYS);
	sw->add(label);

	box.get_content_area()->pack_start(*sw);
	sw->show_all();

	box.run();
	while(Gtk::Main::events_pending())
		Gtk::Main::iteration();
	box.close();

	delete sw;

}
