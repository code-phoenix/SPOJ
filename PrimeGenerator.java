import java.util.Scanner;
        
        class PrimeGenerator{
         
        	 public static void main(String[] args){
                    Scanner in = new Scanner(System.in);
                    int testCases = in.nextInt();
                    for(int i=0;i<testCases;i++){
                        int lower = in.nextInt();
                        int higher = in.nextInt();
         
                        printPrimes(lower,higher);
                        System.out.println();
                    }
                }
         
                public static void printPrimes(int lower,int higher){
                    for(int i=lower;i<=higher;i++){
                        if(checkPrime(i)) {
                            System.out.println(i);
                        }
                    }
                }
         
                public static boolean checkPrime(int n){
                    if(n<2) return false;
                    int sqrt = (int)Math.sqrt(n);
                    for(int i=2;i<=sqrt;i++){
                        if(n%i==0) return false;
                    }
                    return true;
                }
         
        }    