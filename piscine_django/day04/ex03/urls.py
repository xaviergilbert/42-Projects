from django.urls import path
# from django.conf.urls.static import static
from . import views

app_name = 'ex03'
urlpatterns = [
    # ex: /polls/
    path('tab_exercice', views.tab_exercice, name='tab_exercice'),
]