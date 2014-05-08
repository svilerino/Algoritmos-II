import java.util.Arrays;


public class Main {

	private static final int ARR_SIZE = 4;
	private static final int RANGE_NUMBERS = 10;

	/**
	 * @param args
	 */
	public static void main(String[] args) {
//		ejercicio1();
//		ejercicio2();
//		ejercicio3();
//		ejercicio7();
//		ejercicio8a();
//		ejercicio8b();
		ejercicioDC2doRec2010();
//		ejercicio10();
	}

	
	private static void ejercicioDC2doRec2010() {
//		int[] arr= new int[]{2,1,6,6,6,6,6,6,1,2,3, 4};
		int[] arr= new int[]{2,0,3,1};
		System.out.println("Arreglo a:" + Arrays.toString(arr));
		System.out.println("Mayoritario: " + Algoritmos.ejercicioDC2doRec2010(arr, 0, arr.length-1));
	}
	
//	private static void ejercicio10() {
////		int a[] = new int[]{1,2,3,4};
////		int b[] = new int[]{6,4,2,1};
//		
//		int a[] = new int[]{1,2,3,4};
//		int b[] = new int[]{13,12,11,10};
//		
//		System.out.println("Arreglo a:" + Arrays.toString(a));
//		System.out.println("Arreglo b:" + Arrays.toString(b));
//		System.out.println("Arreglo diferencias:" + Arrays.toString(Algoritmos.diff(a, b)));
//		System.out.println("Arreglo diferencias absolutas:" + Arrays.toString(Algoritmos.diffAbs(a, b)));
//		//pre: a y b arreglos de la misma longuitud sin repetidos
//		System.out.println("Arreglo diferencia minima: " + Algoritmos.ejercicio10(a, b, 0, a.length-1));
//	}

//	private static void ejercicio8a() {
//		int n=2;
//		boolean [][] mat = new boolean[n][n];
//		for(int i=0;i<n;i++){
//			for(int j=0;j<n;j++){
//				mat[i][j] = (Math.random()>0.3) ? true : false;				
//			}
//			System.out.println(Arrays.toString(mat[i]));
//		}
//		System.out.println("------------------------------------------------------");
//		System.out.println(Algoritmos.ejercicio8a(mat, 0, 0, n-1, n-1));
//	}
//	
//	private static void ejercicio8b() {
//		int n=4;
//		boolean [][] mat = new boolean[n][n];
//		for(int i=0;i<n;i++){
//			for(int j=0;j<n;j++){
//				mat[i][j] = (Math.random()>0.3) ? true : false;				
//			}
//			System.out.println(Arrays.toString(mat[i]));
//		}
//		System.out.println("------------------------------------------------------");
//		System.out.println(Algoritmos.ejercicio8b(mat, 0, n-1));
//	}

//	private static void ejercicio3() {
//		System.out.println(Algoritmos.ejercicio3(2, 4));
//	}

//	private static void ejercicio2() {
//		int [] arr={0,2,3,4,5,6,7,8};//a[0]==0
//		int [] arr={-6,0,2,4,5,6,7,8};//a[2]==2
//		int [] arr={-6,0,1,2,3,4,6,8};//a[6]==6
//		int [] arr={-6,0,1,2,3,4,5,7};//a[7]==7
//		System.out.println(Arrays.toString(arr));
//		System.out.println(Algoritmos.ejercicio2(arr, 0, arr.length-1));
//	}

//	private static void ejercicio1() {
//		int[] arr = new int[ARR_SIZE];
//		for(int i=0;i<ARR_SIZE;i++){
//			arr[i]=(int) (Math.random()*RANGE_NUMBERS);
//		}
//		System.out.println(Arrays.toString(arr));
//		int [] arr={8,6,7,4,5,1,3,2};
//		int [] arr={8,4,7,6,5,1,3,2};
//		int x = arr.length;
//		if((x & (x - 1)) == 0){
			//pre:es potencia de 2 el largo del array
//			System.out.println(Algoritmos.ejercicio1(arr));
//		}else{
//			System.err.println("ej1: el arreglo no tiene como tamanio una potencia de 2");
//		}
//	}
	
//	private static void ejercicio7(){
//		int[] arr = new int[ARR_SIZE];
//		for(int i=0;i<ARR_SIZE;i++){
//			arr[i]=(int) (Math.random()*RANGE_NUMBERS);
//		}
//		System.out.println(Arrays.toString(arr));
//		int[][] res = Algoritmos.ejercicio7(arr);
//		System.out.println(Arrays.toString(res[0]) + " - inv: " + res[1][0]);
//	}

}
