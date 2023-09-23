import pandas as pd
import csv
import numpy as np
import datetime

data = pd.read_csv('service_event.csv')
dataset = data.sort_values(by='duration')
lista = dataset.to_numpy()

# gerando 100 arquivos
def gerar_arquivos_csv():
    x = 1
    for i in range(100):
        file = open('service_event'+str(i+1)+'.csv','w',newline='')
        w = csv.writer(file)
        for j in range(7815):
            try:
                w.writerow(lista[x])
            except IndexError:
                continue
            x += 1
        file.close()
    print('\nArquivos Gerados!\n')

    # fazendo busca sequencial
def busca_sequencial():
    contador = 0
    data_comp = datetime.datetime(2018,6,29,12,00,00)
    for i in range(100):
        data2 = pd.read_csv('service_event'+str(i+1)+'.csv')
        lista = data2.to_numpy()
        for j in range(7815):
            try:
                data_if = datetime.datetime(int(lista[j][5][0:4]),int(lista[j][5][5:7]),int(lista[j][5][8:10]), int(lista[j][5][11:13]),int(lista[j][5][14:16]), int(lista[j][5][17:19]))
                valor = lista[j][3]
                if valor > 1000 and data_if <= data_comp:
                    contador += 1
            except IndexError:
                break
    print(f"\nEventos que atenderam a condição: {contador:}\n")


def menu():
    r = int(input('(1) dividir arquivo em csv em blocos;\n(2) consulta sem indexação;\n(3) consulta com indexação;\n(4) sair;\nDigite a opção: '))
    return r


if __name__ == '__main__':
    while True:
        r = menu()
        if r == 1:
            gerar_arquivos_csv()
        elif r == 2:
            busca_sequencial()
        elif r == 3:
            print('\nFunção não implementada\n')
        elif r == 4:
            print("\n...Saindo...\n")
            break
