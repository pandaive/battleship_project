#include <iostream>
using namespace std;

#define RED	     0x0004
#define GREEN	     0x0002
#define BLUE	     0x0001
#define WHITE	     RED|GREEN|BLUE
#define YELLOW       RED|GREEN
#define PINK	     RED|BLUE
#define TURQUOISE    BLUE|GREEN
#define BG_RED	     0x0040
#define BG_GREEN     0x0020
#define BG_BLUE	     0x0010
#define BG_WHITE     BG_RED|BG_GREEN|BG_BLUE
#define BG_YELLOW    BG_RED|BG_GREEN
#define BG_PIN       KBG_|BG_BLUE
#define BG_TURQUOISE BG_BLUE|BG_GREEN
typedef unsigned short int usint;
//---------------------------------------------------------------------------------	
class ostreamHelper                                                                         //// do kolorów, wziête z internetu, wa¿ne ¿e dzia³a
{private:
			usint n_;
			bool inten_;
			ostream& (*f_)(ostream&,usint,bool);
	public:
			ostreamHelper(ostream&(*f)(ostream&,usint, bool), usint n, bool inten):f_(f),n_(n),inten_(inten) { }
			friend ostream& operator<<(ostream& os,ostreamHelper helper)
			{return helper.f_(os,helper.n_,helper.inten_); }};
//---------------------------------------------------------------------------------	
ostream& ColHelper(ostream& os, usint col, bool inten)                                                       // dalej kolory
{HANDLE *hOut=new HANDLE;
	*hOut=GetStdHandle(STD_OUTPUT_HANDLE);
	if(inten==true)
		col+=0x0008;
	SetConsoleTextAttribute(*hOut,col);
	delete hOut;
	return os;}
//--------------------------------------------------------------------------------	
ostreamHelper col(usint col, bool intensiv)                                                                  // i tu dalej kolory
{return ostreamHelper(&ColHelper,col,intensiv);}

///////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////KONIEC
