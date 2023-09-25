import sys
from cx_Freeze import setup, Executable

build_exe_options = {"packages": ["os"], "includes": ["os",
"keyboard","pyautogui","time","pandas","splinter","openpyxl"]}

setup(
    name="Envio Whats",
    version="0.1",
    description="Este programa envia mensagens para o WhatsApp",
    options={"build_exe": build_exe_options},
    executables=[Executable("MenuPrincipal.py", base=False)]
)