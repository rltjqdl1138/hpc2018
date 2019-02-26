import java.util.Scanner;

public class Main {

    int[] distance;
    int[] price;
    int C, E, D;
    int N;
    boolean verbose = false;

    public Main(int C, int E, int D, int N, int[] distance, int[] price) {

        this.C = C;
        this.E = E;
        this.D = D;
        this.N = N;
        this.distance = new int[N+3];

        int sum = 0;
        this.distance[0] = 0;
        for(int i=0;i<N;i++) {
            sum += distance[i];
            this.distance[i+1] = sum;
        }
        this.distance[N+1] = D;

        this.price = new int[N+3];
        this.price[0] = 0;
        for(int i=0;i<N;i++) {
            this.price[i+1] = price[i];
        }
        price[N+1] = 0;

        if (verbose) {
            for(int i=0;i<=N+1;i++) {
                System.out.print(this.distance[i] + " ");
            }
            System.out.println();
            for(int i=0;i<=N+1;i++) {
                System.out.print(this.price[i] + " ");
            }
            System.out.println();
        }
    }

    public int solve() {

        int curStation = 0;
        int curOil = C;
        int pay = 0;


        // N + 1 Destination
        while(curStation <= N) {
            int target = curStation;
            int min = Integer.MAX_VALUE;
            int targetDistance = 0;

            int sum = 0;
            int pivot = curStation;

            while( pivot <= N+1 && (distance[pivot+1]-distance[curStation])*E <= C && min > price[curStation] ) {

                sum = sum + distance[pivot];
                pivot = pivot + 1;
                if( price[pivot] < min ) {
                    min = price[pivot];
                    target = pivot;
                }
            }


            if( verbose )
                System.out.println("---Step---");

            if( target == curStation ) return -1;

            targetDistance = 0;
            /* for(int i=curStation;i<target;i++){ // Could be optimized
                targetDistance += distance[i];
            }*/
            targetDistance = distance[target] - distance[curStation];

            if( min > price[curStation]) {
                pay += (C-curOil) * price[curStation];
                curOil = C;
            } else if(curOil < targetDistance * E) {
                pay += (targetDistance*E-curOil) * price[curStation];
                curOil = targetDistance * E;
            }

            if( verbose ) {
                System.out.println("Move: " + curStation + "->" + target);
                System.out.println("Move distance: " + targetDistance);
            }

            curOil = curOil - targetDistance*E;
            if( verbose ) {
                System.out.println("current Oil: " + (curOil + targetDistance*E) + "->" + curOil);
                System.out.println("target: " + target + " pay: " + pay);
            }
            curStation = target;
        }

        return pay;
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int C = sc.nextInt();
        int E = sc.nextInt();
        int D = sc.nextInt();
        int N = sc.nextInt();
        int[] distance = new int[N+3];
        int[] price = new int[N+3];

        for(int i=0;i<N;i++) {
            distance[i] = sc.nextInt();
        }
        for(int i=0;i<N;i++) {
            price[i] = sc.nextInt();
        }


        Main solver = new Main(C, E, D, N, distance, price);
        System.out.println(solver.solve());
    }

}