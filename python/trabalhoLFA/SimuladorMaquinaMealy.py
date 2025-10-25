import sys

class SimuladorMealy:
    def __init__(self):
        self.estados = set()
        self.estado_inicial = ""
        self.estado_final = ""
        self.alfabeto_entrada = set()
        self.alfabeto_saida = set()
        self.transicoes = {}

    def carregar_maquina(self, arquivo_nome):
        try:
            # Extracao das caracteristicas da maquina no arquivo
            with open(arquivo_nome, 'r') as f:
                self.estados = set(f.readline().strip().split())
                self.estado_inicial = f.readline().strip()
                self.estado_final = f.readline().strip()
                self.alfabeto_entrada = set(f.readline().strip().split())
                self.alfabeto_saida = set(f.readline().strip().split())

                # Alimentacao do dicionario de transicoes
                for pos, linha in enumerate(f):
                    partes = linha.strip().split()
                    
                    # Garante o acesso ao segmento das transicoes
                    if len(partes) == 4:
                        q, x, r, y = partes

                        # Verificacao de entrada para quebra de pagina e movimentos vazios
                        if y == "\\n":
                            y = '\n'
                        elif y == 'e' or y == "eps" or y == 'ε': 
                            y = "" 

                        self.transicoes[(q, x)] = (r, y)
                    
                    # elif len(partes)>0:
                    #     print(f"  Linha de transicao {pos} mal formatada: '{linha.strip()}'", file=sys.stderr)

        except FileNotFoundError:
            print(f"Erro: O arquivo de definicao '{arquivo_nome}' nao foi encontrado.", file=sys.stderr)
            sys.exit(1)
        except Exception as e:
            print(f"Erro ao ler o arquivo de definicao: {e}", file=sys.stderr)
            sys.exit(1)
        # finally:
        #     print(f"""
        #           Q =     {self.estados}
        #           SIGMA = {self.alfabeto_entrada}
        #           q0 =    {self.estado_inicial}
        #           F =     {self.estado_final}
        #           DELTA = {self.alfabeto_saida}""")

    def simular(self, arquivo_palavra):
        # Saida eh o simbolo de saida definido na transicao
        try:
            with open(arquivo_palavra, 'r') as f:
                palavra = f.read() 
        
        except FileNotFoundError:
            print(f"Erro: O arquivo de palavra '{arquivo_palavra}' nao foi encontrado.", file=sys.stderr)
            sys.exit(1)

        estado_atual = self.estado_inicial
        saida_total = ""

        for simbolo in palavra:
            if simbolo == '\n' or simbolo == '\r': 
                continue
            
            # Computacao da funcao programa no estado atual
            chave_transicao = (estado_atual, simbolo)
            # print(str(chave_transicao)+" -> "+str(self.transicoes[chave_transicao]))
            if chave_transicao in self.transicoes:
                proximo_estado, simbolo_saida = self.transicoes[chave_transicao]
                saida_total += simbolo_saida
                # if estado_atual == 'N':
                #     if (self.estado_inicial, 'N') in self.transicoes:
                #         continue
                #     else:
                #         estado_atual = self.estado_inicial
                # else:
                estado_atual = proximo_estado
            else:
                if simbolo in self.alfabeto_entrada:
                    print(f"Erro: Transicao nao definida para ({estado_atual}, {simbolo})", file=sys.stderr)
                    sys.exit(1)
                else:
                    print(f"Aviso: Ignorando simbolo '{simbolo}' nao pertencente ao alfabeto.", file=sys.stderr)

        if estado_atual == self.estado_final:
            return saida_total
        else:
            print("Erro: Ultimo estado acessado foi nao-final: "+estado_atual)

    # Gera a matriz bruta da imagem
    def gerar_ppm(self, saida_maquina):
        saida_limpa = saida_maquina.rstrip('\r')
        linhas = saida_limpa.split('\n')
        
        altura = len(linhas)
        largura = len(linhas[0]) if altura > 0 else 0
        
        if altura == 0 or largura == 0:
             print(f"Aviso: A simulacaoo nao gerou saida.", file=sys.stderr)

        cabecalho = f"P1\n{largura} {altura}\n"
        
        return cabecalho + saida_limpa

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Uso: python3 SimuladorMaquinaMealy.py <arquivo_MM.txt> <arquivo_w.txt>")
        sys.exit(1) 

    maquina_path = sys.argv[1]
    palavra_path = sys.argv[2]

    simulador = SimuladorMealy()
    simulador.carregar_maquina(maquina_path)
    saida_bruta = simulador.simular(palavra_path)
    imagem_ppm = simulador.gerar_ppm(saida_bruta)
    # Gera o nome do arquivo da imagem, separando os pedacos anteriores ao .txt
    imagem_nome = maquina_path[:maquina_path.find(".txt")]+'_'+palavra_path[:palavra_path.find(".txt")]
    
    print(f"Arquivo gerado: {imagem_nome}.ppm")
    print(imagem_ppm)
    with open(""+imagem_nome+".ppm", "w") as f:
        f.write(imagem_ppm)
            