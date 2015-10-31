import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Created by informatics on 09.12.13.
 */
public class C {

    public static double eps = 0.000000000001;

    public static void main(String[] args) throws FileNotFoundException {
        Scanner scan = new Scanner(new FileReader("cord.in"));
        PrintWriter pw = new PrintWriter("cord.out");
        int x = scan.nextInt(), y = scan.nextInt(), r = scan.nextInt(), x1 = scan.nextInt(), y1 = scan.nextInt(),
                x2 = scan.nextInt(), y2 = scan.nextInt(), xa = scan.nextInt(), ya = scan.nextInt(), xb = scan.nextInt(),
                yb = scan.nextInt(), xc = scan.nextInt(), yc = scan.nextInt();
        int ans = 0;
        double d1 = Math.sqrt(x * x + y * y);
        if(d1 < r) ans++; //Окружность
        if(x1 > x2) {
            int temp = x1;
            x1 = x2;
            x2 = temp;
            temp = y1;
            y1 = y2;
            y2 = temp;
        }
        if(x1 < 0 && x2 > 0 && (y1 < 0 && y2 > 0) || (y1 > 0 && y2 < 0)) ans++; //Прямоугольник
        double l1 = length(xa, ya, xb, yb);
        double l2 = length(xa, ya, 0, 0);
        double l3 = length(xb, yb, 0, 0);
        double g = geron(l1, l2, l3);
        double sum = g;
        l1 = length(xa, ya, xc, yc);
        l2 = length(xa, ya, 0, 0);
        l3 = length(xc, yc, 0, 0);
        g = geron(l1, l2, l3);
        sum += g;
        l1 = length(xb, yb, xc, yc);
        l2 = length(xb, yb, 0, 0);
        l3 = length(xc, yc, 0, 0);
        g = geron(l1, l2, l3);
        sum += g;
        l1 = length(xa, ya, xb, yb);
        l2 = length(xa, ya, xc, yc);
        l3 = length(xb, yb, xc, yc);
        g = geron(l1, l2, l3);
        if(g - sum + eps >= 0) ans++;
        System.out.println(g + " " + sum);
        System.out.println(ans);
        pw.println(ans + "");
        pw.close();
    }

    public static double geron(double a, double b, double c) {
        double ans = 0;
        double p = (a + b + c) / 2;
        ans = Math.sqrt(p * (p - a) * (p - b) * (p - c));
        return ans;
    }

    public static double length(int x1, int y1, int x2, int y2) {
        return Math.sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    }
}
