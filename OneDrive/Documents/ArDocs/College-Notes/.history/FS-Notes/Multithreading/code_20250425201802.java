public class code extends Thread{
    public static void main(String[] args){

        MyThread t1 = new MyThread();
        System.out.println(t1.start());
        System.out.println(Thread.currentThread().getName());
    }
}


class MyThread extends Thread{
    @Override
    public void run(){
        System.out.println(Thread.currentThread().getName());
    }
}