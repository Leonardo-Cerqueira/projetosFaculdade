import pandas as pd
from Clientes import visualisarCad

class Main:

    print("---------------------------------------INÍCIO DO PROGRAMA---------------------------------------")
    print("Deseja visualizar os cadastros da planilha?(Sim/Não)")
    escolha = input()

   ## if ((escolha == 'SIM') or (escolha == 'sim')):
  ##         visualisarCad()
        
            
"""print("Quantos telefones você deseja cadastrar?")
QTD = int(input())

cont = 0
numero = [QTD]

for i in range (QTD):
    cont = cont + 1
    print(f"Digite o {cont}º de telefone")
    numero = input()
    with open("numeros.txt", "a") as gravar:
        gravar.write("Registro ")
        gravar.write(str(cont))
        gravar.write(" Número do telefone")
        gravar.write(" " + numero + '\n')

print('\n' + "fim prog")


##with open("numeros.txt", "r") as ler:
# ##   print(numero)"""