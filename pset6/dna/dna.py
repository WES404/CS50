from sys import argv
import csv
import re

def main():

    if len(argv) != 3:
        print("Not enough arguments")
        return 0

    DNA = argv[1]
    STR = argv[2]

    dna = open(DNA, "r")
    strs = open(STR, "r")

    base = csv.reader(dna)
    for line in base:
        valores = line #Pega a primeira linha
        break

    lendo = csv.reader(strs)
    for line in lendo:
        strs = line #Devolve como lista de string

    dic = sequencia(strs[0], valores[1:])


    nome = compara(dic, base, valores[1:])

    if nome == None:
        print("No match")

    else:
        print(nome)


def sequencia(arq, valores):

    dic = dict()
    i = 0
    cop_arq = arq

    while i < len(valores):

        limite = len(valores[i]) #Encontra o len da palavra

        for j in range(len(arq)):

            aux = 1
            count = 0

            seq = arq[j:limite + j] #Faz a sequencia ser igual ao len dentro da string

            if seq != valores[i]:
                #Se não for encontrado a sequencia o programa vai pro proximo index
                continue

            else:
                count += 1

                if seq not in dic: # Se não estiver no dic coloca com 1
                    dic[seq] = 1

                while True:
                    #A cada sequencia continua o count é inclementado
                    seq1 = arq[j + limite * count: j + limite * (1 + count)]

                    if seq == seq1:
                        count += 1

                        if dic[seq] < count:
                            #Se ultrapassar o máximo já de sequencias já encontradas adiciona mais 1
                            dic[seq] += 1
                    else:
                        break
        i += 1
    return dic

def compara(dic, base_dados, valores):

    tam =len(valores)

    if tam != len(dic):
        return None

    for line in base_dados:

        igualdade = 0

        for i in range(len(valores)):
            valor = valores[i]

            if dic[valor] == int(line[i+1]):

                igualdade += 1

            else:
                break
        if igualdade == len(valores):
            #se a igualdade for igual a todos os numeros devolve o nome
            return line[0]

    return None

main()