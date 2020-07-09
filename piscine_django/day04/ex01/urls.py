from django.urls import path
# from django.conf.urls.static import static
from . import views

app_name = 'ex01'
urlpatterns = [
    # ex: /polls/
    path('django_description', views.django_description, name='django_description'),
    path('display_process_static_page', views.display_process_static_page, name='display_process_static_page'),
    path('template_engine', views.template_engine, name='template_engine'),
]