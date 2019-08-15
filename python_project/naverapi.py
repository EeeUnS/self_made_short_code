# Token 정보 가져와서 caffe 글쓰기.. code
# !/usr/bin/env python3

# -*- coding: utf-8 -*-
import json
import os
import re
import urllib.request
import time
import random
import datetime
# import thread
import schedule

from bs4 import BeautifulSoup
import requests
from selenium import webdriver
from urllib.error import HTTPError
from urllib.parse import urlencode

DRIVER_DIR = r'C:\Users\usr\PycharmProjects\untitled\chromedriver.exe' 
#자기 chromedriver 위치


# https://junbenchmarking.tistory.com/373

def get_naver_token():
    chromedriver_path = os.environ.get('CHROMEDRIVER_PATH')
    chromedriver_path = DRIVER_DIR
    print(chromedriver_path)

    options = webdriver.ChromeOptions()
    options.add_argument('headless')
    options.add_argument('window-size=1920x1080')
    options.add_argument("disable-gpu")
    #
    options.add_argument(
        "user-agent=Mozilla/5.0 (Macintosh; Intel Mac OS X 10_12_6) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/61.0.3163.100 Safari/537.36")

    driver = webdriver.Chrome(DRIVER_DIR, chrome_options=options)

    driver.get('https://nid.naver.com/nidlogin.login')

    naver_cid = "" ##직접 등록
    naver_csec = ""
    naver_redirect = "http://localhost:8090/callback.jsp"

    id = ''  # ID  직접 입력
    pw = ''  # 비번은 직접 입력
    driver.execute_script("document.getElementsByName('id')[0].value=\'" + id + "\'")
    # time.sleep(1)
    driver.execute_script("document.getElementsByName('pw')[0].value=\'" + pw + "\'")
    # time.sleep(1)

    driver.find_element_by_xpath('//*[@id="frmNIDLogin"]/fieldset/input').click()
    time.sleep(1)
    driver.find_element_by_xpath('//*[@id="frmNIDLogin"]/fieldset/span[1]/a').click()
    time.sleep(1)
    driver.find_element_by_xpath('//*[@id="login_maintain"]/span[1]').click()
    time.sleep(1)

    state = "REWERWERTATE"

    # https://nid.naver.com/oauth2.0/authorize?response_type=code&client_id=CLIENT_ID&state=STATE_STRING&redirect_uri=CALLBACK_URL
    # https://nid.naver.com/oauth2.0/token?grant_type=authorization_code&client_id=jyvqXeaVOVmV&client_secret=527300A0_COq1_XV33cf&code=EIc5bFrl4RibFls1&state=9kgsGTfH4j7IyAkg

    req_url = 'https://nid.naver.com/oauth2.0/authorize?response_type=code&client_id=%s&redirect_uri=%s&state=%s' % (
    naver_cid, naver_redirect, state)
    driver.get(req_url)

    time.sleep(1)

    ########################## # XXX: 최초 1회만 반드시 필요하고 이후엔 불필요함

    '''
    driver.find_element_by_xpath('//*[@id="profile_optional_list"]/span/label').click()
    time.sleep(1)

    driver.find_element_by_xpath('//*[@id="content"]/div[4]/div[2]/button/span').click()
    ##########################
    '''

    redirect_url = driver.current_url
    temp = re.split('code=', redirect_url)
    code = re.split('&state=', temp[1])[0]
    driver.quit()

    url = "https://nid.naver.com/oauth2.0/token?"

    data = "grant_type=authorization_code" + "&client_id=" + naver_cid + "&client_secret=" + naver_csec + \
           "&redirect_uri=" + naver_redirect + "'&code=" + code + "&state=" + state

    request = urllib.request.Request(url, data=data.encode("utf-8"))
    request.add_header('X-Naver-Client-Id', naver_cid)
    request.add_header('X-Naver-Client-Secret', naver_redirect)
    response = urllib.request.urlopen(request)
    rescode = response.getcode()

    token = ''
    if rescode == 200:
        response_body = response.read()
        js = json.loads(response_body.decode('utf 8'))
        token = js['access_token']
    else:
        print("Error Code:", rescode)
        return None

    if len(token) == 0:
        return None
    # print(token)
    return token


def naver_cafe_post(subject, content):
    token = get_naver_token()
    time.sleep(1)

    # 카페의 고유 ID값 일격필살 24831460
    #  자유게시판 41

    header = "Bearer " + token  # Bearer 다음에 공백 추가
    clubid = '24831460'
    menuid = '41'
    url = "https://openapi.naver.com/v1/cafe/" + clubid + "/menu/" + menuid + "/articles"

    subject = urllib.parse.quote(subject)
    content = urllib.parse.quote(content)

    data = {'subject': subject, 'content': content}

    headers = {'Authorization': header}
    response = requests.post(url, headers=headers, data=data)

    rescode = response.status_code
    if rescode == 200:
        print(response.text)

    else:
        print("Error Code:" + rescode)


def W():
    contents = ""
    print('실행중...')
    current = datetime.datetime.now()
    print(current.strftime('%m') + '월' + current.strftime('%d') + '일' + current.strftime(
        '%H') + '시 ' + current.strftime('%M') + '분' + current.strftime('%S') + '초')

    subject = current.strftime('%m') + '월' + current.strftime('%d') + '일' + current.strftime(
        '%H') + '시 ' + current.strftime('%M') + '분'
    contents = '프로그램으로 자동작성되었습니다.  <br>오늘은 ' + current.strftime('%m') + '월' + current.strftime('%d') + '일 입니다.'
    naver_cafe_post(subject, contents)
    print("done", current.strftime('%M'))


if __name__ == "__main__":
    schedule.every().day.at("00:00:00").do(W)
    while True:
        schedule.run_pending()
        time.sleep(1)

    W()


# 카페의 고유 ID값 일격필살 24831460

#  자유게시판 41
