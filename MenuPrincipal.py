import pandas as pd
import openpyxl
import os
from openpyxl import load_workbook
from openpyxl import workbook
from  ViewPlan import VisualisarCad
from  AltPlan  import Escrever

instancia = VisualisarCad
instacia2 = Escrever   



class Main:

    while True:
      print("---------------------------------------INÍCIO DO PROGRAMA---------------------------------------")
      print("|Escolha uma opção:                                                                            |")
      print("------------------------------------------------------------------------------------------------")
      print("|Ler cadastros da planilha(1)                 | Adicionar/Alterar cadastros da planilha(2)     |")
      print("------------------------------------------------------------------------------------------------")
      print("|                                     Finalizar programa(3)                                    |")
      print("------------------------------------------------------------------------------------------------")
      escolha = input()
      if (escolha == '1'):
        instancia.clientes()
        escolha2 = (input("\n" + "Digite -sim- para voltar ao menu principal:" + "\n")).upper()
        os.system("cls")
        if (escolha2 != "SIM"):
           print("---------------------------------------FIM DO PROGRAMA------------------------------------------")
           break  
      if (escolha == '2'):
        instacia2.alterar()
        escolha2 = (input("Digite -sim- para voltar ao menu principal:" + "\n")).upper()
        os.system("cls")
        if (escolha2 != "SIM"):
           print("---------------------------------------FIM DO PROGRAMA------------------------------------------")
           break  
      if (escolha == '3'):
           os.system("cls")
           print("---------------------------------------FIM DO PROGRAMA------------------------------------------")
           break
  