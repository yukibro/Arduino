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
void procedure()
{

  if (state == DOING)
  {
    switch (keystep)
    {

      case 0:
      while(true){
        Keyboard.press(KEY_LEFT_CTRL);
        delay(100);
        Keyboard.press(KEY_RIGHT_ARROW);
        delay(80);
        Keyboard.releaseAll();
        delay(40);
        Keyboard.println("@naver.com");
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
