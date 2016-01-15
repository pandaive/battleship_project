import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;


public class glowna {

	static int mapaGracz[][][] = new int[2][10][10];
    static int mapaKomputer[][][]= new int[2][10][10];
    
    
    public static void odczyt (String sciezka){
    	try {
    	FileReader odczyt;
		odczyt = new FileReader(sciezka);
		BufferedReader odcz = new BufferedReader(odczyt);
		String linia;
		
		while((linia = odcz.readLine()) != null)
			{
			System.out.println(linia);
			}
		odczyt.close();
    } catch (FileNotFoundException e) {
		// TODO Auto-generated catch block
		e.printStackTrace();
    } catch (IOException e) {
		// TODO Auto-generated catch block
		e.printStackTrace();
	}
    };   
    
    public static void wpisywanie(String nick, int wynik, String sciezka){
    	
    	
    	try {
    		FileReader odczyt = new FileReader(sciezka);
    		BufferedReader od = new BufferedReader(odczyt);
    		String linia;
    		//String old = "";
    		int r = 0;
    		String[] tab=new String[20];
				while((linia = od.readLine()) != null)
					{
					tab[r]=linia;
					r++;
					//old =  old + linia;
					}
				if (r==20) throw new Wyjatek();
			//r++;
			
    		odczyt.close();
    		File plik = new File(sciezka);
    		plik.delete();
    	
    		FileWriter zapis = new FileWriter(sciezka);
    		for (int j=0; j<r; j++){
    			zapis.write(tab[j]+"\n");
    		};
    		
    		
    		zapis.write(r+". "+nick+" "+wynik);
    		zapis.close();
    		} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} catch (Wyjatek e) { System.out.println("Ranking pelny!");
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
    		
    	
    };
    
    
    static void wysMenu(){             // funkcja wyswietlajaca menu glowne
        System.out.println( " Gra statki " );
        System.out.println( "Wybierz jedna z ponizszych opcji w menu: " );
        System.out.println( "1. Nowa gra " );
        System.out.println( "2. Ranking " );
        System.out.println( "3. Pomoc " );
        System.out.println( "4. Wyjscie " );    
      }
 /////////////////////
 static void wysMenuGry(){
	 System.out.println( "Zaczynasz nowa gre!" );
	 System.out.println( "Wybierz poziom trudnosci:" );
	 System.out.println( "1. Easy" );
	 System.out.println( "2. Medium" );
	 System.out.println( "3. Hard");
      }
 ///////////////////////////////// 
	public static void main(String[] args) {
		
		int wybor, wybor2;  // zmienna odpowiadajaca za wybor opcji w menu
		 String nick="abc";
		 //obsluga plik = new obsluga();
		 short ruch=0;
		 Scanner sc = new Scanner(System.in); 
		 boolean trafiony=false;
		    do{
		    do{  // petla sprawdzajaca poprawnosc wprowadzonej wareosci
		        wysMenu(); // wyswietlenie menu
		        wybor=sc.nextInt(); //// wczytanie wyboru
		              
		    switch(wybor){
		                  case 1 : {
		                	  //wpisywanie(nick,ruch,"G:/ranking.bin");
		                       wysMenuGry();
		                       wybor2=sc.nextInt();
		                       switch(wybor2){                    
		                         case 1 : {
		                              
		                        	 gracz gracz[]= new gracz[2];
		                            gracz[0]=new Czlowiek();
		                            gracz[1]=new Easy();
		                            gracz[1].zatopione=0;
		                            ruch=0;
		                            System.out.println( "Podaj swoj nick(bez spacji!)" );
		                            nick=sc.next();
		                            gracz[1].rozmiesc();
		                            gracz[0].rozmiesc();
		                               do{
		                             System.out.println( "Tura gracza 1 ! " );
		                             System.out.println( "Mapa gracz 1 :" );
		                             gracz[0].wyswietl((short) 0);
		                             System.out.println( "Mapa strzalow gracza 1: " );
		                             gracz[1].wyswietlStrzaly((short) 1);
		                             gracz[1].wyswietl((short) 1);
		                             gracz[0].strzelanie(trafiony);
		                             System.out.println();
		                             gracz[1].strzelanie(trafiony);
		                             ruch++;
		                             
		                             }while(gracz[1].zatopione<20 && gracz[0].zestrzelone<20);
		                          
		                             
		                           if (gracz[0].zestrzelone==20){
		                            wpisywanie(nick, ruch, "C:/ranking.bin");
		                            System.out.println( "Wygrana ! " );}
		                            else System.out.println( "Przegrana ! " );
		                            //system("PAUSE");
		                            break;
		                            }
		                              
		                         case 3 : {
		                              
		                        	 gracz gracz[]= new gracz[2];
		                            gracz[0]=new Czlowiek();
		                            gracz[1]=new Hard();
		                            gracz[1].mediumtrafienia=0;
		                            gracz[1].zatopione=0;
		                            ruch=0;
		                            System.out.println( "Podaj swoj nick(bez spacji!)" );
		                            nick=sc.next();
		                            gracz[1].rozmiesc();
		                            gracz[0].rozmiesc();
		                               do{
		                             System.out.println( "Tura gracza 1 ! " );
		                             System.out.println( "Mapa gracz 1 :" );
		                             gracz[0].wyswietl((short) 0);
		                             System.out.println( "Mapa strzalow gracza 1: " );
		                             gracz[1].wyswietlStrzaly((short) 1);
		                             gracz[0].strzelanie(trafiony);
		                             System.out.println();
		                             gracz[1].strzelanie(trafiony);
		                             ruch++;
		                             
		                             }while(gracz[1].zatopione<20 && gracz[0].zestrzelone<20);
		 
		                           if (gracz[0].zestrzelone==20){
		                        	   wpisywanie(nick,ruch,"C:/ranking.bin");
		                            System.out.println( "Wygrana ! " );
		                            System.out.println( "Zestrzelone = 20 !!!!! " );
		                            }
		                            else System.out.println( "Przegrana ! " );;
		                           // system("PAUSE");
		                            break;
		                            }
		                         
		                         case 2 : {
		                        
		                        	 gracz gracz[]= new gracz[2];
		                        	 gracz[1]=new Medium();
		                        	 gracz[0]=new Czlowiek();
		                            
		                            ruch=0;
		                            System.out.println( "Podaj swoj nick(bez spacji!)" );
		                            nick=sc.next();
		                            gracz[1].rozmiesc();
		                            gracz[0].rozmiesc();
		                            
		                            do{
		                             System.out.println( "Tura gracza 1 ! " );
		                             System.out.println( "Mapa gracz 1 :" );
		                             
		                             gracz[0].wyswietl((short) 0);
		                             
		                             
		                             System.out.println( "Mapa strzalow gracza 1: " );
		                             gracz[1].wyswietlStrzaly((short)1);
		                            
		                             gracz[0].strzelanie(trafiony);
		                             System.out.println();
		                             
		                             gracz[1].strzelanie(trafiony);
		                             ruch++;
		                             
		                             }while(gracz[0].Koniec()==false && gracz[0].zestrzelone<20);
		                          
		                             
		                           if (gracz[0].zestrzelone==20){
		                            wpisywanie(nick,ruch,"C:/ranking.bin");
		                            System.out.println( "Wygrana ! " );}
		                            else System.out.println( "Przegrana ! " );
		                            //system("PAUSE");
		                            break;
		                            }}}
		                  case 2 : {
		                	  System.out.println("Ranking: ");
			                	  odczyt("G:/ranking.bin");
		                        break;}
		                  case 3 : {
		                	  
		                	  System.out.println("Pomoc: ");
		                	  odczyt("C:/pomoc.txt");
		                        break;}
		                  case 4 : break;
		                  default : System.out.println( "Podaj wlasciwa wartosc ! " );
		                  } 
		    }while(wybor<1 || wybor>4);
		    }while(wybor!=4);
		    //system("PAUSE");
		    
		
		
	}

}
