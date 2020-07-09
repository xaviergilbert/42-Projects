from django.shortcuts import render
from django.template import loader
import requests
from bs4 import BeautifulSoup


def get_info_from_wikipedia(page):
    link = "https://en.wikipedia.org/wiki/" + page
    print("lien : ", link)
    # https://en.m.wikipedia.org/wiki/Django_(web_framework)
    response = requests.get(link) 
    if response.status_code != 200: 
        print("Erreur", str(response.status_code))
        exit()
    else:
        response = response.text
    soup = BeautifulSoup(response, features="html.parser")
    soup.prettify()

    # body = soup.find('body')
    # myfile = open("./templates/test.html", 'w')
    # myfile.write(str(body))
    # myfile.close()

    #paragraphes d'intro
    div = soup.find("div", {"class": "shortdescription nomobile noexcerpt noprint searchaux"}, recursive=True)
    for paragraphe in div:
        print(paragraphe.text)
    # print(div.text)
    exit(0)

    #On recherche le premier (vrai) paragraphe
    for paragraphe in paragraphes:
        try:
            paragraphe['class'][0]
        except:
            try:
                gras = paragraphe.findChildren("b" , recursive=True)
                gras[0]
                # print(gras[0])
                break
            except:
                continue

# Create your views here.
def django_description(request):
    return render(request, 'ex01/django_description.html')

def display_process_static_page(request):
    return render(request, 'ex01/display_process_static_page.html')

def template_engine(request):
    return render(request, 'ex01/template_engine.html')

if __name__ == "__main__":
    get_info_from_wikipedia("Django_(web_framework)")