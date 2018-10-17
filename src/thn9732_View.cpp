#include "thn9732_View.h"

string View::get_start_menu()
{
	string menu = R"(

=======================================
 LIBRARY SYSTEM - START
=======================================
Welcome to the Library System.
Please select what type of user you are.
Enter 0 to exit the system.

(1) Project Manager
(2) Librarian
(3) Customer 

? )";

	return menu;
}

string View::get_cust_menu()
{
	string menu = R"(

=======================================
 LIBRARY SYSTEM - CUSTOMER
=======================================
Hello, Customer. What would you like to do?
Enter 0 to go back to previous menu.

(1) View Catalog
(2) Pay Balance

? )";

	return menu;

}

string View::get_pm_menu()
{
	string menu = R"(

==================================================
LIBRARY SYSTEM - PROJECT MANAGER
==================================================
Hello, Project Manager. What would you like to do?
Enter 0 to go back to previous menu.

(1) Create a Librarian
(2) Load Data
(3) Save Data
(4) Create media
(5) Create a bundle

? )";

	return menu;

}

string View::get_lbrn_menu()
{
	string menu = R"(

===========================================
LIBRARY SYSTEM - LIBRARIAN
============================================
Hello, Librarian. What would you like to do?
Enter 0 to go back to previous menu.	

(1) Check out media/bundles
(2) Check in media/bundles
(3) Create a Customer

? )";

	return menu;

}

string View::get_media_menu()
{
	string menu = R"(

============================================
LIBRARY SYSTEM - CREATE MEDIA
============================================
What type of media would you like to create?
Enter 0 to go back to previous menu.	

(1) Book
(2) Movie
(3) TV Show Season 
(4) Video Game
(5) Music Album

? )";

return menu;
}
