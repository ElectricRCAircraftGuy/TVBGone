TVBGone Readme  
Readme Written: 13 Feb. 2015  
Readme Last Updated: 13 Feb. 2015  

###Note: the source version of this fork is found in Ken Shirriff's repository here: https://github.com/shirriff/Arduino-TV-B-Gone. Let's keep Ken's source fork as the primary version. When I get the chance I will update it instead of mine, to first bring his up to the current status of mine, then to make his even better by making it compatible with the latest Arduino IDE. Meanwhile, feel free to use mine if you have problems with his, until I can make these changes to his.

**Note: my fork here is still not compatible with the latest Arduino IDE either. See notes below.**

**Circuit**  
(also described in the .ino file)  
Circuit:  
-Connect an IR LED to pin 3.  
-Connect a visible LED to pin 13 (or use builtin LED in some Arduinos).  
-Connect a pushbutton between pin 2 (TRIGGER) and ground.  
-Pin 5 (REGIONSWITCH) is floating for North America, or wired to ground for Europe.  

**IMPORTANT**  
1. **Note, this code will NOT compile in Arduino 1.5.7 or later, due to the newer Arduino IDEs using a newer version of the gcc compiler, which has changed the way progmem is handled. I am using Arduino 1.5.6-r2 Beta to compile and upload this code. It is available here:** http://arduino.cc/en/Main/OldSoftwareReleases  
2. You must have my eRCaGuy_ButtonReader library installed to compile this code. It is available here: http://bit.ly/eRCaGuy_ButtonReader_TVBGoneReadme  
 
**Description**  
This is my version of the TVBGone, invented by Mitch Altman, supported and expanded by Limor Fried (Ladyada), and ported to Arduino by Ken Shirriff.
Here is Ken's website, from where I originally downloaded the code: http://www.righto.com/2010/11/improved-arduino-tv-b-gone.html - his download link is at the top.  
I downloaded:  
-TV-B-Gone for Arduino version 1.2, Oct 23 2010  
-Ported to Arduino by Ken Shirriff  

I have made some slight modifications to his code, however, so you might call this version V1.21 or something now. I added debouncing to the pushbutton, for instance, using my eRCaGuy_ButtonReader library found here: http://bit.ly/eRCaGuy_ButtonReader_TVBGoneReadme -- you will need this library to compile this version of the code. I'm not sure if this makes much of a difference for this particular application, due to how the TVBGone works, but I didn't see debouncing going on already, so I thought it wasn't a bad idea.  

**For other interesting articles and info, visit my website here: (http://electricrcaircraftguy.blogspot.com/)**  

I hope you find this useful.  
~Gabriel Staples  
http://electricrcaircraftguy.blogspot.com/  
