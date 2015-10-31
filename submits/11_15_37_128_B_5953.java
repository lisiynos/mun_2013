import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Created by informatics on 09.12.13.
 */
public class B {

    public static void main(String[] args) throws FileNotFoundException {
        Scanner scan = new Scanner(new FileReader("berg.in"));
        PrintWriter pw = new PrintWriter("berg.out");
        String s = scan.next();
        String ans = "";
        for(int i = 0; i < s.length(); i++) {
            if(i % 2 == 1 && !String.valueOf(s.charAt(i)).equals("a")) {
                pw.println("Suspicious!");
                pw.close();
                return;
            }else if(i % 2 == 0) ans += String.valueOf(s.charAt(i));
        }
        pw.println(ans);
        pw.close();
    }

}
