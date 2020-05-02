import requests
import sys
from bs4 import BeautifulSoup


# ne pas oublier de faire le fichier reaquirements

#trouver le titre de la page et l'ajouter a road_to_philosophy


def main():
    links = [sys.argv[1].replace(" ", "_")]
    road_to_philosophy = [sys.argv[1]]
    # print(sys.argv[1].replace(" ", "_"))
    myfile = open('tmpFile', 'w')
    # links = open('links', 'w')
    #prameters of the url with our argument
    # param = {'titles':sys.argv[1],} 
    #send the request
    #if no result

    page_visitees = 0
    while True:
        # print("Page que l'on va visiter : ", road_to_philosophy[-1])
        link = "https://en.wikipedia.org/wiki/" + links[-1]
        print("lien : ", link)
        response = requests.get(link) 
        if response.status_code != 200: 
            print("Erreur", str(response.status_code))
            exit()
        else:
            response = response.text
        soup = BeautifulSoup(response, features="html.parser")
        soup.prettify()

        titre_page = soup.title.string[:-12]
        if page_visitees > 0:
            road_to_philosophy.append(titre_page)

        if road_to_philosophy[-1] == "Philosophy":
            break

        #div global la moins globale avec tout les sous elements
        div = soup.find("div", {"class": "mw-parser-output"})
        #Les paragraphes de cette div
        paragraphes = div.findChildren("p" , recursive=False)

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

        #On test si il y a des liens
        try:
            liens = paragraphe.findChildren("a" , recursive=True)
            # for lien in liens:
            #     print(lien)
            i = 0
            while i < len(liens):
                # print("ici", liens[i]['href'])
                if liens[i].has_attr('href'):
                    if "/wiki/Help" not in liens[i]['href'] and "/wiki/" in liens[i]['href'][0:6] and "About this sound" not in liens[i]['title']:
                        break
                    else:
                        i += 1
                else:
                    i += 1

            first_link = liens[i].get('href').split("/")[-1]
        except Exception as error:
            # print(type(error))
            # print(error.args) 
            print("It leads to a dead end!")
            page_visitees = -1
            break

        #On test si le lien a deja ete visite
        if first_link in links:
            print("It leads to an infinite loop!")
            # road_to_philosophy.append(first_link) 
            page_visitees = -1
            break

        print(first_link)
        links.append(first_link.replace(" ", "_"))
        # print(first_link) #Pour voir ou on en est
        page_visitees += 1

    if page_visitees > 0:
        for element in road_to_philosophy:
            print(element)
        print(page_visitees, "roads from " + road_to_philosophy[0] + " to philosophy")
    myfile.close()
    # links.close()


if __name__ == "__main__":
    main()