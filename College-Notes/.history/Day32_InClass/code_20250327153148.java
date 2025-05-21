import java.util.*;
interface I1{
    public String readDataS1();

    public String getDataS2();

    public void updateDate();

    public 

}

interface I2{
    public void m1();
}


class c1 implements I1{
    public String getDataS1(int x,int y){
        return x + " " + y;
    }
    public String getDataS2(int x){
        return x + " ";
    }
}
public class code extends c1 implements I1{
    public static void main(String[] args){
        code cobj = new code(); 
    }
}
