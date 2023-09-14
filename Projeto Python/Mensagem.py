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
from selenium.webdriver.common.keys import Keys 

#df  = pd.read_excel("C:\\Meus Projetos\\projetosFaculdade\\Planilhateste.xlsx")
df = pd.read_excel("C:\\TESTE GIT 2\\projetosFaculdade\\Projeto Python\\Planilhateste.xlsx", index_col=0)
df.head(100)

#
navegador = webdriver.Chrome()
navegador.get("https://web.whatsapp.com/")

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
            #tel = '+55 11961611974'
            
           # escoluna = input(("Digite o nome da coluna desejada: " + "\n\n"))
           # linhacol = int(input("Digite a linha onde o número está: " + "\n\n")) 
           # print(escoluna, linhacol)
                 
           # url = 'https://web.whatsapp.com/send?phone=' + tel + '&text=' + msg
          #  whats_win = pw.getWindowsWithTitle("WhatsApp")
         #   if len(whats_win) > 0:
            #b: str = escoluna         
            
            
            #a: str = linhacol..

            msg = input()
            a = input()
            um = 4
            dois = 7
            for i, posicao in enumerate(range(um, dois)):
             #print(posicao)
            # telefone5 = df["telefone5"].iloc[posicao]
             #telefone5 = df[["telefone1","telefone2","telefone3","telefone4","telefone5"]].iloc[posicao]
             telefone5 = df[a].iloc[posicao]
             
             telefone = str(telefone5)
             print(telefone)
             navegador.get('https://web.whatsapp.com/send?phone='+telefone+'&text='+msg)
             #conn.sendwhatmsg_instantly(phone_no= telefone, message= msg, tab_close= True, close_time= 1)
             #web.open('https://web.whatsapp.com/send?phone='+telefone+'&text='+msg, new=0)
             time.sleep(11)
             navegador.find_element_by_xpath('//*[@id="main"]/footer/div[1]/div[2]/div/div[2]').send_keys(Keys.ENTER)
             time.sleep(1.3)
             #te = 2l = df.loc[i, "telefone4"]

            # print(telefone5)
             #nome = input(("\n" + "Digite o nome da pessoa para qual a mensagem será enviada: " + "\n\n" + "\n\n"))
                 
             
            #"Olá, " +  nome + ", tudo bem? Somos da Digital, da *CAIXA*. Você pode RENOVAR o seu empréstimo *CONSIGNADO* CAIXA, com taxas e prazos SUPER ESPECIAIS! A parcela será mantida, e você ainda receberá um troco na RENOVAÇÃO. Gostou? Retorne essa mensagem."
                # print(escoluna)
            #conn.sendwhatmsg_instantly(phone_no= tel, message= msg, tab_close= False, close_time= 1)
            #time.sleep(6.3)
            #pyautogui.hotkey('enter')
          #  else:
           #     web.open('https://web.whatsapp.com/send?phone=' + tel + '&text=' + msg)
            #    print("\n" + "Aguarde um momento para abrir o WhatsApp Web e enviar a mensagem.")
             #   time.sleep(12) 
     else:
            print("\n" + "Aguarde...")
            time.sleep(0.5)
            os.system("cls")
