from django.shortcuts import render
import colorsys


def get_nuances():
    colors = [(x * 1.0 / 100) for x in range(2, 102, 2)]
    return colors

# Create your views here.
def tab_exercice(request):
    colors = get_nuances()
    return render(request, 'ex03/tab_exercice.html', {'colors': colors})

if __name__ == "__main__":
    tab_color = get_nuances()
    print(tab_color)