from django.shortcuts import render, redirect
from .models import MessageForm
from datetime import datetime
from django.urls import reverse
from ex02 import views
from django.shortcuts import redirect


# Create your views here.
def form_exercice(request):
    # if this is a POST request we need to process the form data
    if request.method == 'POST':
        # create a form instance and populate it with data from the request:
        form = MessageForm(request.POST)
        # check whether it's valid:
        if form.is_valid():
            # inscrire les entrées du form dans le fichier log
            message = form.cleaned_data['message']
            date = datetime.utcnow().strftime('%d/%m/%Y %H:%M:%S')
            log = open("message.log", "a")
            log.write(str(date) + " : " + message + "\n")
            log.close()

            # return redirect('/ex02/form_exercice', request)
            return redirect('ex02:form_exercice')
    

    # if a GET (or any other method) we'll create a blank form
    else:
        form = MessageForm()
        # on recupere les messages dans le fichier log
        log = open("message.log", "r")
        messages = log.readlines()
        for message in messages:
            message = message[22:]
        log.close()

        return render(request, 'ex02/form_exercice.html', {
            'form': form,
            'messages': messages,
            })

# if __name__ == "__main__":
#     log = open("message.log", "r")
#     messages = log.readlines()
#     for message in messages:
#         message = message[22:]
#     print(messages)
#     log.close()