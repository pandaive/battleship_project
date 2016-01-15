#include <iostream>
using namespace std;

class Easy: public Komputer{
      
    private:  void strzelanie(bool &trafiony){
           bool mozna=false;
                      
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
                  mapaGracz[0][a][b]=4;
                  }
                  }while(mozna==false);   
}
};
