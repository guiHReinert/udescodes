from .Pessoa import Pessoa

class Professor(Pessoa):
    def __init__(self, nome="", salario=0.0):
        super().__init__(nome)
        self.salario = salario
        
    def __repr__(self):
        return "Professor(a): {}\nSalario: RS{:.2f}".format(self.nome, self.salario)