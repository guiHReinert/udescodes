class Reta():
    def __init__(self, a=0, b=0):
        self.a = a
        self.b = b
        
    def intercepta(self, reta=None):
        
        # Se as retas forem concorrentes (nao considera retas multiplas entre si).
        if self.a != reta.a:
            return True
        else:
            return False
        
    def estaNaReta(self, ponto=None):
        
        # y da reta pelo x do ponto(x,y).
        y = self.a * ponto.x + self.b
        # x da reta pelo y do ponto(x,y).
        x = ponto.y/self.a - self.b
        
        if ponto.x == x and ponto.y == y:
            return True
        else:
            return False
        
    def __repr__(self):
        return f"y = {self.a}x + {self.b}"