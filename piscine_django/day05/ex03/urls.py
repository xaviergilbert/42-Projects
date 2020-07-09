from django.urls import path
from . import views

app_name = 'ex03'
urlpatterns = [
    path('init/', views.init, name='init'),
    path('populate/', views.populate, name='populate'),
    path('display/', views.display, name='display'),
]