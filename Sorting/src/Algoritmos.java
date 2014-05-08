import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;
import java.util.Comparator;
import java.util.LinkedList;

public class Algoritmos {

	public static int[] mergeSort(int[] array) {
		int len = array.length;
		if (len <= 2) {
			if (len == 2) {
				int item1 = array[0];
				int item2 = array[1];
				if (item2 < item1) {
					array[0] = item2;
					array[1] = item1;
				}
			}
			return array;
		} else {
			int mitad1Size = array.length / 2;
			int[] firstHalf = new int[mitad1Size];
			int[] secondHalf = new int[array.length - mitad1Size];
			System.arraycopy(array, 0, firstHalf, 0, mitad1Size);
			System.arraycopy(array, mitad1Size, secondHalf, 0, array.length
					- mitad1Size);
			firstHalf = mergeSort(firstHalf);
			secondHalf = mergeSort(secondHalf);
			return merge(firstHalf, secondHalf);
		}
	}

	public static int[] merge(int[] firstHalf, int[] secondHalf) {
		int lenFirst = firstHalf.length;
		int lenSecond = secondHalf.length;
		int finalArray[] = new int[lenFirst + lenSecond];
		int i = 0;
		int j = 0;
		int k = 0;
		while ((i < lenFirst) && (j < lenSecond)) {
			if (firstHalf[i] < secondHalf[j]) {
				finalArray[k] = firstHalf[i];
				i++;
			} else {
				finalArray[k] = secondHalf[j];
				j++;
			}
			k++;
		}

		while (i < lenFirst) {
			finalArray[k] = firstHalf[i];
			i++;
			k++;
		}

		while (j < lenSecond) {
			finalArray[k] = secondHalf[j];
			j++;
			k++;
		}
		return finalArray;
	}

	public static int[] merge(int[][] arraysCollection) {
		for (int j = 1; j < arraysCollection.length; j++) {
			arraysCollection[j] = merge(arraysCollection[j - 1],
					arraysCollection[j]);
		}
		return arraysCollection[arraysCollection.length - 1];
	}

	public static int[] selectionSort(int[] arr) {
		int minIndex = 0;
		for (int i = 0; i < arr.length - 1; i++) {
			minIndex = i;
			for (int j = i + 1; j < arr.length; j++) {
				if (arr[j] < arr[minIndex]) {
					minIndex = j;
				}
			}
			System.out.println(Arrays.toString(arr));
			System.out.println(arr[minIndex]);
			int tmp = arr[i];
			arr[i] = arr[minIndex];
			arr[minIndex] = tmp;
		}
		return arr;
	}

	public static int[] obtenerFrecuencias(int[] arr) {
		int res[] = new int[arr.length];
		for (int i = 0; i < arr.length; i++) {
			for (int j = 0; j < arr.length; j++) {
				if (arr[i] == arr[j]) {
					res[j]++;
				}
			}
		}
		return res;
	}

	public static int[] ordenarFrecuenciaYValorDesempate(int[] arr) {
		int[] frecuencias = obtenerFrecuencias(arr);
		for (int i = 0; i < arr.length; i++) {
			for (int j = i + 1; j < arr.length; j++) {
				if (frecuencias[i] < frecuencias[j]) {
					swap(arr, frecuencias, i, j);
				} else if ((frecuencias[i] == frecuencias[j])
						&& (arr[i] > arr[j])) {
					swap(arr, frecuencias, i, j);
				}
			}
		}
		return arr;
	}

	public static void swap(int[] arr, int[] frecuencias, int i, int j) {
		// swap valor
		int aux = arr[i];
		arr[i] = arr[j];
		arr[j] = aux;
		// swap frecuencia
		aux = frecuencias[i];
		frecuencias[i] = frecuencias[j];
		frecuencias[j] = aux;
	}

	/**
	 * pre: arreglo no vacio
	 * 
	 * @param arr
	 * @return
	 */
	public static LinkedList<LinkedList<Integer>> dameEscaleras(
			ArrayList<Integer> arr) {
		LinkedList<LinkedList<Integer>> ret = new LinkedList<LinkedList<Integer>>();
		System.out.println("Arreglo original: ");
		System.out.println(arr);
		// armo las escaleras
		int j = 1;
		while (j <= arr.size()) {
			LinkedList<Integer> currentEscalera = new LinkedList<Integer>();
			currentEscalera.add(arr.get(j - 1));
			while ((j < arr.size()) && (arr.get(j) == arr.get(j - 1) + 1)) {
				currentEscalera.add(arr.get(j));
				j++;
			}
			ret.add(currentEscalera);
			j++;
		}
		return ret;
	}

	/**
	 * Complejidad: O(n) para armas los bloques O(n.logn) para ordenar las
	 * escaleras donde n=|escaleras| O(n) para aplanar
	 * 
	 * Idea: 1.- precomputo una lista< lista<int> > que contiene las escaleras
	 * del arreglo, en orden de aparicion en el arreglo 2.- Sea l la lista<int>
	 * de la i-esima lista, su longuitud long(l) se puede obtener en O(1) ,
	 * reordeno esta lista por ese paràmetro long(l) y por lista.pri en caso de
	 * desempate y unfico la lista de listas a un array
	 * 
	 * @param arr
	 */
	public static ArrayList<Integer> ordenarEscaleras(ArrayList<Integer> arr) {
		LinkedList<LinkedList<Integer>> escaleras = dameEscaleras(arr);

		System.out.println("Escaleras del arreglo original: ");
		for (LinkedList<Integer> escalera : escaleras) {
			System.out.print(escalera + ",");
		}
		System.out.println();

		Collections.sort(escaleras, new EscalerasComparator());

		System.out.println("Escaleras ordenadas: ");
		for (LinkedList<Integer> escalera : escaleras) {
			System.out.print(escalera + ",");
		}
		System.out.println();

		ArrayList<Integer> res = new ArrayList<Integer>();
		for (LinkedList<Integer> escalera : escaleras) {
			res.addAll(escalera);
		}
		return res;
	}

	private static class EscalerasComparator implements
			Comparator<LinkedList<Integer>> {

		@Override
		public int compare(LinkedList<Integer> o1, LinkedList<Integer> o2) {
			if (o1.size() < o2.size()) {
				return 1;
			} else if (o1.size() > o2.size()) {
				return -1;
			} else {
				// las long son iguales, desempate por primer elemento
				return o1.get(0) - o2.get(0);
			}
		}

	}

	public static ArrayList<LinkedList<Integer>> armarBloques(int[] arr) {
		LinkedList<LinkedList<Integer>> res = new LinkedList<LinkedList<Integer>>();
		int i = 1;
		while (i <= arr.length) {
			LinkedList<Integer> currentBlock = new LinkedList<Integer>();
			currentBlock.add(arr[i - 1]);
			while ((i < arr.length) && (arr[i - 1] == arr[i])) {
				currentBlock.add(arr[i]);
				i++;
			}
			res.add(currentBlock);
			i++;
		}
		ArrayList<LinkedList<Integer>> resArr = new ArrayList<LinkedList<Integer>>();
		resArr.addAll(res);
		return resArr;
	}

	public static ArrayList<Integer> ordenamientoConGruposDeRepetidosSiBEstaEnA(
			int[] arrA, int[] arrB) {
		ArrayList<ArrayList<Integer>> auxiliarValorRepeticiones = comprimirArreglo(arrA);
		Collections.sort(auxiliarValorRepeticiones,
				new Comparator<ArrayList<Integer>>() {
					@Override
					public int compare(ArrayList<Integer> o1,
							ArrayList<Integer> o2) {
						return o1.get(0) - o2.get(0);// 0 es valor, 1 es
														// #repeticionescontinuas
					}
				});
		// como todo lo de B esta en A...
		agregarTodosAlComprimido(arrB, auxiliarValorRepeticiones);
		return expandirComprimido(auxiliarValorRepeticiones);
	}

	private static ArrayList<Integer> expandirComprimido(
			ArrayList<ArrayList<Integer>> auxiliarValorRepeticiones) {
		ArrayList<Integer> res = new ArrayList<Integer>();
		for (ArrayList<Integer> list : auxiliarValorRepeticiones) {
			for (int i = 0; i < list.get(1); i++) {
				res.add(list.get(0));
			}
		}
		return res;
	}

	private static void agregarTodosAlComprimido(int[] arrB,
			ArrayList<ArrayList<Integer>> auxiliarValorRepeticiones) {
		for (int j = 0; j < arrB.length; j++) {
			// busco la posicion para colocar el j-esimo elemento de b en la
			// posicion correcta
			int k = 0;
			boolean encontrado = false;
			while (k < auxiliarValorRepeticiones.size() && !encontrado) {
				ArrayList<Integer> tupla = auxiliarValorRepeticiones.get(k);
				if (tupla.get(0) == arrB[j]) {
					tupla.set(1, tupla.get(1) + 1);// incremento la aparicion.
					encontrado = true;
				}
				k++;
			}
		}
	}

	private static ArrayList<ArrayList<Integer>> comprimirArreglo(int[] arrA) {
		ArrayList<ArrayList<Integer>> res = new ArrayList<ArrayList<Integer>>();
		int j = 1;
		while (j <= arrA.length) {
			ArrayList<Integer> currentBlock = new ArrayList<Integer>();
			currentBlock.add(arrA[j - 1]);// agrego el elemento
			int repeticiones = 1;
			while (j < arrA.length && arrA[j] == arrA[j - 1]) {// mientras se
																// repita,
																// incremento
																// las
																// repeticiones
				repeticiones++;
				j++;
			}
			currentBlock.add(repeticiones);// pongo su #repeticiones en la 2da
											// pos del array.
			res.add(currentBlock);
			j++;
		}
		return res;
	}

	public static ArrayList<Integer> ordenamientoConGruposDeRepetidos(
			int[] arrA, int[] arrB) {
		ArrayList<LinkedList<Integer>> unionDeBloques = new ArrayList<LinkedList<Integer>>();
		unionDeBloques.addAll(armarBloques(arrA));
		unionDeBloques.addAll(armarBloques(arrB));
		Collections.sort(unionDeBloques, new Comparator<LinkedList<Integer>>() {
			@Override
			public int compare(LinkedList<Integer> o1, LinkedList<Integer> o2) {
				return o1.getFirst() - o2.getFirst();
			}
		});
		return aplanar(unionDeBloques);
	}

	public static ArrayList<Integer> aplanar(
			ArrayList<LinkedList<Integer>> unionDeBloques) {
		ArrayList<Integer> res = new ArrayList<Integer>();
		for (LinkedList<Integer> list : unionDeBloques) {
			for (Integer i : list) {
				res.add(i);
			}
		}
		return res;
	}

	public static ArrayList<Alumno> ejercicio9(Alumno[] a) {
		// inicializamos 2 arreglos con capacidad 11(rango de notas 0 a 10)
		// LinkedList<Alumno>[] hombres = (LinkedList<Alumno>[])new
		// LinkedList[11];
		// LinkedList<Alumno>[] mujeres = (LinkedList<Alumno>[])new
		// LinkedList[11];
		// for(int j=0;j<11;j++){
		// hombres[j]=new LinkedList<Alumno>();
		// mujeres[j]=new LinkedList<Alumno>();
		// }
		// for(int i=0;i<a.length;i++){
		// if(a[i].getSexo().equals(MF.Femenino)){
		// //alumno es femenino
		// mujeres[a[i].getNota()].addLast(a[i]);
		// }else{
		// //alumno es masculino
		// hombres[a[i].getNota()].addLast(a[i]);
		// }
		// }
		// ArrayList<Alumno> res = new ArrayList<>(a.length);
		//
		// res.addAll(expandirAlumnos(mujeres));
		// res.addAll(expandirAlumnos(hombres));
		// return res;

		// separo en 2 listas, hombres de mujeres //O(n)
		LinkedList<Alumno> hombresList = new LinkedList<Alumno>();
		LinkedList<Alumno> mujeresList = new LinkedList<Alumno>();
		for (int i = 0; i < a.length; i++) {
			if (a[i].getSexo().equals(MF.Femenino)) {
				mujeresList.addLast(a[i]);
			} else {
				hombresList.addLast(a[i]);
			}
		}
		// paso las listas a arreglos
		Alumno[] hombres = hombresList.toArray(new Alumno[0]); // O(n)
		Alumno[] mujeres = mujeresList.toArray(new Alumno[0]); // O(n)
		// como las notas son acotadas, hago countingsort sobre cada arreglo. y
		// me toma O(n) ya que entre las dos longuitudes de los arreglos suman
		// n.
		hombres = countingSort(hombres, 11);
		mujeres = countingSort(mujeres, 11);

		ArrayList<Alumno> res = new ArrayList<>(a.length);
		for (int i = 0; i < mujeres.length; i++) {
			res.add(mujeres[i]);
		}
		for (int i = 0; i < hombres.length; i++) {
			res.add(hombres[i]);
		}
		return res;
	}

	/**
	 * rango countsort [0..rango)
	 * 
	 * @param entrada
	 * @param rango
	 * @return
	 */
	public static Alumno[] countingSort(Alumno[] entrada, int rango) {
		int[] auxCount = new int[rango];
		Alumno[] salida = new Alumno[entrada.length];
		for (int i = 0; i < entrada.length; i++) {
			auxCount[entrada[i].getNota()]++;
		}
		// System.out.println(Arrays.toString(auxCount));
		for (int i = 1; i < rango; i++) {
			auxCount[i] += auxCount[i - 1];
		}
		// System.out.println(Arrays.toString(auxCount));
		for (int k = entrada.length - 1; k >= 0; k--) {
			salida[auxCount[entrada[k].getNota()] - 1] = entrada[k];
			auxCount[entrada[k].getNota()]--;
		}
		// System.out.println(Arrays.toString(salida));
		return salida;
	}

	@SuppressWarnings("unused")
	private static Collection<Alumno> expandirAlumnos(
			LinkedList<Alumno>[] mujeres) {
		ArrayList<Alumno> res = new ArrayList<Alumno>();
		for (LinkedList<Alumno> list : mujeres) {
			for (Alumno i : list) {
				res.add(i);
			}
		}
		return res;
	}

	/**
	 * Idea: countingsort + bucketsort realizo un countingsort, teniendo en
	 * cuenta un "corrimiento" en el arreglo de salida segun sexo.
	 * @param minRange 
	 * @param maxRange 
	 * 
	 * @param entrada
	 * @param rango
	 */
	// public static Alumno[] ejercicio9(Alumno[] entrada, int rango){
	// int[] auxCount = new int[rango];//las notas estan acotadas entre 0 y 10
	// Alumno[] salida = new Alumno[entrada.length];
	// for(int i=0;i<entrada.length;i++){
	// auxCount[entrada[i].getNota()]++;
	// }
	// System.out.println(Arrays.toString(auxCount));
	// for(int i=1;i<rango;i++){
	// auxCount[i]+=auxCount[i-1];
	// }
	// System.out.println(Arrays.toString(auxCount));
	// for(int k=entrada.length-1;k>=0;k--){
	// salida[auxCount[entrada[k].getNota()]-1]=entrada[k];
	// auxCount[entrada[k].getNota()]--;
	// }
	// System.out.println(Arrays.toString(salida));
	// return salida;
	// }

	@SuppressWarnings("unchecked")
	public static Integer[] ejercicio12(Integer arr[], Integer minRange, Integer maxRange) {
		LinkedList<Integer>[] buckets = (LinkedList<Integer>[]) new LinkedList[2];
		for (int i = 0; i < 2; i++) {
			buckets[i] = new LinkedList<Integer>();
		}
		for (int j = 0; j < arr.length; j++) {
			if ((arr[j] >= minRange) && (arr[j] <= maxRange)) {
				buckets[0].addLast(arr[j]);
			} else {
				buckets[1].addLast(arr[j]);
			}
		}
				
		return merge(
				countingSortEnRango(buckets[0].toArray(new Integer[0]), minRange, maxRange) , 
				insertionSort(buckets[1].toArray(new Integer[0]))
			);
	}

	public static Integer[] merge(Integer[] firstHalf, Integer[] secondHalf) {
		int lenFirst = firstHalf.length;
		int lenSecond = secondHalf.length;
		Integer[] finalArray = new Integer[lenFirst + lenSecond];
		int i = 0;
		int j = 0;
		int k = 0;
		while ((i < lenFirst) && (j < lenSecond)) {
			if (firstHalf[i] < secondHalf[j]) {
				finalArray[k] = firstHalf[i];
				i++;
			} else {
				finalArray[k] = secondHalf[j];
				j++;
			}
			k++;
		}

		while (i < lenFirst) {
			finalArray[k] = firstHalf[i];
			i++;
			k++;
		}

		while (j < lenSecond) {
			finalArray[k] = secondHalf[j];
			j++;
			k++;
		}
		return finalArray;		
	}

	public static Integer[] insertionSort(Integer[] vector) {
		for (int i = 1; i < vector.length; i++) {
			int temp = vector[i];
			int j;

			for (j = i - 1; j >= 0 && vector[j] > temp; j--) {
				vector[j + 1] = vector[j];

			}

			vector[j + 1] = temp;
		}
		return vector;
	}

	public static Integer[] countingSortEnRango(Integer[] entrada,
			Integer minRange, Integer maxRange) {
		int rango = maxRange - minRange + 1;
		int[] auxCount = new int[rango];
		Integer[] salida = new Integer[entrada.length];
		for (int i = 0; i < entrada.length; i++) {
			auxCount[entrada[i] - minRange]++;
		}
		// System.out.println(Arrays.toString(auxCount));
		for (int i = 1; i < rango; i++) {
			auxCount[i] += auxCount[i - 1];
		}
		// System.out.println(Arrays.toString(auxCount));
		for (int k = entrada.length - 1; k >= 0; k--) {
			salida[auxCount[entrada[k] - minRange] - 1] = entrada[k];
			auxCount[entrada[k] - minRange]--;
		}
		// System.out.println(Arrays.toString(salida));
		return salida;
	}

	public static TuplaEj13[] ordenamientoPorNombreYNumeroDesempate(TuplaEj13[] arr, Integer cotaString) {
//		Arrays.sort(arr, new Comparator<TuplaEj13>() {
//
//			@Override
//			public int compare(TuplaEj13 o1, TuplaEj13 o2) {
//				return o1.getNum()-o2.getNum();
//			}
//		});
		ordenamientoString(arr, cotaString);
		return arr;
	}

	public static void ordenamientoString(TuplaEj13[] arr, Integer cotaStr) {
		//radix por caracter
		char[][] mat = new char[arr.length][cotaStr];
		for(int i=0;i<arr.length;i++){
			for(int j=0;j<cotaStr;j++){
				mat[i][j]=(j<arr[i].getNombre().length()) ? arr[i].getNombre().charAt(j) : 64;//64 es menor que 65 en chars. 
			}
		}
		for(int columnaAOrdenar=cotaStr-1;columnaAOrdenar>=0;columnaAOrdenar--){
//			countingSortEnRango(mat, columnaAOrdenar, 65, 90);
			Integer[] tmp = countingSortEnRango(dameColumna(mat, columnaAOrdenar), 65, 90);
			reemplazarColumna(mat, columnaAOrdenar, tmp);
		}
	}

	private static void reemplazarColumna(char[][] mat, int columnaAOrdenar, Integer[] tmp) {
		for(int j=0;j<mat[columnaAOrdenar].length;j++){
			mat[columnaAOrdenar][j]=(char) Byte.parseByte(String.valueOf(tmp[j]));
		}
	}

	private static Integer[] dameColumna(char[][] mat, int columnaAOrdenar) {
		Integer res[] = new Integer[mat[columnaAOrdenar].length];
		for(int j=0;j<mat.length;j++){
			res[j]=(int) mat[j][columnaAOrdenar];
		}
		return res;
	}

//	private static void countingSortEnRango(char[][] mat, int columnaAOrdenar, int minRange, int maxRange) {
//		int rango = maxRange - minRange + 1;
//		int[] auxCount = new int[rango];
//		for (int i = 0; i < mat[columnaAOrdenar].length; i++) {
//			auxCount[mat[columnaAOrdenar][i] - minRange]++;
//		}
//		// System.out.println(Arrays.toString(auxCount));
//		for (int i = 1; i < rango; i++) {
//			auxCount[i] += auxCount[i - 1];
//		}
//		// System.out.println(Arrays.toString(auxCount));
//		for (int k = mat[columnaAOrdenar].length - 1; k >= 0; k--) {
//			mat[columnaAOrdenar][auxCount[mat[columnaAOrdenar][k] - minRange] - 1] = mat[columnaAOrdenar][k];
//			auxCount[mat[columnaAOrdenar][k] - minRange]--;
//		}
//		// System.out.println(Arrays.toString(salida));
//	}

}
