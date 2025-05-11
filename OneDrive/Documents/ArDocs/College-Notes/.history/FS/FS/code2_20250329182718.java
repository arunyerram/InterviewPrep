import java.util.*;

public class code2 {
    public static void main(String[] args){
        Set<Integer>st = new HashSet<>();
        st.add(12);
        st.add(20);
        st.add(12);

        System.out.println(st.contains(12));
        st.remove(12);
        st.add(299);
        st.add(143);
        int n = st.size();
        // st.clear();
        Set<Integer>st1 = new HashSet<>();
        st1.add(299);
        st1.add(143);
        st1.add(20);
        System.out.println(st.containsAll(st1));
        // System.out.println(st.retainAll(st1));
        st.addAll(st1);
        Set<Integer>p = new HashSet<>(st);
        p.removeAll(st1);
        System.out.println(p);

    }
}
