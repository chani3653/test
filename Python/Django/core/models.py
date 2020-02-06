from django.db import models

class TimeStampedModel(models.Model):
    """Time Stamped Model"""
# Create your models here.
    created = models.DateTimeField()
    updated = models.DateTimeField()
    
    class Meta:
        abstract=True