import pandas as pd

contatos_df = pd.read_excel("Enviar.xlsx")

from selenium import webdriver
from selenium.webdriver.common.keys import Keys
import time
import urllib
import pywhatkit as conn
import pyautogui
import webbrowser as web

#navegador = webdriver.Chrome()
#navegador.get("https://web.whatsapp.com/")

#while len(navegador.find_elements_by_id("side")) < 1:
 #   time.sleep(1)

# já estamos com o login feito no whatsapp web
for i, mensagem in enumerate(contatos_df['Mensagem']):
    pessoa = contatos_df.loc[i, "Pessoa"]
    numero = contatos_df.loc[i, "Número"]
    texto = urllib.parse.quote(f"Oi {pessoa}! {mensagem}")
    link = f"https://web.whatsapp.com/send?phone={numero}&text={texto}"
    #navegador.get(link)
    #conn.sendwhatmsg_instantly(phone_no= {numero}, message= {texto}, tab_close= False, close_time= 1)
    web.open(link)
    #phone_no= tel, message= msg, tab_close= False, close_time= 1
    time.sleep(10)
    pyautogui.hotkey('enter')
    #while len(navegador.find_elements_by_id("side")) < 1:
    #    time.sleep(1)
    #navegador.find_element_by_xpath('//*[@id="main"]/footer/div[1]/div[2]/div/div[2]').send_keys(Keys.ENTER)
    #time.sleep(10)
        
    


# In[ ]: