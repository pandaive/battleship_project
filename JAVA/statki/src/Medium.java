import java.util.Random;


public class Medium extends Komputer {
	 Random r = new Random();
	void strzelanie(boolean trafiony){  // strzaly komputera
        boolean mozna=false;
        short ilemasztow;
        short zab=0;
          
        if(trafiony==false)  // jesli nie ma zadnego trafionego statku
          do{
        	  a=(short) r.nextInt(10);
              b=(short) r.nextInt(10);
           
           if(mapaGracz[0][a][b]==1) {                  // jesli trafilismy w tym momencie
              mozna=true;
              mapaGracz[0][a][b]=3;
              a1=a;
              b1=b;
              trafiony=true;
              for (int i=0 ; i<10 ; i++) {  // sprawdzanie ile masztow ma statek trafiony
                 for (int j=0; j<4 ; j++) {
                    if (statki[i].wspol[j][0]==a && statki[i].wspol[j][1]==b)                                                                                  
                    ktorystatek=(short) i;
                    } }
                    
              for (int s=0 ; s<4 ; s++)      // zapisanie trafienia statku
                 if (statki[ktorystatek].trafiony[s]==0) {statki[ktorystatek].trafiony[s]=1; break;}
                                                                                    
                    if (ktorystatek<4) ilemasztow=1;       /// szukanie, który statek zosta³ postrzelony
                    else if (ktorystatek>=4 && ktorystatek<7) ilemasztow=2;
                    else if (ktorystatek>=7 && ktorystatek<9) ilemasztow=3;
                    else ilemasztow=4;
                                                 
                    if (ilemasztow==1) {statki[ktorystatek].zatopiony=true; trafiony=false; }  // sprawdzenie czy statek jest zatopiony
                    else {
                       statki[ktorystatek].zatopiony=czyZatopiony(ktorystatek);
                       if(statki[ktorystatek].zatopiony==true) trafiony=false;
                                                              
                       }                                      
                       }
                    else if(mapaGracz[0][a][b]==0 || mapaGracz[0][a][b]==2) {                       // jesli nie trafilismy w tym momencie
                    mapaGracz[0][a][b]=4;
                    mozna=true;
                    trafiony=false;
                    }
                    else mozna=false;
           }while(mozna==false); 
          
          else do{     
                                                                      // jesli trafilismy wczesniej
                  if(    ( (czyMapa(a-1,b) && (mapaGracz[0][a-1][b]==3 || mapaGracz[0][a-1][b]==4)) || czyMapa(a-1,b)==false  )     &&     (  (czyMapa(a+1,b) && (mapaGracz[0][a+1][b]==3 || mapaGracz[0][a+1][b]==4)) || czyMapa(a+1,b)==false   ) &&   (  (czyMapa(a,b-1) && (mapaGracz[0][a][b-1]==3 || mapaGracz[0][a][b-1]==4)) || czyMapa(a,b-1)==false   ) && (  (czyMapa(a,b+1) && (mapaGracz[0][a][b+1]==3 || mapaGracz[0][a][b+1]==4)) || czyMapa(a-1,b)==false  )    ){
                  a=a1;     // ustalenie zmiennych pocz¹tkowych, ¿eby komputer móg³ do nich wróciæ, kiedy np. trafi w œrodek statku i pójdzie w jak¹œtam stronê i bêdzie musia³ wróciæ ¿eby zestrzeliæ ca³y statek
                  b=b1;
                                     
                  if(wktora==1) wktora=3;         // ustawienie w któr¹ stronê bêdzie musia³ pójœæ
                  else wktora=(short) Math.abs(wktora-2);                                      
                                      }
                   else wktora=(short) r.nextInt(4);
                                                                                                                                                                                                                                                                                                                                                                                                                   zab++;
                   if(wktora==0) {
                      if(czyMapa(a-1,b) && (mapaGracz[0][a-1][b]==0 || mapaGracz[0][a-1][b]==2 || mapaGracz[0][a-1][b]==1)){      // w górê
                      mozna=true;
                                                                                                                                                                                                                                                                                                                                                                                                                               zab=0;
 
                      if (mapaGracz[0][a-1][b]==1){ 
                      mapaGracz[0][a-1][b]=3;
                                                              
                      for (int s=0 ; s<4 ; s++)      // zapisanie trafienia statku
                      if (statki[ktorystatek].trafiony[s]==0) {statki[ktorystatek].trafiony[s]=1; break;}

                      if (czyZatopiony(ktorystatek)==true) {statki[ktorystatek].zatopiony=true; trafiony=false;}
                      a--;
                      }
                                                               
                      else mapaGracz[0][a-1][b]=4;   }
                      else mozna=false;                             
                               }
                   else if(wktora==1) {
                   if(czyMapa(a,b+1) && (mapaGracz[0][a][b+1]==0 || mapaGracz[0][a][b+1]==2 || mapaGracz[0][a][b+1]==1)){      // w prawo
                   zab=0;
                   mozna=true; 
                                   
                   if (mapaGracz[0][a][b+1]==1){                                                           
                   mapaGracz[0][a][b+1]=3;
                                                            
                   for (int s=0 ; s<4 ; s++)      // zapisanie trafienia statku
                   if (statki[ktorystatek].trafiony[s]==0) {statki[ktorystatek].trafiony[s]=1; break;}
                                                                                                    
                   if (czyZatopiony(ktorystatek)==true) {statki[ktorystatek].zatopiony=true; trafiony=false; }
                   b++;
                                                               } 
                   else mapaGracz[0][a][b+1]=4;   }
                   else mozna=false;
        }
                   else if(wktora==2) {
                   if(czyMapa(a+1,b) && (mapaGracz[0][a+1][b]==0 || mapaGracz[0][a+1][b]==2 || mapaGracz[0][a+1][b]==1)){      // w dó³
                   zab=0;
                   mozna=true;
                                  
                   if (mapaGracz[0][a+1][b]==1){ 
                   mapaGracz[0][a+1][b]=3;
 
                   for (int s=0 ; s<4 ; s++)      // zapisanie trafienia statku
                   if (statki[ktorystatek].trafiony[s]==0) {statki[ktorystatek].trafiony[s]=1; break;}
                                                       
                   if (czyZatopiony(ktorystatek)==true) {statki[ktorystatek].zatopiony=true; trafiony=false;}
                   a++;
                   }
                   else mapaGracz[0][a+1][b]=4;   }
                   else mozna=false;
             }
                   else     { 
                   if(czyMapa(a,b-1) && (mapaGracz[0][a][b-1]==0 || mapaGracz[0][a][b-1]==2 || mapaGracz[0][a][b-1]==1) ){      // w lewo
                   zab=0;
                   mozna=true;
                                     
                   if (mapaGracz[0][a][b-1]==1){ 
                   mapaGracz[0][a][b-1]=3;
                                                         
                   for (int s=0 ; s<4 ; s++)      // zapisanie trafienia statku
                   if (statki[ktorystatek].trafiony[s]==0) {statki[ktorystatek].trafiony[s]=1; break;}
                                  
                   if (czyZatopiony(ktorystatek)==true) {statki[ktorystatek].zatopiony=true; trafiony=false;   }                                   
                   b--;
                   }
                   else mapaGracz[0][a][b-1]=4;    }
                   else mozna=false;
                   }
                                                                                                                                                                                                                                                                                                                                                                                                                                       if(zab==50) {trafiony=false; break;}   // zabezpieczam program przed nim samym

                 }while(mozna==false);        
         }  // koniec strzalow komputera
	@Override
	boolean Koniec() {
		// TODO Auto-generated method stub
		return false;
	}

}
