package dados;

public class Reserva {
	private int numReserva;
	private String dataVoo;
	private String horaVoo;
	private float preco;
	private String classeVoo;
	private boolean idaEVolta;
	private boolean volta;
	private int poltrona;
	private Cidade cidade;
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
		return volta;
	}
	public void setVolta(boolean volta) {
		this.volta = volta;
	}

	public int getPoltrona() {
		return poltrona;
	}
	public void setPoltrona(int poltrona) {
		this.poltrona = poltrona;
	}

	public Cidade getCidade() {
		return cidade;
	}
	public void setCidade(Cidade cidade) {
		this.cidade = cidade;
	}

	public Reserva getReservaVolta() {
		return reservaVolta;
	}
	public void setReservaVolta(Reserva reservaVolta) {
		this.reservaVolta = reservaVolta;
	}

	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		Reserva other = (Reserva) obj;
		if (numReserva != other.numReserva)
			return false;
		if (dataVoo == null) {
			if (other.dataVoo != null)
				return false;
		} else if (!dataVoo.equals(other.dataVoo))
			return false;
		if (horaVoo == null) {
			if (other.horaVoo != null)
				return false;
		} else if (!horaVoo.equals(other.horaVoo))
			return false;
		if (Float.floatToIntBits(preco) != Float.floatToIntBits(other.preco))
			return false;
		if (classeVoo == null) {
			if (other.classeVoo != null)
				return false;
		} else if (!classeVoo.equals(other.classeVoo))
			return false;
		if (idaEVolta != other.idaEVolta)
			return false;
		if (volta != other.volta)
			return false;
		if (poltrona != other.poltrona)
			return false;
		if (cidade == null) {
			if (other.cidade != null)
				return false;
		} else if (!cidade.equals(other.cidade))
			return false;
		if (reservaVolta == null) {
			if (other.reservaVolta != null)
				return false;
		} else if (!reservaVolta.equals(other.reservaVolta))
			return false;
		return true;
	}
	@Override
	public String toString() {
		return "Reserva [numReserva=" + numReserva + ", dataVoo=" + dataVoo + ", horaVoo=" + horaVoo + ", preco="
				+ preco + ", classeVoo=" + classeVoo + ", idaEVolta=" + idaEVolta + ", volta=" + volta + ", poltrona="
				+ poltrona + ", cidade=" + cidade +
				"\nreservaVolta=" + reservaVolta + "]";
	}

}
