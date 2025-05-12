from classes import Aluno, Professor
from random import randint

notas = [[], [], [], [], []]

for n in notas:
    for i in range(4):
        n.append(randint(0, 10) + randint(0, 10) / 10)
        
print(Professor("Rubens", 4000.00))
print(Professor("Fatima", 4000.00))
        
print(Aluno("Pedro", notas[0]))
print(Aluno("Leonardo", notas[1]))
print(Aluno("Gabriel", notas[2]))
print(Aluno("Luciano", notas[3]))
print(Aluno("Paulo", notas[4]))