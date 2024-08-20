class Item:
    def __init__(self, peso, valor):
        self.peso = peso
        self.valor = valor
        self.valor_peso = None

def mochila_01(capacidade, itens):
    
    for item in itens:
        item.valor_peso = item.valor / item.peso
    
    itens.sort(key=lambda x: x.valor_peso, reverse=True)

    valor_total = 0
    resultado = []

    for item in itens:
        if capacidade == 0:
            break
        if item.peso <= capacidade:
            capacidade -= item.peso
            valor_total += item.valor
            resultado.append(item)

    return resultado, valor_total, capacidade

if __name__ == "__main__":
    itens = [
        Item(50, 120),
        Item(12,56),
        Item(40, 90),
        Item(5, 15),
        Item(25, 50),
    ]

    capacidade = 50

    resultado, valor_total, capacidade = mochila_01(capacidade, itens)

    print(resultado, valor_total, capacidade)
