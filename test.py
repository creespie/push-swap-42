import subprocess
import random
import matplotlib.pyplot as plt
import sys
import os
import math
from concurrent.futures import ThreadPoolExecutor, as_completed

CONFIG_TEST = [
    (10, 300),
    (25, 200),
    (50, 150),
    (100, 80),
    (200, 40),
    (300, 25),
    (500, 15),
    (750, 8),
    (1000, 5),
    (1500, 3),
    (2000, 2),
]

FLAGS = {
    "Simple": "--simple",
    "Medium": "--medium",
    "Complex": "--complex",
}

MAX_SIMPLE_SIZE = 500
MAX_WORKERS = os.cpu_count() or 4


def genera_stack_casuale(size):
    return [str(n) for n in random.sample(range(-10_000_000, 10_000_000), size)]


def esegui_push_swap(flag, numeri):
    result = subprocess.run(
        ["./push_swap", flag] + numeri,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True
    )

    if result.returncode != 0:
        raise RuntimeError(f"Errore con {flag}:\n{result.stderr}")

    return len([m for m in result.stdout.splitlines() if m.strip()])


def test_singolo(size):
    stack = genera_stack_casuale(size)
    res = {}

    for nome, flag in FLAGS.items():
        if nome == "Simple" and size > MAX_SIMPLE_SIZE:
            res[nome] = None
        else:
            res[nome] = esegui_push_swap(flag, stack)

    return res


def teorica(nome, n):
    if nome == "Simple":
        return n ** 2
    if nome == "Medium":
        return n * math.sqrt(n)
    if nome == "Complex":
        return n * math.log2(n)
    return n


def stima_esponente(xs, ys):
    """
    Stima p in: mosse ~= C * n^p
    usando due punti consecutivi.
    """
    exps = []

    for i in range(1, len(xs)):
        if ys[i] is None or ys[i - 1] is None:
            exps.append(None)
            continue

        n1, n2 = xs[i - 1], xs[i]
        y1, y2 = ys[i - 1], ys[i]

        if y1 <= 0 or y2 <= 0:
            exps.append(None)
            continue

        p = math.log(y2 / y1) / math.log(n2 / n1)
        exps.append(p)

    return exps


def main():
    grandezze = []
    risultati = {k: [] for k in FLAGS}

    print("==============================================")
    print("      BENCHMARK BIG-O PUSH_SWAP               ")
    print("==============================================")
    print(f"Thread usati: {MAX_WORKERS}\n")

    for size, num_test in CONFIG_TEST:
        print(f"Size {size:5d} | test {num_test:3d} ... ", end="", flush=True)

        somme = {k: 0 for k in FLAGS}
        count = {k: 0 for k in FLAGS}

        with ThreadPoolExecutor(max_workers=MAX_WORKERS) as executor:
            futures = [executor.submit(test_singolo, size) for _ in range(num_test)]

            for future in as_completed(futures):
                res = future.result()

                for nome in FLAGS:
                    if res[nome] is not None:
                        somme[nome] += res[nome]
                        count[nome] += 1

        grandezze.append(size)

        for nome in FLAGS:
            if count[nome] == 0:
                risultati[nome].append(None)
            else:
                risultati[nome].append(somme[nome] / count[nome])

        s = risultati["Simple"][-1]
        m = risultati["Medium"][-1]
        c = risultati["Complex"][-1]

        s_txt = "SKIP" if s is None else str(int(s))
        print(f"OK  S:{s_txt} | M:{int(m)} | C:{int(c)}")

    # ==========================
    # GRAFICO 1: mosse reali
    # ==========================

    plt.figure(figsize=(22, 9))

    for nome in FLAGS:
        plt.plot(grandezze, risultati[nome], marker="o", linewidth=2, label=nome)

    plt.axhline(1500, linestyle=":", linewidth=1.5, label="Subject 100 num: 1500")
    plt.axhline(12000, linestyle="--", linewidth=1.5, label="Subject 500 num: 12000")

    plt.title("1) Numero medio reale di mosse", fontsize=18, fontweight="bold")
    plt.xlabel("Dimensione stack n")
    plt.ylabel("Mosse medie")
    plt.grid(True, linestyle="--", alpha=0.4)
    plt.legend()
    plt.tight_layout()
    plt.savefig("01_mosse_reali.png", dpi=200)

    # ==========================
    # GRAFICO 2: normalizzazione Big-O
    # ==========================

    plt.figure(figsize=(22, 9))

    for nome in FLAGS:
        valori = []

        for n, y in zip(grandezze, risultati[nome]):
            if y is None:
                valori.append(None)
            else:
                valori.append(y / teorica(nome, n))

        plt.plot(grandezze, valori, marker="o", linewidth=2, label=f"{nome} / teorica")

    plt.title("2) Controllo Big-O: mosse / complessità teorica", fontsize=18, fontweight="bold")
    plt.xlabel("Dimensione stack n")
    plt.ylabel("Rapporto normalizzato")

    plt.grid(True, linestyle="--", alpha=0.4)
    plt.legend()
    plt.tight_layout()
    plt.savefig("02_big_o_normalizzata.png", dpi=200)

    # ==========================
    # GRAFICO 3: esponente reale stimato
    # ==========================

    plt.figure(figsize=(22, 9))

    for nome in FLAGS:
        exps = stima_esponente(grandezze, risultati[nome])
        x_exp = grandezze[1:]
        plt.plot(x_exp, exps, marker="o", linewidth=2, label=nome)

    plt.axhline(1.0, linestyle=":", linewidth=1.2, label="O(n)")
    plt.axhline(1.2, linestyle=":", linewidth=1.2, label="circa O(n^1.2)")
    plt.axhline(1.5, linestyle="--", linewidth=1.2, label="O(n√n) = O(n^1.5)")
    plt.axhline(2.0, linestyle="-.", linewidth=1.2, label="O(n²)")

    plt.title("3) Esponente reale stimato: mosse ≈ C × n^p", fontsize=18, fontweight="bold")
    plt.xlabel("Dimensione stack n")
    plt.ylabel("Esponente p stimato")

    plt.grid(True, linestyle="--", alpha=0.4)
    plt.legend()
    plt.tight_layout()
    plt.savefig("03_esponente_reale.png", dpi=200)

    plt.show()

    print("\nGrafici salvati:")
    print(" - 01_mosse_reali.png")
    print(" - 02_big_o_normalizzata.png")
    print(" - 03_esponente_reale.png")


if __name__ == "__main__":
    main()
