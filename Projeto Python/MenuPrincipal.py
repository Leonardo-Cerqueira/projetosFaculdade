import os
import keyboard
import pyautogui
import time
from  ViewPlan import VisualisarCad
from  AltPlan  import Escrever
from  Mensagem import Mensagem
from  Observações import Obs

instancia = VisualisarCad
instancia2 = Escrever   
instancia3 = Mensagem
instancia4 = Obs

class Main:
    
    os.system('cls')
    print("------------------------------------------------------Observações importantes------------------------------------------------------" + '\n\n' + "Escolha sempre valores condizentes com as opções disponíveis, sejam elas números ou afimações." + '\n\n' + 'As afirmações (Sim e Nao), podem ser escritas de forma maiúscula ou minúscula, entretanto, o "Nao" deve estar sempre sem acetuação.')
    #time.sleep(7.0)

    while True:
      os.system('cls')
      print("\n\n"+"                              ---------------------------------------INÍCIO DO PROGRAMA---------------------------------------"+'\n'+"                              |Escolha uma opção:                                                                            |"+"\n" + "                              ------------------------------------------------------------------------------------------------" + '\n' +"                              |Ler cadastros da planilha(1)                 | Adicionar/Alterar cadastros da planilha(2)     |"+ '\n' +"                              ------------------------------------------------------------------------------------------------" + '\n'+"                              |Enviar mensagem(3)                           | Finalizar programa(4)                          |"+ '\n' + "                              ------------------------------------------------------------------------------------------------"'\n'+"                              |                                       Observações(5)                                         |"+'\n'+"                              ------------------------------------------------------------------------------------------------"+"\n")
      escolha = input()

      match escolha:
         case '1':
          instancia.clientes()
          escolha2 = (input("\n" + "Deseja voltar ao menu principal? (Sim/Nao):" + "\n\n")).upper()
          while (escolha2 != 'NAO') and (escolha2 != 'SIM'):
            print("---------------------------------------Digite uma opção válida!---------------------------------------")
            time.sleep(1.0)
            os.system('cls')
            escolha2 = (input("\n" + "Deseja voltar ao menu principal? (Sim/Nao):" + "\n\n")).upper()
          if(escolha2 == 'NAO'):
             os.system('cls')
             print("---------------------------------------FIM DO PROGRAMA------------------------------------------")
             time.sleep(2.0)
             keyboard.write("exit")
             pyautogui.hotkey('enter')
             os.system("cls")
             break
         case '2':
          instancia2.alterar()
          escolha4 = (input("\n" + "Deseja voltar ao menu principal? (Sim/Nao):" + "\n\n")).upper()
          while (escolha4 != 'NAO') and (escolha4 != 'SIM'):
            print("---------------------------------------Digite uma opção válida!---------------------------------------")
            time.sleep(1.0)
            os.system('cls')
            escolha4 = (input("\n" + "Deseja voltar ao menu principal? (Sim/Nao):" + "\n\n")).upper()
          if(escolha4 == 'NAO'):
             os.system('cls')
             print("---------------------------------------FIM DO PROGRAMA------------------------------------------")
             time.sleep(2.0)
             keyboard.write("exit")
             pyautogui.hotkey('enter')
             os.system("cls")
             break
         case '3':
          instancia3.mensagem()
          escolha5 = (input("\n" + "Deseja voltar ao menu principal? (Sim/Nao):" + "\n\n")).upper()
          while (escolha5 != 'NAO') and (escolha5 != 'SIM'):
            print("---------------------------------------Digite uma opção válida!---------------------------------------")
            time.sleep(1.0)
            os.system('cls')
            escolha5 = (input("\n" + "Deseja voltar ao menu principal? (Sim/Nao):" + "\n\n")).upper()
          if(escolha5 == 'NAO'):
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
         case '5': 
          os.system("cls")
          instancia4.obs()
          escolha6 = (input("\n" + "Deseja voltar ao menu principal? (Sim/Nao):" + "\n\n")).upper()
          while (escolha6 != 'NAO') and (escolha6 != 'SIM'):
             print("---------------------------------------Digite uma opção válida!---------------------------------------")
             time.sleep(1.0)
             os.system('cls')
             escolha6 = (input("\n" + "Deseja voltar ao menu principal? (Sim/Nao):" + "\n\n")).upper()
             if(escolha6 == 'NAO'):
                os.system('cls')
                print("---------------------------------------FIM DO PROGRAMA------------------------------------------")
                time.sleep(2.0)
                keyboard.write("exit")
                pyautogui.hotkey('enter')
                break