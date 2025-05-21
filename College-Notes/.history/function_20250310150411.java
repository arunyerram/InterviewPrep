interface Greetings{
    greet(String greeting){};
        // return 
    // }
}

class Greeting implements Greetings{
    public String greet(String greeting){
        greeting += "Welcome Arun!";
        return greeting;
    }
} 
public class function {
    public static void  main(String[] args){
        Greeting greeting = new Greeting();
        System.out.println(greeting.greet("Hwllo!"));
    }
}
