import pandas as pd
import openpyxl
import os
from openpyxl import load_workbook
from openpyxl import workbook

#df  = pd.read_excel("C:\\Meus Projetos\\projetosFaculdade\\Planilhateste.xlsx")
df = pd.read_excel("C:\\TESTE GIT 2\\projetosFaculdade\\Planilhateste.xlsx")
df.head(100)

planilha = load_workbook(filename= 'Planilhateste.xlsx')
plan = planilha.active

class Mensagem:

    