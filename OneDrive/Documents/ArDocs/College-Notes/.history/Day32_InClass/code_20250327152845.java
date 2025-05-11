import java.util.*;
interface I1{
    public String getDataS1();

    public String getDataS2();

}

class c1 implements I1{
    public String getDataS1(int x,int y){
        return x + " " + y;
    }
    public String getDataS2(){
        
    }
}
public class code extends c1 implements I1{
    public static void main(String[] args){

    }
}
