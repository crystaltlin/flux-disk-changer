# -*- coding: utf-8 -*-
from __future__ import unicode_literals
from django.http import HttpResponse, HttpRequest, QueryDict
from django.shortcuts import render
import os



def foo(request):
    return render(request, "st_id.html", locals())

def statusComplete(request):
    statusID = request.GET.__getitem__("st_id")
    if statusID == '64':
        print('Print Complete')
        os.system("python3 /home/pi/machine_control/automation.py")
        return HttpResponse('Print Complete')
    else: 
        return HttpResponse(statusID)

def control(request):
    return render(request, 'control.html', locals())

def loadDisk(request):
    os.system("python3 /home/pi/machine_control/loadDisk.py")
    return render(request, 'control.html', locals())

def dumpDisk(request):
    os.system("python3 /home/pi/machine_control/dumpDisk.py")
    return render(request, 'control.html', locals())

def unloadDisk(request):
    os.system("python3 /home/pi/machine_control/unloadDisk.py")
    return render(request, 'control.html', locals())

def all(request):
    os.system("python3 /home/pi/machine_control/automation.py")
    return render(request, 'control.html', locals())
