#ifndef SITE_WEB_H
#define SITE_WEB_H

#include <WiFi.h>
#include <WebServer.h>

extern const char *ssid;
extern const char *password;
extern WebServer server;

extern const char htmlPage[] PROGMEM;
extern bool eyesOn;

void setupWebServer();
void eteindreYeux();
void loopWebServer();


#endif
