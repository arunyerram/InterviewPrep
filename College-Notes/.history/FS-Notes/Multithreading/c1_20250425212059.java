// package FS-Notes.Multithreading;

public class c1 extends Thread{
    @Override
    public void run(){
        for(int i=0;i<5;i++){
            System.out.println(Thread.currentThread().getName() + " " + i);
            Thread.yield();
        }
    }
    public static void main(String[] args){
        // System.out.println("Hello World!");
        c1 t1 = new c1();
        c1 t2 = new c1();

        t1.start();
        t2.start();
        
    }
}
