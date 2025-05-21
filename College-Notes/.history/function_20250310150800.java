interface Greetings {
    String greet(); // Correct abstract method declaration
}



public class function {
    public static void  main(String[] args){
        Greeting greeting = new Greeting();
        System.out.println(greeting.greet("Hwllo!"));
    }
}

class Greeting implements Greetings{
    public String greet(String greeting){
        greeting += "Welcome Arun!";
        return greeting;
    }
} 