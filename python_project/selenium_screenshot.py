##### -*- coding: utf-8 -*-
from selenium import webdriver
import os
import datetime

# https://okky.kr/article/603075
os.environ["LANG"] = "en_US.UTF-8"
# Create a new cromedriver
DRIVER_DIR = r'.\chromedriver.exe'
#options = webdriver.ChromeOptions()
#options.add_argument("disable-gpu")
# , chrome_options=options
#chromedriver_path = os.environ.get('CHROMEDRIVER_PATH')
#chromedriver_path = DRIVER_DIR
#print(chromedriver_path)
#(DRIVER_DIR
print(DRIVER_DIR)
options = webdriver.ChromeOptions()
options.add_argument('headless')
options.add_argument('window-size=1920x1080')
options.add_argument("disable-gpu")
options.add_argument(
        "user-agent=Mozilla/5.0 (Macintosh; Intel Mac OS X 10_12_6) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/61.0.3163.100 Safari/537.36")


strr = datetime.datetime .today().strftime("%Y%m%d")


rf = open("address.txt", 'r')

fol = strr  + '\\' + strr + ".txt"
print(fol)

ln = ".\\"+ strr
print(ln)

try:
    if not(os.path.isdir(ln)):
        os.makedirs(os.path.join(ln))
except OSError as e:
    if e.errno != errno.EEXIST:
        print(r"Failed to create directory!!!!!")
        raise
wf = open(fol, 'w')

i = 1

#while True:
#    line = rf.readline()
#    if not line: break
line = rf.readline()
wf.write(line)
# Go to www.google.com

driver = webdriver.Chrome(DRIVER_DIR, chrome_options=options)
driver.get(line)

# Saves a .png file with name my_screenshot_name to the directory that
# you are running the program from.

screenshot_name = strr  + '\\'+ str(i)+".png"



driver.save_screenshot(screenshot_name)
print("end")
driver.close()
