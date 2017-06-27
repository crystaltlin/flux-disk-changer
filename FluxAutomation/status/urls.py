from django.conf.urls import url
from . import views
urlpatterns = [
    url(r'^$',views.foo),
    url(r'^flux-status-changed', views.statusComplete),
    url(r'^control$', views.control),
    url(r'^control/unload$', views.unloadDisk),
    url(r'^control/dump$', views.dumpDisk),
    url(r'^control/load$', views.loadDisk),
    url(r'^control/all$', views.all),

]
