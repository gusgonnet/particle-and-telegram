/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "/home/ceajog/0trabajo/gust/particle/telegram/src/telegram.ino"
/*
 * Project telegram
 * Description: send a message via a Particle webhook to Telegram via its API
 * Author: Gustavo Gonnet gusgonnet@gmail.com
 * Date: Veganuary 2021
 */

void setup();
void loop();
void button_final_click_handler(system_event_t event, int param);
#line 8 "/home/ceajog/0trabajo/gust/particle/telegram/src/telegram.ino"
bool sendMessage = false;

void setup()
{
  System.on(button_final_click, button_final_click_handler);
}

void loop()
{

  if (sendMessage)
  {
    Particle.publish("telegramWebhook", "the button was clicked!", PRIVATE | WITH_ACK);
    sendMessage = false;
  }
}

void button_final_click_handler(system_event_t event, int param)
{
  int times = system_button_clicks(param);
  Serial.printlnf("button was clicked %d times", times);
  sendMessage = true;
}
