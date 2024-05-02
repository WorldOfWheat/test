from bs4 import BeautifulSoup
import requests

url = 'https://www.kingnet.com.tw'
headers = {'user-agent': 'Mozilla/5.0 (Windows NT 6.1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/52.0.2743.116 Safari/537.36'}

def next_common(string, current_index) -> str:
    return string.find(',', current_index) + 1

class subject_handle:
    def __init__(self) -> None:
        pass

    # 取得所有科別
    def get_subjects(self) -> list:
        web = requests.get(url, headers=headers)
        web.encoding = 'utf8'

        soup = BeautifulSoup(web.text, 'html5lib')
        # 找到 “我要諮詢” 按鈕，之後找到其之後的所有 li
        start_menu_options = soup.find('li', string='我要諮詢').find_next_siblings()
        # format li
        subjects = []
        for i in start_menu_options:
            # 去掉 li 留下 a
            a = i.findNext()
            # 從 onclick 中抓出網址
            onclick_text = a['onclick']
            subjects.append(url + '/' + self.get_start_menu_options_href(onclick_text))
        return subjects


    # 從 onclick 中把網址 href 抓出來
    def get_start_menu_options_href(self, a_text) -> list:
        # 定位到網址，並且取出網址
        left_index = 0
        for _ in range(0, 3):
            left_index = next_common(a_text, left_index)
        right_index = next_common(a_text, left_index)

        # 去掉前後的標識
        href_url = str(a_text)[left_index:right_index]
        href_url = href_url.removeprefix('\'/')
        href_url = href_url.removesuffix('\',')

        return href_url

subjects = subject_handle().get_subjects()
print(subjects)
