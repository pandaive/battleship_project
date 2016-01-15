#include <iostream>
#include <string>
#include <stdio.h>
#include <ctype.h>
#include <windows.h>
#include <fstream>
#include "statek.h"
#include "ostreamHelper.h"
#include "gracz.h"
#include "Komputer.h"
#include "Czlowiek.h"
#include "Easy.h"
#include "Medium.h"
#include "Hard.h"
using namespace std;
///////////////////////////////////////////////////////////////////////
/////////////////////////DEFINICJE KOLOROW/////////////////////////////
///////////////////////////////////////////////////////////////////////

///////////////////////////////////  struktura odpowiadajaca za pola rankingu.
struct ranking{                                
       
       string nazwa;
       int lp,wynik;
       
       };      
/////////////////////
void wysMenu(){             // funkcja wyswietlajaca menu glowne
       cout << " Gra statki " << endl;
       cout << "Wybierz jedna z ponizszych opcji w menu: " << endl;
       cout << "1. Nowa gra " << endl;
       cout << "2. Ranking " << endl;
       cout << "3. Pomoc " << endl;
       cout << "4. Wyjscie " << endl;    
     }
/////////////////////
void wysMenuGry(){
     cout << "Zaczynasz nowa gre!" << endl;
     cout << "Wybierz poziom trudnosci:" << endl;
     cout << "1. Easy" << endl;
     cout << "2. Medium" << endl;
     cout << "3. Hard" << endl;
     }
/////////////////////////////////     
void odczytPomoc(){
      fstream odc("pomoc.txt", ios::in);
      string linia;
      
      if(ifstream("pomoc.txt"))
       while(getline(odc, linia)) cout << linia << endl;
       else cout << "Plik pomocy nie istnieje ! " << endl;
      
     }
///////////////////////
 void wpisRanking(string nick, int wynik){   // funkcja sluzaca do zapisu wyniku
              string linia;
              int ileRekordow=0; // zmienna przechowujaca aktualna ilosc rekordow
              int tmp;           //tmp do sortowania
              string tmp1;       //tmp1 do sortowania
              char kropka; // zmienna do odczytu kropki :)
                                          
              fstream odczyt("ranking.bin", ios::in);  // otwarcie strumeinia odczytu
              while(getline(odczyt, linia)) ileRekordow++;  // petla sprawdzajaca ilkosc lini w pliku
              
              odczyt.clear(); // resetowanie stanow flag
              odczyt.seekg (0,ios::beg);  // ustawienie wskaznika na poczatek pliku
              
              getline(odczyt, linia);  // odczytanie pierwszej linii zaw. opisy kolumn
                               
              ranking *tabRanking = new ranking[ileRekordow];  // dynamiczna tablica struktur o rozmiarze ilosc_wpisow + 1 miejsce na nowy wpis 
              
              for(int i=0 ; i<ileRekordow-1 ; i++){
                            odczyt>>tabRanking[i].lp>>kropka>>tabRanking[i].nazwa>>tabRanking[i].wynik;
                      } 
                      
             odczyt.close();  // zamkniecie strumienia odczytu      
             tabRanking[ileRekordow-1].nazwa=nick;       // dopisanie aktualnie wprowadzanego wpisy do wyniku                        
             tabRanking[ileRekordow-1].wynik=wynik;
                                        
             for(int i=0 ; i<ileRekordow ; i++)        // sortowanie babelkowe
              for(int j=0 ; j<ileRekordow-1 ; j++)
               if(tabRanking[j].wynik>tabRanking[j+1].wynik){
                                                               tmp=tabRanking[j].wynik;
                                                               tabRanking[j].wynik = tabRanking[j+1].wynik;
                                                               tabRanking[j+1].wynik = tmp;
                                                               
                                                               tmp1=tabRanking[j].nazwa;
                                                               tabRanking[j].nazwa = tabRanking[j+1].nazwa;
                                                               tabRanking[j+1].nazwa = tmp1;
                                                                                                                              
                                                             }
                                                 
              for(int i=0 ; i<ileRekordow ; i++) tabRanking[i].lp=i+1;               
                            
              fstream zapis("ranking.bin", ios::out);
              zapis << "Lp." << " " << "Gracz" << " " << "Wynik";  // wpisanie pierwszej lini
              zapis.close();
             
              ofstream dopis("ranking.bin", ios::app);
              // dopisywanie wszystkich wynikow do przygotowanego pliku
              for(int i=0 ; i<ileRekordow ; i++) dopis << endl << tabRanking[i].lp << "." << " " << tabRanking[i].nazwa << " " << tabRanking[i].wynik;
              delete [] tabRanking; // zwolnienie pamieci zajmowanej przez tablice dynamiczna
              dopis.close();              
            }
///////////////////////
 void odczytRanking(){  // metoda wyswietlajaca zawartosci pliku rankingowego, ten plik docelowo bedzie jeszcze szyfrowany
               fstream odc("ranking.bin", ios::in);
          string linia;
          if(ifstream("ranking.bin")) //cout << "istnieje!" << endl; if sprawdzajacy czy plik rankingu istnieje
           while(getline(odc, linia)){
                               cout << linia << endl << endl;
                              }
            else cout << "Plik z rankingiem nie istnieje !" << endl << endl; 
          
            }   // koniec 
///////////////////////
int main(){

srand(time(NULL));  // uruchomienie generatora licz losowych    
 int wybor, wybor2;  // zmienna odpowiadajaca za wybor opcji w menu
 string nick;
 short ruch;
 
 bool trafiony=false;
    do{
    do{  // petla sprawdzajaca poprawnosc wprowadzonej wareosci
        wysMenu(); // wyswietlenie menu
        cin >> wybor; // wczytanie wyboru
              
    switch(wybor){
                  case 1 : {
                       wysMenuGry();
                       cin >> wybor2;
                       switch(wybor2){                    
                         case 1 : {
                              
                            gracz* gracz[2];
                            gracz[0]=new Czlowiek();
                            gracz[1]=new Easy();
                            gracz[1]->zatopione=0;
                            ruch=0;
                            cout << "Podaj swoj nick(bez spacji!)" << endl;
                            cin >> nick;
                            gracz[1]->rozmiesc();
                            gracz[0]->rozmiesc();
                               do{
                             cout << "Tura gracza 1 ! " << endl;
                             cout << "Mapa gracz 1 :" << endl;
                             gracz[0]->wyswietl(0);
                             cout << "Mapa strzalow gracza 1: " << endl;
                             gracz[1]->wyswietlStrzaly(1);
                             gracz[0]->strzelanie(trafiony);
                             cout << endl;
                             gracz[1]->strzelanie(trafiony);
                             ruch++;
                             
                             }while(gracz[1]->zatopione<20 && gracz[0]->zestrzelone<20);
                          
                           
                           if (gracz[0]->zestrzelone==20){
                            wpisRanking(nick, ruch);
                            cout << "Wygrana ! " << endl;}
                            else cout << "Przegrana ! " << endl;
                            system("PAUSE");
                            break;
                            }
                              
                         case 3 : {
                              
                            gracz* gracz[2];
                            gracz[0]=new Czlowiek();
                            gracz[1]=new Hard();
                            gracz[1]->mediumtrafienia=0;
                            gracz[1]->zatopione=0;
                            ruch=0;
                            cout << "Podaj swoj nick(bez spacji!)" << endl;
                            cin >> nick;
                            gracz[1]->rozmiesc();
                            gracz[0]->rozmiesc();
                               do{
                             cout << "Tura gracza 1 ! " << endl;
                             cout << "Mapa gracz 1 :" << endl;
                             gracz[0]->wyswietl(0);
                             cout << "Mapa strzalow gracza 1: " << endl;
                             gracz[1]->wyswietlStrzaly(1);
                             gracz[0]->strzelanie(trafiony);
                             cout << endl;
                             gracz[1]->strzelanie(trafiony);
                             ruch++;
                             
                             }while(gracz[1]->zatopione<20 && gracz[0]->zestrzelone<20);
 
                           if (gracz[0]->zestrzelone==20){
                            wpisRanking(nick, ruch);
                            cout << "Wygrana ! " << endl;
                            
                            }
                            else cout << "Przegrana ! " << endl;
                            system("PAUSE");
                            break;
                            }
                         
                         case 2 : {
                        
                            gracz* gracz[2];
                            gracz[0]=new Czlowiek();
                            gracz[1]=new Medium();
                            ruch=0;
                            cout << "Podaj swoj nick(bez spacji!)" << endl;
                            cin >> nick;
                            gracz[1]->rozmiesc();
                            gracz[0]->rozmiesc();
                            
                            do{
                             cout << "Tura gracza 1 ! " << endl;
                             cout << "Mapa gracz 1 :" << endl;
                             
                             gracz[0]->wyswietl(0);
                             
                             
                             cout << "Mapa strzalow gracza 1: " << endl;
                             gracz[1]->wyswietlStrzaly(1);
                            
                             gracz[0]->strzelanie(trafiony);
                             cout << endl;
                             
                             gracz[1]->strzelanie(trafiony);
                             ruch++;
                             
                             }while(gracz[0]->Koniec()==false && gracz[0]->zestrzelone<20);
                          
                             
                           if (gracz[0]->zestrzelone==20){
                            wpisRanking(nick, ruch);
                            cout << "Wygrana ! " << endl;}
                            else cout << "Przegrana ! " << endl;
                            system("PAUSE");
                            break;
                            }}}
                  case 2 : {
                             odczytRanking();
                             break;}
                  case 3 : {
                           odczytPomoc();
                           break;}
                  case 4 : break;
                  default : cout << "Podaj wlasciwa wartosc ! " << endl;
                  } 
    }while(wybor<1 || wybor>4);
    }while(wybor!=4);
    system("PAUSE");
    }
