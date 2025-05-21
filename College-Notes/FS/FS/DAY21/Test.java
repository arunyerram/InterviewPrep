package DAY21;

@FunctionalInterface
interface Greetings {
    String greet(String name);
}

class UserGreeting implements Greetings {
    @Override
    public String greet(String name) {
        return "Welcome " + name;
    }
}

public class Test {
    public static void main(String[] args) {
        Greetings obj = new UserGreeting();

        System.out.println(obj.greet("Keshav"));

        Greetings greetUser = (s) -> "Lambda Welcome : " + s;
        System.out.println(greetUser.getClass().getName());

        Greetings greetUser2 = (s) -> "Lambda Welcome version 2: " + s;
        System.out.println(greetUser2);

        System.out.println(greetUser.greet("Keshav"));
    }
}