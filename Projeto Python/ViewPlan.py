import os
import pandas as pd


df = pd.read_excel("C:\\TESTE GIT 2\\projetosFaculdade\\Projeto Python\\Planilhateste.xlsx", index_col=0)
#df  = pd.read_excel("C:\\Meus Projetos\\projetosFaculdade\\Planilhateste.xlsx", index_col=0)

class VisualisarCad:
    
    @staticmethod
    def clientes():
     os.system("cls")
     print(df)
  

        
     