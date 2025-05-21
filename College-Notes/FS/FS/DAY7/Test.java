import java.util.ArrayList;

public class Test {
    final static int a = 10;
    public static void main(String[] args) {
        // boolean y = false;
        // boolean x = (y == true);
        // System.out.println(x+":"+y);
        // x = (y = true);
        // System.out.println(x+":"+y);

        int x = 2;
        // if(x=5){
        //     System.out.println(x);
        // 
        switch (x) {
            case 0:
                System.out.println(1);
            default:
                System.out.println("de");
            case 1:
                System.out.println(2);
            break;
        }

        Test t = new Test();

        // System.out.println(a++);
        String str = "anc";
        for (String s : str) {
            System.out.println(s);
        }
    }
}
