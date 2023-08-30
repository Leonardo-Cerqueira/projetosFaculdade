import pandas as pd
import openpyxl
import os
from openpyxl import load_workbook
from openpyxl import workbook



#df = pd.read_excel("C:\\TESTE GIT 2\\projetosFaculdade\\Planilhateste.xlsx", index_col=0)
df  = pd.read_excel("C:\\Meus Projetos\\projetosFaculdade\\Planilhateste.xlsx", index_col=0)

class VisualisarCad:
    
    @staticmethod
    def clientes():
     os.system("cls")
     print(df)
  

        
     