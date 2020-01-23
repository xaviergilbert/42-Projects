class Evaluator:
    def __init__(self, coefs, words):
        print("on passe dans init")
        self.coefs = []
        self.words = []
    def zip_evaluate(coefs, words):
        lst = zip(coefs, words)
        answer = 0
        for tup in lst:
            answer += tup[0] * len(tup[1])
        print(answer)
    def enumerate_evaluate(coefs, words):
        words = enumerate(words)
        ret = 0
        for count, elem in words:
            ret += len(elem) * coefs[count]
        print(ret)
coefs = [1.0, 2.0, 1.0, 4.0, 0.5]
words = ["Le", "Lorem", "Ipsum", "est", "simple"]
print(type(words))
Evaluator.zip_evaluate(coefs, words)
# words = ["Le", "Lorem", "Ipsum", "n'", "est", "pas", "simple"]
# coefs = [0.0, -1.0, 1.0, -12.0, 0.0, 42.42]
print("evaluate :")
Evaluator.enumerate_evaluate(coefs, words)