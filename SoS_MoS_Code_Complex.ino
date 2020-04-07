int ledPin =4;//the pin I'm working with
int blinkCounter=3;//the number of total blinks
//blink 3 parameters are equal to blink 1's, all share the same off time delay
int blinkSS=150,blinkSoSOff=100,blinkO_On=400,stgTransit=1000;//initialize all my timers
int totNumBlink=0;//this allows me to blink 9 times in total, 3 times for each stage
int stgBlink=0;//enables me to get from S to O then S 
void setup() {
  // put your setup code here, to run once:
pinMode(ledPin,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
while(totNumBlink<10){//to ensure I transition through all stages and I've blinked thrice in each category
    while(stgBlink<blinkCounter){
           while((stgBlink==0&&(totNumBlink>=0&&totNumBlink<=2))||(stgBlink==2 &&(totNumBlink>=6&&totNumBlink<=9))){
                    digitalWrite(ledPin,HIGH);
                    delay(blinkSS);
                    digitalWrite(ledPin,LOW);
                    delay(blinkSoSOff);
                    totNumBlink++; 
                    //to ensure that my code runs repeatedly
                    if(totNumBlink>9){
                          totNumBlink=1;/*reset the number of times blinked, this has to be this way
                          we cannot reset to zero as the serial monitor counter will begin at 0,1,2,3 for the next SoS which is fatal
                          to those in distress. */
                          stgBlink=0;//reset the stages of blinking to begin S then O then S
                          delay(stgTransit);//needed still to show the transition from one stage to another
                    }
                    Serial.println(totNumBlink);
                }//ends the SS combination
            delay(stgTransit);
          while(stgBlink==1&&(totNumBlink>=3&&totNumBlink<=5)){
                    digitalWrite(ledPin,HIGH);
                    delay(blinkO_On);
                    digitalWrite(ledPin,LOW);
                    delay(blinkSoSOff);
                    totNumBlink++;
                    Serial.println(totNumBlink); 
                   }//ends the O combination  
            delay(stgTransit);
            stgBlink++;
          }
       }
      }
