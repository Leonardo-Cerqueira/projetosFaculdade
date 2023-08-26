import pandas as pd
import openpyxl
import os
from openpyxl import load_workbook
from openpyxl import workbook

#df  = pd.read_excel("C:\\Meus Projetos\\projetosFaculdade\\Planilhateste.xlsx")
df = pd.read_excel("C:\\TESTE GIT 2\\projetosFaculdade\\Planilhateste.xlsx")
df.head(41)

planilha = load_workbook(filename= 'Planilhateste.xlsx')
plan = planilha.active


class VisualisarCad:
    
    @staticmethod
    def clientes():
     print(df.head(41))
  

        
     