import pandas as pd

# Pl = pd.read_excel("C:\Meus Projetos\projetosFaculdade\Planilhateste.xlsx")
df = pd.read_excel("C:\\TESTE GIT 2\\projetosFaculdade\\Planilhateste.xlsx")
df.head(42)



class VisualisarCad:

    @staticmethod
    def clientes():
        return print(df.head(41))
