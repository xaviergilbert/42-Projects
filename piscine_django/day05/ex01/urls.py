from django.urls import path
from . import views

app_name = 'ex01'
urlpatterns = [
    path('init/', views.init, name='init'),
]