package jan21;
import java.util.*;


public class SortingGame {
    public static void main(String[] args) throws Exception {
        FastScanner fs = new FastScanner();
        int t = fs.nextInt();
        if (t == Integer.MIN_VALUE) {
            return;
        }
        StringBuilder out = new StringBuilder();
        for (int tc = 0; tc < t; tc++) {
            int n = fs.nextInt();
            String s = fs.next();
            if (s == null) {
                s = "";
            }
            if (n > 0 && s.length() != n) {
                s = s.replaceAll("\\s+", "");
            }
            out.append(solve(s));
            if (tc + 1 < t) {
                out.append('\n');
            }
        }
        System.out.print(out.toString());
    }


    public static String solve(String s) {
        int n = s.length();
        int zeros = 0;
        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == '0') {
                zeros++;
            }
        }

        ArrayList<Integer> indices = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            char c = s.charAt(i);
            if (i < zeros) {
                if (c == '1') {
                    indices.add(i + 1);
                }
            } else {
                if (c == '0') {
                    indices.add(i + 1);
                }
            }
        }

        if (indices.isEmpty()) {
            return "Bob";
        }

        StringBuilder res = new StringBuilder();
        res.append("Alice\n");
        res.append(indices.size()).append('\n');
        for (int i = 0; i < indices.size(); i++) {
            if (i > 0) res.append(' ');
            res.append(indices.get(i));
        }
        return res.toString();
    }


    private static class FastScanner {
        private final java.io.InputStream in = System.in;
        private final byte[] buffer = new byte[1 << 16];
        private int ptr = 0, len = 0;

        private int read() throws java.io.IOException {
            if (ptr >= len) {
                len = in.read(buffer);
                ptr = 0;
                if (len <= 0) return -1;
            }
            return buffer[ptr++];
        }

        int nextInt() throws java.io.IOException {
            int c;
            do {
                c = read();
                if (c == -1) return Integer.MIN_VALUE;
            } while (c <= ' ');
            int sign = 1;
            if (c == '-') {
                sign = -1;
                c = read();
            }
            int val = 0;
            while (c > ' ') {
                val = val * 10 + (c - '0');
                c = read();
            }
            return val * sign;
        }

        String next() throws java.io.IOException {
            int c;
            do {
                c = read();
                if (c == -1) return null;
            } while (c <= ' ');
            StringBuilder sb = new StringBuilder();
            while (c > ' ') {
                sb.append((char) c);
                c = read();
            }
            return sb.toString();
        }

        String nextLine() throws java.io.IOException {
            int c = read();
            if (c == -1) return null;
            StringBuilder sb = new StringBuilder();
            while (c != -1 && c != '\n') {
                if (c != '\r') sb.append((char) c);
                c = read();
            }
            return sb.toString();
        }

    }
}
