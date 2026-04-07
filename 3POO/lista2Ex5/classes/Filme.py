import json

class Filme:
    def __init__(self):
        self.titulo = ""
        self.ano = 0
        self.classificacao = ""
        self.nota = 0.0

    def __init__(self, titulo="", ano=0, classificacao="", nota=0.0):
        self.titulo = titulo
        self.ano = ano
        self.classificacao = classificacao
        self.nota = nota

    def importarJSON(self, dictJSON):
        self.titulo = dictJSON["titulo"]
        self.ano = dictJSON["ano"]
        self.classificacao = dictJSON["classificacao"]
        self.nota  = dictJSON["nota"]

    def __str__(self):
        return "{}, {}, {}, {}".format(self.titulo, self.ano, self.classificacao, self.nota)


