from django.shortcuts import render
from django.http import HttpResponse

rooms = [
    { "id": 1, "name": "Lets learn Python!"},
    { "id": 2, "name": "Design with me"},
    { "id": 3, "name": "Frontend Developers"},
]

def home(request):
    return render(request, "base/home.html", {"rooms": rooms})

def room(request, pk):
    return render(request , "base/room.html")
