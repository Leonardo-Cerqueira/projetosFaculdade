import pandas as pd
import os
import time
from splinter import Browser

#df = pd.read_excel("C:\\Users\\leonardo.gomes\\Desktop\Meus Projetos\\projetosFaculdade\\Projeto Python\\Planilhateste.xlsx",index_col=0)
df = pd.read_excel("C:\\planilha.xlsx", index_col=0)


class Mensagem:

    def mensagem():
          
          while True:
            
            os.system("cls")

            msg = input(("Digite a mensagem que será enviada aos clientes: " + "\n\n"))

            coluna = input(("\n"+ "Digite o nome da coluna onde os contatos desejados estão localizados: " + "\n\n"))

            while True:
                try:
                 ini = int(input("\n" + "Digite a linha inicial da coluna" + "\n\n"))
                 break
                except ValueError:
                  print("\n" + "Digite apenas números!!" + "\n")
                  time.sleep(2)
                  os.system("cls")
            while True:
               try:                  
                 fim = int(input("\n" + "Digite a linha final da coluna" + "\n\n"))
                 break
               except ValueError:
                  print("\n" + "Digite apenas números!!" + "\n")
                  time.sleep(2)
                  os.system("cls")

            os.system("cls")
            print("Linha inicial: ", ini, "Linha Final: ", fim, "\n\nMensagem: " + msg)

            corr = input(("\n" + "Os dados estão corretos? (Sim/Nao): " + "\n\n")).upper()
            cont = 0 

            if corr == "SIM":
               
               nav = Browser('chrome')
               nav.visit("https://web.whatsapp.com/")
               time.sleep(30)
               
               fim = fim + 1

               for i, posicao in enumerate(range(ini, fim)):
               
                end = fim
                cont = cont + 1

                telefones = df[[coluna]].iloc[posicao]

                time.sleep(3)
             
                telefone = str(telefones)

                nav.visit(f'https://web.whatsapp.com/send?phone={telefone}&text={msg}')
 
                os.system('cls')
                time.sleep(3)
                
                V = nav.is_element_present_by_xpath('//*[@id="main"]/footer/div[1]/div/span[2]/div/div[2]/div[2]/button/span',wait_time = 10)

                if V: 
                     time.sleep(3)
                     nav.find_by_xpath('//*[@id="main"]/footer/div[1]/div/span[2]/div/div[2]/div[2]/button/span').click()
                     print('Mensagem enviada para: ', cont , 'pessoas')
                     time.sleep(6)
                elif not V:
                     time.sleep(3)
               if end == fim:
                break
                  
            elif corr == 'NAO' or corr == 'NÃO':
                 os.system("cls")
                 print("---------------------------------------Aguarde------------------------------------------")
                 time.sleep(2.0)
            else:
               os.system('cls')
               print("---------------------------------------Opção inválida. Digite *Sim* ou *Nao*------------------------------------------" + "\n")
               time.sleep(2.0)