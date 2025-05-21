public class code extends Thread{
    public static void main(String[] args){

        
        System.out.println(Thread.currentThread().getName());
    }
}


class MyThread extends Thread{
    @Override
    public void run(){
        System.out.println(Thread.currentThread().getName());
    }
}