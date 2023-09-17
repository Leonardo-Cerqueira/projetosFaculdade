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
from selenium.webdriver.common.by import By

df = pd.read_excel("C:\\Users\\leonardo.gomes\\Desktop\Meus Projetos\\projetosFaculdade\\Projeto Python\\Planilhateste.xlsx",index_col=0)
#df = pd.read_excel("C:\\TESTE GIT 2\\projetosFaculdade\\Projeto Python\\Planilhateste.xlsx", index_col=0)


navegador = webdriver.Chrome()
navegador.get("https://web.whatsapp.com/")

class Mensagem:

    def mensagem():
          
          while True:

            os.system("cls")

            msg = input(("Digite a mensagem  que será enviada aos clientes: " + "\n\n"))

            coluna = input(("\n"+ "Digite o nome da coluna onde os contatos desejados estão localizados: " + "\n\n"))

            ini = int(input("\n" + "Digite a linha inicial da coluna" + "\n\n"))

            fim = int(input("\n" + "Digite a linha final da coluna" + "\n\n"))
            
            fim = fim+1
            os.system("cls")
            print("Linha inicial: ", ini, "Linha Final: ", fim, "\n\nMensagem: " + msg)

            corr = input(("\n" + "Os dados estão corretos? (Sim/Nao): " + "\n\n")).upper()
             
            if corr == "SIM":
 
             for i, posicao in enumerate(range(ini, fim)):
             
              telefones = df[coluna].iloc[posicao]
             
              telefone = str(telefones)

              navegador.get('https://web.whatsapp.com/send?phone='+telefone+'&text='+msg)
              #conn.sendwhatmsg_instantly(phone_no= telefone, message= msg, tab_close= True, close_time= 1)
              #web.open('https://web.whatsapp.com/send?phone='+telefone+'&text='+msg, new=0)
              time.sleep(11)

              navegador.find_element(By.XPATH, '//*[@id="main"]/footer/div[1]/div/span[2]/div/div[2]/div[1]/div/div/p/span').send_keys(Keys.ENTER)
              time.sleep(1.3)
              
            elif corr == 'NAO' or corr == 'NÃO':
                os.system("cls")
                print("---------------------------------------Aguarde------------------------------------------")
                time.sleep(3.0)
            else:
               os.system('cls')
               print("---------------------------------------Opção inválida. Digite *Sim* ou *Nao*------------------------------------------" + "\n")
               time.sleep(3.0)