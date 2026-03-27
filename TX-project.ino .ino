#include <LiquidCrystal.h>
#include <stdio.h>

#include <SoftwareSerial.h>
SoftwareSerial mySerial(A4, A5);

LiquidCrystal lcd(6, 7, 5, 4, 3, 2);
// defines pins numbers


const int trigPin = 10;
const int echoPin = 11;
int button = 12;

int rf1 = 8;
int rf2 = 9;
int rf3 = A2;
int rf4 = A3;

int buzzer = 13;


int rtr1=0;
int dist1=0,dist2=0,dist3,sts1=0,sts2=0;
long duration;
int distanceCm, distanceInch;
 
 unsigned char rcv,count,gchr='x',gchr1='x',robos='s';
 
 char pastnumber[10];
 char gpsval[50];
// char dataread[100] = "";
// char lt[15],ln[15];


int i=0,k=0;
int  gps_status=0;
float latitude=0; 
float logitude=0;                       
String Speed="";
String gpsString="";
char *test="$GPRMC";


int hbtc=0,hbtc1=0,rtrl=0;

unsigned char gv=0,msg1[10],msg2[11];
 float lati=0,longi=0;
unsigned int lati1=0,longi1=0;
unsigned char flat[5],flong[5];
unsigned char finallat[8],finallong[9];


 int ii=0;
 
float tempc=0,weight=0;
float vout=0;


String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete


unsigned int ultra_dist()
{int ud=0;
   digitalWrite(trigPin, LOW);
   delayMicroseconds(2);
   digitalWrite(trigPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(trigPin, LOW);
   duration = pulseIn(echoPin, HIGH);
   distanceCm= duration*0.034/2;
   ud = distanceCm;
   return ud;
}



void setup() 
{
 mySerial.begin(9600);

    pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
    pinMode(echoPin, INPUT); // Sets the echoPin as an Input 
    pinMode(button, INPUT_PULLUP);
    pinMode(rf1, OUTPUT);pinMode(rf2, OUTPUT);pinMode(rf3, OUTPUT);pinMode(rf4, OUTPUT);
    pinMode(buzzer, OUTPUT);
    
    digitalWrite(buzzer, HIGH);
    digitalWrite(rf1, HIGH);digitalWrite(rf2, HIGH);digitalWrite(rf3, HIGH);digitalWrite(rf4, HIGH);
  
  lcd.begin(16, 2);lcd.cursor();
  lcd.print(" Design Haptic");
  lcd.setCursor(0,1);
  lcd.print("Disabled Individual");
    delay(2000);

   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print("U:");//3-4-5-6-7,0
   
}

int dista=0;

void loop() 
{
  dista=0;
  dist1=0;
  dist2=0;

for(rtr1=0;rtr1<5;rtr1++)
   {
    dista = ultra_dist();
    dist1 = (dist1 + dista);
      delay(10);
   }

 dist1 = (dist1/5);
 lcd.setCursor(3,0);lcd.print(dist1);lcd.print("    ");delay(10);

 if(dist1 < 10) 
   {
    digitalWrite(rf1, LOW);
   }
 if(digitalRead(button) == LOW)
   {
    digitalWrite(rf2, LOW);  
   }
 if(dist1 > 10 && digitalRead(button) == HIGH)
   {
    digitalWrite(rf1, HIGH);digitalWrite(rf2, HIGH);
   }

   delay(50);
}
