public class code extends Thread{
    public static void main(String[] args){
        
        System.out.println(Thread.currentThread().getName());
    }


    public void run(){
        System.out.println(Thread.currentThread().getName());
    }
}