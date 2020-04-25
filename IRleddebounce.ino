#include <IRremote.h>

int RECV_PIN = 2;
IRrecv irrecv(RECV_PIN);
decode_results results;

#define BUTTON_1 0xFF6897
#define BUTTON_2 0xFF9867
#define BUTTON_3 0xFFB04F

int r_LED = 9;
int y_LED = 10;
int b_LED = 13;

bool outputState = false;

void setup()
{
  pinMode(r_LED, OUTPUT);
  pinMode(b_LED, OUTPUT);
  pinMode(y_LED, OUTPUT);

  irrecv.enableIRIn();
}
void loop() {
if (irrecv.decode(&results)) {
    irrecv.resume();

    if(results.value == BUTTON_1)
    {
      outputState = !outputState;
       digitalWrite(r_LED, outputState);
    }
     if(results.value == BUTTON_2)
    {
      outputState = !outputState;
       digitalWrite(y_LED, outputState);
    }
        if(results.value == BUTTON_3)
    {
      outputState = !outputState;
       digitalWrite(b_LED, outputState);
    }
  }
  }
