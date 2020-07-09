from django.db import models
from django import forms

# Create your models here.


class MessageForm(forms.Form):
    message = forms.CharField(label='message', max_length=300)

    def __init__(self, *args, **kwargs):
        super(MessageForm, self).__init__(*args, **kwargs)
        self.fields['message'].widget.attrs['placeholder'] = 'Votre message'