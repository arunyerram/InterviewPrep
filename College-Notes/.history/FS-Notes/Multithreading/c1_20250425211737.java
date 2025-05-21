// package FS-Notes.Multithreading;

public class c1 extends Thread{
    public static void main(String[] args){
        // System.out.println("Hello World!");
        Thread t1 = new Thread(new Runnable() {
            @Override
            public void run() {
                System.out.println("Thread 1 is running");
            }
        });

        // 
    }
}
