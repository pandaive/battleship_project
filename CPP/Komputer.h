#include <iostream>
using namespace std;

class Komputer: public gracz{
public:      statek statki[10];
       
       bool Koniec(){}
public:      Komputer(){
                            // zerowanie map przed rozpoczeciem rozgrywki
           for(int i=0 ; i<10 ; i++)
            for(int j=0 ; j<10 ; j++){
                      mapaKomputer[0][i][j]=0;
                      mapaKomputer[1][i][j]=0;
                    }
        // przydzielanie statkom masztow
           for(int i=0 ; i<10 ; i++) if(i<=3) statki[i].maszty=1;
                                      else if(i>3 && i<=6) statki[i].maszty=2;
                                       else if(i>6 && i<=8) statki[i].maszty=3;
                                        else statki[i].maszty=4;
                                                        
                 }
                 
    public:             bool czyZatopiony(short x) {                                       /// metoda sprawdzaj�ca czy statek zosta� zatopiony
         bool zatopiony=true;
                    
          for (int i=0 ; i<4 ; i++) if (statki[x].trafiony[i]==0) zatopiony=false;
          return zatopiony;
          }
             
    private:     void rozmiesc(){
           short x,y;
           x1=50; y1=50;
           bool pion=false;  // zmienna przechowujaca informacje o tym czy statek jest w pionie czy w poziomie
           bool mozna;
           
           zestrzelone=0;
           //umieszczenie 4 masztowca
           if((rand()%2)==0) pion=true;
            else pion=false;           
           for(int i=0 ; i<4 ; i++) statki[9].trafiony[i]=0;
           
           if(pion){
                    x=rand()%7;
                    y=rand()%10;
                    
                    statki[9].wspol[0][0]=x;
                    statki[9].wspol[0][1]=y;
                               
                    for(int a=1 ; a<4 ; a++) {statki[9].wspol[a][0]=x+a; statki[9].wspol[a][1]=y;}
                    
                    mapaKomputer[0][x][y]=1;
                    odstep(x,y,1);
                    for(int i=1 ; i<4 ; i++){ mapaKomputer[0][x+i][y]=1;
                    odstep(x+i,y,1);}                    
                    }
             else{
                    y=rand()%7;
                    x=rand()%10;
                    
                    statki[9].wspol[0][0]=x;
                    statki[9].wspol[0][1]=y;
                               
                    for(int a=1 ; a<4 ; a++) {statki[9].wspol[a][0]=x; statki[9].wspol[a][1]=y+a;}
                                        
                    mapaKomputer[0][x][y]=1;
                    odstep(x,y,1);
                    for(int i=1 ; i<4 ; i++){ mapaKomputer[0][x][y+i]=1;
                    odstep(x,y+i,1);}
                  }
           // umieszczenie 3 masztowcow
          
          for(int i=0 ; i<2 ; i++){  // for zeby umiescic 2 statki
           
           for(int j=0 ; j<3 ; j++) statki[9-i-1].trafiony[j]=0;
           statki[9-i-1].trafiony[3]=1;
                  
                  if((rand()%2)==0) pion=true;
            else pion=false;
           
           if(pion){
                    do{ // sprawdzenie czy mozna umiescic statek
                            
                    x=rand()%8;
                    y=rand()%10;
                    
                    statki[9-i-1].wspol[0][0]=x;
                    statki[9-i-1].wspol[0][1]=y;
                               
                    for(int a=1 ; a<3 ; a++) {statki[9-i-1].wspol[a][0]=x+a; statki[9-i-1].wspol[a][1]=y;}
                    
                   if(czyWolny(x,y,1,0))
                    for(int i=1 ; i<3 ; i++){
                            if(czyWolny(x+i,y,1,0)) mozna=true;
                             else mozna=false; 
                            }
                     else mozna=false;
                    }while(mozna==false);
                    
                    mapaKomputer[0][x][y]=1;
                    odstep(x,y,1);
                    for(int i=1 ; i<3 ; i++){ mapaKomputer[0][x+i][y]=1;
                    odstep(x+i,y,1);}                    
                    }
             else{                                       
                    do{ // sprawdzenie czy mozna umiescic statek
                            
                    x=rand()%8;
                    y=rand()%10;
                    
                      statki[9-i-1].wspol[0][0]=x;
                    statki[9-i-1].wspol[0][1]=y;
                               
                    for(int a=1 ; a<3 ; a++) {statki[9-i-1].wspol[a][0]=x; statki[9-i-1].wspol[a][1]=y+a;}
                    
                   if(czyWolny(x,y,1,0))
                    for(int i=1 ; i<3 ; i++){
                            if(czyWolny(x,y+i,1,0)) mozna=true;
                             else mozna=false; 
                            }
                     else mozna=false;
                    }while(mozna==false);
                    
                    mapaKomputer[0][x][y]=1;
                    odstep(x,y,1);
                    for(int i=1 ; i<3 ; i++){ mapaKomputer[0][x][y+i]=1;
                    odstep(x,y+i,1);}
                  }                             
                  } // koniec fora od 2 statkow                    
           // umieszczenie 2 masztowcow
          
          for(int i=0 ; i<3 ; i++){  // for zeby umiescic 3 statki
           
            for(int j=0 ; j<3 ; j++) statki[9-i-3].trafiony[j]=0;
           statki[9-i-3].trafiony[3]=1;
           statki[9-i-3].trafiony[2]=1;
                  
                  if((rand()%2)==0) pion=true;
            else pion=false;
           
           if(pion){
                    do{ // sprawdzenie czy mozna umiescic statek
                            
                    x=rand()%8;
                    y=rand()%10;
                    
                      statki[9-i-3].wspol[0][0]=x;
                    statki[9-i-3].wspol[0][1]=y;
                               
                    for(int a=1 ; a<2 ; a++) {statki[9-i-3].wspol[a][0]=x+a; statki[9-i-3].wspol[a][1]=y;}
                    
                   if(czyWolny(x,y,1,0))
                    for(int i=1 ; i<2 ; i++){
                            if(czyWolny(x+i,y,1,0)) mozna=true;
                             else mozna=false; 
                            }
                     else mozna=false;
                    }while(mozna==false);
                    mapaKomputer[0][x][y]=1;
                    odstep(x,y,1);
                    for(int i=1 ; i<2 ; i++){ mapaKomputer[0][x+i][y]=1;
                    odstep(x+i,y,1);}
                    }
             else{ 
                    do{ // sprawdzenie czy mozna umiescic statek
                            
                    x=rand()%8;
                    y=rand()%10;
                    
                       statki[9-i-3].wspol[0][0]=x;
                    statki[9-i-3].wspol[0][1]=y;
                               
                    for(int a=1 ; a<2 ; a++) {statki[9-i-3].wspol[a][0]=x; statki[9-i-3].wspol[a][1]=y+a;}
                    
                    
                   if(czyWolny(x,y,1,0))
                    for(int i=1 ; i<2 ; i++){
                            if(czyWolny(x,y+i,1,0)) mozna=true;
                             else mozna=false; 
                            }
                     else mozna=false;
                    }while(mozna==false);
                    
                    mapaKomputer[0][x][y]=1;
                    odstep(x,y,1);
                    
                    for(int i=1 ; i<2 ; i++){ mapaKomputer[0][x][y+i]=1;
                    odstep(x,y+i,1);}
                  }   
                  } // koniec fora od 3 statkow
          
           // umieszczenie 1 masztowcow
          
          for(int i=0 ; i<4 ; i++){  // for zeby umiescic 4 statki
           for(int j=0 ; j<4 ; j++) statki[i].trafiony[j]=1;
           statki[i].trafiony[i]=0;
            
                  do{
                  
                  x=rand()%10;
                  y=rand()%10;
                  
                     statki[i].wspol[0][0]=x;
                    statki[i].wspol[0][1]=y;
                               
                                     
                  if(czyWolny(x,y,1,0)) mozna=true;
                   else mozna=false;
                   
                  }while(mozna==false); 
                          
                  mapaKomputer[0][x][y]=1;
                  odstep(x,y,1);
                  
                  } // koniec fora od 4 statkow
          
           }  // koniec metody
      
      virtual void strzelanie(bool &cokolwiek)=0;
             
      } ;   
