#include "thn9732_Library.h"

class View
{
public:
	View(Library& l): lib(l) {};
	string get_start_menu();
	string get_cust_menu();
	string get_pm_menu();
	string get_lbrn_menu();
	string get_media_menu();

private:
	Library& lib;
};
