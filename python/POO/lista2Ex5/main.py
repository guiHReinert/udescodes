from classes import *

import json
from operator import itemgetter

pathJSON = "exemplos/filmes_teste.json"
lista_json = []
lista_filmes = []

with open(pathJSON) as f:
    lista_json = json.load(f)
    # Sort na lista
    lista_json = sorted(lista_json, key=itemgetter("nota"))
    for item in lista_json:
        filme = Filme()
        filme.importarJSON(item)
        lista_filmes.append(filme)

for filme in lista_filmes:
    print(filme)

