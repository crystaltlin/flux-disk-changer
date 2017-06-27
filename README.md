# flux-disk-changer

Flux disk changer is designed to enable FLUX Delta to print multiple objects without manually changing the magnetic printing disks.
- It is composed of two mechanical parts, the disk loader and unloader.
- It is controlled with raspberry pi, receiving request from FLUX Delta and gives command to Arduino+RAMP, which further controls the mechanical parts.


## What you need to do
- make sure FLUX Delta and pi server are connected to the same network
- upload arduino code to the arduino
- set up the django server inside your pi (see FluxAutomation) and run the server
- copy the machine_control directory to pi
- set the IP of your FLUX Delta's status callback url to your pi server's IP through Flux Studio (firmware 1.6.74+ required).
  (http://pi's_IP:portnum/flux-status-changed?st_id=%(st_id)i)
   <br>File >> Preferences >> Machine >> choose your machine from machine list >> status callback URL
- set up hardware

  disk changer will operate after printing is complete; or control manually through http://pi's_IP:portnum/control

## File notes
- FluxAutomation is the django project created in the pi server.
- machine_control are the py files that will be executed when pi server receives a request reporting print complete. The py file sends command to arduino.

Note: Flux Studio cannot give printing commands of multiple objects yet. 
