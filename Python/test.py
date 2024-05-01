from random import randint
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.common.action_chains import ActionChains
from time import sleep
from datetime import datetime

secrets = ''
with open('/home/worldofwheat/.flipclass-secrets', 'r') as f:
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
sleep(0.1)
element_password.send_keys(password)
sleep(0.1)

# click login button
element_login = driver.find_element(By.CSS_SELECTOR, 'button.btn.btn-primary.btn-lg.btn-block')
element_login.click()
sleep(1)

# deal with alert
try:
    element_keep_other = driver.find_element(By.CSS_SELECTOR, 'a.btn.btn-default.keepLoginBtn')
    element_keep_other.click()
    sleep(1)
except:
    pass

# jump to course page
driver.get('https://flipclass.stust.edu.tw/course/31204')
sleep(1)

# list all videos
element_doc_links = driver.find_elements(By.XPATH, '//a[starts-with(@href, "/media/doc/")]')
links = []
for element_doc_link in element_doc_links:
    doc_link = element_doc_link.get_attribute('href')
    links.append(doc_link)
    # driver.execute_script(f'window.open("{doc_link}");')
    # sleep(0.5)

ok_counter = 0
while (len(links) > 0):
    ok_counter += 1
    print(ok_counter, datetime.now())

    # open link
    link = links[randint(0, len(links) - 1)]
    links.remove(link)
    driver.execute_script(f'window.open("{link}");')
    driver.switch_to.window(driver.window_handles[1])

    # sleep
    sleep_time = randint(600, 1200)
    # sleep_time = randint(2, 3)
    sleep(sleep_time)

    driver.close()
    driver.switch_to.window(driver.window_handles[0])

driver.close()