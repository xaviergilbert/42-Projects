from django.shortcuts import render
import os

# Create your views here.
def create_table():
    sortie = os.popen('python manage.py makemigrations ex01', "r").read()
    log = open("database.log", "a")
    log.write("\n" + sortie)
    log.close()
    try:
        os.system('python manage.py migrate ex01')
        if sortie == "No changes detected in app 'ex01'\n":
            return sortie
        else:
            return "Ok."
    except Exception as e:
        return str(e)

def init(request):
    response = create_table()
    return render(request, 'ex01/init.html', {'response': response})

def init_test():
    response = create_table()
    print(response)

if __name__ == "__main__":
    # create_table()
    init_test()