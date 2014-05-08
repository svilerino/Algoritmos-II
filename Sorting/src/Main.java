import java.util.ArrayList;
import java.util.Arrays;

@SuppressWarnings("unused")
public class Main {
	
	public static void main(String args[]) {
//		ejercicio4();
//		ejercicio5();
//		ejercicio6();
//		ejercicio8();
//		ejercicio9();
//		ejercicio11();
//		ejercicio12();
		ejercicio13();
	}

	private static void ejercicio13() {
		TuplaEj13[] arr= new TuplaEj13[10];
		Integer largo=1;
		for(int i=0;i<10;i++){
			arr[i]=new TuplaEj13((int) (Math.random()*10 + 1), stringRandom(largo));
		}
		System.out.println(Arrays.toString(arr));
		System.out.println(Arrays.toString(Algoritmos.ordenamientoPorNombreYNumeroDesempate(arr, largo)));
	}

	private static String stringRandom(Integer largo) {
		StringBuilder sb = new StringBuilder();
		for(int i=0;i<largo;i++){
			sb.append((char)(Math.random()*26 + 65));
		}
		return sb.toString();
	}

	private static void ejercicio11() {
//		Algoritmos.countingSortEnRango(entrada, minRange, maxRange);
	}

	private static void ejercicio12() {
		Integer[] arr = new Integer[16];
		int minRange=20;
		int maxRange=40;
		int marginRange=10;
		for(int i=0;i<12;i++){
			arr[i]=(int) ( Math.random()*(maxRange-minRange+1) + minRange );
		}
		for(int i=12;i<16;i++){
			arr[i]=(int) ( Math.random()*(marginRange) + ((Math.random()<0.5) ? maxRange : -minRange ));
		}
		System.out.println(Arrays.toString((Algoritmos.ejercicio12(arr, minRange, maxRange))));
	}

	private static void ejercicio9() {
		int cantElementos=5;
		Alumno[] arreglo = new Alumno[cantElementos];	
		for(int a=0;a<cantElementos;a++){
			arreglo[a]=new Alumno("Alumno " + a, (Math.random()<0.5)?MF.Femenino:MF.Masculino, (int) (Math.random()*10 + 1));
		}
		System.out.println(Arrays.toString(arreglo));
		System.out.println(Algoritmos.ejercicio9(arreglo));
	}

	private static void ejercicio8() {
		int[] arrA = new int[]{1,1,3,3,2,2,2,2,1,1,1,4,4,5,5,5,5,5,5,5};
		int[] arrB = new int[10];
		for(int a=0;a<arrB.length;a++){
			arrB[a]=(int) (Math.random()*4)+1;
		}
		System.out.println(Arrays.toString(arrA));
		System.out.println(Arrays.toString(arrB));
//		System.out.println(Algoritmos.ordenamientoConGruposDeRepetidos(arrA, arrB));
		System.out.println(Algoritmos.ordenamientoConGruposDeRepetidosSiBEstaEnA(arrA, arrB));
	}

	private static void ejercicio6() {
		ArrayList<Integer> arr = new ArrayList<Integer>();
		
		arr.add(5);
		arr.add(6);
		arr.add(8);
		arr.add(9);
		arr.add(10);
		arr.add(7);
		arr.add(8);
		arr.add(9);
		arr.add(20);
		arr.add(15);

		System.out.println(Algoritmos.ordenarEscaleras(arr));
	}

	private static void ejercicio5() {
		int[] arr = new int[]{1,2,1,2,1,2};
//		int arr[] = new int[TAM_ARRAY];
//		for(int a=0;a<arr.length;a++){
//			arr[a]=(int) (Math.random()*RANGO_NUMEROS);
//		}
		System.out.println(Arrays.toString(arr));
		System.out.println(Arrays.toString(Algoritmos.obtenerFrecuencias(arr)));
		System.out.println(Arrays.toString(Algoritmos.ordenarFrecuenciaYValorDesempate(arr)));
	}

	private static void ejercicio4() {
		System.out.println("Arreglos iniciales:");
		int cantArreglos=3;
		int tam_maximo=10;
		int tam_minimo=1;
		int num_maximo=0;
		int num_minimo=5;
		int arraysCollection[][] = new int[cantArreglos][];
		for(int j=0;j<cantArreglos;j++){
			//creamos una array de tamaño random con valores random
			int tamanioArregloJEsimo = (int) (Math.random()*(tam_maximo-tam_minimo) + tam_minimo);
			int [] arregloActual = new int[tamanioArregloJEsimo];
			for(int k=0;k<tamanioArregloJEsimo;k++){
				arregloActual[k]=(int) (Math.random()*(num_maximo-num_minimo) + num_minimo);
			}
			//lo ordenamos
			Arrays.sort(arregloActual);
			//lo asignamos.
			arraysCollection[j]=arregloActual;
			System.out.println(j + ".- " + Arrays.toString(arregloActual));
		}
		System.out.println("Merge piola:");
		System.out.println(Arrays.toString(Algoritmos.merge(arraysCollection)));
	}

}
