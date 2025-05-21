import java.util.*;
interface I1{
    public String readDataS1();

    public String postDataS2();

    public void updateDate();

    public void putData();

    // public 
}

interface I2{
    public void m1();
}


abstract class c1 implements I1,I2{
    public String readDataS1(int x,int y){
        return x + " " + y;
    }
    public String postDataS2(int x){
        return x + " ";
    }

}
public class code extends c1 implements I1,I2{
    public static void main(String[] args){
        code cobj = new code(); 


    }
}
