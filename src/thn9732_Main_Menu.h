#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include <gtkmm.h>
#include "thn9732_Controller.h"

class Main_Menu : public Gtk::Window {

public:
	Main_Menu(Library& l, Controller& c);
	virtual ~Main_Menu();
protected:
	Gtk::Box* vbox;
	void create_lbrn_clicked();
	void load_data_clicked(); 	
	void save_data_clicked();
	void default_save_clicked();
	void default_load_clicked();
	void create_media_clicked();
	void create_bundle_clicked();
	void check_out_list();
	void check_out_clicked();
	void check_in_clicked();
	void create_customer_clicked();
	void view_catalog_clicked();
	void pay_balance_clicked();
	void on_exit_clicked();
	Library& lib;
	Controller& controller;
	
};

#endif
