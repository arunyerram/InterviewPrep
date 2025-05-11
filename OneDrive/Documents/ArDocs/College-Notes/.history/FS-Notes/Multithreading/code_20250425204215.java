public class code extends Thread{
    @Override 
    public void run(){
        System.out.println(Thread.currentThread().getName());
    }
    public static void main(String[] args) throws InterruptedException{

        MyThread t1 = new MyThread();
        MyThread t2 = new MyThread();
        // System.out.println(Thread.currentThread().getName());
        // t1.start();
        // System.out.println(Thread.currentThread().getName());
        // t2.start();
        System.out.println(t1.getState());
        // The line `// System.out.println(t1.getName());` is a commented-out line in the code. This
        // means that it is not active and will not be executed when the program runs.
        // System.out.println(t2.getState());
        t1.start();
        // System.out.println(t1.getState());
        t2.start();
        // System.out.println(t2.getState());
        // System.out.println(Thread.currentThread().getState());
        // Thread.sleep(100);
        // System.out.println(Thread.currentThread().getState());
        // System.out.println(t1.getState());
        // System.out.println(t2.getState());

        t1.join();
        System.out.println(t1.getState());
        // t2.join();
        t1.sleep(5);
        System.out.println(t2.getState());
    }
}


class MyThread extends Thread{
    @Override
    public void run(){
        System.out.println(Thread.currentThread().getName());
    }
}