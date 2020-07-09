import sys
import requests
import json
import dewiki


# ne pas oublier de faire le fichier reaquirements

def main():
    #prameters of the url with our argument
    param = {'action':'query', 'titles':sys.argv[1], 'prop':'revisions','rvprop':'content','format':'json'} 
    #send the request
    response = requests.get("https://fr.wikipedia.org/w/api.php", param) 
    #if no result
    if response.status_code != 200: 
        print("Erreur", str(response.status_code))
        exit()
    #json object -> python object
    response = response.json() 
    #skip useless info and go to the one we want
    requete = response['query']
    #set the name of our file search_with_spaces.wiki
    filename = sys.argv[1].strip().replace(" ", "_") + ".wiki" 
    #create the file
    myfile = open(filename, 'w')
    txt = ''
    if requete.get('pages'):
        pages = requete['pages']
        for pageId in pages:
            page = pages[pageId]
            if page.get('revisions'):
                contenu = page['revisions']
                if contenu[0].get('*'):
                    txt = contenu[0]['*'] + "\n"
    txt = dewiki.from_string(txt)
    myfile.write(txt)
    myfile.close()

if __name__ == "__main__":
    main()