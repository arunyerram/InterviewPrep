package com.example.demo;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.context.annotation.Scope;
import org.springframework.stereotype.Component;

@Component
//@Scope(value="prototype")
public class Student {
    private int sid;
    private String sname;
    @Autowired
    @Qualifier("mylaptop")
    private Laptop laptop;

    public Student(){
        super();
        System.out.println("Object created...");
    }

    public int getSid(){
        return sid;
    } 

    public void setId(int sid){
        this.sid = sid;
    }
   
    public String getSname(){
        return sname;
    } 
    
    public void setSname(String sname){
        this.sname = sname;
    }

    public Laptop getBrand(){
        return laptop;
    }

    public  void setBrand(Laptop laptop){
        this.laptop = laptop;
    }
    public void print(){
        System.out.println("Printing...");
        laptop.laptopTesting();
    }
}
