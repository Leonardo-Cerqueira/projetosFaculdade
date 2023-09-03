import pandas as pd
import openpyxl
import os
from openpyxl import load_workbook
from openpyxl import workbook
from  ViewPlan import VisualisarCad
from  AltPlan  import Escrever
from  Mensagem import Mensagem

instancia = VisualisarCad
instacia2 = Escrever   
instacia3 = Mensagem


class Main:

    while True:
      print("---------------------------------------INÍCIO DO PROGRAMA---------------------------------------")
      print("|Escolha uma opção:                                                                            |")
      print("------------------------------------------------------------------------------------------------")
      print("|Ler cadastros da planilha(1)                 | Adicionar/Alterar cadastros da planilha(2)     |")
      print("------------------------------------------------------------------------------------------------")
      print("|Enviar mensagem(3)                           | Finalizar programa(4)                          |")
      print("------------------------------------------------------------------------------------------------" + "\n")
      escolha = input()
      if (escolha == '1'):
        instancia.clientes()
        escolha2 = (input("\n" + "Digite -sim- para voltar ao menu principal:" + "\n\n")).upper()
        os.system("cls")
        if (escolha2 != "SIM"):
           print("---------------------------------------FIM DO PROGRAMA------------------------------------------")
           os.system("exit")
           break  
      if (escolha == '2'):
        instacia2.alterar()
        escolha2 = (input("Digite -sim- para voltar ao menu principal:" + "\n\n")).upper()
        os.system("cls")
        if (escolha2 != "SIM"):
           print("---------------------------------------FIM DO PROGRAMA------------------------------------------")
           break  
      if(escolha == '3'):
        os.system("cls")
        instacia3.mensagem()
        escolha2 = (input("\n" + "Digite -sim- para voltar ao menu principal:" + "\n\n")).upper()
        os.system("cls")
        if (escolha2 != "SIM"):
           print("---------------------------------------FIM DO PROGRAMA------------------------------------------")
           break  
      if (escolha == '4'):
           os.system("cls")
           print("---------------------------------------FIM DO PROGRAMA------------------------------------------")
           os.system("exit")
           break

  