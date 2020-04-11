def list_tuple():
    d = [
        ('Hendrix', '1942'),
        ('Allman', '1946'),
        ('King', '1925'),
        ('Clapton', '1945'),
        ('Johnson', '1911'),
        ('Berry', '1926'),
        ('Vaughan', '1954'),
        ('Cooder', '1947'),
        ('Page', '1944'),
        ('Richards', '1943'),
        ('Hamett', '1962'),
        ('Cobain', '1967'),
        ('Garcia', '1942'),
        ('Beck', '1944'),
        ('Santana', '1947'),
        ('Ramone', '1948'),
        ('White', '1975'),
        ('Frusciante', '1970'),
        ('Thomson', '1949'),
        ('Burton', '1939')
    ]
    return d

def to_dic(liste):
    dico = {}
    for elem in liste:
        dico[int(elem[1])] = elem[0]
    return dico

def main():
    liste_tuple = list_tuple()
    dictionnaire = to_dic(liste_tuple)
    for key, value in dictionnaire.items():
        print(key, ":", value)

if __name__ == "__main__":
    main()