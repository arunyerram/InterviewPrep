import java.util.*;
//create an BankAccount class number name and bal write appropriate number and override euals method to return true if the account number and account name are the same.

class Bank {
    int accNumber;
    String accName;
    double bal;

    Bank(int accNumber, String accName, double bal) {
        this.accNumber = accNumber;
        this.accName = accName;
        this.bal = bal;
    }

    @Override
    public boolean equals(Object obj) {
        if (obj instanceof Bank) {
            return this.bal == ((Bank) obj).bal && this.accName.equals(((Bank) obj).accName);
        } else {
            return false;
        }
    }

    @Override
    public String toString() {
        return "Name : " + this.accName + ", Account Number : " + this.accNumber + ", Balance : " + this.bal;
    }

}

class Circle {
    static double radius;

    Circle() {
        radius++;
    }
}

public class Test {
    public static void main(String[] args) {
        Bank cust1 = new Bank(100, "Keshav", 5000);
        Bank cust2 = new Bank(120, "Keshav", 3000);
        System.out.println(cust1.equals(cust2));
        Bank cust3 = new Bank(130, "Keshav", 5000);
        System.out.println(cust1.equals(cust3));
        System.out.println(cust1);
        System.out.println(cust2);
        System.out.println(cust3);
        String arr[] = { "17", "4", "21", "2", "111" };
        Arrays.sort(arr);
        System.out.println(Arrays.toString(arr));
        Circle[] obj = new Circle[3];
        for (int i = 0; i < 3; i++) {
            obj[i] = new Circle();
            System.out.println(obj[2].radius);
        }
    }
}