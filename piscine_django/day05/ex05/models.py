from django.db import models

# Create your models here.
class movies(models.Model):
    episode_nb = models.IntegerField(primary_key=True)
    title = models.CharField(unique=True, max_length=64, null=False, blank=False)
    opening_crawl = models.TextField(null=True)
    director = models.CharField(null=False, blank=False, max_length=32)
    producer = models.CharField(null=False, blank=False, max_length=128)
    release_date = models.DateField(auto_now=False, auto_now_add=False, null=False, blank=False)

    def __str__(self):
        return self.title