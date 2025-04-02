from classes import *

gerente1 = Gerente(
    "Dunder Muffin",
    Pessoa("Michael Shot", 90917688174, 47, "Broken Dreams Boulevard, N.13")
)
gerente2 = Gerente(
    "Mini Store One",
    Pessoa("Juiz Dredd", 64791062812, 53, "Galipodos Lane Street, N.78")
)

print("\n{}".format(str(gerente1)))
print("\n{}".format(str(gerente2)))

faxineiro = Cargo("Faxineiro", 1510, 250, True)
caixista = Cargo("Caixista", 1630, 250, False)

print("\n{}".format(str(faxineiro)))
print("\n{}\n".format(str(caixista)))