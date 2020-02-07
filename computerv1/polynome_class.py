class polynome_class:
    def __init__(self, chaine):
        self.signe = "+"
        self.tab = []
        self.parse_elem(chaine)
    
    def fonction(self, chaine, char):        
        signe = 1 if self.signe == "+" else -1
        index = 0
        while index < len(chaine) and chaine[index] == "+" or chaine[index] == '-':
            signe = signe * -1 if chaine[index] == '-' else signe * 1
            index +=1
        chaine = chaine[index:]
        index = 0
        while index < len(chaine) and chaine[index] != "X":
            index += 1
        if index == len(chaine):
            if len(self.tab) < 1:
                self.tab.append(int(chaine))
            else:
                self.tab[0] = (float(chaine))
        else:
            nb = int(chaine[(index + 2):])
            while len(self.tab) <= nb:
                nb -= 1
                self.tab.append(0)
            # print(self.tab)
            # print(chaine[:(index - 2)])
            self.tab[int(chaine[index + 2:])] += float(chaine[:(index - 2)]) * signe
        self.signe = char

    def parse_elem(self, chaine):
        index = 0
        while index < len(chaine) and chaine[index]:
            tmp = index
            while index < len(chaine) and chaine[index] != "+" and chaine[index] != "-" and chaine[index] != "=":
                index += 1
            # print(chaine[tmp:index-1])
            if (index == len(chaine)):
                self.fonction(chaine[tmp:index], "+")                
            else:
                self.fonction(chaine[tmp:index - 1], chaine[index])
            index += 1
