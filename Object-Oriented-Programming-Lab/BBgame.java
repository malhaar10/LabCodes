//import child.*;
import child.Shoot;
import child.Pass;
import child.Drive;

import java.util.Scanner;

interface game{
    public void select();
}

class BBgame implements game{
    Scanner sc = new Scanner(System.in);
    public void select(){
        System.out.println("Enter operation to do: ");
        //a = sc.nextInt();
    }
    public static void main(String[] args) {
        BBgame bb= new BBgame();
        Scanner sd = new Scanner(System.in);
        System.out.println("Enter mov: ");
        int mov = sd.nextInt();;
        if(mov == 1){
            Shoot s = new Shoot();
        }else if(mov == 2){
            Pass p = new Pass();
        }else{
            Drive d = new Drive();
        }
    }
}