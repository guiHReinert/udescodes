class Cargo():
    def __init__(self):
        self.funcao = ""
        self.salarioMinimo = 1500
        self.salarioBase = ""
        self.valorValeAlimentacao = 0.0
        self.valeTransporte = False

    def __init__(self, funcao="", salarioBase="", valorValeAlimentacao=0.0, valeTransporte=False):
        self.funcao = funcao
        self.salarioMinimo = 1509
        self.salarioBase = salarioBase
        self.valorValeAlimentacao = valorValeAlimentacao
        self.valeTransporte = valeTransporte

    def __str__(self):
        return "Nome da funcao: {}" \
        "\nSalario Base: {}" \
        "\nValor do vale alimentação: {}" \
        "\nPossui vale transporte: {}".format(self.funcao, self.salarioBase, self.valorValeAlimentacao, self.valeTransporte)