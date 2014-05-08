public class TuplaEj13 {
	private int num;
	private String nombre;

	public String getNombre() {
		return nombre;
	}

	public void setNombre(String nombre) {
		this.nombre = nombre;
	}

	public TuplaEj13(int num, String nombre) {
		super();
		this.num = num;
		this.nombre = nombre;
	}

	public int getNum() {
		return num;
	}

	public void setNum(int num) {
		this.num = num;
	}
	
	@Override
	public String toString(){
		StringBuilder sb = new StringBuilder();
		sb.append("{ ");
		sb.append(getNum());
		sb.append(", ");
		sb.append(getNombre());
		sb.append(" }\n");
		return sb.toString();
	}
}
