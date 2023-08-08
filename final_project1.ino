#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(32,16,2);
int a1=6,b1=7,c1=13,d1=12,e1=11,f1=5,g1=4; //firist 7 segment
int a2=3,b2=2,c2=10,d2=9,e2=8,f2=1,g2=0; //second 7 segment
char button1=A2,button2=A3; //two buttons
char buzzer1=A0,buzzer2=A1; //two buzzers
int score=0;
void setup() {
for(int i=0;i<=15;i++){pinMode(i,OUTPUT);}
pinMode(button1,INPUT_PULLUP);pinMode(button2,INPUT_PULLUP);
lcd.init();lcd.backlight();lcd.print("loading....");delay(500);
digitalWrite(buzzer1,1);lcd.clear();
}

void zero1(){digitalWrite(a1,1);digitalWrite(b1,1);digitalWrite(c1,1);digitalWrite(d1,1);
digitalWrite(e1,1);digitalWrite(f1,1);digitalWrite(g1,0);}
void one1(){digitalWrite(a1,0);digitalWrite(b1,1);digitalWrite(c1,1);digitalWrite(d1,0);
digitalWrite(e1,0);digitalWrite(f1,0);digitalWrite(g1,0);}
void two1(){digitalWrite(a1,1);digitalWrite(b1,1);digitalWrite(c1,0);digitalWrite(d1,1);
digitalWrite(e1,1);digitalWrite(f1,0);digitalWrite(g1,1);}
void three1(){digitalWrite(a1,1);digitalWrite(b1,1);digitalWrite(c1,1);digitalWrite(d1,1);
digitalWrite(e1,0);digitalWrite(f1,0);digitalWrite(g1,1);}
void four1(){digitalWrite(a1,0);digitalWrite(b1,1);digitalWrite(c1,1);digitalWrite(d1,0);
digitalWrite(e1,0);digitalWrite(f1,1);digitalWrite(g1,1);}
void five1(){digitalWrite(a1,1);digitalWrite(b1,0);digitalWrite(c1,1);digitalWrite(d1,1);
digitalWrite(e1,0);digitalWrite(f1,1);digitalWrite(g1,1);}
void six1(){digitalWrite(a1,1);digitalWrite(b1,0);digitalWrite(c1,1);digitalWrite(d1,1);
digitalWrite(e1,1);digitalWrite(f1,1);digitalWrite(g1,1);}
void seven1(){digitalWrite(a1,1);digitalWrite(b1,1);digitalWrite(c1,1);digitalWrite(d1,0);
digitalWrite(e1,0);digitalWrite(f1,0);digitalWrite(g1,0);}
void eight1(){digitalWrite(a1,1);digitalWrite(b1,1);digitalWrite(c1,1);digitalWrite(d1,1);
digitalWrite(e1,1);digitalWrite(f1,1);digitalWrite(g1,1);}
void nine1(){digitalWrite(a1,1);digitalWrite(b1,1);digitalWrite(c1,1);digitalWrite(d1,0);
digitalWrite(e1,0);digitalWrite(f1,1);digitalWrite(g1,1);}
/////////////////////////
void zero2(){digitalWrite(a2,1);digitalWrite(b2,1);digitalWrite(c2,1);digitalWrite(d2,1);
digitalWrite(e2,1);digitalWrite(f2,1);digitalWrite(g2,0);}
void one2(){digitalWrite(a2,0);digitalWrite(b2,1);digitalWrite(c2,1);digitalWrite(d2,0);
digitalWrite(e2,0);digitalWrite(f2,0);digitalWrite(g2,0);}
void two2(){digitalWrite(a2,1);digitalWrite(b2,1);digitalWrite(c2,0);digitalWrite(d2,1);
digitalWrite(e2,1);digitalWrite(f2,0);digitalWrite(g2,1);}
void three2(){digitalWrite(a2,1);digitalWrite(b2,1);digitalWrite(c2,1);digitalWrite(d2,1);
digitalWrite(e2,0);digitalWrite(f2,0);digitalWrite(g2,1);}
void four2(){digitalWrite(a2,0);digitalWrite(b2,1);digitalWrite(c2,1);digitalWrite(d2,0);
digitalWrite(e2,0);digitalWrite(f2,1);digitalWrite(g2,1);}
void five2(){digitalWrite(a2,1);digitalWrite(b2,0);digitalWrite(c2,1);digitalWrite(d2,1);
digitalWrite(e2,0);digitalWrite(f2,1);digitalWrite(g2,1);}
void six2(){digitalWrite(a2,1);digitalWrite(b2,0);digitalWrite(c2,1);digitalWrite(d2,1);
digitalWrite(e2,1);digitalWrite(f2,1);digitalWrite(g2,1);}
void seven2(){digitalWrite(a2,1);digitalWrite(b2,1);digitalWrite(c2,1);digitalWrite(d2,0);
digitalWrite(e2,0);digitalWrite(f2,0);digitalWrite(g2,0);}
void eight2(){digitalWrite(a2,1);digitalWrite(b2,1);digitalWrite(c2,1);digitalWrite(d2,1);
digitalWrite(e2,1);digitalWrite(f2,1);digitalWrite(g2,1);}
void nine2(){digitalWrite(a2,1);digitalWrite(b2,1);digitalWrite(c2,1);digitalWrite(d2,0);
digitalWrite(e2,0);digitalWrite(f2,1);digitalWrite(g2,1);}
void scroll(){for(int i=15;i>=1;i--){lcd.setCursor(i,1);lcd.print("#");lcd.print("             ");}}
void number(){switch(score){case 0:zero1();zero2();break;case 1:one1();break;case 2:two1();
break;case 3:three1();break;case 4:four1();break;case 5:five1();break;case 6:six1();break;case 7:seven1();
break;case 8:eight1();break;case 9:nine1();break;case 10:zero1();one2();break;}}

void loop() {number();
lcd.clear();
lcd.setCursor(8,0);lcd.print("score:");lcd.setCursor(14,0);lcd.print(score);lcd.setCursor(1,1);lcd.print(">");
lcd.setCursor(15,1);lcd.print("#");scroll();
int reading1=digitalRead(button1);int reading2=digitalRead(button2);
if(reading1==0&&reading2==1){score++;tone(buzzer2,400,500);lcd.setCursor(1,1);lcd.print(" ");lcd.setCursor(1,0);lcd.print(">");delay(500);
lcd.setCursor(1,0);lcd.print(" ");lcd.setCursor(1,1);lcd.print(">");lcd.setCursor(14,0);lcd.print(score);delay(1000);}
else if(reading1==0&&reading2==0){lcd.clear();lcd.print("restarting game");tone(buzzer2,200,1000);delay(1000);score=0;}
else if(reading1==1&&reading2==1){lcd.clear();lcd.print("game over");tone(buzzer2,900,500);delay(500);score=0;}
else if(reading1==1&&reading2==0){lcd.clear();lcd.print("restarting game");tone(buzzer2,200,1000);delay(1000);score=0;}
if(score==11){lcd.clear();lcd.home();tone(buzzer2,3000,2000);lcd.print("congrats gameover");
lcd.setCursor(0,1);lcd.print("developed by KTK");tone(buzzer1,1500,1000);delay(5000);score=0;}
}
