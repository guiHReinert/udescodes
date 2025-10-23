import sys

class SimuladorMealy:
    def __init__(self):
        self.transicoes = {}
        self.estado_inicial = ""
        self.estados = set()
        self.alfabeto_entrada = set()
        self.alfabeto_saida = set()

    def carregar_maquina(self, arquivo_mm):
        try:
            #aqq abre o arquivo
            #vou mudar pra abrir qualquer nome de arquivo
            with open(arquivo_mm, 'r') as f:
                self.estados = set(f.readline().strip().split())
                self.estado_inicial = f.readline().strip()
                #linha 3, estados finais
                f.readline() 
                self.alfabeto_entrada = set(f.readline().strip().split())
                self.alfabeto_saida = set(f.readline().strip().split())

                #transicoes
                for linha in f:
                    partes = linha.strip().split()
                    
                    if len(partes) == 4:
                        q_atual, s_in, q_prox, s_out = partes
                        
                        #'\n'
                        if s_out == "\\n":
                            s_out = "\n"
                        #movmento vazio (epsilon)
                        elif s_out == "e" or s_out == "eps" or s_out == "ε": 
                            s_out = "" 

                        #armazena transicao no dicionario
                        self.transicoes[(q_atual, s_in)] = (q_prox, s_out)
                    
                    elif len(partes)>0:
                        print(f"Aviso: Ignorando linha de transicaoo mal formatada: '{linha.strip()}'", file=sys.stderr)

        except FileNotFoundError:
            print(f"Erro: O arquivo de definicaoo '{arquivo_mm}' nao foi encontrado.", file=sys.stderr)
            sys.exit(1)
        except Exception as e:
            print(f"Erro ao ler o arquivo de definicao: {e}", file=sys.stderr)
            sys.exit(1)

    def simular(self, arquivo_palavra):
        #saida eh o simbolo saida definido na transicaos
        try:
            with open(arquivo_palavra, 'r') as f:
                palavra_entrada = f.read() 
        
        except FileNotFoundError:
            print(f"Erro: O arquivo de palavra '{arquivo_palavra}' nao foi encontrado.", file=sys.stderr)
            sys.exit(1)

        estado_atual = self.estado_inicial
        saida_total = ""

        for simbolo in palavra_entrada:
            if simbolo == '\n' or simbolo == '\r': 
                continue
            
            chave_transicao = (estado_atual, simbolo)
            
            if chave_transicao in self.transicoes:
                proximo_estado, simbolo_saida = self.transicoes[chave_transicao]
                saida_total += simbolo_saida
                estado_atual = proximo_estado
            else:
                if simbolo in self.alfabeto_entrada:
                    print(f"Erro: Transicao no definida para (Estado: {estado_atual}, Simbolo: '{simbolo}')", file=sys.stderr)
                    sys.exit(1)
                else:
                    print(f"Aviso: Ignorando simbolo '{simbolo}' nao pertencente ao alfabeto.", file=sys.stderr)

        return saida_total

    #ainda nao testei pra ver se funciona, peguei do gemini essa funcao!!
    def gerar_ppm(self, saida_maquina):
        saida_limpa = saida_maquina.strip()
        linhas = saida_limpa.split('\n')
        
        altura = len(linhas)
        largura = len(linhas[0]) if altura > 0 else 0
        
        if altura == 0 or largura == 0:
             print(f"Aviso: A simulacaoo nao gerou saida.", file=sys.stderr)

        cabecalho = f"P1\n{largura} {altura}\n"
        
        return cabecalho + saida_limpa

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Uso: python SimuladorMealy.py <arquivo_MM.txt> <arquivo_w.txt>")
        sys.exit(1) 

    arquivo_mm_path = sys.argv[1]
    arquivo_palavra_path = sys.argv[2]

    simulador = SimuladorMealy()
    simulador.carregar_maquina(arquivo_mm_path)
    saida_bruta = simulador.simular(arquivo_palavra_path)
    imagem_ppm = simulador.generar_ppm(saida_bruta)

    print(imagem_ppm)