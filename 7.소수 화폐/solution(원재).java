import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class Main {

    ArrayList<Integer> prime;
    int[] che;
    int N;
    int mod=123456789;

    public Main (int N) {
        prime = new ArrayList<Integer>();
        che = new int[N+1];
        this.N = N;
        for(int i=2;i<=N;i++) {
            if(che[i] == 1) continue;

            prime.add(i);
            for(int j=i+i;j<=N;j+=i)
                che[j] = 1;
        }

        //System.out.println(prime.size());
        //System.out.println(prime.get(prime.size()-1));

        //8System.out.println(prime.toString());
    }

    public int solve() {

        int[][] dp = new int[2][N+2];
        Arrays.fill(dp[1], 0);
        dp[1][0] = 1;
        int primeCount = prime.size();
        for(int i=0;i<primeCount;i++) {

            int coin = prime.get(i);
            for(int j=0;j<=N;j++) {
                if( coin > j ) {
                    dp[i%2][j] = (dp[(i+1)%2][j])%mod;
                    continue;
                }
                dp[i%2][j] = (dp[i%2][j-coin] + dp[(i+1)%2][j])%mod;
            }
        }

        //System.out.println(primeCount);
        for(int i=0;i<=N;i++) {
            //System.out.print (dp[0][i]);
        }
        return dp[(primeCount-1)%2][N];
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();

        Main solver = new Main(N);
        System.out.println(solver.solve());
    }
}