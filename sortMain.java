import java.util.Random;
class Sorting{
    public static void insertionSort(int[] a) {
        for(int i = 1; i < a.length; i++){
            int temp = a[i];
            int j;
            for(j=i-1; j > 0&&temp < a[j]; j--){
                a[j+1]=temp;
            }
            a[j+1]=temp;
        }
    }
    public static void selctionSort(int[] a){
        for(int i = 0; i < a.length-1; i++){
            int min_idx=i;
            for(int j = i+1; j < a.length; j++){
                if(a[j] < a[min_idx]){
                    min_idx=j;
                }
            }
            int temp = a[min_idx];
            a[min_idx]=a[i];
            a[i]=temp;
        }
    }
    public static void bubbleSort(int[] a){
        int i, j, temp;
        for(i =0; i < a.length-1; i++){
            for(j = 0; j < a.length-1; j++){
                if(a[j] > a[j+1]){
                    temp =a[j];
                    a[j]= a[j+1];
                    a[j+1]= temp;
                }
            }
        }
    }
    public static void flagbubbleSort(int[] a){
        int i, j, temp;
        boolean swapped;
        for(i=0; i < a.length-1; i++){
            swapped = false;
            for(j=0; j < a.length-1; j++){
                if(a[j] > a[j+1]){
                    temp = a[j];
                    a[j] = a[j+1];
                    a[j+1] = temp;
                    swapped = true;
                }
            }
            if(swapped == false)
                break;
        }
    }
}
public class sortMain {
    private static int SIZE = 1000000;
    private static final int MAX = 1000000;
    public static void main(String[] args) {
        int a[] = new int[SIZE];
        Random R = new Random();
        for(int i = 0; i < SIZE; i++){
            R.nextInt(MAX);
        }
        /*
        for(int i =0; i < SIZE; i++){
            a[i]=MAX-i;
            }
        for(int i =0; i < SIZE; i++){
            }
        */
        long start = System.currentTimeMillis();
        Sorting.insertionSort(a);
        Sorting.selctionSort(a);
        Sorting.bubbleSort(a);
        Sorting.flagbubbleSort(a);
        long end = System.currentTimeMillis();
        System.out.println(" Execution Time ="+(end-start));
    }
}
