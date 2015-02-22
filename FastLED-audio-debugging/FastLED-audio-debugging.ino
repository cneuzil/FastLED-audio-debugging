#include <FastLED.h>

// added for FastLED/audio debugging
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <Audio.h>

#define LED_PIN     2
#define COLOR_ORDER GRB
#define CHIPSET     WS2811
#define NUM_LEDS    64

#define BRIGHTNESS  25
#define FRAMES_PER_SECOND 100

CRGB leds[NUM_LEDS];

//added for FastLED/audio debugging
//AudioInputI2S          audioInput;         // audio shield: mic or line-in
AudioInputAnalog         adc1(A2);
//AudioSynthWaveformSine sinewave;
AudioAnalyzeFFT1024    myFFT;
//AudioOutputI2S         audioOutput;        // audio shield: headphones & line-out
AudioConnection patchCord1(adc1, 0, myFFT, 0);

void setup() {
  delay(3000); // sanity delay
  FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness( BRIGHTNESS );
  
  // added for FastLED/audio library debugging
  AudioMemory(12);
  myFFT.windowFunction(AudioWindowHanning1024);
}
byte toggle = 0;
void loop()
{

    if (toggle==0) {
      fill_solid(leds,NUM_LEDS,CHSV(255,255,255));
    }
    else
    {
      fill_solid(leds,NUM_LEDS,CHSV(255,255,0));
    }

  
  
  FastLED.show(); // display this frame
  FastLED.delay(1000 / FRAMES_PER_SECOND);
  toggle = !toggle;
}


