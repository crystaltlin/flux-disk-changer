# flux-disk-changer

Flux disk changer is designed to enable FLUX Delta to print multiple objects without manually changing the magnetic printing disks.
- It is composed of two mechanical parts, the disk loader and unloader.
- It is controlled with raspberry pi, receiving request from FLUX Delta and gives command to Arduino+RAMP, which further controls the mechanical parts.


## What you need to do
- make sure FLUX Delta and pi server are connected to the same network
- upload arduino code to the arduino
- set up the django server inside your pi (see FluxAutomation) and run the server
- set the IP of your FLUX Delta's status callback url to your pi server's IP through Flux Studio (firmware 1.6.74+ required).
  (http://pi's_IP:portnum/flux-status-changed?st_id=%(st_id)i)
  File >> Preferences >> Machine >> choose your machine from machin list >> status callback URL
- set up hardware

  disk changer will operate after printing is completed; or control manually through http://pi's_IP:portnum/control

Note: Flux Studio cannot give printing commands of multiple objects yet. 
