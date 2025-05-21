import pack1.*;
import pack1.subpack1.Test1;
public class Demo {
    public static void main(String[] args) {
        Test1 obj = new Test1();
        obj.m1();
        pack1.Test2 obj2 = new pack1.Test2();
        obj2.m1();
        pack1.Test3 obj3 = new pack1.Test3();
        obj3.m1();
        System.out.println("Demo");
    }
}
