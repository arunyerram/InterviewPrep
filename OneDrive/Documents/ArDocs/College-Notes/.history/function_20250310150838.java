interface Greetings {
    String greet(); // Correct abstract method declaration
}

public class function {
    public static void main(String[] args) {
        Greetings greeting = new Greeting();
        System.out.println(greeting.greet()); // No argument, as per interface
    }
}

class Greeting implements Greetings {
    public String greet() { // Correctly implements the method from the interface
        return "Hello! Welcome Arun!";
    }
}
