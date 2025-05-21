public class code extends Thread{
    public static void main(String[] args){

        MyThread t1 = new MyThread();
        MyThread t2 = new MyThread();
        System.out.println(Thread.currentThread().getName());
        t1.start();
        // System.out.println(Thread.currentThread().getName());
        t2.start();
        System.out.println(t1.getState());
        // System.out.println(t1.getName());
        // System.out.println(t2.getName());
    }
}


class MyThread extends Thread{
    @Override
    public void run(){
        System.out.println(Thread.currentThread().getName());
    }
}