import java.util.Random;
import java.util.Scanner;

public class GAME {
    String str;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Random random = new Random();
        String str;
        do {
            int num = random.nextInt(3);

            if (num == 0) {
                str = "ROCK";
            } else if (num == 1) {
                str = "PAPER";     
            } else {
                str = "SCISSORS";
            }
            System.out.println("WE ARE PLAYING ROCK, PAPER AND SCISSORS\nEnter your choice:");
            String str1 = sc.next();
            if (str1.equalsIgnoreCase("rock") && str.equalsIgnoreCase("PAPER")) {
                System.out.println("OPPONENT CHOOSED PAPER\nYOU LOSS");
            } else if (str1.equalsIgnoreCase("rock") && str.equalsIgnoreCase("ROCK")) {
                System.out.println("OPPONENT CHOOSED ROCK\nDRAW");
            } else if (str1.equalsIgnoreCase("rock") && str.equalsIgnoreCase("SCISSORS")) {
                System.out.println("OPPONENT CHOOSED SCISSORS\nYOU WON");
            } else if (str1.equalsIgnoreCase("paper") && str.equalsIgnoreCase("PAPER")) {
                System.out.println("OPPONENT CHOOSED PAPER\nDRAW");
            } else if (str1.equalsIgnoreCase("paper") && str.equalsIgnoreCase("ROCK")) {
                System.out.println("OPPONENT CHOOSED ROCK\nYOU WON");
            } else if (str1.equalsIgnoreCase("paper") && str.equalsIgnoreCase("SCISSORS")) {
                System.out.println("OPPONENT CHOOSED SCISSORS\nYOU LOSS");
            } else if (str1.equalsIgnoreCase("scissors") && str.equalsIgnoreCase("PAPER")) {
                System.out.println("OPPONENT CHOOSED PAPER\nYOU WON");
            } else if (str1.equalsIgnoreCase("scissors") && str.equalsIgnoreCase("SCISSORS")) {
                System.out.println("OPPONENT CHOOSED SCISSORS\nDRAW");
            } else if (str1.equalsIgnoreCase("scissors") && str.equalsIgnoreCase("ROCK")) {
                System.out.println("OPPONENT CHOOSED ROCK\nYOU LOSS");
            } else {
                System.out.println("Not valid input");
            }
            System.out.println("Do you want to continue? (Type 'YES' to continue, 'EXIT' to quit):");
        } while (sc.next().equalsIgnoreCase("YES"));
    }
}
