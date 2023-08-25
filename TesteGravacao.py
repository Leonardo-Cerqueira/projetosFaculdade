from Clientes import VisualisarCad

instancia = VisualisarCad


class Main:
    print("---------------------------------------INÍCIO DO PROGRAMA---------------------------------------")
    print("Deseja visualizar os cadastros da planilha?(Sim/Não)")
    escolha = str(input())

    if (escolha == 'SIM') or (escolha == 'sim'):
        instancia.clientes()
