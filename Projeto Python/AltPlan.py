import pandas as pd
import os
import time
from openpyxl import load_workbook


#df  = pd.read_excel("C:\\Meus Projetos\\projetosFaculdade\\Planilhateste.xlsx")
df = pd.read_excel("C:\\TESTE GIT 2\\projetosFaculdade\\Projeto Python\\Planilhateste.xlsx", index_col=0)
df.head(41)

planilha = load_workbook(filename= 'Planilhateste.xlsx')
plan = planilha.active

class Escrever:

    def alterar():
        os.system("cls")
        print("Escolha a coluna a ser alterada (somente números!!):" + "\n")
        coluna = int(input())

        print("\n" + "Escolha a linha a ser alterada (somente números!!):" + "\n")
        linha  = int(input())

        print("\n" + "Escolha o novo valor a ser inserido:" + "\n")
        valor  = input()

        os.system('cls')
        print('Os dados inseridos estão corretos? (Sim/Não): Coluna ', coluna, 'Linha ', linha, 'Valor ', valor + '\n')
        escolha = input().upper()

        if(escolha == 'SIM'):
          os.system("cls")
          print("---------------------------------------Valores Atualizados------------------------------------------" + "\n")
          time.sleep(1.5)
          plan.cell(row=linha,column=coluna,value=valor)
          plan.template = True
          planilha.save('Planilhateste.xlsx')
          os.system('cls')

        if(escolha == 'NAO' and escolha == 'NÃO'):

            escolha2 = 'NAO'
            while(escolha2 == 'NAO' and escolha2 == 'NÃO'):
         
             print("Escolha a coluna a ser alterada (somente números!!):" + "\n")
             coluna = int(input())

             print("\n" + "Escolha a linha a ser alterada (somente números!!):" + "\n")
             linha = int(input())
 
             print("\n" + "Escolha o novo valor a ser inserido:" + "\n")
             valor  = input() 

             print('Os dados inseridos estão corretos? (Sim/Não): Coluna ', coluna, 'Linha ', linha, 'Valor ', valor)
             escolha2 = input().upper()

             if(escolha2 == 'SIM'):
              os.system("cls")
              print("---------------------------------------Valores Atualizados------------------------------------------" + "\n")
              time.sleep(1.5)
              plan.cell(row=linha,column=coluna,value=valor)
              plan.template = True
              planilha.save('Planilhateste.xlsx')
              os.system('cls')

        if(escolha != 'SIM') and (escolha != 'NAO'):
         
         escolha3 = 'SIM'
         while(escolha3 != 'SIM') and (escolha3 != 'NAO'):
         

          print("---------------------------------------Digite uma opção válida!---------------------------------------")
          time.sleep(1.0)
          os.system('cls')
          print('Os dados inseridos estão corretos? (Sim/Não): Coluna ', coluna, 'Linha ', linha, 'Valor ', valor)
          escolha3 = input()

          if(escolha3 == 'SIM'):
           print("---------------------------------------Valores Atualizados------------------------------------------" + "\n")
           time.sleep(1.5)
           plan.cell(row=linha,column=coluna,value=valor)
           plan.template = True
           planilha.save('Planilhateste.xlsx')
           os.system('cls')

           if(escolha3 == 'NAO' and escolha3 == 'NÃO'):
         
            print("Escolha a coluna a ser alterada (somente números!!):" + "\n")
            coluna = int(input())

            print("\n" + "Escolha a linha a ser alterada (somente números!!):" + "\n")
            linha = int(input())
 
            print("\n" + "Escolha o novo valor a ser inserido:" + "\n")
            valor  = input() 

            print('Os dados inseridos estão corretos? (Sim/Não): Coluna ', coluna, 'Linha ', linha, 'Valor ', valor)
            escolha3 = input().upper()

            if(escolha3 == 'SIM'):
             os.system("cls")
             print("---------------------------------------Valores Atualizados------------------------------------------" + "\n")
             time.sleep(1.5)
             plan.cell(row=linha,column=coluna,value=valor)
             plan.template = True
             planilha.save('Planilhateste.xlsx')
             os.system('cls')




    