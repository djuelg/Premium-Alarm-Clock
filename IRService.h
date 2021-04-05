#ifndef __IRService_H__
#define __IRService_H__

#include <Arduino.h>
#include <assert.h>
#include <IRrecv.h>
#include <IRremoteESP8266.h>
#include <IRac.h>
#include <IRtext.h>
#include <IRutils.h>

void IR_init();
void IR_read();

#endif
