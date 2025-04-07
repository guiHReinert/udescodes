from .Cargo import Cargo
from .Pessoa import Pessoa

class Gerente():
    def __init__(self):
        self.cargo = Cargo()
        self.identificacao = Pessoa()
        self.nomeFilial = ""
        
        self.cargo.funcao = "Gerente"
        self.cargo.salarioBase = self.cargo.salarioMinimo * 99
        self.cargo.valorValeAlimentacao = 999
        self.cargo.valeTransporte = True

    def __init__(self, nomeFilial="", pessoa=Pessoa()):
        self.cargo = Cargo()
        self.identificacao = pessoa
        self.nomeFilial = nomeFilial
        
        self.cargo.funcao = "Gerente"
        self.cargo.salarioBase = self.cargo.salarioMinimo * 99
        self.cargo.valorValeAlimentacao = 9999
        self.cargo.valeTransporte = True

    def __str__(self):
        return "Gerente da filial {}:\n{}\n{}".format(self.nomeFilial, str(self.identificacao), str(self.cargo))
        