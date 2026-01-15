package jan14;
import java.io.*;

public class BlackslexAndPassword {
    static class FastScanner {
        private final InputStream in;
        private final byte[] buffer = new byte[1 << 16];
        private int ptr = 0, len = 0;
        FastScanner(InputStream in) { this.in = in; }
        int nextInt() throws IOException {
            int c, val = 0, sign = 1;
            do { c = in.read(); if (c == -1) return -1; } while (c <= ' ');
            if (c == '-') { sign = -1; c = in.read(); }
            while (c > ' ') { val = val * 10 + (c - '0'); c = in.read(); }
            return sign * val;
        }
    }

    public static void main(String[] args) throws IOException {
        FastScanner fs = new FastScanner(System.in);
        int t = fs.nextInt();
        StringBuilder out = new StringBuilder();
        for (int i = 0; i < t; i++) {
            int k = fs.nextInt();
            int x = fs.nextInt();
            out.append(solve(k, x)).append('\n');
        }
        System.out.print(out);
    }

    static int solve(int k, int x) {
        StringBuilder res = new StringBuilder();
        
        while (true) {
            int before = res.length();
            for (int c = 0; c < k; c++) {
                char letter = (char) ('a' + c);
                if (validAppend(res, letter, x)) {
                    res.append(letter);
                }
            }
            if (res.length() == before) break;
        }
        return res.length() + 1;
    }

    static boolean validAppend(StringBuilder sb, char ch, int x) {
        int j = sb.length();
        for (int i = 0; i < j; i++) {
            if ((j - i) % x == 0 && sb.charAt(i) == ch) return false;
        }
        return true;
    }
}
