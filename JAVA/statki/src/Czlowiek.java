import java.util.Scanner;



class Czlowiek extends gracz implements rozmieszczanie {
	Scanner sc = new Scanner(System.in);                         
	statek statki[]= new statek[10];
          Czlowiek(){            // konstruktor bezparametrowy
                             // zerowanie map przed rozpoczeciem rozgrywki
           for(int i=0 ; i<10 ; i++)
            for(int j=0 ; j<10 ; j++){
                      mapaGracz[0][i][j]=0;
                      mapaGracz[1][i][j]=0;
                    }
           
           for (int i=0; i<10; i++){
        	   statki[i]=new statek();     
           }
              // przydzielanie statkom masztow
           for(int i=0 ; i<10 ; i++) if(i<=3) statki[i].maszty=1;
                                      else if(i>3 && i<=6) statki[i].maszty=2;
                                       else if(i>6 && i<=8) statki[i].maszty=3;
                                        else statki[i].maszty=4;
                                        }
          
          boolean szukaj(String litery, char litera){
           boolean znal=false;                                           /// przy rozmieszczaniu statk�w przez gracza
           
           for(int i=0 ; i<4 ; i++) if(litery.charAt(i)==litera) znal=true;
           
           return znal;
           }
           
            boolean strzal(short x, short y){   // metoda od szczelania(stszelania(?)) shoocenia
          boolean shot; 
          
          if(mapaKomputer[0][x][y]==1) {shot=true; mapaKomputer[0][x][y]=3;}
           else {shot=false; mapaKomputer[0][x][y]=4;}
           
          return shot; 
           }                     // koniec wystrzalowej metody
      
      boolean Koniec(){                          // metoda sprawdzaj�ca czy komputer wygra�
                     boolean koniec=true;
                     
                     for(int i=0 ; i<10 ; i++)
                      for(int j=0 ; j<4 ; j++)
                       if(statki[i].trafiony[j]==0) {koniec=false; break;}
                       
                       return koniec; 
                     
                     }
                              
      void strzelanie(boolean cokolwiek){                       // strzelanie przez gracza
           short x,y;
           boolean mozna;
           
           
           do{  //do..while poprawnosc wspolrzednych
           System.out.println("Podaj pierwsza wspolrzedna ");
           y=sc.nextShort();
           System.out.println("Podaj druga wspolrzedna ");
           x=sc.nextShort();
           x--;
           y--;
           if(czyMapa(x,y)) mozna=true;
            else mozna=false;
            
           }while(mozna==false); // koniec do,,while
           
           if(strzal(x,y)) {System.out.println( "Trafiony !" ); zestrzelone++; mapaKomputer[1][x][y]=1; 
           if (x1==50 && y1==50) { x1=x; y1=y;}
           
           
           if (x!=0 && y!=0 && x!=9 && y!=9 && x1!=0 && y1!=0 && x1!=9 && y1!=9 )
            				   if ((mapaKomputer[0][(x+1)][y]!=1 && mapaKomputer[0][(x-1)][y]!=1 && mapaKomputer[0][x][(y+1)]!=1 && mapaKomputer[0][x][(y-1)]!=1) && (mapaKomputer[0][(x1+1)][y1]!=1 && mapaKomputer[0][(x1-1)][y1]!=1 && mapaKomputer[0][x1][(y1+1)]!=1 && mapaKomputer[0][x1][(y1-1)]!=1) ) { System.out.println( "Trafiony zatopiony !" ); x1=50; y1=50; }
            			   
           
           }  // je�li gracz trafi, zapisujemy udany strza� oraz oznaczamy strza� na mapie strza��w
            else {System.out.println( "Pudlo ! " ); mapaKomputer[1][x][y]=2;}   // zapisuje na mapie nietrafiony strza�
          
            
           //wyswietl();
           
           }                             
         
  public void rozmiesc(){
          short x,y; // zmienne przechowujace wspolrzedne statkow
          x1=50; y1=50;
                                 
           boolean wmapie,wolne,ruch = false,zawiera; // zmienna pomocniczna
           char kierunek;
           zestrzelone=0;
                 for(int i=0 ; i<10 ; i++) 
                 
                 if(i<=3) {
                                                      
                   do{ // petla sprawdzajaca czy wspolrzedne leza na mapie
                                                      
                     System.out.println( "Podaj pierwsza wspolrzedna dla " + (i+1) + " statku 1 masztowego " );
                     y=sc.nextShort();
                     y--;
                     System.out.println( "Podaj druga wspolrzedna dla " + (i+1) + " statku 1 masztowego " );
                     x=sc.nextShort();
                     x--;
                                                      
                     wmapie=czyMapa(x,y);
                     wolne=czyWolny(x,y,0,0);
                                                                
                     if(wmapie==false) System.out.println( "Podane wspolrzedne leza poza obszarem mapy, wpisz je ponownie !");
                     if(wolne==false) System.out.println( "Podane wspolrzedne sa zajete ! Wprowadz je ponownie " );
                                                      
                       }while(wmapie==false || wolne==false); // koniec do..while
                                                      
                     mapaGracz[0][x][y]=1;
                     statki[i].wspol[0][0]=x;      /// przyporz�dkowanie wsp�lrz�dnych statku
                     statki[i].wspol[0][1]=y;
                     statki[i].trafiony[0]=0;
                       for (int k=0 ; k<3 ; k++) {
                       statki[i].trafiony[k+1]=1;} 
                       odstep(x,y,0);    
                       wyswietl((short) 0);
                                                                        
                         }
                 else if(i>3 && i<=6) {  // pocztek dla 2 masztow
                                            
                   do{ // petla sprawdzajaca czy wspolrzedne leza na mapie
                                                      
                                                      
                	  System.out.println( "Podaj pierwsza wspolrzedna dla " + (i+1) + " statku czyli dwumasztowca " );
                	  y=sc.nextShort();
                      y--;
                      System.out.println( "Podaj druga wspolrzedna dla " + (i+1) + " statku czyli dwumasztowca " );
                      x=sc.nextShort();
                      x--;
                      System.out.println(mapaGracz[0][x][y]);                                
                      wmapie=czyMapa(x,y);
                      wolne=czyWolny(x,y,0,0);
                                                      
                      if(umiesc(x,y,2,0)=="OOOO") ruch=false;
                        else ruch=true;
                                                                 
                      if(wmapie==false) System.out.println( "Podane wspolrzedne leza poza obszarem mapy, wpisz je ponownie !");
                      if(wolne==false) System.out.println( "Podane wspolrzedne sa zajete ! Wprowadz je ponownie " );
                      if(ruch==false) System.out.println( "Nie mozesz umiescic tam pierwszego masztu ! " );
                   }while(wmapie==false || wolne==false || ruch==false); // koniec do..while
                                                      
                   mapaGracz[0][x][y]=1;
                   statki[i].wspol[0][0]=x; 
                   statki[i].wspol[0][1]=y;
                   for (int l=0 ; l<2 ; l++) { 
                   statki[i].trafiony[l]=0; }
                   for (int k=0 ; k<2 ; k++) {
                   statki[i].trafiony[k+2]=1;}
                                                      
                     do{  // wpisywanie poprawnej litery
                                                       
                       System.out.println( " W ktora strone umiescic reszte masztow? w/s/e/n" );
                       kierunek=sc.next().charAt(0);
                       
                                                                                          
                       kierunek=Character.toUpperCase(kierunek);
                       
                       if(szukaj(umiesc(x,y,2,0),kierunek)==false) {zawiera=false ; System.out.println( "Podales bledny kierunek " );}
                        else zawiera=true;
                     }while(zawiera==false || (kierunek!='N' && kierunek!='W' && kierunek!='E' && kierunek!='S'));
                                                      
                     odstep(x,y,0);
                                                      
                                                      
                     if(kierunek=='W') {mapaGracz[0][x][y-1]=1; odstep(x,y-1,0);
                          statki[i].wspol[1][0]=x; 
                          statki[i].wspol[1][1]=(short) (y-1);}      // dostawianie drugiego masztu
                     else if(kierunek=='S') {mapaGracz[0][x+1][y]=1; odstep(x+1,y,0);
                          statki[i].wspol[1][0]=(short) (x+1); 
                          statki[i].wspol[1][1]=y; }
                     else if(kierunek=='E') { mapaGracz[0][x][y+1]=1; odstep(x,y+1,0);
                          statki[i].wspol[1][0]=x; 
                          statki[i].wspol[1][1]=(short) (y+1); }
                     else { mapaGracz[0][x-1][y]=1; odstep(x-1,y,0);
                          statki[i].wspol[1][0]=(short) (x-1); 
                          statki[i].wspol[1][1]=y; }
                                                      
                     wyswietl((short) 0);
                                                      
                                                      
                     } // koniec dla 2
                 else if(i>6 && i<=8) {   // poczatek dla 3
                                                    
                    do{ // petla sprawdzajaca czy wspolrzedne leza na mapie
                                                       
                      System.out.println( "Podaj pierwsza wspolrzedna dla " + i+1 + " statku czyli 3 masztowca " );
                      y=sc.nextShort();
                      y--;
                      System.out.println( "Podaj druga wspolrzedna dla " +i+1 + " statku czyli 3 masztowca " );
                      x=sc.nextShort();
                      x--;
                                                      
                      wmapie=czyMapa(x,y);
                      wolne=czyWolny(x,y,0,0);
                                                                
                      if(wmapie==false) System.out.println( "Podane wspolrzedne leza poza obszarem mapy, wpisz je ponownie !" );
                      if(wolne==false) System.out.println( "Podane wspolrzedne sa zajete ! Wprowadz je ponownie " );
                      if(ruch==false) System.out.println( "Nie mozesz umiescic tam pierwszego masztu ! " );
                    }while(wmapie==false || wolne==false || ruch==false); // koniec do..while
                                                      
                                                      
                    mapaGracz[0][x][y]=1;
                    statki[i].wspol[0][0]=x; 
                    statki[i].wspol[0][1]=y;
                    for (int k=0; k<3; k++) { 
                    statki[i].trafiony[k]=0; }
                    statki[i].trafiony[3]=1;
                 do{  // wpisywanie poprawnej litery
                                                       
                    System.out.println( " W ktora strone umiescic reszte masztow? w/s/e/n" );
                    kierunek=sc.next().charAt(0);
                    kierunek=Character.toUpperCase(kierunek);
                    if(szukaj(umiesc(x,y,3,0),kierunek)==false) {zawiera=false ; System.out.println( "Podales bledny kierunek " );}
                    else zawiera=true;
                 }while((kierunek!='W' && kierunek!='N' && kierunek!='S' && kierunek!='E') || zawiera==false);
                                                      
                 odstep(x,y,0);
                                                      
                 for(int a=1 ; a<3 ; a++){
                 if(kierunek=='W') {mapaGracz[0][x][y-a]=1; odstep(x,y-a,0);
                       statki[i].wspol[a][0]=x; 
                       statki[i].wspol[a][1]=(short) (y-a);}      // dostawianie drugiego masztu
                 else if(kierunek=='S') {mapaGracz[0][x+a][y]=1; odstep(x+a,y,0);
                       statki[i].wspol[a][0]=(short) (x+a); 
                       statki[i].wspol[a][1]=y; }
                 else if(kierunek=='E') {mapaGracz[0][x][y+a]=1; odstep(x,y+a,0);
                       statki[i].wspol[a][0]=x; 
                       statki[i].wspol[a][1]=(short) (y+1); }
                 else {mapaGracz[0][x-a][y]=1; odstep(x-a,y,0);
                       statki[i].wspol[a][0]=(short) (x-a); 
                       statki[i].wspol[a][1]=y; }
                       }
                 wyswietl((short) 0);
                                                                                                                                                                
                   }  // koniec dla 3
           else { //poczatek dla 4
                                              
              do{ // petla sprawdzajaca czy wspolrzedne leza na mapie
                                                       
                System.out.println( "Podaj pierwsza wspolrzedna dla statku 4 masztowego " );
                y=sc.nextShort();
                y--;
                System.out.println( "Podaj druga wspolrzedna dla statku 4 masztowego " );
                x=sc.nextShort();
                x--;
                                                      
                wmapie=czyMapa(x,y);
                wolne=czyWolny(x,y,0,0);
                                                                
                if(wmapie==false) System.out.println( "Podane wspolrzedne leza poza obszarem mapy, wpisz je ponownie !" );
                if(wolne==false) System.out.println( "Podane wspolrzedne sa zajete ! Wprowadz je ponownie " );
                if(ruch==false) System.out.println( "Nie mozesz umiescic tam pierwszego masztu ! " );
              }while(wmapie==false || wolne==false || ruch==false); // koniec do..while
                                                      
              mapaGracz[0][x][y]=1;
              statki[i].wspol[0][0]=x; 
              statki[i].wspol[0][1]=y; 
                                                      
                do{  // wpisywanie poprawnej litery
                                                       
                   System.out.println( " W ktora strone umiescic reszte masztow? w/s/e/n" );
                   kierunek=sc.next().charAt(0);
                   kierunek=Character.toUpperCase(kierunek);
                   if(szukaj(umiesc(x,y,4,0),kierunek)==false) {zawiera=false ; System.out.println( "Podales bledny kierunek " );}
                   else zawiera=true;
                                                           
               }while((kierunek!='W' && kierunek!='N' && kierunek!='S' && kierunek!='E') || zawiera==false);
                                                      
                odstep(x,y,0);
                for(int g=0 ; g<4 ; g++){ statki[i].trafiony[g]=0;}  ;                                    
                for(int a=1 ; a<4 ; a++){
                        
                        
                if(kierunek=='W') {mapaGracz[0][x][y-a]=1; odstep(x,y-a,0);
                      statki[i].wspol[a][0]=x; 
                      statki[i].wspol[a][1]=(short) (y-a);}      // dostawianie drugiego masztu
                else if(kierunek=='S') {mapaGracz[0][x+a][y]=1; odstep(x+a,y,0);
                      statki[i].wspol[a][0]=(short) (x+a); 
                      statki[i].wspol[a][1]=y; }
                else if(kierunek=='E') {mapaGracz[0][x][y+a]=1; odstep(x,y+a,0);
                      statki[i].wspol[a][0]=x; 
                      statki[i].wspol[a][1]=(short) (y+a); }
                else {mapaGracz[0][x-a][y]=1; odstep(x-a,y,0);
                      statki[i].wspol[a][0]=(short) (x-a); 
                      statki[i].wspol[a][1]=y; }
                                                         }                                                                                         
                } // koniec dla 4
           
           }
      };  
