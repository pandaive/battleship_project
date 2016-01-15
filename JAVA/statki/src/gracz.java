

public abstract class gracz extends glowna{
	
short a,b;  // wspol ostatniego trafienia
short a1,b1,x1,y1; // wspol 1 trafienia
short zatopione;
short mediumtrafienia;
short ktorystatek; //
short wktora;
short s;


abstract void strzelanie(boolean trafiony);
abstract boolean Koniec();
                                                 

public void rozmiesc(){};      
boolean czyMapa(int i, int j){  // metoda sprawdzajaca czy wspl leza na mapie
        boolean czy=false;
        if(i>=0 && i<=9){
                  if(j>=0 && j<=9) czy=true;
                }
        return czy;
        }

boolean czyWolny(int i, int j, int k, int l){  // metoda sprawdzajaca czy podane pole jest wolne
      boolean czy=false;
      if (k==0){
            if(mapaGracz[l][i][j]!=1 && mapaGracz[l][i][j]!=2) czy=true; 
                     }
      
      else if (k==1){
       if(mapaKomputer[l][i][j]!=1 && mapaKomputer[l][i][j]!=2) czy=true;      
     } return czy;
      
     }     

void odstep(int j, int k, int i){                                            // metoda dzi�ki kt�rej teoretycznie maja byc zachowane odst�py mi�dzy statkami
    if (i==0){                                                                     // niestety dzia�a chyba kiedy chce
    if(czyMapa(j-1,k-1)==true && czyWolny(j-1,k-1,0,0)==true) mapaGracz[0][j-1][k-1]=2;
    if(czyMapa(j+1,k+1)==true && czyWolny(j+1,k+1,0,0)==true) mapaGracz[0][j+1][k+1]=2;
    if(czyMapa(j-1,k)==true && czyWolny(j-1,k,0,0)==true) mapaGracz[0][j-1][k]=2;
    if(czyMapa(j,k-1)==true && czyWolny(j,k-1,0,0)==true) mapaGracz[0][j][k-1]=2;
    
    if(czyMapa(j+1,k-1)==true && czyWolny(j+1,k-1,0,0)==true) mapaGracz[0][j+1][k-1]=2;
    if(czyMapa(j+1,k)==true && czyWolny(j+1,k,0,0)==true) mapaGracz[0][j+1][k]=2;
    if(czyMapa(j,k+1)==true && czyWolny(j,k+1,0,0)==true) mapaGracz[0][j][k+1]=2;
    if(czyMapa(j-1,k+1)==true && czyWolny(j-1,k+1,0,0)==true) mapaGracz[0][j-1][k+1]=2;
    }
    else if (i==1){
    if(czyMapa(j-1,k-1)==true && czyWolny(j-1,k-1,1,0)==true) mapaKomputer[0][j-1][k-1]=2;
    if(czyMapa(j+1,k+1)==true && czyWolny(j+1,k+1,1,0)==true) mapaKomputer[0][j+1][k+1]=2;
    if(czyMapa(j-1,k)==true && czyWolny(j-1,k,1,0)==true) mapaKomputer[0][j-1][k]=2;
    if(czyMapa(j,k-1)==true && czyWolny(j,k-1,1,0)==true) mapaKomputer[0][j][k-1]=2;
    
    if(czyMapa(j+1,k-1)==true && czyWolny(j+1,k-1,1,0)==true) mapaKomputer[0][j+1][k-1]=2;
    if(czyMapa(j+1,k)==true && czyWolny(j+1,k,1,0)==true) mapaKomputer[0][j+1][k]=2;
    if(czyMapa(j,k+1)==true && czyWolny(j,k+1,1,0)==true) mapaKomputer[0][j][k+1]=2;
    if(czyMapa(j-1,k+1)==true && czyWolny(j-1,k+1,1,0)==true) mapaKomputer[0][j-1][k+1]=2;
    }
    }                    
    
String umiesc(short x, short y, int j, int k){  // sprawdza czy z danego punktu poczatkowego mozna umiescic statek
    //String ktore="OOOO";
	char[] ktore = new char[4];
    j--;
    
     for(int i=1 ; i<=j ; i++) {  // sprawdzenie dla N
                if(czyMapa(x-i,y) && czyWolny((x-i),y,k,0)) ktore[0]='N';
                 else ktore[0]='O';
             }  
     
     for(int i=1 ; i<=j ; i++) {  // sprawdzenie dla S
                if(czyMapa(x+i,y) && czyWolny((x+i),y,k,0)) ktore[1]='S';
                 else ktore[1]='O';  
             }  
     
     for(int i=1 ; i<=j ; i++) {  // sprawdzenie dla W
                if(czyMapa(x,y-i) && czyWolny(x,(y-i),k,0)) ktore[2]='W';
                 else ktore[2]='O';  
             }  
     
     for(int i=1 ; i<=j ; i++) {  // sprawdzenie dla E
                if(czyMapa(x,y+i) && czyWolny(x,(y+i),k,0)) ktore[3]='E';
                
                else ktore[3]='O';  
             }
     String ktory = new String(ktore);
     
    return ktory;
    } // koniec sprawdzania                


      short zestrzelone;                   // zmienna zliczaj�ca ilo�� udanych strza��w gracza, dzi�ki kt�rej wiemy kiedy gracz wygra gr�

      
void wyswietl(short czyja){  // wyswietlanie mapy

     System.out.print("  ") ; for(int i=0 ; i<10 ; i++) System.out.print((i+1)); System.out.println();
     
     for(int i=0 ; i<10 ; i++){
            if (i>=0 && i<9) System.out.print((i+1)+ ".");
            if (i==9) System.out.print((i+1));
            
            if (czyja==0){
      for(int j=0 ; j<10 ; j++)
       if(mapaGracz[0][i][j]==1) {System.out.print("O");}
        else if(mapaGracz[0][i][j]==3) {System.out.print("X");}
         else if(mapaGracz[0][i][j]==4) System.out.print("I");
         else System.out.print(" ");
      System.out.println();
     }
     else if (czyja==1){
          for(int j=0 ; j<10 ; j++)
       if(mapaKomputer[0][i][j]==1) {System.out.print("X");}
        else if(mapaKomputer[0][i][j]==3) {System.out.print("O");}
         else if(mapaKomputer[0][i][j]==4) System.out.print("I");
         else System.out.print(" ");
          System.out.println();
       }
          
          }
     }  // koniec metiody wyswietlajacej


void wyswietlStrzaly(short czyja){  // wyswietlanie mapy strza��w
    
	System.out.print("  ") ; for(int i=0 ; i<10 ; i++) System.out.print((i+1)); System.out.println();
     
     for(int i=0 ; i<10 ; i++){
            if (i>=0 && i<9) System.out.print((i+1) + ".");
            if (i==9) System.out.print((i+1));
             
      for(int j=0 ; j<10 ; j++)
      if (czyja==0){
       if(mapaGracz[1][i][j]==1 || mapaGracz[1][i][j]==3) {System.out.print("O");}
        else if(mapaGracz[1][i][j]==2 || mapaGracz[1][i][j]==4) {System.out.print("I");}
         else System.out.print(" ");}
       
       else if (czyja==1){
            if(mapaKomputer[1][i][j]==1 || mapaKomputer[1][i][j]==3) {System.out.print("X");}
        else if(mapaKomputer[1][i][j]==2 || mapaKomputer[1][i][j]==4) {System.out.print("I");}
         else System.out.print(" ");}
      System.out.println();
            }
     }

	
}