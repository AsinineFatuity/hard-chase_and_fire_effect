//the LED pins to be used
int red=4;
int yellow=7;
int green=8;
//declare the various timers to be used
int rgOn=10000;//red and green lights on
int yOn=2000;//yellow lights on
void setup() {
  // pins declared as output
pinMode(red,OUTPUT);
pinMode(yellow,OUTPUT);
pinMode(green,OUTPUT);
}

void loop() {
//red is first on
digitalWrite(red,HIGH);
digitalWrite(yellow,LOW);
delay(rgOn-yOn);//red first on for 8 seconds
/*then both red and yellow on for 2 seconds
this implies red is on for 10 seconds and yellow for only two*/
digitalWrite(yellow,HIGH);
digitalWrite(red,HIGH);
delay(yOn);
//switch both red and yellow off at the end of the 10 seconds
digitalWrite(red,LOW);
digitalWrite(yellow,LOW);
//green lights come on as the yellow and red go off this should happen immediately
digitalWrite(green,HIGH);
delay(rgOn);
digitalWrite(green,LOW);
//we light up yellow again to prepare the road users then switch it off
digitalWrite(yellow,HIGH);
delay(yOn);
digitalWrite(yellow,LOW);
}
