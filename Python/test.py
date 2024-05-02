from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.common.by import By
from time import sleep

secrets = ''
with open('secrets', 'r') as f:
    secrets = f.read()

account = secrets.split('\n')[0]
password = secrets.split('\n')[1]

# print(account, password)

driver = webdriver.Chrome()
driver.get('https://flipclass.stust.edu.tw')

sleep(1)

# input account and password
element_account = driver.find_element(By.NAME, 'account')
element_password = driver.find_element(By.NAME, 'password')

element_account.send_keys(account)
sleep(1)
element_password.send_keys(password)
sleep(1)

# click login button
element_login_text = driver.find_element(By.PARTIAL_LINK_TEXT, 'Login')
element_login = element_login_text.parent

element_login.click()
sleep(10)

driver.close()