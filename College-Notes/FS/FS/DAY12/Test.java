public class Test {
    public static void main(String[] args) {
        String str = "Hello World";
        String str1 = "Hello World";
        String str2 = new String("Hello World");
        System.out.println(str == str1); // true
        System.out.println(str == str2); // false   //reson: str is in string pool and str2 is in heap memory
        System.out.println(str.equals(str2)); // true
        
        String s1 = "hello";
        String s2 = "hello";
        String s3 = "hello".intern();
        String s4 = new String("hello");
        String s5 = new String("hello").intern();

        if(s1 == s4){
            System.out.println("s1 and s3 are same");
        }

        StringBuilder sb1 = new StringBuilder("Java");
        StringBuilder sb2 = new StringBuilder("Java");
        System.out.println(sb1 == sb2);
        System.out.println("sb1: " + sb1);
        System.out.println("sb2: " + sb2);
        sb1.append(" Bean");
        System.out.println("sb1: " + sb1);
        System.out.println("sb2: " + sb2);
        sb1.insert(4, "**");
        System.out.println("sb1: " + sb1);
        System.out.println("sb2: " + sb2);
        System.out.println("Reverse: " + sb1.reverse());
        System.out.println("sb1: " + sb1);
        System.out.println("sb2: " + sb2);
        System.out.println("String representation: " + sb1.toString());

        //difference between StringBuilder and StringBuilder
    }
}
