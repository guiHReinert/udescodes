from excessoes.ObjetoSobrepostoException import ObjetoSobrepostoException

class EspacoGeometrico():
    def __init__(self):
        self.pontos = []
        self.retas = []
    
    def adicionarReta(self, reta=None):
        if reta not in self.retas:
            self.retas.append(reta)
        else:
            raise ObjetoSobrepostoException()
        
    def adicionarPonto(self, ponto=None):
        if ponto not in self.pontos:
            self.pontos.append(ponto)
        else:
            raise ObjetoSobrepostoException()