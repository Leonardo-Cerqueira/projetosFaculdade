import pandas as pd
import os
from openpyxl import load_workbook
import webbrowser as web
import keyboard 
import pyautogui
import time
import pygetwindow as pw
from   selenium import webdriver 
import pywhatkit as conn

#df  = pd.read_excel("C:\\Meus Projetos\\projetosFaculdade\\Planilhateste.xlsx")
df = pd.read_excel("C:\\TESTE GIT 2\\projetosFaculdade\\Projeto Python\\Planilhateste.xlsx", index_col=0)
df.head(100)

class Mensagem:

    def mensagem():
     
     #df['telefone4'] = ['+55 11961611974']
     
       #print(df)
     #print(df.columns)
       # coluna = int(input(("\n\n" + "Digite a coluna onde o telefone está:" + "\n\n")))
       # linha = int(input(("\n" + "Digite a linha onde o telefone está:" + "\n\n")))
        

       # Varmeng = plan.cell(row=linha, column=coluna).value
       # os.system("cls")
        #print("\n" + "Dado da Célula: " + Varmeng + "\n\n" + "Nome digitado: " + nome)
     corr = input(("\n" + "Os dados estão corretos? (sim/não): " + "\n\n")).upper()
        
     if corr == "SIM":
            tel = '+55 11961611974'
            
           # escoluna = input(("Digite o nome da coluna desejada: " + "\n\n"))
           # linhacol = int(input("Digite a linha onde o número está: " + "\n\n")) 
           # print(escoluna, linhacol)
                 
           # url = 'https://web.whatsapp.com/send?phone=' + tel + '&text=' + msg
          #  whats_win = pw.getWindowsWithTitle("WhatsApp")
         #   if len(whats_win) > 0:
            #b: str = escoluna         
            #a: str = linhacol
           # for i, telefone4 in enumerate(df["telefone4"]):
                   # tel = df.loc[i, "telefone4"]
            #print(tel)
            nome = input(("\n" + "Digite o nome da pessoa para qual a mensagem será enviada: " + "\n\n" + "\n\n"))
                 
            msg = input()
            #"Olá, " +  nome + ", tudo bem? Somos da Digital, da *CAIXA*. Você pode RENOVAR o seu empréstimo *CONSIGNADO* CAIXA, com taxas e prazos SUPER ESPECIAIS! A parcela será mantida, e você ainda receberá um troco na RENOVAÇÃO. Gostou? Retorne essa mensagem."
                # print(escoluna)
            conn.sendwhatmsg_instantly(phone_no= tel, message= msg, tab_close= False, close_time= 1)
            time.sleep(6.3)
            pyautogui.hotkey('enter')
          #  else:
           #     web.open('https://web.whatsapp.com/send?phone=' + tel + '&text=' + msg)
            #    print("\n" + "Aguarde um momento para abrir o WhatsApp Web e enviar a mensagem.")
             #   time.sleep(12) 
     else:
            print("\n" + "Aguarde...")
            time.sleep(0.5)
            os.system("cls")
