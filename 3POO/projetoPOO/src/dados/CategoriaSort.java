package dados;

public enum CategoriaSort {
    NOME_MUSICA("NMU"),
    NOME_ARTISTA("NAR"),
    NOME_ALBUM("NAL"),
    DURACAO("DUR"),
    GENERO("GEN"),
    LANCAMENTO("LAN");
    
    private String codigo;

    private CategoriaSort(String codigo) {
        this.codigo = codigo;
    }

    public String getCodigo() {
        return codigo;
    }
}
