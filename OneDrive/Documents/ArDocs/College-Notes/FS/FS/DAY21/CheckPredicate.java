// package DAY21;

import java.util.*;
import java.util.function.Predicate;

public class CheckPredicate {

    public static void eval(List<Integer> al, Predicate<Integer> p) {
        for (Integer a : al) {
            if (p.test(a)) {
                System.out.print(a + " ");
            }
        }
    }

    public static void main(String[] args) {
        Predicate<String> p = s -> s.length() > 5;
        System.out.println(p.test("Keshav"));

        List<Integer> al = Arrays.asList(1, 12, 3, 24, 5, 6, 37, 58, 9);

        Predicate<Integer> lessthan = i -> (i < 20);

        // al.stream().filter(lessthan).forEach(System.out::println);
        System.out.println(lessthan.test(10));

        System.out.println("Print all numbers less than 20");
        Predicate<Integer> ptrue = i -> (i < 20);
        eval(al, ptrue);
    }
}
