def mon_dictionnaire():
    d = {
        "Hendrix": "1942",
        "Allman": "1946",
        "King": "1925",
        "Clapton": "1945",
        "Johnson": "1911",
        "Berry": "1926",
        "Vaughan": "1954",
        "Cooder": "1947",
        "Page": "1944",
        "Richards": "1943",
        "Hammett": "1962",
        "Cobain": "1967",
        "Garcia": "1942",
        "Beck": "1944",
        "Santana": "1947",
        "Ramone": "1948",
        "White": "1975",
        "Frusciante": "1970",
        "Thomson": "1949",
        "Burton": "1939",
    }
    return d


def main():
    dico = mon_dictionnaire()
    dico = {k: v for k, v in sorted(dico.items(), key=lambda x: x[1])}
    liste_artiste = list(dico.keys())
    liste_date = list(dico.values())
    i = 0
    while i < len(liste_date):
        if liste_date[i] == liste_date[i - 1]:
            if liste_artiste[i] < liste_artiste[i - 1]:
                liste_artiste[i], liste_artiste[i - 1] = liste_artiste[i - 1], liste_artiste[i]
                liste_date[i], liste_date[i - 1] = liste_date[i - 1], liste_date[i]
        i += 1
    for elem in liste_artiste:
        print(elem)

if __name__ == "__main__":
    main()