#include "thn9732_Main_Menu.h"
#include <iostream>

Main_Menu::Main_Menu(Library& l, Controller& c) : lib(l), controller(c)
{
	set_default_size(200,200);
	vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));

	Gtk::MenuBar *mb = Gtk::manage(new Gtk::MenuBar()); //creating the menubar 

	//creating project manager menu item and its submenu
	Gtk::MenuItem *pm = Gtk::manage(new Gtk::MenuItem("_Project Manager", true));
	Gtk::Menu *pm_menu = Gtk::manage(new Gtk::Menu());
	pm->set_submenu(*pm_menu);

	Gtk::MenuItem *create_lbrn_item = Gtk::manage(new Gtk::MenuItem("Create Librarian", true));
	create_lbrn_item->signal_activate().connect(sigc::mem_fun(*this, &Main_Menu::create_lbrn_clicked));
	pm_menu->append(*create_lbrn_item);

	Gtk::MenuItem *create_media_item = Gtk::manage(new Gtk::MenuItem("Create Media", true));
	create_media_item->signal_activate().connect(sigc::mem_fun(*this, &Main_Menu::create_media_clicked));
	pm_menu->append(*create_media_item);

	Gtk::MenuItem *create_bundle_item = Gtk::manage(new Gtk::MenuItem("Create Bundle", true));
	create_bundle_item->signal_activate().connect(sigc::mem_fun(*this, &Main_Menu::create_bundle_clicked));
	pm_menu->append(*create_bundle_item);

	Gtk::MenuItem *load_data_item = Gtk::manage(new Gtk::MenuItem("Load Data", true));
	Gtk::Menu *load_menu = Gtk::manage(new Gtk::Menu());
	load_data_item->set_submenu(*load_menu);	
	pm_menu->append(*load_data_item);

	Gtk::MenuItem *default_load_item = Gtk::manage(new Gtk::MenuItem("Load from default file", true));
	default_load_item->signal_activate().connect(sigc::mem_fun(*this, &Main_Menu::default_load_clicked));
	load_menu->append(*default_load_item);

	Gtk::MenuItem *reg_load_item = Gtk::manage(new Gtk::MenuItem("Load from different file", true));
	reg_load_item->signal_activate().connect(sigc::mem_fun(*this, &Main_Menu::load_data_clicked));
	load_menu->append(*reg_load_item);

	Gtk::MenuItem *save_data_item = Gtk::manage(new Gtk::MenuItem("Save Data", true));
	Gtk::Menu *save_menu = Gtk::manage(new Gtk::Menu());
	save_data_item->set_submenu(*save_menu);
	pm_menu->append(*save_data_item);

	Gtk::MenuItem *default_save_item = Gtk::manage(new Gtk::MenuItem("Save to default file", true));
	default_save_item->signal_activate().connect(sigc::mem_fun(*this, &Main_Menu::default_save_clicked));
	save_menu->append(*default_save_item);
	
	Gtk::MenuItem *reg_save_item = Gtk::manage(new Gtk::MenuItem("Save to different file", true));
	reg_save_item->signal_activate().connect(sigc::mem_fun(*this, &Main_Menu::save_data_clicked));
	save_menu->append(*reg_save_item);

	Gtk::MenuItem *checkoutlist_item = Gtk::manage(new Gtk::MenuItem("View checked out items", true));
	checkoutlist_item->signal_activate().connect(sigc::mem_fun(*this, &Main_Menu::check_out_list));
	pm_menu->append(*checkoutlist_item);


	//creating librarian menubar item and its submenu
	Gtk::MenuItem *lbrn = Gtk::manage(new Gtk::MenuItem("_Librarian", true));
	Gtk::Menu *lbrn_menu = Gtk::manage(new Gtk::Menu());
	lbrn->set_submenu(*lbrn_menu);

	Gtk::MenuItem *check_out_item = Gtk::manage(new Gtk::MenuItem("Check out media/bundles", true));
	check_out_item->signal_activate().connect(sigc::mem_fun(*this, &Main_Menu::check_out_clicked));
	lbrn_menu->append(*check_out_item);

	Gtk::MenuItem *check_in_item = Gtk::manage(new Gtk::MenuItem("Check in media/bundles", true));
	check_in_item->signal_activate().connect(sigc::mem_fun(*this, &Main_Menu::check_in_clicked));
	lbrn_menu->append(*check_in_item);

	Gtk::MenuItem *create_customer_item = Gtk::manage(new Gtk::MenuItem("Create customer", true));
	create_customer_item->signal_activate().connect(sigc::mem_fun(*this, &Main_Menu::create_customer_clicked));
	lbrn_menu->append(*create_customer_item);

	//creating customer menubar item and its submenu
	Gtk::MenuItem *cust = Gtk::manage(new Gtk::MenuItem("_Customer", true));
	Gtk::Menu *cust_menu = Gtk::manage(new Gtk::Menu());
	cust->set_submenu(*cust_menu);

	Gtk::MenuItem *view_catalog_item = Gtk::manage(new Gtk::MenuItem("View catalog", true));
	view_catalog_item->signal_activate().connect(sigc::mem_fun(*this, &Main_Menu::view_catalog_clicked));
	cust_menu->append(*view_catalog_item);

	Gtk::MenuItem *pay_balance_item = Gtk::manage(new Gtk::MenuItem("Pay balance", true));
	pay_balance_item->signal_activate().connect(sigc::mem_fun(*this, &Main_Menu::pay_balance_clicked));
	cust_menu->append(*pay_balance_item);

	//adding the menu items to menubar
	mb->append(*pm);
	mb->append(*lbrn);
	mb->append(*cust);

	Gtk::Label *welcome_msg = Gtk::manage(new Gtk::Label("\t\t\t\t\t\t\tWelcome to the Library System.\nUse the menubar above to perform actions according to what type of user you are."));
	add(*vbox);
	vbox->pack_start(*mb, Gtk::PACK_SHRINK, 0);
	vbox->pack_start(*welcome_msg);

	Gtk::Button *exit = Gtk::manage(new Gtk::Button("Exit"));
	exit->signal_clicked().connect(sigc::mem_fun(*this, &Main_Menu::on_exit_clicked));
	vbox->pack_start(*exit/*, Gtk::PACK_SHRINK, 0*/);
	vbox->show_all();
}

Main_Menu::~Main_Menu() {}

void Main_Menu::create_lbrn_clicked()
{
	controller.execute_pm(1);
}

void Main_Menu::load_data_clicked()
{
	controller.execute_pm(2);
}

void Main_Menu::default_load_clicked()
{
	controller.execute_pm(8);
}

void Main_Menu::save_data_clicked()
{
	controller.execute_pm(3);
}

void Main_Menu::default_save_clicked()
{
	controller.execute_pm(7);
}

void Main_Menu::create_media_clicked()
{
	controller.execute_pm(4);	
}

void Main_Menu::create_bundle_clicked()
{
	controller.execute_pm(5);
}

void Main_Menu::check_out_list()
{
	controller.execute_pm(6);
}

void Main_Menu::check_out_clicked()
{
	controller.execute_lbrn(1);
}

void Main_Menu::check_in_clicked()
{
	controller.execute_lbrn(2);
}

void Main_Menu::create_customer_clicked()
{
	controller.execute_lbrn(3);
}

void Main_Menu::view_catalog_clicked()
{
	controller.execute_cust(1);
}

void Main_Menu::pay_balance_clicked()
{
	controller.execute_cust(2);
}

void Main_Menu::on_exit_clicked()
{
	close();
}
