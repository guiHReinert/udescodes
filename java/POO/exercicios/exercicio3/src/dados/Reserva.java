package dados;

public class Reserva {
	private int numReserva;
	private String dataVoo;
	private String horaVoo;
	private float preco;
	private String classeVoo;
	private boolean idaEVolta;
	private boolean isVolta;
	private int poltrona;
	private Cidade cidadeOrigem, cidadeDestino;
	private Reserva reservaVolta;



	public int getNumReserva() {
		return numReserva;
	}



	public void setNumReserva(int numReserva) {
		this.numReserva = numReserva;
	}



	public String getDataVoo() {
		return dataVoo;
	}



	public void setDataVoo(String dataVoo) {
		this.dataVoo = dataVoo;
	}



	public String getHoraVoo() {
		return horaVoo;
	}



	public void setHoraVoo(String horaVoo) {
		this.horaVoo = horaVoo;
	}



	public float getPreco() {
		return preco;
	}



	public void setPreco(float preco) {
		this.preco = preco;
	}



	public String getClasseVoo() {
		return classeVoo;
	}



	public void setClasseVoo(String classeVoo) {
		this.classeVoo = classeVoo;
	}



	public boolean isIdaEVolta() {
		return idaEVolta;
	}



	public void setIdaEVolta(boolean idaEVolta) {
		this.idaEVolta = idaEVolta;
	}



	public boolean isVolta() {
		return isVolta;
	}



	public void setVolta(boolean isVolta) {
		this.isVolta = isVolta;
	}



	public int getPoltrona() {
		return poltrona;
	}



	public void setPoltrona(int poltrona) {
		this.poltrona = poltrona;
	}



	public Cidade getCidadeOrigem() {
		return cidadeOrigem;
	}



	public void setCidadeOrigem(Cidade cidadeOrigem) {
		this.cidadeOrigem = cidadeOrigem;
	}



	public Cidade getCidadeDestino() {
		return cidadeDestino;
	}



	public void setCidadeDestino(Cidade cidadeDestino) {
		this.cidadeDestino = cidadeDestino;
	}



	public Reserva getReservaVolta() {
		return reservaVolta;
	}



	public void setReservaVolta(Reserva reservaVolta) {
		this.reservaVolta = reservaVolta;
	}



	public String toString() {
		if(isIdaEVolta() == true){
			if(isVolta == true){
				return "\nCodigo da reserva: "+numReserva+
				"\nData do voo: "+dataVoo+
				"\nHorario do voo: "+horaVoo+
				"\nPreco: "+preco+
				"\nClasse do voo: "+classeVoo+
				"\nPoltrona: "+poltrona+
				"\nCidade de origem: "+cidadeOrigem+
				"\nCidade de destino: "+cidadeDestino+'\n';
			}
			else{
				return "Codigo da reserva: "+numReserva+
				"\nData do voo: "+dataVoo+
				"\nHorario do voo: "+horaVoo+
				"\nPreco: "+preco+
				"\nClasse do voo: "+classeVoo+
				"\nPossui reserva de volta: "+idaEVolta+
				"\nPoltrona: "+poltrona+
				"\nCidade de origem: "+cidadeOrigem+
				"\nCidade de destino: "+cidadeDestino+
				"\nRESERVA DE VOLTA: "+reservaVolta+'\n';
			}
		}
		else{
			return "Codigo da reserva: "+numReserva+
			"\nData do voo: "+dataVoo+
			"\nHorario do voo: "+horaVoo+
			"\nPreco: "+preco+
			"\nClasse do voo: "+classeVoo+
			"\nPossui reserva de volta: "+idaEVolta+
			"\nPoltrona: "+poltrona+
			"\nCidade de origem: "+cidadeOrigem+
			"\nCidade de destino: "+cidadeDestino+'\n';
		}
	}
}
