import os
import keyboard
import pyautogui
import time
from  ViewPlan import VisualisarCad
from  AltPlan  import Escrever
from  Mensagem import Mensagem
from  Limpar   import Limpar

instancia = VisualisarCad
instacia2 = Escrever   
instacia3 = Mensagem
instacia4 = Limpar

class Main:

    while True:
      os.system('cls')
      print("\n\n" + "---------------------------------------INÍCIO DO PROGRAMA---------------------------------------")
      print("|Escolha uma opção:                                                                            |")
      print("------------------------------------------------------------------------------------------------")
      print("|Ler cadastros da planilha(1)                 | Adicionar/Alterar cadastros da planilha(2)     |")
      print("------------------------------------------------------------------------------------------------")
      print("|Enviar mensagem(3)                           | Finalizar programa(4)                          |")
      print("------------------------------------------------------------------------------------------------" + "\n")
      escolha = input()

      match escolha:
         case '1':
          instancia.clientes()
          escolha2 = (input("\n" + "Deseja voltar ao menu principal? (Sim/Não):" + "\n\n")).upper()
          while (escolha2 != 'NAO') and (escolha2 != 'SIM'):
            print("---------------------------------------Digite uma opção válida!---------------------------------------")
            time.sleep(1.0)
            os.system('cls')
            escolha2 = (input("\n" + "Deseja voltar ao menu principal? (Sim/Não):" + "\n\n")).upper()
          if(escolha2 == 'NAO'):
             os.system('cls')
             print("---------------------------------------FIM DO PROGRAMA------------------------------------------")
             time.sleep(2.0)
             keyboard.write("exit")
             pyautogui.hotkey('enter')
             os.system("cls")
             break
         case '2':
          instacia2.alterar()
          escolha4 = (input("\n" + "Deseja voltar ao menu principal? (Sim/Não):" + "\n\n")).upper()
          while (escolha4 != 'NAO') and (escolha4 != 'SIM'):
            print("---------------------------------------Digite uma opção válida!---------------------------------------")
            time.sleep(1.0)
            os.system('cls')
            escolha4 = (input("\n" + "Deseja voltar ao menu principal? (Sim/Não):" + "\n\n")).upper()
          if(escolha4 == 'NAO'):
             os.system('cls')
             print("---------------------------------------FIM DO PROGRAMA------------------------------------------")
             time.sleep(2.0)
             keyboard.write("exit")
             pyautogui.hotkey('enter')
             os.system("cls")
             break
          if (escolha4 != 'SIM'):
            os.system('cls')
            print("---------------------------------------FIM DO PROGRAMA------------------------------------------")
            time.sleep(2.0)
            keyboard.write("exit")
            pyautogui.hotkey('enter')
            os.system("cls")
            break
         case '3':
          instacia3.mensagem()
          escolha5 = (input("\n" + "Deseja voltar ao menu principal? (Sim/Não):" + "\n\n")).upper()
          while (escolha5 != 'NAO') and (escolha5 != 'SIM'):
            print("---------------------------------------Digite uma opção válida!---------------------------------------")
            time.sleep(1.0)
            os.system('cls')
            escolha5 = (input("\n" + "Deseja voltar ao menu principal? (Sim/Não):" + "\n\n")).upper()
          if(escolha5 == 'NAO'):
             os.system('cls')
             print("---------------------------------------FIM DO PROGRAMA------------------------------------------")
             time.sleep(2.0)
             keyboard.write("exit")
             pyautogui.hotkey('enter')
             os.system("cls")
             break
          if (escolha5 != 'SIM'):
            os.system('cls')
            print("---------------------------------------FIM DO PROGRAMA------------------------------------------")
            time.sleep(2.0)
            keyboard.write("exit")
            pyautogui.hotkey('enter')
            os.system("cls")
            break
         case '4': 
          os.system("cls")
          print("---------------------------------------FIM DO PROGRAMA------------------------------------------")
          keyboard.write("exit")
          pyautogui.hotkey('enter')
          break

      '''if (escolha == '1'):
        instancia.clientes()
        escolha2 = (input("\n" + "Deseja voltar ao menu principal? (Sim/Não):" + "\n\n")).upper()
        os.system("cls")
        if (escolha2 != "SIM"):
           print("---------------------------------------FIM DO PROGRAMA------------------------------------------")
           keyboard.write("exit")
           pyautogui.hotkey('enter')
           break  
      if (escolha == '2'):
        instacia2.alterar()
        escolha2 = (input("Deseja voltar ao menu principal? (Sim/Não):" + "\n\n")).upper()
        os.system("cls")
        if (escolha2 != "SIM"):
           print("---------------------------------------FIM DO PROGRAMA------------------------------------------")
           keyboard.write("exit")
           pyautogui.hotkey('enter')
           break  
      if(escolha == '3'):
        os.system("cls")
        instacia3.mensagem()
        instacia4.limpa()
        escolha2 = (input("\n" + "Deseja voltar ao menu principal? (Sim/Não):" + "\n\n")).upper()
        os.system("cls")
        if (escolha2 != "SIM"):
           print("---------------------------------------FIM DO PROGRAMA------------------------------------------")
           keyboard.write("exit")
           pyautogui.hotkey('enter')
           break  
      if (escolha == '4'):
           os.system("cls")
           print("---------------------------------------FIM DO PROGRAMA------------------------------------------")
           keyboard.write("exit")
           pyautogui.hotkey('enter')
           break'''
        
