'''
from selenium import webdriver
import  time
from selenium.webdriver import DesiredCapabilities

## Chrome의 경우 | 아까 받은 chromedriver의 위치를 지정해준다.

options = webdriver.ChromeOptions()


#options.add_argument('headless')
options.add_argument('window-size=1920x1080')
options.add_argument("disable-gpu")
options.add_argument('user-agent=Mozilla/5.0 (Windows NT 10.0; Win64; x64)AppleWebKit/537.36 (KHTML, like Gecko) Chrome/72.0.3626.121 Safari/537.36')
options.add_argument("lang=ko_KR") # 한국어!
#lys312510@naver.com


driver = webdriver.Chrome('chromedriver', chrome_options=options)

#Mozilla/5.0 (Windows NT 10.0; Win64; x64)AppleWebKit/537.36 (KHTML, like Gecko) Chrome/72.0.3626.121 Safari/537.36
## PhantomJS의 경우 | 아까 받은 PhantomJS의 위치를 지정해준다.

#driver = webdriver.PhantomJS('/phantomjs-2.1.1-windows/bin')

driver.implicitly_wait(3)

driver.get('https://nid.naver.com/nidlogin.login')

time.sleep(0.5)
driver.find_element_by_name('id').send_keys('')
time.sleep(0.5)
driver.find_element_by_name('pw').send_keys('')
time.sleep(0.5)
#driver.find_element_by_xpath('//*[@id="frmNIDLogin"]/fieldset/input').click()
'''


## parser.py
import requests
from bs4 import BeautifulSoup
'''
## HTTP GET Request
req = requests.get('http://alg.pknu.ac.kr/')
## HTML 소스 가져오기
html = req.text
## BeautifulSoup으로 html소스를 python객체로 변환하기
## 첫 인자는 html소스코드, 두 번째 인자는 어떤 parser를 이용할지 명시.
## 이 글에서는 Python 내장 html.parser를 이용했다.
soup = BeautifulSoup(html, 'html.parser')

my_titles = soup.select('a')
my_section = soup.select('span')

## my_titles는 list 객체
for title in my_titles:
    ## Tag안의 텍스트
    print(title.text)
    ## Tag의 속성을 가져오기(ex: href속성)
    #print(title.get('href'))

#ember945 > table > tbody > tr > td.main-link > tr:nth-child(1) > a
print("--------------------------------------")
for section in my_section:
    ## Tag안의 텍스트
    #print(section)
    print(section.text)
    ## Tag의 속성을 가져오기(ex: href속성)
'''
backjoon = requests.get('https://www.acmicpc.net/school/ranklist/279')

backhtml = backjoon.text

back = BeautifulSoup(backhtml, 'html.parser')


back_title = back.select('a')
back_section = back.select('span')
print("--------------------------------------")
for title in back_title:
    ## Tag안의 텍스트
    print(title.text)
print("--------------------------------------")

#ranklist > tbody > tr:nth-child(1) > td:nth-child(3)
