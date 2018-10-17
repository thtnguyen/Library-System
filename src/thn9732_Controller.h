#include "thn9732_Library.h"
#include "thn9732_View.h"
#include "thn9732_gui.h"

class Controller
{
public:
	Controller(View& v, Library& lib) : view(v), library(lib) {};
	void execute_pm(int cmd);
	void execute_cust(int cmd);
	void execute_lbrn(int cmd);

private:
	View& view;
	Library& library;	

};
