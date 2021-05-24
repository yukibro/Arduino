#include <Keyboard.h>
unsigned int keystep = 0;
enum keymouse_state
{
  DOING,
  STOPPED
};

keymouse_state state = STOPPED;
void procedure();
void setup()
{
  pinMode(8, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(13, OUTPUT);
  Serial.begin(115200);
  Keyboard.begin();
}
void loop()
{
  if (state == STOPPED)
  {
    if (digitalRead(8) == LOW) // Start this state DOING
    {
      state = DOING;
      keystep = 0;
    }
  }
  else if (state == DOING)
  {
    if (digitalRead(10) == LOW) // Stop State
    {
      state = STOPPED;
    }
  }

  if (state == STOPPED)
  {
    digitalWrite(13, LOW);
    Keyboard.releaseAll();
  }
  else if (state == DOING)
  {
    digitalWrite(13, HIGH);
  }
  procedure();
}
void firstCase(){
  Keyboard.press('H');
  delay(random(20, 25));
  Keyboard.release('H');
  delay(random(20, 25));
  Keyboard.press('E');
  delay(random(20, 25));
  Keyboard.release('E');
  delay(random(20, 25));
  Keyboard.press('L');
  delay(random(20, 25));
  Keyboard.release('L');
  delay(random(20, 25));
  Keyboard.press('L');
  delay(random(20, 25));
  Keyboard.release('L');
  delay(random(20, 25));
  Keyboard.press('O');
  delay(random(20, 25));
  Keyboard.release('O');
  delay(random(20, 25));
  Keyboard.press(KEY_RETURN);
  delay(random(20, 25));
  Keyboard.release(KEY_RETURN);
  delay(random(20, 25));
  }
void secondCase(){
  Keyboard.press('h');
  delay(random(20, 25));
  Keyboard.release('h');
  delay(random(20, 25));
  Keyboard.press('i');
  delay(random(20, 25));
  Keyboard.release('i');
  delay(random(20, 25));
  Keyboard.press(KEY_RETURN);
  delay(random(20, 25));
  Keyboard.release(KEY_RETURN);
  delay(random(20, 25));}
void thirdCase(){
  Keyboard.press('e');
  delay(random(20, 25));
  Keyboard.release('e');
  delay(random(20, 25));
  Keyboard.press('x');
  delay(random(20, 25));
  Keyboard.release('x');
  delay(random(20, 25));
  Keyboard.press('i');
  delay(random(20, 25));
  Keyboard.release('i');
  delay(random(20, 25));
  Keyboard.press('t');
  delay(random(20, 25));
  Keyboard.release('t');
  delay(random(20, 25));
  Keyboard.press(KEY_RETURN);
  delay(random(20, 25));
  Keyboard.release(KEY_RETURN);
  delay(random(20, 25));
  }
void fourthCase(){
  Keyboard.press('b');
  delay(random(20, 25));
  Keyboard.release('b');
  delay(random(20, 25));
  Keyboard.press('y');
  delay(random(20, 25));
  Keyboard.release('y');
  delay(random(20, 25));
  Keyboard.press('e');
  delay(random(20, 25));
  Keyboard.release('e');
  delay(random(20, 25));
  Keyboard.press(KEY_RETURN);
  delay(random(20, 25));
  Keyboard.release(KEY_RETURN);
  delay(random(20, 25));
  }
void procedure()
{

  if (state == DOING)
  {
    switch (keystep)
    {

      case 0:
      while(true){
        unsigned int i = random(1,5);
        if(i == 1){
          firstCase();
          } else if(i==2){
            secondCase();
            }else if(i==3){
              thirdCase();
              }else if(i==4){
                fourthCase();
                }
        }
        break;
    }
    if (keystep < 9)
    {
      keystep++;
    }
    else
    {
      keystep = 0;
      state = STOPPED;
    }
  }
}
