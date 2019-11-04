import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;
 
public class main_java {
 
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(System.out);
        int k = 20;
        int n = in.readInt();
        int a[] = new int[n];
        for(int i = 0;  i < n; i ++)
            a[i] = in.readInt();
 
        int lf = 1;
        int rg = n + 1;
 
        int tg[][] = new int [n][k];
        int tm[][] = new int [n][k];
        for(int i = 0; i < n; i++){
            Arrays.fill(tg[i], -1);
            Arrays.fill(tm[i], Integer.MAX_VALUE);
        }
 
        for(int j = 0; j < k; j++) {
            if (j == 0){
                for(int i = 0; i < n; i++) {
                    tm[i][j] = a[i];
                    tg[i][j] = a[i];
                }
                continue;
            }
 
            for(int i = 0; i < n; i++) {
                if (tg[i][j - 1] == -1) continue;
                int tv = i + (1 << (j - 1));
                if (tv >= n) continue;
                if (tg[tv][j - 1] == -1) continue;
                tg[i][j] = gcd(tg[i][j - 1], tg[tv][j - 1]);
                tm[i][j] = Math.min(tm[i][j - 1], tm[tv][j - 1]);
            }
        }
 
        while (rg - lf > 1){
            int mid = (lf + rg) >> 1;
 
            boolean ok = false;
 
            int power = 0;
 
            while ((1 << power) <= mid)
                power++;
            power--;
 
            for(int i = 0; (i <= n - mid) && !ok; i++){
                int g = tg[i][power];
                int b = i + mid - 1;
                g = gcd(tg[b - (1 << power) + 1][power], g);
                g -= Math.min(tm[i][power], tm[b - (1 << power) + 1][power]);
 
                if (g == 0)
                    ok = true;
            }
 
            if (ok)
                lf = mid;
            else
                rg = mid;
        }
        int power = 0;
 
        while ((1 << power) <= lf)
            power++;
        power--;
 
        int anscnt = 0;
        for(int i = 0; (i <= n - lf); i++){
            int g = tg[i][power];
            int b = i + lf - 1;
            g = gcd(tg[b - (1 << power) + 1][power], g);
            g -= Math.min(tm[i][power], tm[b - (1 << power) + 1][power]);
 
            if (g == 0) {
                anscnt ++;
            }
        }
        out.println(anscnt + " " + (lf - 1));
        for(int i = 0; (i <= n - lf); i++){
            int g = tg[i][power];
            int b = i + lf - 1;
            g = gcd(tg[b - (1 << power) + 1][power], g);
            g -= Math.min(tm[i][power], tm[b - (1 << power) + 1][power]);
 
            if (g == 0) {
                out.print(i + 1 + " ");
            }
        }
 
        out.close();
    }
 
    static int gcd(int a, int b){
        if (a == 0)
            return b;
        return gcd(b % a, a);
    }
}
 
class InputReader {
 
    private InputStream stream;
    private byte[] buf = new byte[1024];
    private int curChar;
    private int numChars;
    private SpaceCharFilter filter;
 
    public InputReader(InputStream stream) {
        this.stream = stream;
    }
 
    public int read() {
        if (numChars == -1)
            throw new InputMismatchException();
        if (curChar >= numChars) {
            curChar = 0;
            try {
                numChars = stream.read(buf);
            } catch (IOException e) {
                throw new InputMismatchException();
            }
            if (numChars <= 0)
                return -1;
        }
        return buf[curChar++];
    }
 
    public int readInt() {
        int c = read();
        while (isSpaceChar(c))
            c = read();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        int res = 0;
        do {
            if (c < '0' || c > '9')
                throw new InputMismatchException();
            res *= 10;
            res += c - '0';
            c = read();
        } while (!isSpaceChar(c));
        return res * sgn;
    }
 
    public boolean isSpaceChar(int c) {
        if (filter != null)
            return filter.isSpaceChar(c);
        return isWhitespace(c);
    }
 
    public static boolean isWhitespace(int c) {
        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }
 
    public interface SpaceCharFilter {
        public boolean isSpaceChar(int ch);
    }
}
 