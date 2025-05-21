public class Singleton {
    int val;
    static Singleton obj = null;
    private Singleton() {
        val = 10;
    }
    public int getValue() {
        return val;
    }
    public void setValue(int val) {
        this.val = val;
    }
    public static Singleton getInstance() {
        if (obj == null) {
            obj = new Singleton();
        }
        return obj;
    }
}

class Demo {
    public static void main(String[] args) {
        Singleton obj1 = Singleton.getInstance();
        Singleton obj2 = Singleton.getInstance();
        System.out.println(obj1);
    }
}
