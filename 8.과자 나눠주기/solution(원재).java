import java.util.Scanner;

public class Main {

    int M, N;
    int[] stick;
    int maxStick = Integer.MIN_VALUE;

    public Main(int M, int N, int[] stick) {

        this.M = M;
        this.N = N;
        this.stick = stick;
    }

    public int findMin() {

        int maxStick = Integer.MIN_VALUE;
        for(int i=0;i<N;i++) {
            if( stick[i] > maxStick )
                maxStick = stick[i];
        }

        return maxStick;
    }

    public boolean makeHappy(int length) {

        int sum = 0;
        for(int i=0;i<N && sum < M;i++) {
            sum += (stick[i] / length);
        }
        return sum >= M;
    }

    public int solve() {

        this.maxStick = findMin();
        int left = 1;
        int right = this.maxStick;
        int ans = 0;
        while( left <= right ) {
            int mid = (left + right)/2;

            if (makeHappy(mid)) {
                left = mid+1;
                ans = mid;
            } else {
                right = mid-1;
            }
        }

        return ans;
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int M = sc.nextInt();
        int N = sc.nextInt();

        int[] stick = new int[N+3];

        for(int i=0;i<N;i++) {
            stick[i] = sc.nextInt();
        }


        Main solver = new Main(M, N, stick);
        System.out.println(solver.solve());
    }
}