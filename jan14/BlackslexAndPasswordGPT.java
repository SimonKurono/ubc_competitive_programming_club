package jan14;
import java.io.*;
public class BlackslexAndPasswordGPT {

    // Fast input (much faster than Scanner)
    static class FastScanner {
        private final InputStream in;
        private final byte[] buffer = new byte[1 << 16];
        private int ptr = 0, len = 0;

        FastScanner(InputStream in) {
            this.in = in;
        }

        private int readByte() throws IOException {
            if (ptr >= len) {
                len = in.read(buffer);
                ptr = 0;
                if (len <= 0) return -1;
            }
            return buffer[ptr++];
        }

        int nextInt() throws IOException {
            int c;
            do {
                c = readByte();
            } while (c <= ' '); // skip whitespace

            int sign = 1;
            if (c == '-') {
                sign = -1;
                c = readByte();
            }

            int val = 0;
            while (c > ' ') {
                val = val * 10 + (c - '0');
                c = readByte();
            }
            return val * sign;
        }
    }

    public static void main(String[] args) throws Exception {
        FastScanner fs = new FastScanner(System.in);
        StringBuilder out = new StringBuilder();

        int t = fs.nextInt();
        for (int tc = 0; tc < t; tc++) {
            int k = fs.nextInt();
            int x = fs.nextInt();

            int ans = blackslexAndPassword(k, x); 
            out.append(ans).append('\n');
        }

        System.out.print(out.toString());
    }

    
    public static int blackslexAndPassword(int k, int x) {
        String[] alphabet = "abcdefghijklmnopqrstuvwxyz".split("");
        String res = "";
        int n = 0;

        while (true) {
            int start = n;
            for (int l = 0; l < k; l++) {
                String temp = res + alphabet[l];
                if (checkX(temp, x)) {
                    res += alphabet[l];
                    n++;
                }
            }
            if (n == start) break;
        }
        return n + 1;
    }

    public static boolean checkX(String s, int x) {
        int j = s.length() - 1;
        for (int i = 0; i < s.length() - 1; i++) {
            if ((j - i) % x == 0 && s.charAt(i) == s.charAt(j)) {
                return false;
            }
        }
        return true;
    }
}
