from abc import ABC

class Pessoa(ABC):
    def __init__(self, nome=""):
        self.nome = nome
    
    def __string__(self):
        return self.nome
    