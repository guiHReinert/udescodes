package dados;

public class Reserva {
	private int numReserva;
	private String dataVoo;
	private String horaVoo;
	private float preco;
	private String classeVoo;
	private boolean idaEVolta;
	private int poltrona;
	
	private int getPoltrona() {
		return poltrona;
	}
	private void setPoltrona(int poltrona) {
		this.poltrona = poltrona;
	}
	
	private boolean isIdaEVolta() {
		return idaEVolta;
	}
	private void setIdaEVolta(boolean idaEVolta) {
		this.idaEVolta = idaEVolta;
	}
	
	private String getClasseVoo() {
		return classeVoo;
	}
	private void setClasseVoo(String classeVoo) {
		this.classeVoo = classeVoo;
	}
	
	private float getPreco() {
		return preco;
	}
	private void setPreco(float preco) {
		this.preco = preco;
	}
	
	private String getHoraVoo() {
		return horaVoo;
	}
	private void setHoraVoo(String horaVoo) {
		this.horaVoo = horaVoo;
	}
	
	private String getDataVoo() {
		return dataVoo;
	}
	private void setDataVoo(String dataVoo) {
		this.dataVoo = dataVoo;
	}
	
	private int getNumReserva() {
		return numReserva;
	}
	private void setNumReserva(int numReserva) {
		this.numReserva = numReserva;
	}
	
	public String toString() {
		return "Numero da reserva: "+numReserva+
				"\nData do voo: "+dataVoo+
				"\nHorario do voo: "+horaVoo+
				"\nPreco: "+preco+
				"\nClasse: "+classeVoo+
				"\nPassagem de ida e volta: "+idaEVolta+
				"\nPoltrona: "+poltrona;
	}
}
