class Text(str):
	"""
	A Text class to represent a text you could use with your HTML elements.
	Because directly using str class was too mainstream.
	"""
	def __str__(self):
		new = super().__str__().replace('>', '&gt;').replace('<', '&lt;')
		if new == '"':
			new = new.replace('"', '&quot;')
		return new.replace('\n', '\n<br />\n')

class Elem:
    class ValidationError(Exception):
        def __init__(self, msg = "This content is not a Text or a elem."):
            Exception.__init__(self, msg)

    def __init__(self, name = "div", attr = {}, content = None, type = "double"):
        self.name = name
        self.attr = attr
        self.content = []
        if content:
            self.add_content(content)
        elif content != None and not isinstance(content, Text):
            raise Elem.ValidationError
        self.type = type
    
    def __str__(self):
        if self.type == "double":
            res = "<" + self.name + self.format_attr() + ">" + self.format_content() + "</" + self.name + ">"
        else:
            res = "<" + self.name + self.format_attr() + "/>"
        return res

    def add_content(self, content):
        if type(content) == list:
            self.content += [elem for elem in content if elem != Text('')]
        elif content != Text(''):
            self.content.append(content)

    def format_attr(self):
        res = ""
        for attr in self.attr.items():
            res += " " + str(attr[0]) + "=\"" + str(attr[1]) + "\""
        return res

    def format_content(self):
        if len(self.content) == 0:
            return ""
        res = "\n"
        for elem in self.content:
            elem = str(elem).replace('\n', '\n\t')
            res += "\t" + str(elem) + "\n"
        return res

if __name__ == '__main__':
	elem = Elem(name='html',
			content=[Elem(name='head',
			content=Elem(name='title',
			content=Text('"Hello ground!"'))),
			Elem(name='body',
			content=[Elem(name='h1', content=Text('"Oh no, not again!"')),
			Elem(name='img', type='simple', attr={'src': 'http://i.imgur.com/pfp3T.jpg'})])])
	print(elem)