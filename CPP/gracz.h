#include <iostream>
using namespace std;

short mapaGracz[2][10][10];
      short mapaKomputer[2][10][10]; 

class gracz{                                                 // klasa na podstawie której stworzona jest tablica obiektów "gracz1" i "gracz2"
      
  public:    short a,b;  // wspol ostatniego trafienia
      short a1,b1,x1,y1; // wspol 1 trafienia
      short zatopione;
      short mediumtrafienia;
      short ktorystatek; //
      short wktora;
      short zestrzelone;
      
      virtual void rozmiesc()=0;
      virtual void strzelanie(bool &trafiony)=0;
      virtual bool Koniec()=0;
      public:                                                  
      
            
      bool czyMapa(short x, short y){  // metoda sprawdzajaca czy wspl leza na mapie
              bool czy=false;
              if(x>=0 && x<=9){
                        if(y>=0 && y<=9) czy=true;
                      }
              return czy;
              }
      
      bool czyWolny(short x, short y, short czyja, short i){  // metoda sprawdzajaca czy podane pole jest wolne
            bool czy=false;
            if (czyja==0){
                  if(mapaGracz[i][x][y]!=1 && mapaGracz[i][x][y]!=2) czy=true; 
                           }
            
            else if (czyja==1){
             if(mapaKomputer[i][x][y]!=1 && mapaKomputer[i][x][y]!=2) czy=true;      
           } return czy;
            
           }     
     
     void odstep(short x, short y, short czyja){                                            // metoda dziêki której teoretycznie maja byc zachowane odstêpy miêdzy statkami
          if (czyja==0){                                                                     // niestety dzia³a chyba kiedy chce
          if(czyMapa(x-1,y-1)==true && czyWolny(x-1,y-1,0,0)==true) mapaGracz[0][x-1][y-1]=2;
          if(czyMapa(x+1,y+1)==true && czyWolny(x+1,y+1,0,0)==true) mapaGracz[0][x+1][y+1]=2;
          if(czyMapa(x-1,y)==true && czyWolny(x-1,y,0,0)==true) mapaGracz[0][x-1][y]=2;
          if(czyMapa(x,y-1)==true && czyWolny(x,y-1,0,0)==true) mapaGracz[0][x][y-1]=2;
          
          if(czyMapa(x+1,y-1)==true && czyWolny(x+1,y-1,0,0)==true) mapaGracz[0][x+1][y-1]=2;
          if(czyMapa(x+1,y)==true && czyWolny(x+1,y,0,0)==true) mapaGracz[0][x+1][y]=2;
          if(czyMapa(x,y+1)==true && czyWolny(x,y+1,0,0)==true) mapaGracz[0][x][y+1]=2;
          if(czyMapa(x-1,y+1)==true && czyWolny(x-1,y+1,0,0)==true) mapaGracz[0][x-1][y+1]=2;
          }
          else if (czyja==1){
          if(czyMapa(x-1,y-1)==true && czyWolny(x-1,y-1,1,0)==true) mapaKomputer[0][x-1][y-1]=2;
          if(czyMapa(x+1,y+1)==true && czyWolny(x+1,y+1,1,0)==true) mapaKomputer[0][x+1][y+1]=2;
          if(czyMapa(x-1,y)==true && czyWolny(x-1,y,1,0)==true) mapaKomputer[0][x-1][y]=2;
          if(czyMapa(x,y-1)==true && czyWolny(x,y-1,1,0)==true) mapaKomputer[0][x][y-1]=2;
          
          if(czyMapa(x+1,y-1)==true && czyWolny(x+1,y-1,1,0)==true) mapaKomputer[0][x+1][y-1]=2;
          if(czyMapa(x+1,y)==true && czyWolny(x+1,y,1,0)==true) mapaKomputer[0][x+1][y]=2;
          if(czyMapa(x,y+1)==true && czyWolny(x,y+1,1,0)==true) mapaKomputer[0][x][y+1]=2;
          if(czyMapa(x-1,y+1)==true && czyWolny(x-1,y+1,1,0)==true) mapaKomputer[0][x-1][y+1]=2;
          }
          }                    
          
     string umiesc(short x, short y, short ile, short czyja){  // sprawdza czy z danego punktu poczatkowego mozna umiescic statek
          string ktore="OOOO";
          ile--;
          
           for(int i=1 ; i<=ile ; i++) {  // sprawdzenie dla N
                      if(czyMapa(x-i,y) && czyWolny(x-i,y,czyja,0)) ktore[0]='N';
                       else ktore[0]='O';
                   }  
           
           for(int i=1 ; i<=ile ; i++) {  // sprawdzenie dla S
                      if(czyMapa(x+i,y) && czyWolny(x+i,y,czyja,0)) ktore[1]='S';
                       else ktore[1]='O';  
                   }  
           
           for(int i=1 ; i<=ile ; i++) {  // sprawdzenie dla W
                      if(czyMapa(x,y-i) && czyWolny(x,y-i,czyja,0)) ktore[2]='W';
                       else ktore[2]='O';  
                   }  
           
           for(int i=1 ; i<=ile ; i++) {  // sprawdzenie dla E
                      if(czyMapa(x,y+i) && czyWolny(x,y+i,czyja,0)) ktore[3]='E';
                       else ktore[3]='O';  
                   }                         
          return ktore;
          } // koniec sprawdzania                
     
       public:
                               // zmienna zliczaj¹ca iloœæ udanych strza³ów gracza, dziêki której wiemy kiedy gracz wygra grê
      
            
      void wyswietl(short czyja){  // wyswietlanie mapy
      
           cout << "  " ; for(int i=0 ; i<10 ; i++) cout << i+1; cout << endl;
           
           for(int i=0 ; i<10 ; i++){
                  if (i>=0 && i<9) cout << i+1 << ".";
                  if (i==9) cout << i+1;
                  
                  if (czyja==0){
            for(int j=0 ; j<10 ; j++)
             if(mapaGracz[0][i][j]==1) {cout << col(GREEN,true) << "X"; cout << col(WHITE, false);}
              else if(mapaGracz[0][i][j]==3) {cout << col(RED,true) << "X"; cout << col(WHITE, false);}
               else if(mapaGracz[0][i][j]==4) cout << "X";
               else cout << " ";
             cout << endl;
           }
           else if (czyja==1){
                for(int j=0 ; j<10 ; j++)
             if(mapaKomputer[0][i][j]==1) {cout << col(GREEN,true) << "X"; cout << col(WHITE, false);}
              else if(mapaKomputer[0][i][j]==3) {cout << col(RED,true) << "X"; cout << col(WHITE, false);}
               else if(mapaKomputer[0][i][j]==4) cout << "X";
               else cout << " ";
             cout << endl;
             }
                
                }
           }  // koniec metiody wyswietlajacej
      
      
      void wyswietlStrzaly(short czyja){  // wyswietlanie mapy strza³ów
          
          cout << "  " ; for(int i=0 ; i<10 ; i++) cout << i+1; cout << endl;
           
           for(int i=0 ; i<10 ; i++){
                  if (i>=0 && i<9) cout << i+1 << ".";
                  if (i==9) cout << i+1;
                   
            for(int j=0 ; j<10 ; j++)
            if (czyja==0){
             if(mapaGracz[1][i][j]==1 || mapaGracz[1][i][j]==3) {cout << col(RED,true) << "X"; cout << col(WHITE, false);}
              else if(mapaGracz[1][i][j]==2 || mapaGracz[1][i][j]==4) {cout << col(WHITE,false) << "X";}
               else cout << " ";}
             
             else if (czyja==1){
                  if(mapaKomputer[1][i][j]==1 || mapaKomputer[1][i][j]==3) {cout << col(RED,true) << "X"; cout << col(WHITE, false);}
              else if(mapaKomputer[1][i][j]==2 || mapaKomputer[1][i][j]==4) {cout << col(WHITE,false) << "X";}
               else cout << " ";}
             cout << endl;
                  }
           }
           } ; // koniec metiody wyswietlajacej
