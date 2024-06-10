from django.contrib import admin
from django.urls import path, include
from . import views
urlpatterns=[
    
        
    path('parsepdf', views.parse_pdf, name="parsepdf"),
    path('uploadpdf', views.upload_pdf, name="parsepdf"),
    path('register_users', views.register_teachers, name="register_teachers"),
]