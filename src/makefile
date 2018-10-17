CXXFLAGS = -std=c++11
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

all: executable

executable: thn9732_main.o thn9732_gui.o thn9732_Date.o thn9732_Transaction.o thn9732_Controller.o thn9732_View.o thn9732_Library.o thn9732_Librarian.o thn9732_Customer.o thn9732_Bundle.o thn9732_Music_Album.o thn9732_Video_Game.o thn9732_TV_Show.o thn9732_movie.o thn9732_book.o thn9732_media.o thn9732_Main_Menu.o
	$(CXX) $(CXXFLAGS) thn9732_main.o thn9732_gui.o thn9732_Date.o thn9732_Transaction.o thn9732_Controller.o thn9732_View.o thn9732_Library.o thn9732_Librarian.o thn9732_Customer.o thn9732_Bundle.o thn9732_Music_Album.o thn9732_Video_Game.o thn9732_TV_Show.o thn9732_movie.o thn9732_book.o thn9732_media.o thn9732_Main_Menu.o $(GTKFLAGS)

thn9732_main.o: thn9732_main.cpp thn9732_media.h
	$(CXX) $(CXXFLAGS) -c thn9732_main.cpp $(GTKFLAGS)

thn9732_gui.o: thn9732_gui.cpp thn9732_gui.h
	$(CXX) $(CXXFLAGS) -c thn9732_gui.cpp $(GTKFLAGS)
	
thn9732_Date.o: thn9732_Date.cpp thn9732_Date.h
	$(CXX) $(CXXFLAGS) -c thn9732_Date.cpp 

thn9732_Transaction.o: thn9732_Transaction.cpp thn9732_Transaction.h
	$(CXX) $(CXXFLAGS) -c thn9732_Transaction.cpp 

thn9732_Controller.o: thn9732_Controller.cpp thn9732_Controller.h
	$(CXX) $(CXXFLAGS) -c thn9732_Controller.cpp $(GTKFLAGS)

thn9732_View.o: thn9732_View.cpp thn9732_View.h
	$(CXX) $(CXXFLAGS) -c thn9732_View.cpp $(GTKFLAGS)

thn9732_Library.o: thn9732_Library.cpp thn9732_Library.h
	$(CXX) $(CXXFLAGS) -c thn9732_Library.cpp $(GTKFLAGS)

thn9732_Librarian.o: thn9732_Librarian.cpp thn9732_Librarian.h
	$(CXX) $(CXXFLAGS) -c thn9732_Librarian.cpp 

thn9732_Customer.o: thn9732_Customer.cpp thn9732_Customer.h
	$(CXX) $(CXXFLAGS) -c thn9732_Customer.cpp

thn9732_Bundle.o: thn9732_Bundle.cpp thn9732_Bundle.h
	$(CXX) $(CXXFLAGS) -c thn9732_Bundle.cpp

thn9732_Music_Album.o: thn9732_Music_Album.cpp thn9732_Music_Album.h
	$(CXX) $(CXXFLAGS) -c thn9732_Music_Album.cpp

thn9732_Video_Game.o: thn9732_Video_Game.cpp thn9732_Video_Game.h
	$(CXX) $(CXXFLAGS) -c thn9732_Video_Game.cpp

thn9732_TV_Show.o: thn9732_TV_Show.cpp thn9732_TV_Show.h
	$(CXX) $(CXXFLAGS) -c thn9732_TV_Show.cpp

thn9732_movie.o: thn9732_movie.cpp thn9732_movie.h
	$(CXX) $(CXXFLAGS) -c thn9732_movie.cpp

thn9732_book.o: thn9732_book.cpp thn9732_book.h
	$(CXX) $(CXXFLAGS) -c thn9732_book.cpp

thn9732_media.o: thn9732_media.cpp thn9732_media.h
	$(CXX) $(CXXFLAGS) -c thn9732_media.cpp

thn9732_Main_Menu.o: thn9732_Main_Menu.cpp thn9732_Main_Menu.h
	$(CXX) $(CXXFLAGS) -c thn9732_Main_Menu.cpp $(GTKFLAGS)


clean:
	rm -f a.out *.o
