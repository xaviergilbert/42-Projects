from django.shortcuts import render
import requests
from bs4 import BeautifulSoup

def markdown(request):
    # link = "https://en.m.wikipedia.org/wiki/Markdown"
    # print("lien : ", link)
    # response = requests.get(link)
    # if response.status_code != 200: 
    #     print("Erreur", str(response.status_code))
    #     exit()
    # else:
    #     response = response.text
    # soup = BeautifulSoup(response, features="html.parser")
    # # print("ici")
    # soup.prettify()
    # body = soup.find('body')
    # myfile = open("./ex00/templates/markdown.html", 'w')
    # myfile.write(str(body))
    # myfile.close()
    return render(request, 'ex00/index.html')


if __name__ == "__main__":
    markdown(1)