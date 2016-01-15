import java.util.Random;


public class Easy extends Komputer {

	 void strzelanie(boolean trafiony){
         boolean mozna=false;
         Random r = new Random();           
        do{
            a=(short) r.nextInt(10);
            b=(short) r.nextInt(10);
            
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

	@Override
	boolean Koniec() {
		// TODO Auto-generated method stub
		return false;
	}

}
