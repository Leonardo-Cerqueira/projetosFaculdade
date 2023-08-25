from Clientes import VisualisarCad
from Clientes import Escrever

instancia = VisualisarCad
instacia2 = Escrever


class Main:
    print("---------------------------------------INÍCIO DO PROGRAMA---------------------------------------")
    print("|Escolha uma opção:                                                                            |")
    print("------------------------------------------------------------------------------------------------")
    print("|Ler cadastros da planilha(1)                 | Alterar cadastros da planilha(2)               |")
    print("------------------------------------------------------------------------------------------------")
    escolha = input()

    if (escolha == '1'):
        instancia.clientes()
    if (escolha == '2'):
        instacia2.alterar

        
