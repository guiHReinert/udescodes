
# Importacao diferente da comum, pois eu (Guilherme) estou rodando o programa
# pelo meu WSL Ubuntu.
import matplotlib
matplotlib.use("Agg")

import matplotlib.pyplot as plt
import numpy as np

bases = range(500, 9001, 500)

mediaRS = [
    120.04, 242.18, 366.19, 488.81, 606.03, 727.70, 853.44, 986.47, 1165.98, 1224.53,
    1345.80, 1463.32, 1591.05, 1717.84, 1826.47, 1943.24, 2144.44, 2241.47
]
mediaRC = [
    39.98, 81.23, 125.01, 167.46, 207.62, 245.83, 284.64, 326.33, 366.48, 411.20,
    452.18, 493.15, 534.63, 575.97, 616.45, 659.14, 698.61, 739.78
]

mediaMS = [
    123.34, 260.44, 380.44, 501.69, 633.99, 759.53, 892.52, 1028.27, 1138.25, 1259.83,
    1391.31, 1509.28, 1636.74, 1769.91, 1895.26, 2013.48, 2130.13, 2255.71
]
mediaMC = [
    41.45, 83.56, 124.48, 167.12, 211.68, 252.51, 297.16, 338.66, 383.51, 422.41,
    464.68, 507.65, 551.11, 591.59, 630.77, 672.05, 717.11, 756.93
]

# Para salvar cada grafico, comenta-se um bloco e libera o novo.

# plt.title("Média de Repetições por Base - Inserção por Ranking")
# plt.plot(bases, mediaRS, "-o", label="SEM REF")
# plt.plot(bases, mediaRC, "-o", label="COM REF")
# plt.xlabel("Tamanho da Base")
# plt.ylabel("Média de Repetições")
# plt.grid()
# plt.legend()
# plt.savefig("graficoRanking.png")

plt.title("Média de Repetições por Base - Inserção por Matrícula")
plt.plot(bases, mediaMS, "-o", label="SEM REF", color="red")
plt.plot(bases, mediaMC, "-o", label="COM REF", color="orange")
plt.xlabel("Tamanho da Base")
plt.ylabel("Média de Repetições")
plt.grid()
plt.legend()
plt.savefig("graficoMatricula.png")