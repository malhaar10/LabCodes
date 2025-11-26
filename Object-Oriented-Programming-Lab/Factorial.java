import java.util.Scanner;
class Factorial{
    int i=7,n;
    void fact(){
        for(n=i;n>0;n--){
            int fact=i+n;
            System.out.println(fact);
            break;
        }
    }
    public static void main(String[] args){
    Factorial object=new Factorial();
    object.Factorial();        
    }
}