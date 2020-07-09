from django.shortcuts import render
from .models import movies
import os

# Create your views here.
def create_table():
    sortie = os.popen('python manage.py makemigrations ex03', "r").read()
    log = open("database.log", "a")
    log.write("\n" + sortie)
    log.close()
    try:
        os.system('python manage.py migrate ex03')
        if sortie == "No changes detected in app 'ex03'\n":
            return sortie
        else:
            return "Ok."
    except Exception as e:
        return str(e)

def init(request):
    response = create_table()
    return render(request, 'ex03/init.html', {'response': response})

def populate(request):
    form = movies()

    #1
    try:
        form = movies(episode_nb=1)
        form.title = "The Phantom Menace"
        form.director = "George Lucas"
        form.producer = "Rick McCallum"
        form.release_date = "1999-05-19"
        form.save()
        response = {1: "The Phantom Menace : OK."}
    except Exception as e:
        response = {1: "The Phantom Menace : " + str(e)}

    #2
    try:
        form = movies(episode_nb=2)
        form.title = "Attack of the Clones"
        form.director = "George Lucas"
        form.producer = "Rick McCallum"
        form.release_date = "2002-05-16"
        form.save()
        response[2] = "Attack of the Clones : OK."
    except Exception as e:
        response[2] = "Attack of the Clones : " + str(e)

    #3
    try:
        form = movies(episode_nb=3)
        form.title = "Revenge of Sith"
        form.director = "George Lucas"
        form.producer = "Rick McCallum"
        form.release_date = "2005-05-19"
        form.save()
        response[3] = "Revenge of Sith : OK."
    except Exception as e:
        response[3] = "Revenge of Sith : " + str(e)

    #4
    try:
        form = movies(episode_nb=4)
        form.title = "A New Hope"
        form.director = "George Lucas"
        form.producer = "Rick McCallum, Gary Kurtz"
        form.release_date = "1977-05-25"
        form.save()
        response[4] = "A New Hope : OK."
    except Exception as e:
        response[4] = "A New Hope : " + str(e)

    #5
    try:
        form = movies(episode_nb=5)
        form.title = "The Empire Strikes Back"
        form.director = "Irvin Kershner"
        form.producer = "Rick McCallum, Gary Kurtz"
        form.release_date = "1980-05-17"
        form.save()
        response[5] = "The Empire Strikes Back : OK."
    except Exception as e:
        response[5] = "The Empire Strikes Back : " + str(e)

    #6
    try:
        form = movies(episode_nb=6)
        form.title = "Return of the Jedi"
        form.director = "Richard Marquand"
        form.producer = "Howard G. Kazanjian, George Lucas, Rick Mc Callum"
        form.release_date = "1983-05-25"
        form.save()
        response[6] = "Return of the Jedi : OK."
    except Exception as e:
        response[6] = "Return of the Jedi : " + str(e)

    #7
    try:
        form = movies(episode_nb=7)
        form.title = "The Force Awakens"
        form.director = "J. J. Abrams"
        form.producer = "Kathleen Kennedy, J. J. Abrams, Bryan Burk"
        form.release_date = "2015-12-11"
        form.save()
        response[7] = "The Force Awakens : OK."
    except Exception as e:
        response[7] = "The Force Awakens : " + str(e)

    return render(request, 'ex03/populate.html', {'responses': response})


def display(request):
    all_entries = movies.objects.all()
    return render(request, 'ex03/display.html', {'films': all_entries})


def display_test():
    all_entries = movies.objects.all()
    print(all_entries)

def init_test():
    response = create_table()
    print(response)

if __name__ == "__main__":
    # create_table()
    # init_test()
    display_test()