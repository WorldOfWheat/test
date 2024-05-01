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
driver.get('https://flipclass.stust.edu.tw/course/31169')
sleep(1)
date = datetime.now().strftime('%Y%m%d')
element_attendance_button = driver.find_element(By.XPATH, f'//a/span[text()="{date}_簽到"]')
element_attendance_button.click()
sleep(1)

# click submit button
element_submit_button = driver.find_element(By.XPATH, '//a/span[text()="Submit assignment"]')
element_submit_button.click()
sleep(2)

# fill in the form 
# switch to the iframe
iframe = driver.find_element(By.TAG_NAME, "iframe")
driver.switch_to.frame(iframe)
sleep(0.5)
# input
element_text_box = driver.find_element(By.CSS_SELECTOR, 'body')
element_text_box.click()
input_action = ActionChains(driver)
input_action.send_keys('4B2G0003')
input_action.perform()
sleep(0.5)

# click second submit button
element_second_submit_button = driver.find_element(By.XPATH, '//button/span[text()="Temporary save"]')
element_second_submit_button.click()

# take a screenshot
sleep(1)
driver.save_screenshot('/home/worldofwheat/Pictures/flipclass-attendance-record.png')

driver.close()