#include <IRremote.h>

const int RECV_PIN = 13;
IRrecv irrecv(RECV_PIN);
decode_results results;
unsigned long key_value = 0;
const int leftForward=A5;
const int leftBackward=A4;
const int rightForward=A3;
const int rightBackward=A2;
const int enable1=6;
const int enable2=5;
const int irPin8=3;
const int irPin7=4;
const int irPin6=7;
const int irPin5=8;
const int irPin4=9;
const int irPin3=10;
const int irPin2=11;
const int irPin1=12;
const int IR=2;
int state=0;
int ponderi[9];
int inputIRPin1=0,inputIRPin2=0,inputIRPin3=0,inputIRPin4=0,inputIRPin5=0,inputIRPin6=0,inputIRPin7=0,inputIRPin8=0;
void setup(){
      ponderi[1]=-400;
      ponderi[2]=-300;
      ponderi[3]=-200;
      ponderi[4]=0;
      ponderi[5]=0;
      ponderi[6]=200;
      ponderi[7]=300;
      ponderi[8]=400;
      Serial.begin(9600);
      irrecv.enableIRIn();
      pinMode(IR,OUTPUT);
      pinMode(leftForward,OUTPUT);
      pinMode(leftBackward,OUTPUT);
      pinMode(rightForward,OUTPUT);
      pinMode(rightBackward,OUTPUT);
      pinMode(enable1,OUTPUT);
      pinMode(enable2,OUTPUT);
      pinMode(irPin1,INPUT);
      pinMode(irPin2,INPUT);
      pinMode(irPin3,INPUT);
      pinMode(irPin4,INPUT);
      pinMode(irPin5,INPUT);
      pinMode(irPin6,INPUT);
      pinMode(irPin7,INPUT);
      pinMode(irPin8,INPUT);
      analogWrite(enable1,0);
      analogWrite(enable2,0);
      digitalWrite(IR,HIGH);
      digitalWrite(leftForward,LOW);
      digitalWrite(leftBackward,HIGH);
      digitalWrite(rightForward,LOW);
      digitalWrite(rightBackward,HIGH);
}
int lastsum=0,sum=0;
void direction(int x){
      if (x<0)
      {
      //analogWrite(enable2,state*(200+2*(x/100)*10));
        analogWrite(enable2,state*0);
        analogWrite(enable1,state*200);
        
      }
      else 
      if (x>0){
      //analogWrite(enable1,state*(200-2*(x/100)*10));
        analogWrite(enable2,state*200);
        analogWrite(enable1,0);
      
      }
      else if (x==0)
      {
        analogWrite(enable1,state*200);
        analogWrite(enable2,state*200);
      }
}
void loop(){
      lastsum=sum;
      inputIRPin1=digitalRead(irPin1);
      inputIRPin2=digitalRead(irPin2);
      inputIRPin3=digitalRead(irPin3);
      inputIRPin4=digitalRead(irPin4);
      inputIRPin5=digitalRead(irPin5);
      inputIRPin6=digitalRead(irPin6);
      inputIRPin7=digitalRead(irPin7);
      inputIRPin8=digitalRead(irPin8);
      if (inputIRPin1==inputIRPin2==inputIRPin3==inputIRPin4==inputIRPin5==inputIRPin6==inputIRPin7==inputIRPin8==0)//in case of going out of the line, keeping the last direction
          sum=lastsum;
      else
          sum=inputIRPin1*ponderi[1]+inputIRPin2*ponderi[2]+inputIRPin3*ponderi[3]+inputIRPin4*ponderi[4]+inputIRPin5*ponderi[5]+inputIRPin6*ponderi[6]+inputIRPin7*ponderi[7]+inputIRPin8*ponderi[8];//Proportion based direction
      Serial.print(inputIRPin1);
      Serial.print(inputIRPin2);
      Serial.print(inputIRPin3);
      Serial.print(inputIRPin4);
      Serial.print(inputIRPin5);
      Serial.print(inputIRPin6);
      Serial.print(inputIRPin7);
      Serial.print(inputIRPin8);
      Serial.println();
      direction(sum);
      if (irrecv.decode(&results)){
        //remote controlled start
            if (results.value == 0XFFFFFFFF)
              results.value = key_value;
            switch(results.value){
              case 0xFFA25D:
              Serial.println("CH-");
              break;
              case 0xFF629D:{
              state=0;//motors turn off
              Serial.println("CH");
              break;}
              case 0xFFE21D:{
              state=1;//motors turn on
              Serial.println("CH+");
              break;}
              case 0xFF22DD:
              Serial.println("|<<");
              break;
              case 0xFF02FD:
              Serial.println(">>|");
              break ;  
              case 0xFFC23D:
              Serial.println(">|");
              break ;               
              case 0xFFE01F:
              Serial.println("-");
              break ;  
              case 0xFFA857:
              Serial.println("+");
              break ;
              case 0xFF906F:
              Serial.println("EQ");
              break ;  
              case 0xFF6897:{
              Serial.println("0");
              break ;  }
              case 0xFF9867:
              Serial.println("100+");
              break ;
              case 0xFFB04F:
              Serial.println("200+");
              break ;
              case 0xFF30CF:
              Serial.println("1");
              break ;
              case 0xFF18E7:
              Serial.println("2");
              break ;
              case 0xFF7A85:
              Serial.println("3");
              break ;
              case 0xFF10EF:{
              Serial.println("4");
              break ;}
              case 0xFF38C7:
              Serial.println("5");
              break ;
              case 0xFF5AA5:{
              Serial.println("6");
              break ;}
              case 0xFF42BD:
              Serial.println("7");
              break ;
              case 0xFF4AB5:
              Serial.println("8");
              break ;
              case 0xFF52AD:
              Serial.println("9");
              break ;
              default: 
              Serial.println("default");
              break;
            }
            key_value = results.value;
            irrecv.resume(); 
      }
}

