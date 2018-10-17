//#include "thn9732_Controller.h"
#include "thn9732_Main_Menu.h"
#include <gtkmm.h>
#include <iostream>

int main(int argc, char* argv[])
{
	Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv, "edu.uta.cse1325.example");
	//Gtk::Main kit(argc, argv);
	
	Library library;
	View view = View(library);
	Controller controller = Controller(view, library);
	
	Main_Menu mm(library, controller);
	
	return app->run(mm);
	
}
