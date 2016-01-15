#include <iostream>
using namespace std;

class Hard: public Komputer{
  private:     void strzelanie(bool &trafiony){
           bool mozna=false;
           
 cout << "Strzelam!!!!" << endl; //s=0;         
short s=rand()%2;
//cout << s << endl;
switch(s){
          case 0 : {
          do{
              
              a=rand()%10;
              b=rand()%10;
              
              if(mapaGracz[0][a][b]==1){
                  mozna=true;
                  zatopione++;
                  mapaGracz[0][a][b]=3;
                  cout << "Strzelilem!!!" << endl;
                  cout << mapaGracz[0][a][b] << endl;
                  }
                  }while(mozna==false);
                  break;   
                  }
          case 1 : {          
               do{
              a=rand()%10;
              b=rand()%10;
              
              if(mapaGracz[0][a][b]==1){
                  mozna=true;
                  zatopione++;
                  mapaGracz[0][a][b]=3;
                  }
                  else if (mapaGracz[0][a][b]==2 || mapaGracz[0][a][b]==0) {
                  mozna=true;
                  mapaGracz[0][a][b]=4;}
                  }while(mozna==false);
               break;
               }        
}} 
      };        
