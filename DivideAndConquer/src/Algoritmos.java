import java.util.Arrays;


//ejercicios de la guia de divide and conquer

public class Algoritmos {
	
	/**
	 * Ej. 3. Divide & Conquer
		Dado un arreglo A = [a1; : : : ; an] de elementos de tipo , un elemento mayoritario de A es cualquier
		elemento que ocurra en estrictamente más de bn=2c posiciones. Por ejemplo, si n = 6 ó n = 7, cualquier
		elemento mayoritario va a ocurrir en al menos 4 posiciones del arreglo.
		El tipo  sólo cuenta con la función igualdad. Esta función puede ser invocada usando el símbolo usual, es
		decir, dos elementos a1 y a2 de tipo  pueden compararse con la expresión a1 = a2. El tipo  no provee ninguna
		función de orden, con lo cual no es posible establecer si un elemento es mayor o menor que otro.
		a) Escribir un algoritmo à la C++ para encontrar un elemento mayoritario de un arreglo de  (o para
		determinar que no hay elementos mayoritarios). Se pueden escribir funciones auxiliares, pero se deberá
		escribir una función que resuelva el problema con el siguiente tipo:
		hayMayoritario(in A: array de , out Elem: ) ! bool
		Si A tiene un elemento mayoritario, el valor del parámetro de salida Elem debe ser dicho elemento y el
		valor booleano de retorno debe ser true. En caso contrario, el valor de retorno deber ser false y Elem
		puede tener cualquier valor. Considerando que la operación de igualdad entre elementos de tipo  tiene
		O(1), el algoritmo debe poseer una complejidad O(n:log(n)), donde n es el tamaño de A.
		b) Calcular y justicar la complejidad del algoritmo propuesto. Para simplicar el cálculo, se puede suponer
		que n es potencia de dos.
	 * @param sup 
	 * @param low 
	 * @param arr 
	 */
//	NO ANDA
//	public static boolean ejercicioDC2doRec2010(int[] arr, int low, int sup){
//		if(low==sup){
//			return true;//este elemento es mayoritario en un array de un solo elemento
//		}else{
//			int mitad = (low+sup)/2;
//			boolean mitadSup = ejercicioDC2doRec20sa10(arr, mitad+1, sup) && (cantApariciones(arr, arr[mitad], mitad+1, sup)>=(sup-low)/2);
//			boolsaean mitadInf =SA ejercicioDC2doRec2010(arr, low, mitad) && (asdfsdacantApariciones(arr, arr[mitad], low, mitad)>=(sup-low)/2);
//			return mitadSup || mitadInf;
//		}
//	}
	
	/**
	 * Complejidad: O(n)
	 */
	private static int cantApariciones(int arr[], int target, int low, int sup){
		int res=0;
		for(int j=low;j<=sup;j++){
			res+=(arr[j]==target) ? 1 : 0;
		}
		return res;
	}
	

	/**
	 * Ejercicio 1 F
		Escriba un algoritmo con dividir y conquistar que determine si un arreglo de tama~no potencia de 2 es mas
		a la izquierda, donde \mas a la izquierda" signica que:
		La suma de los elementos de la mitad izquierda superan los de la mitad derecha.
		Cada una de las mitades es a su vez \mas a la izquierda".
		Por ejemplo, el arreglo [8, 6, 7, 4, 5, 1, 3, 2] es \mas a la izquierda", pero [8, 4, 7, 6, 5, 1, 3, 2] no lo es.
		Intente que su solucion aproveche la tecnica de modo que complejidad del algoritmo sea estrictamente menor
		a O(n2).
	 * 
	 * 
	 * Pre: tamaÃ±o array potencia de 2
	 * 
	 * @return true si es masALaIzquierda, false en otro caso
	 * @throws Exception 
	 */
	public static boolean ejercicio1(int[] arr){
		if(arr.length>0){
			int [] mitadDerecha = new int[arr.length/2];
			int [] mitadIzquierda = new int[arr.length/2];
			System.arraycopy(arr, 0, mitadIzquierda, 0, mitadIzquierda.length);
			System.arraycopy(arr, (arr.length/2), mitadDerecha, 0, mitadDerecha.length);
			return sumaMasALaIzquierda(arr) && ejercicio1(mitadIzquierda) && ejercicio1(mitadDerecha);
		}else{
			return true;
		}
	}
	
	/**
	 * @pre arr.length es potencia de 2
	 * @param arr
	 * @return
	 */
	private static boolean sumaMasALaIzquierda(int[] arr) {
		if(arr.length>1) {
			int mitad = arr.length/2;
			int i=0;
			int sum=0;
			for(i=0;i<mitad;i++){
				sum+=arr[i];
			}
			for(i=mitad;i<arr.length;i++){
				sum-=arr[i];
			}
			return sum>0;
		}else{
			return true;
		}
	}

	/**
	 * Tenemos un arreglo a = [a1; a2; : : : ; an] de n enteros distintos (positivos y negativos) en orden estrictamente
		creciente. Queremos determinar si existe una posicion i tal que ai = i. Por ejemplo, dado el arreglo a =
		[􀀀4;􀀀1; 2; 4; 7], i = 4 es esa posicion.
		Dise~nar un algoritmo dividir y conquistar eciente (de complejidad de orden estrictamente menor que lineal)
		que resuelva el problema. Calcule y justique la complejidad del algoritmo dado.
	 * @return indice del numero buscado o -1 si no se encontro
	 */
	/*
	 * Idea: Como los numeros tienen un orden estricto, es decir i<j => a[i]<a[j] . No puede haber numeros repetidos
	 * ya que supongamos 1,2,2,3,4 , sean los indices i=1,j=2 luego 1<2 => a[i]<a[j] => a[1]<a[2] => 2<2 es falso!.
	 * entonces podemos realizar lo siguiente, estilo busqueda binaria:
	 * voy a la mitad, si el numero del arreglo en la mitad es mayor que el indice, para todos los j>indice esto se mantendrà.
	 * De esta forma podemos descartar la mitad a la derecha del indice mitad de la busqueda.
	 * Del lado izquierdo, podrìa ocurrir que haya "agujeros" es decir, que la secuencia de numeros no sea consecutiva y efectivamente
	 * exista un numero tal que a[i]=i
	 */
	public static int ejercicio2(int[] arr, int low, int sup){
		if(sup-low>1){//chequeo que el arreglo tenga al menos 2 elementos
			//calculo el indice de la mitad del arreglo
			//(notar que es el indice no inclusivo, hay que recorrer hasta indice < mitad)
			int mitad = (sup+low+1)/2;
			if(arr[mitad]<mitad){
				//conquistar mitad derecha
				return ejercicio2(arr, mitad, sup);
			}else if(arr[mitad]>mitad){
				//conquistar mitad izquierda
				return ejercicio2(arr, low, mitad);
			}else{//implica que arr[mitad] == mitad es true.
				return mitad;//devolver el indice de la posicion buscada
			}
		}else{
			//OJO QUE HAY 2 CASOS SEGUN PARA QUE LADO DEL ARREGLO SE VAYA EN CADA PASADA.
			//sup en borde derecho
			//low en borde izquierdo
			if(low==0){
				return (arr[low]==low) ? low : -1;
			}else{//dado que es uno de los 2 bordes, debe valer sup==7
				return (arr[sup]==sup) ? sup : -1;
			}
		}
	}
	
	/**
	 * Encuentre un algoritmo para calcular ab en tiempo logartmico en b. Piense como reutilizar los resultados
		ya calculados. Justique la complejidad del algoritmo dado.
	 * @param a
	 * @param b
	 * @return
	 */
	/*
	 * Idea: sea a^b <=> a^(2.b/2) <=> a^(b/2 + b/2) <=> (a^b/2)*(a^b/2) <=> (a^b/2)^2 . En este paso redujimos la cantidad de operaciones
	 * de b multiplicaciones a b/2 + 1 multiplicaciones
	 * repitiendo esta idea recursivamente hasta que b=1, esperamos mejorar la complejidad de forma logaritmica en b
	 * Hay que tener en cuenta que eso funciona bien unicamente si b es divisible por 2. En el caso impar, deberemos realizar lo siguiente
	 * a^b = a.a^(b-1) = a.(a^((b-1)/2))^2 , dado que b-1 serà para, el otro caso se encargara.
	 */
	public static long ejercicio3(int a, int b){
		if(b==1){
			return a;
		}else{//b>1
			if(b%2==0){
				//caso par
				long res = ejercicio3(a,b/2);
				return res*res;
			}else{
				//caso impar
				long res = ejercicio3(a,(b-1)/2);
				return a*res*res;
			}
		}
	}
	
	/**
	 * 
	 * @param mat
	 * @param n
	 * @return
	 */
	/*
	 * Suponga que se tiene un metodo potencia que, dada un matriz cuadrada A de orden 4  4 y un numero n,
		computa la matriz An. Dada una matriz cuadrada A de orden 4  4 y un numero natural n que es potencia de
		2 (i.e., n = 2k para algun k  1), desarrollar, utilizando la tecnica de dividir y conquistar y el metodo potencia,
		un algoritmo que permita calcular
		A1 + A2 + : : : + An:
		Calcule el numero de veces que el algoritmo propuesto aplica el metodo potencia. Si no es estrictamente menor
		que O(n), resuelva el ejercicio nuevamente.
	 */
//	public static int[][] ejercicio5(int [][] mat, int n){
//		if(n==1){
//			return mat;
//		}else{
//			int [][] m = ejercicio5(mat, n/2);//A1+A2+...+A^(2^(k-1))
//			int [][] m2 = potenciaMat(mat, n/2);//A^(2^(k-1))
//			return m+m*m2;
//		}
//	}
	
	/**
	 * 
	 * @return # de inversiones
	 * La cantidad de parejas en desorden de un arreglo A[1..n] es la cantidad de parejas de posiciones 1 <= i <
		j <= n tales que A[i] > A[j]. Dar un algoritmo que calcule la cantidad de parejas en desorden de un arreglo
		y cuya complejidad temporal sea estrictamente mejor que O(n2) en el peor caso. Hint: Considerar hacer una
		modificacion de un algoritmo de sorting.
	 */
	public static int[][] ejercicio7(int [] arr){
		if(arr.length<=1){
			return new int[][]{arr, new int[]{0}};
		}else{
			int longuitud=arr.length;
			int[] mitadInferior = new int[longuitud/2];
			int[] mitadSuperior = new int[longuitud-(longuitud/2)];
			System.arraycopy(arr, 0, mitadInferior, 0, longuitud/2);
			System.arraycopy(arr, (longuitud/2), mitadSuperior, 0, longuitud-(longuitud/2));
			int [][]conquerInferior = ejercicio7(mitadInferior);
			int [][]conquerSuperior = ejercicio7(mitadSuperior);
			int[][] combineInv = contarInv(conquerInferior[0], conquerSuperior[0]);
			return new int[][]{combineInv[0], new int[]{combineInv[1][0] + conquerInferior[1][0] + conquerSuperior[1][0]}};
		}
	}

	private static int[][] contarInv(int[] mitadInferior, int[] mitadSuperior) {
		int i=0;
		int j=0;
		int k=0;
		int res[]=new int[mitadInferior.length+mitadSuperior.length];
		int inv=0;
		while((i<mitadInferior.length) && (j<mitadSuperior.length)){
			if(mitadInferior[i]<mitadSuperior[j]){
				res[k]=mitadInferior[i];
				i++;
			}else{
				res[k]=mitadSuperior[j];
				j++;
				inv++;
			}
			k++;
		}		
		while(i<mitadInferior.length){
			res[k]=mitadInferior[i];
			i++;k++;
		}
		while(j<mitadSuperior.length){
			res[k]=mitadSuperior[j];
			j++;k++;
		}
		System.out.println(Arrays.toString(mitadInferior) + " + " + Arrays.toString(mitadSuperior) + " = " + Arrays.toString(res) + " (inv:" + inv + ")");
		return new int[][]{res, new int[]{inv}};
	}

	/**
	 * pre: existe un false y la matriz es cuadrada de nxn y n es potencia de 2
	 * @param mat
	 * @param low
	 * @param sup
	 * @return cantidad de falses
	 */
//	public static int ejercicio8b(boolean[][] mat, int low, int sup) {
//		if(sup-low<=0){
//			int k=0;
//			int count=0;
//			while(k<mat.length){
//				count+=(mat[sup][k]) ? 0 : 1;
//				k++;
//			}
//			return count;
//		}else{
//			int numeroFalsesMitad = contarFalses(low, 0, sup/2, mat.length-1, mat);
//			if(numeroFalsesMitad>0){
//				//el false esta en esta mitad
//				return ejercicio8b(mat, low, sup/2);
//			}else{
//				//esta de la otra mitad
//				return ejercicio8b(mat, (sup/2)+1, sup);
//			}
//		}
//	}
	
//	private static int contarFalses(int x0, int y0, int x1, int y1, boolean[][] mat) {
//		int res=0;
//		for(int i=x0;i<=x1;i++){
//			for(int j=y0;j<=y1;j++){
//				res+=(mat[i][j]) ? 0 : 1;	
//			}
//		}
//		return res;
//	}

	/**
	 * pre: matriz cuadrada
	 * @param x0
	 * @param y0
	 * @param x1
	 * @param y1
	 * @param mat
	 * @return conjuncion entre los bordes x1,y1 inclusive.
	 */
//	private static boolean conjuncionSubMatriz(int x0, int y0, int x1, int y1, boolean[][] mat){
//		boolean res=true;
//		for(int i=x0;i<=x1;i++){
//			for(int j=y0;j<=y1;j++){
//				res&=mat[i][j];	
//			}
//		}
//		return res;
//	}
	
//	private static void imprimirSubMatriz(int x0, int y0, int x1, int y1, boolean[][] mat){
//		for(int i=x0;i<=x1;i++){
//			for(int j=y0;j<=y1;j++){
//				System.out.print(mat[i][j] + " ");	
//			}
//			System.out.println();
//		}
//	}
	
	/**
	 * pre: existe un false y la matriz es cuadrada de nxn y n es potencia de 2
	 * @param mat
	 * @param x0
	 * @param y0
	 * @return posicion en x,y de un false
	 */
//	public static Point2D ejercicio8a(boolean[][] mat, int x0, int y0, int x1, int y1) {
//		if((x1-x0<=0) && (y1-y0<=0)){
//			return new Point2D.Double(x0,y0);
//		}else{
//			//ver en el cuaderno las particiones con los indices y los graficos
//			//sup izq
//			if(!conjuncionSubMatriz(x0, y0, (x0+x1)/2, (y0+y1)/2, mat)){
//				return ejercicio8a(mat, x0, y0, (x0+x1)/2, (y0+y1)/2);
//			}else{
//				//sup der
//				if(!conjuncionSubMatriz((x0+x1)/2, y0, x1, (y0+y1)/2, mat)){
//					return ejercicio8a(mat, (x0+x1)/2, y0, x1, (y0+y1)/2);
//				}else{
//					//inf izq
//					if(!conjuncionSubMatriz(x0, (y0+y1)/2, (x0+x1)/2, y1, mat)){
//						return ejercicio8a(mat, x0, (y0+y1)/2, (x0+x1)/2, y1);
//					}else{
//						//como existe un false, por descarte esta aca
//						//inf der
////						if(!conjuncionSubMatriz((x0+x1)/2, (y0+y1)/2, x1, y1, mat)){
//						return ejercicio8a(mat, (x0+x1)/2, (y0+y1)/2, x1, y1);
////						}
//					}
//				}
//			}			
//		}
//	}
	
	/**
	 * Se tienen dos arreglos de n naturales A y B. A esta ordenado de manera creciente y B esta ordenado de
	manera decreciente. Ningun valor aparece mas de una vez en el mismo arreglo. Para cada posicion i consideramos
	la diferencia absoluta entre los valores de ambos arreglos jA[i] 􀀀 B[i]j. Se desea buscar el mnimo valor posible
	de dicha cuenta. Por ejemplo, si los arreglos son A = [1; 2; 3; 4] y B = [6; 4; 2; 1] los valores de las diferencias son
	5; 2; 1; 3 y el resultado es 1.	
	
	a) Implementar la funcion
		minDif(in A: arreglo(nat), in B: arreglo(nat)) ! nat
		que resuelve el problema planteado. La funcion debe ser de tiempo O(log n), donde n = tam(A) = tam(B).
		b) Calcular y justicar la complejidad del algoritmo propuesto.
	 * @return
	 */
	/*
			Idea:
		  		Como estan ordenados creciente y decrecientemente respectivamente los arreglos a y b. Podemos realizar una variacion de la busqueda binaria en la siguiente forma:
		  		calculo la mitad, analizo el valor de if(a[mitad]>b[mitad]){...} : 
		  			Sea k un entero mayor que cero, luego a[mitad+k]>=a[mitad] && b[mitad]>=b[mitad+k] por el orden en la precondicion de los arreglos
		  			utilizando la hipotesis de que vale la guarda del if, y la transitividad de la relacion de orden en < podemos obtener la siguiente desigualdad
		  			a[mitad+k]>=a[mitad]>b[mitad]>=b[mitad+k], lo que nos dice que a[mitad+k]-b[mitad+k] > 0 y en particular por la desigualdad:		  			
		  			a[mitad+k]>=a[mitad] && b[mitad]>=b[mitad+k] ,  sabemos que la diferencia se maximizarà, o quedarà constante. 
		  			Dado que buscamos minimizar la diferencia, podemos optar por lo siguiente:
		  			Si vale a[mitad]-b[mitad]>0 miramos el subarreglo entre [low..mitad], dado que por la explicacion analoga a la de arriba serà mas chica la diferencia.
		  			Si vale a[mitad]-b[mitad]<=0, podemos estar en el caso donde la diferencia es 0 y es la minima, o nos pasamos a los negativos, en ambos casos
		  			analizamos el subarreglo que proviene de la mitad derecha del arreglo actual.
		  			
		  			El caso base se darà cuando low==sup, es decir, haya un solo elemento en el arreglo
	 */
	public static int ejercicio10(int a[], int b[], int low, int sup){
		if(low==sup){//una sola posicion.
			return Math.abs(a[sup]-b[sup]);//caso base, devuelvo el minimo
		}else{
			int mitad=(low+sup)/2;
			if(a[mitad]>b[mitad]){
				return ejercicio10(a, b, low, mitad);
			}else{//a[mitad]<=b[mitad]
				return ejercicio10(a, b, mitad+1, sup);
			}
		}
	}
	
	/**
	 * pre: len(a)==len(b)
	 * @return arreglo diferencias entre a y b
	 */
	public static int[] diff(int a[], int b[]){
		int [] diff = new int[a.length];
		for(int j=0;j<a.length;j++){
			diff[j]=(a[j]-b[j]);
		}
		return diff;
	}
	
	/**
	 * pre: len(a)==len(b)
	 * @return arreglo diferencias ABSOLUTAS entre a y b
	 */
	public static int[] diffAbs(int a[], int b[]){
		int [] diff = new int[a.length];
		for(int j=0;j<a.length;j++){
			diff[j]=Math.abs(a[j]-b[j]);
		}
		return diff;
	}
}
