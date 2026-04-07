
from classes import *
from excessoes import *

# Espaco geometrico
espGeo = EspacoGeometrico()

# Pontos
p3 = Ponto2D(2, 3)
p2 = Ponto2D(3, 4)
p1 = Ponto2D(4, 6)

# Retas
r1 = Reta(1, 1)
r2 = Reta(2, -2)
r3 = Reta(1, 2)

espGeo.adicionarPonto(p1)
espGeo.adicionarPonto(p2)
espGeo.adicionarPonto(p3)

espGeo.adicionarReta(r1)
espGeo.adicionarReta(r2)
espGeo.adicionarReta(r3)

print("Pontos contidos no espaco:")
for p in espGeo.pontos:
    print("\tPonto: " + str(p))
    
print("Retas contidas no espaco:")
for p in espGeo.retas:
    print("\tReta: " + str(p))
    
print(r1.intercepta(r2))
print(r1.intercepta(r3))
print(r2.intercepta(r3))

print(r1.estaNaReta(p1))
print(r1.estaNaReta(p2))
print(r1.estaNaReta(p3))

espGeo.adicionarPonto(p1)