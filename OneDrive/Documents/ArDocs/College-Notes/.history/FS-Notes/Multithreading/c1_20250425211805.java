// package FS-Notes.Multithreading;

public class c1 extends Thread{
    @Override
    public void run(){
        System.out.println(Thread.currentThread().getName());
    }
    public static void main(String[] args){
        // System.out.println("Hello World!");
        Thread t1 = new Thread();
        Thread t2 = new Thread();

        t1.start();
        t2.start();
        
    }
}
