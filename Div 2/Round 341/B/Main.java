import java.io.*;
import java.util.*;

public class Main
{
    public static void main(String[] args)
    {
        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));

	int n = sc.nextInt();

	int [] s1, s2;
	s1 = new int[600000];
	s2 = new int[600000];
	for(int i = 0; i < n; i++) {
	    int a, b;
	    a = sc.nextInt();
	    b = sc.nextInt();
	    
	    s1[b - a + n]++;
	    s2[b + a]++;
	}

	long ans = 0;
	for(int i = 1; i < 600000; i++) {
	    ans += s1[i] * (s1[i] - 1) / 2;
	    ans += s2[i] * (s2[i] - 1) / 2;
	}

	out.println(ans);

        // Stop writing your solution here.
        out.close();
    }

    // PrintWriter for faster output
    public static PrintWriter out;

    // MyScanner class for faster input
    public static class MyScanner
    {
        BufferedReader br;
        StringTokenizer st;

        public MyScanner()
        {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        boolean hasNext()
        {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (Exception e) {
                    return false;
                }
            }
            return true;
        }

        String next()
        {
            if (hasNext())
                return st.nextToken();
            return null;
        }

        int nextInt()
        {
            return Integer.parseInt(next());
        }

        long nextLong()
        {
            return Long.parseLong(next());
        }

        double nextDouble()
        {
            return Double.parseDouble(next());
        }

        String nextLine()
        {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }
}
