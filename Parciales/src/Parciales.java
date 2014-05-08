
public class Parciales {
	
	public static void main(String args[]) {
		unAgujero();
//		picosArray();
	}

	public static void unAgujero() {
//		int arr[] = {1,2,3,4,5,6,7,9};
		int arr[] = {1,2,3,50};
		System.out.println(unAgujero(arr, 0, arr.length-1));
	}

	public static int unAgujero(int[] arr, int low, int sup) {
		if(low==sup){
			return arr[low]-1;
		}else{
			int mitad=(low+sup)/2;
			if(Math.abs(mitad-low)==Math.abs(arr[mitad]-arr[low])){
				//si vale |mitad-low| == |arr[mitad]-arr[low]|,
				//es decir, el rango es igual al largo del arreglo, 
				//como son no repetidos y crecientes, si vale, no hay agujeros
				//utilizaremos esto para "descartar" mitades y ubicar el agujero en O(logn)
				//como sabemos que existe al menos un agujero y descartamos la mitad izquierda, llamamos recursivamente sobre la derecha
				return unAgujero(arr, mitad+1, sup);
			}else{
				//si existen agujeros a la izquierda, descartamos el lado derecho y llamamos a la izquierda
				return unAgujero(arr, low, mitad);
			}
		}
	}

//	private static void picosArray() {
		//		int arr[] = {2,9,7,5,3,1};
//				int arr[] = {1,3,5,7,9,2};
		//		int arr[] = {10,8,5,6,7,9};
//				int arr[] = {9,7,6,5,8,10};
//				System.out.println(arr[pico(arr, 0, arr.length)]);
//	}
	
	public static int pico(int[] a, int low, int sup){
		int medio = (sup+low)/2;
		if(a.length<3){
			return a[medio];
		}else{
			//si es un pico es menor o mayor que los 2 vecinos
			// a[medio-1]>a[medio]<a[medio+1]
			// a[medio-1]>a[medio]>a[medio+1]
			if( ( (a[medio-1]>a[medio]) && (a[medio+1]>a[medio]) )
				|| ( (a[medio-1]<a[medio]) && (a[medio+1]<a[medio]) ) ){
				return medio;
			}else{//no es un pico.
				//me voy para el lado que siga el orden que quiero segun picoMaximo
				//si crece, voy a la derecha
				//si decrece voy a la izquierda
				if( (a[medio-1]<a[medio+1]) && (a[medio]<a[medio+1]) ){
					if(a[0]<a[1]){//es creciente?
						return pico(a, medio, sup);
					}else{
						return pico(a, low, medio);
					}
				}else if( (a[medio-1]>a[medio+1]) && (a[medio]>a[medio+1]) ){
					if(a[0]<a[1]){//es creciente?
						return pico(a, low, medio);
					}else{
						return pico(a, medio, sup);
					}
				}else{
					return -1;
				}
			}
		}
	}
	
}
