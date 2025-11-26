import java.util.*;
class New1{
    public static void main(String[] args) {
        int [] marks={100,2,3};
       /*  marks[0]=100;
        marks[1]=2;
        marks[2]=9;*/
        //System.out.println(marks.length);
        //int n=marks.length;
        //System.out.println(n);
        /*for(int i=n;i<=n;i--){
            System.out.println(marks[i]);
            i++;
        }*/
        for(int el: marks){
            System.out.println(el);
        }
    }
}