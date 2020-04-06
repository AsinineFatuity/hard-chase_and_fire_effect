/*This program seeks to simulate fire using LEDs I realised that I could use random numbers to change the brightness of my
LEDs rapidly. I further realised that the more the range over which they were to light up, the faster the change in brightness
Then again I have to use 3 random numbers to obtain three different kinds of random brightness*/

int redLed=3;
int yellow1=5;
int yellow2=6;
byte randoNum1,randoNum2,randoNum3;// used byte as rhe values will be between zero and 255
void setup() {
Serial.begin(9600);
//initialize my random number with an analog read seed
randomSeed(analogRead(A0));
}
void loop() {

  randoNum1=random(0,256);
  Serial.println("rando1: ");
  Serial.println(randoNum1);
  randoNum2=random(0,256);
   Serial.println("rando2: ");
  Serial.println(randoNum2);
  randoNum3=random(0,256);
  Serial.println("rando3: ");
  Serial.println(randoNum3);
  
  analogWrite(redLed,randoNum1);

  analogWrite(yellow1,randoNum2);

  analogWrite(yellow2,randoNum3);


  }
 
