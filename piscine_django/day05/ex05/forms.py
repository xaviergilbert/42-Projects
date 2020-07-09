from django import forms
from django.forms import ModelForm
from .models import movies

class RemoveForm(forms.ModelForm): 
    class Meta:
        model = movies
        # fields = ["title"]
        fields = '__all__'
    choice = forms.ModelChoiceField(queryset=movies.objects.all())