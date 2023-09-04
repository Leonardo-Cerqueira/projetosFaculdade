import os
import keyboard
import pyautogui
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
      print("\n\n" + "---------------------------------------INÍCIO DO PROGRAMA---------------------------------------")
      print("|Escolha uma opção:                                                                            |")
      print("------------------------------------------------------------------------------------------------")
      print("|Ler cadastros da planilha(1)                 | Adicionar/Alterar cadastros da planilha(2)     |")
      print("------------------------------------------------------------------------------------------------")
      print("|Enviar mensagem(3)                           | Finalizar programa(4)                          |")
      print("------------------------------------------------------------------------------------------------" + "\n")
      escolha = input()
      if (escolha == '1'):
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
        escolha2 = (input("\n" + "Deseja voltar ao menu principal para corrigir? (Sim/Não):" + "\n\n")).upper()
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
           break
  