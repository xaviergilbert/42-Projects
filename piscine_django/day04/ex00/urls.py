from django.urls import path

from . import views

app_name = 'ex00'
urlpatterns = [
    # ex: /polls/
    path('', views.markdown, name='index'),
]