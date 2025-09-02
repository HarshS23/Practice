package Java;
import java.util.Scanner;


public class Main {
    // testing java program 

    public static void main(String[] args){
        System.out.println("Hello world\n");




        // variable assingment 

        // String - stores strings , int, float char, boolean; 

        int age = 8; 
        System.out.println(age); 

        // if statement 
        if(age >= 18){
            System.out.println("idk");
        }else{
            age = age + 1;
        }

        // printf(), also %[flags][Width][.precision][specifier-character]
        // String name = "Adharsh";

        // System.out.printf("\nHello %s\n", name);

        // while loops

        Scanner scanner = new Scanner(System.in);
        String name = ""; 

        while(name.isEmpty() || !name.equals("Q")){
            System.err.print("Enter your name: ");
            name = scanner.nextLine();
        }
        System.err.println("Hello " + name);
        scanner.close();


    }
}