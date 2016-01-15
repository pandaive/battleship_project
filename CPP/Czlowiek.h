#include <iostream>
using namespace std;

class Czlowiek: public gracz{
                              /// szukajka liter odpowiadaj¹cych za kierunek umieszczania statków
   private:       statek statki[10];
  public:        Czlowiek(){            // konstruktor bezparametrowy
                             // zerowanie map przed rozpoczeciem rozgrywki
           for(int i=0 ; i<10 ; i++)
            for(int j=0 ; j<10 ; j++){
                      mapaGracz[0][i][j]=0;
                      mapaGracz[1][i][j]=0;
                    }
              // przydzielanie statkom masztow
           for(int i=0 ; i<10 ; i++) if(i<=3) statki[i].maszty=1;
                                      else if(i>3 && i<=6) statki[i].maszty=2;
                                       else if(i>6 && i<=8) statki[i].maszty=3;
                                        else statki[i].maszty=4;
                                        }
          
     private:     bool szukaj(string litery, char litera){
           bool znal=false;                                           /// przy rozmieszczaniu statków przez gracza
           
           for(int i=0 ; i<4 ; i++) if(litery[i]==litera) znal=true;
           
           return znal;
           }
           
            bool strzal(short x, short y){   // metoda od szczelania(stszelania(?)) shoocenia
          bool shot; 
          
          if(mapaKomputer[0][x][y]==1) {shot=true; mapaKomputer[0][x][y]=3;}
           else {shot=false; mapaKomputer[0][x][y]=4;}
           
          return shot; 
           }                     // koniec wystrzalowej metody
      
   public:   bool Koniec(){                          // metoda sprawdzaj¹ca czy komputer wygra³
                     bool koniec=true;
                     
                     for(int i=0 ; i<10 ; i++)
                      for(int j=0 ; j<4 ; j++)
                       if(statki[i].trafiony[j]==0) {koniec=false; break;}
                       
                       return koniec; 
                     
                     }
                              
   private:   void strzelanie(bool &cokolwiek){                       // strzelanie przez gracza
           short x,y;
           bool mozna;
           
           
           do{  //do..while poprawnosc wspolrzednych
           cout << "Podaj pierwsza wspolrzedna " << endl;
           cin >> y;
           cout << "Podaj druga wspolrzedna " << endl;
           cin >> x;
           x--;
           y--;
           if(czyMapa(x,y)) mozna=true;
            else mozna=false;
            
           }while(mozna==false); // koniec do,,while
           
           if(strzal(x,y)) {cout << "Trafiony !" << endl; zestrzelone++; mapaKomputer[1][x][y]=1; 
           if (x1==50 && y1==50) { x1=x; y1=y;}
           if ((mapaKomputer[0][x+1][y]!=1 && mapaKomputer[0][x-1][y]!=1 && mapaKomputer[0][x][y+1]!=1 && mapaKomputer[0][x][y-1]!=1) && (mapaKomputer[0][x1+1][y1]!=1 && mapaKomputer[0][x1-1][y1]!=1 && mapaKomputer[0][x1][y1+1]!=1 && mapaKomputer[0][x1][y1-1]!=1) ) { cout << "Trafiony zatopiony !" << endl; x1=50; y1=50; }
           
           
           }  // jeœli gracz trafi, zapisujemy udany strza³ oraz oznaczamy strza³ na mapie strza³ów
            else {cout << "Pudlo ! " << endl; mapaKomputer[1][x][y]=2;}   // zapisuje na mapie nietrafiony strza³
          
            
           //wyswietl();
           
           }                             
         
  void rozmiesc(){
          int x,y; // zmienne przechowujace wspolrzedne statkow
          x1=50; y1=50;
                                 
           bool wmapie,wolne,ruch,zawiera; // zmienna pomocniczna
           char kierunek;
           zestrzelone=0;
                 for(int i=0 ; i<10 ; i++) 
                 
                 if(i<=3) {
                                                      
                   do{ // petla sprawdzajaca czy wspolrzedne leza na mapie
                                                      
                     cout << "Podaj pierwsza wspolrzedna dla " << i+1 << " statku 1 masztowego " <<endl;
                     cin >> y;
                     y--;
                     cout << "Podaj druga wspolrzedna dla " << i+1 << " statku 1 masztowego " <<endl;
                     cin >> x;
                     x--;
                                                      
                     wmapie=czyMapa(x,y);
                     wolne=czyWolny(x,y,0,0);
                                                                
                     if(wmapie==false) cout << "Podane wspolrzedne leza poza obszarem mapy, wpisz je ponownie !" << endl;
                     if(wolne==false) cout << "Podane wspolrzedne sa zajete ! Wprowadz je ponownie " << endl;
                                                      
                       }while(wmapie==false || wolne==false); // koniec do..while
                                                      
                     mapaGracz[0][x][y]=1;
                     statki[i].wspol[0][0]=x;      /// przyporz¹dkowanie wspólrzêdnych statku
                     statki[i].wspol[0][1]=y;
                     statki[i].trafiony[0]=0;
                       for (int k=0 ; k<3 ; k++) {
                       statki[i].trafiony[k+1]=1;} 
                       odstep(x,y,0);    
                       wyswietl(0);
                                                                        
                         }
                 else if(i>3 && i<=6) {  // pocztek dla 2 masztow
                                            
                   do{ // petla sprawdzajaca czy wspolrzedne leza na mapie
                                                      
                                                      
                      cout << "Podaj pierwsza wspolrzedna dla " << i+1 << " statku czyli 2 masztowca " <<endl;
                      cin >> y;
                      y--;
                      cout << "Podaj druga wspolrzedna dla " << i+1 << " statku czyli 2 masztowca " <<endl;
                      cin >> x;
                      x--;
                                                      
                      wmapie=czyMapa(x,y);
                      wolne=czyWolny(x,y,0,0);
                                                      
                      if(umiesc(x,y,2,0)=="OOOO") ruch=false;
                        else ruch=true;
                                                                 
                      if(wmapie==false) cout << "Podane wspolrzedne leza poza obszarem mapy, wpisz je ponownie !" << endl;
                      if(wolne==false) cout << "Podane wspolrzedne sa zajete ! Wprowadz je ponownie " << endl;
                      if(ruch==false) cout << "Nie mozesz umiescic tam pierwszego masztu ! " << endl;
                   }while(wmapie==false || wolne==false || ruch==false); // koniec do..while
                                                      
                   mapaGracz[0][x][y]=1;
                   statki[i].wspol[0][0]=x; 
                   statki[i].wspol[0][1]=y;
                   for (int l=0 ; l<2 ; l++) { 
                   statki[i].trafiony[l]=0; }
                   for (int k=0 ; k<2 ; k++) {
                   statki[i].trafiony[k+2]=1;}
                                                      
                     do{  // wpisywanie poprawnej litery
                                                       
                       cout << " W ktora strone umiescic reszte masztow? w/s/e/n" << endl;
                       cin >> kierunek;
                                                                                          
                       kierunek=toupper(kierunek);
                       if(szukaj(umiesc(x,y,2,0),kierunek)==false) {zawiera=false ; cout << "Podales bledny kierunek " << endl;}
                        else zawiera=true;
                     }while(zawiera==false || (kierunek!='N' && kierunek!='W' && kierunek!='E' && kierunek!='S'));
                                                      
                     odstep(x,y,0);
                                                      
                                                      
                     if(kierunek=='W') {mapaGracz[0][x][y-1]=1; odstep(x,y-1,0);
                          statki[i].wspol[1][0]=x; 
                          statki[i].wspol[1][1]=y-1;}      // dostawianie drugiego masztu
                     else if(kierunek=='S') {mapaGracz[0][x+1][y]=1; odstep(x+1,y,0);
                          statki[i].wspol[1][0]=x+1; 
                          statki[i].wspol[1][1]=y; }
                     else if(kierunek=='E') { mapaGracz[0][x][y+1]=1; odstep(x,y+1,0);
                          statki[i].wspol[1][0]=x; 
                          statki[i].wspol[1][1]=y+1; }
                     else { mapaGracz[0][x-1][y]=1; odstep(x-1,y,0);
                          statki[i].wspol[1][0]=x-1; 
                          statki[i].wspol[1][1]=y; }
                                                      
                     wyswietl(0);
                                                      
                                                      
                     } // koniec dla 2
                 else if(i>6 && i<=8) {   // poczatek dla 3
                                                    
                    do{ // petla sprawdzajaca czy wspolrzedne leza na mapie
                                                       
                      cout << "Podaj pierwsza wspolrzedna dla " << i+1 << " statku czyli 3 masztowca " <<endl;
                      cin >> y;
                      y--;
                      cout << "Podaj druga wspolrzedna dla " << i+1 << " statku czyli 3 masztowca " <<endl;
                      cin >> x;
                      x--;
                                                      
                      wmapie=czyMapa(x,y);
                      wolne=czyWolny(x,y,0,0);
                                                                
                      if(wmapie==false) cout << "Podane wspolrzedne leza poza obszarem mapy, wpisz je ponownie !" << endl;
                      if(wolne==false) cout << "Podane wspolrzedne sa zajete ! Wprowadz je ponownie " << endl;
                      if(ruch==false) cout << "Nie mozesz umiescic tam pierwszego masztu ! " << endl;
                    }while(wmapie==false || wolne==false || ruch==false); // koniec do..while
                                                      
                                                      
                    mapaGracz[0][x][y]=1;
                    statki[i].wspol[0][0]=x; 
                    statki[i].wspol[0][1]=y;
                    for (int k=0; k<3; k++) { 
                    statki[i].trafiony[k]=0; }
                    statki[i].trafiony[3]=1;
                 do{  // wpisywanie poprawnej litery
                                                       
                    cout << " W ktora strone umiescic reszte masztow? w/s/e/n" << endl;
                    cin >> kierunek;
                    kierunek=toupper(kierunek);
                    if(szukaj(umiesc(x,y,3,0),kierunek)==false) {zawiera=false ; cout << "Podales bledny kierunek " << endl;}
                    else zawiera=true;
                 }while((kierunek!='W' && kierunek!='N' && kierunek!='S' && kierunek!='E') || zawiera==false);
                                                      
                 odstep(x,y,0);
                                                      
                 for(int a=1 ; a<3 ; a++){
                 if(kierunek=='W') {mapaGracz[0][x][y-a]=1; odstep(x,y-a,0);
                       statki[i].wspol[a][0]=x; 
                       statki[i].wspol[a][1]=y-a;}      // dostawianie drugiego masztu
                 else if(kierunek=='S') {mapaGracz[0][x+a][y]=1; odstep(x+a,y,0);
                       statki[i].wspol[a][0]=x+a; 
                       statki[i].wspol[a][1]=y; }
                 else if(kierunek=='E') {mapaGracz[0][x][y+a]=1; odstep(x,y+a,0);
                       statki[i].wspol[a][0]=x; 
                       statki[i].wspol[a][1]=y+1; }
                 else {mapaGracz[0][x-a][y]=1; odstep(x-a,y,0);
                       statki[i].wspol[a][0]=x-a; 
                       statki[i].wspol[a][1]=y; }
                       }
                 wyswietl(0);
                                                                                                                                                                
                   }  // koniec dla 3
           else { //poczatek dla 4
                                              
              do{ // petla sprawdzajaca czy wspolrzedne leza na mapie
                                                       
                cout << "Podaj pierwsza wspolrzedna dla statku 4 masztowego " <<endl;
                cin >> y;
                y--;
                cout << "Podaj druga wspolrzedna dla statku 4 masztowego " <<endl;
                cin >> x;
                x--;
                                                      
                wmapie=czyMapa(x,y);
                wolne=czyWolny(x,y,0,0);
                                                                
                if(wmapie==false) cout << "Podane wspolrzedne leza poza obszarem mapy, wpisz je ponownie !" << endl;
                if(wolne==false) cout << "Podane wspolrzedne sa zajete ! Wprowadz je ponownie " << endl;
                if(ruch==false) cout << "Nie mozesz umiescic tam pierwszego masztu ! " << endl;
              }while(wmapie==false || wolne==false || ruch==false); // koniec do..while
                                                      
              mapaGracz[0][x][y]=1;
              statki[i].wspol[0][0]=x; 
              statki[i].wspol[0][1]=y; 
                                                      
                do{  // wpisywanie poprawnej litery
                                                       
                   cout << " W ktora strone umiescic reszte masztow? w/s/e/n" << endl;
                   cin >> kierunek;
                   kierunek=toupper(kierunek);
                   if(szukaj(umiesc(x,y,4,0),kierunek)==false) {zawiera=false ; cout << "Podales bledny kierunek " << endl;}
                   else zawiera=true;
                                                           
               }while((kierunek!='W' && kierunek!='N' && kierunek!='S' && kierunek!='E') || zawiera==false);
                                                      
                odstep(x,y,0);
                for(int g=0 ; g<4 ; g++){ statki[i].trafiony[g]=0;}  ;                                    
                for(int a=1 ; a<4 ; a++){
                        
                        
                if(kierunek=='W') {mapaGracz[0][x][y-a]=1; odstep(x,y-a,0);
                      statki[i].wspol[a][0]=x; 
                      statki[i].wspol[a][1]=y-a;}      // dostawianie drugiego masztu
                else if(kierunek=='S') {mapaGracz[0][x+a][y]=1; odstep(x+a,y,0);
                      statki[i].wspol[a][0]=x+a; 
                      statki[i].wspol[a][1]=y; }
                else if(kierunek=='E') {mapaGracz[0][x][y+a]=1; odstep(x,y+a,0);
                      statki[i].wspol[a][0]=x; 
                      statki[i].wspol[a][1]=y+a; }
                else {mapaGracz[0][x-a][y]=1; odstep(x-a,y,0);
                      statki[i].wspol[a][0]=x-a; 
                      statki[i].wspol[a][1]=y; }
                                                         }                                                                                         
                } // koniec dla 4
           
           }
      };  
