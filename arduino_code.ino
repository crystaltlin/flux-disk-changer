// controls the movement of disk loader and unloader

// commands (serial monitor):
// "GO S1 D " - unload disk
// "GO S1 R " - dump disk
// "GO S2 D " - load new disk


// pin num for stepper motor one (S1)
#define pin_stp      26
#define pin_dir      28
#define pin_en       24
// pin num for stepper motor two (S2)
#define pin_stp2      60
#define pin_dir2      61
#define pin_en2       56
#define uart Serial

// params for servor motor
int incomingByte = 0;
// change servo0 and servo180 to adjust the disk dumping angle
// ending point
int servo0 = 900;
// starting point
int servo180 = 1555;
int inc = 20;
int pos = servo180;

// pin num for servo motor
int servoPin = 6;
int pulseInterval=2000;

typedef struct {
    int stp;
    int dir;
    int en;
}stepperType;

stepperType stepper[2];
void setup() {
  uart.begin(115200);
  stepper[0].stp = pin_stp;
  stepper[0].dir = pin_dir;
  stepper[0].en = pin_en;
  stepper[1].stp = pin_stp2;
  stepper[1].dir = pin_dir2;
  stepper[1].en = pin_en2;

  pinMode(pin_en,OUTPUT);
  pinMode(pin_stp,OUTPUT);
  pinMode(pin_dir,OUTPUT);
  pinMode(pin_en2,OUTPUT);
  pinMode(pin_stp2,OUTPUT);
  pinMode(pin_dir2,OUTPUT);
  pinMode(servoPin, OUTPUT);;
  digitalWrite(pin_en,LOW);
  digitalWrite(pin_dir,LOW);
  digitalWrite(pin_en2,LOW);
  digitalWrite(pin_dir2,LOW);
}

void loop() {
    if (uart.find("GO "))
    {
        int stp_num;
        String stepper = uart.readStringUntil(' ');
        if(stepper=="S1"){
            stp_num = 0;
        }else if(stepper=="S2"){
            stp_num = 1;
        }
        else {
            return;
        }
        String direction = uart.readStringUntil(' ');
        if (direction == "D")
        {
            step(stp_num,19000,100,HIGH);
            uart.print("forward\n");
            delay(1000);
            step(stp_num, 19000, 100, LOW);
            uart.print("backward\n");
            uart.print("done\n");
      
        }

        else if (direction == "R")
         {
     while (1==1) {
       int i;
       pos -= inc;
       uart.print(pos);
       uart.print("\n");
        
       if (pos > servo180) {
        uart.print("REVERSE!");
        pos = servo180;
        inc *= -1;
        delay(500);
        break;
      } 
      else if (pos < servo0) {
        uart.print("STOP!");
        pos = servo0;
        inc *= -1;
        delay(1500);
       
      }


    
      digitalWrite(servoPin, HIGH);
      delayMicroseconds(pos);
      digitalWrite(servoPin, LOW);
      delay(20);
     }
    }
    }

}

void step(int stepper_num,int count,int delay_time_us,bool dir){
  digitalWrite(stepper[stepper_num].dir,dir);
  for(int i=0;i<count;i++){
    digitalWrite(stepper[stepper_num].stp,HIGH);
    delayMicroseconds(delay_time_us);
    digitalWrite(stepper[stepper_num].stp,LOW);
    delayMicroseconds(delay_time_us);
  }
}

