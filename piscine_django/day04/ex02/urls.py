from django.urls import path
# from django.conf.urls.static import static
from . import views

app_name = 'ex02'
urlpatterns = [
    # ex: /polls/
    path('form_exercice', views.form_exercice, name='form_exercice'),
]