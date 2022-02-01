const int trigger1 = 2; //Trigger pin of 1st Sensor
const int echo1 = 3; //Echo pin of 1st Sensor
const int trigger2 = 4; //
const int echo2 = 5;//

long time_taken;
int dist;

void setup() {
Serial.begin(115200); 
  
pinMode(trigger1, OUTPUT); 
pinMode(echo1, INPUT); 
pinMode(trigger2, OUTPUT); 
pinMode(echo2, INPUT)
; 
}

/*###Function to calculate distance###*/
void calculate_distance(int trigger, int echo)
{
digitalWrite(trigger, LOW);
delayMicroseconds(2);
digitalWrite(trigger, HIGH);
delayMicroseconds(10);
digitalWrite(trigger, LOW);

time_taken = pulseIn(echo, HIGH);
dist= time_taken*0.034/2;
if (dist>50)
dist = 50;
}

void loop() { //infinite loopy
  calculate_distance(trigger1,echo1);
  int distV =dist; //get distance of left sensor
  Serial.print("V=");
  Serial.println(distV);
  ;
  calculate_distance(trigger2,echo2);
  int distD =dist; //get distance of left sensor
  Serial.print("D=");
  Serial.println(distD);
  ;
  if(distV<=40)
     {
       calculate_distance(trigger1,echo1);
       if (distV<10 && distV>0) //Hand pushed in 
       {
       Serial.println ("Vup"); 
       delay (300);
       }
     }
   if((distV>20) && (distV<50)) //Hand pulled out
       {
      Serial.println ("Vdown"); 
      delay (300);
      }
   if(distV== 50) //Hand pulled out
       {
      Serial.println ("."); 
      delay (300);
      }
      if(distD<=40)
     {
       calculate_distance(trigger1,echo1);
       if (distD<10 && distD>0 ) //Hand pushed in 
       {
       Serial.println ("Rewind"); 
       delay (300);
       }
     }
   if((distD>20) && (distD<50)) //Hand pulled out
       {
      Serial.println ("Forward"); 
      delay (300);
      }
   if(distD== 50) //Hand pulled out
       {
      Serial.println ("."); 
      delay (300);
      }
  }
