class Pessoa:
    def __init__(self):
        self.nome = ""
        self.cpf = 0
        self.idade = 0
        self.endereco = ""

    def __init__(self, nome="", cpf=0, idade=0, endereco=""):
        self.nome = nome
        self.cpf = cpf
        self.idade = idade
        self.endereco = endereco

    def __str__(self):
        return "Nome: {}\nCPF: {}\nIdade: {}\nEndereco: {}".format(self.nome, self.cpf, self.idade, self.endereco)