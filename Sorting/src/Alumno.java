public class Alumno {
	private String nombre;
	private MF sexo;
	private int nota;

	public String getNombre() {
		return nombre;
	}

	public void setNombre(String nombre) {
		this.nombre = nombre;
	}

	public MF getSexo() {
		return sexo;
	}

	public void setSexo(MF sexo) {
		this.sexo = sexo;
	}

	public int getNota() {
		return nota;
	}

	public void setNota(int nota) {
		this.nota = nota;
	}

	public Alumno(String nombre, MF sexo, int nota) {
		super();
		this.nombre = nombre;
		this.sexo = sexo;
		this.nota = nota;
	}

	@Override
	public String toString(){
		StringBuilder sb = new StringBuilder();
		sb.append("{ ");
		sb.append(getNota());
		sb.append(", ");
		sb.append(getSexo());
		sb.append(", ");
		sb.append(getNombre());
		sb.append(" }\n");
		return sb.toString();
	}
	
}
