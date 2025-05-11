public class code extends Thread{
    public static void main(String[] args){

        MyThread t1 = new MyThread();
        MyThread t2 = new MyThread();
        t1.start();
        // System.out.println(t1.run());
        System.out.println(Thread.currentThread().getName());
    }
}


class MyThread extends Thread{
    @Override
    public void run(){
        System.out.println(Thread.currentThread().getName());
    }
}