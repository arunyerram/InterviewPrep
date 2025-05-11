import java.util.*;
public class c1 {
    public void m1(String s, StringBuilder sb, Integer n) {
        sb.append("India");
        s += "College";
        n++;
    }
    public static void main(String[] args){
        c1 c = new c1();
        String s = "kmit";
        StringBuilder sb = new StringBuilder("hyderabad");
        Integer i = (100);

        c.m1(s, sb, i);
        System.out.println(s + " " + i + " " + sb);
    }
}
