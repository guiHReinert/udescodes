from .Pessoa import Pessoa

class Aluno(Pessoa):
    def __init__(self, nome="", notas=[]):
        super().__init__(nome)
        self.notas = notas

    def calcularMedia(self):
        if len(self.notas) == 0:
            return 0
        else:
            return sum(self.notas) / len(self.notas)

    def __repr__(self):
        str_notas = ""
        for nota in self.notas:
            str_notas += str(nota) + " "
            
        situacao = ""
        if self.calcularMedia() >= 7:
            situacao = "APROVADO"
        else:
            situacao = "EXAME"
        
        return "Aluno(a) {}: {}\nMedia: {:.2f}\nSituacao: {}".format(self.nome, str_notas, self.calcularMedia(), situacao)