# T-Watch-2020-Smartwatch-Port
This repo is a port of the core functionality of my ESP32 based smartwatch (https://github.com/Bellafaire/ESP32-Smart-Watch) to the TTGO T-Watch 2020. 
This firmware can track the time and date, read android phone notifications, and control spotify all through a companion BLE app installed on an android device. 

<img src="https://github.com/Bellafaire/T-Watch-2020-Smartwatch-Port/blob/master/Images/basicNotifications.gif?raw=true" height="400px" />

Music controls will appear when the android app detects that spotify is actively being played and the watch has established a connection over BLE.
Notifications can be read by tapping the bell icon, use the arrows on the right to select the notification you want to read and tap anywhere on the screen that isn't a button. 
The popup window will show all the notification data, tap anywhere outside the window to exit. 

## Installation

All sources for this file are available in this repo and can be uploded directly to the T-watch 2020 through the Arduino IDE. 
Make sure that you have the T-Watch Library installed on your Arduino IDE (https://github.com/Xinyuan-LilyGO/TTGO_TWatch_Library). 

In order to obtain phone notifications and control spotify you must have the BLE companion app running on your android device. 
The sources for the BLE Companion App can be found here: https://github.com/Bellafaire/Android-Companion-App-For-BLE-Devices Along with instructions for installation. 
**Please Note: Currently this code can only operate with the BLE Companion app up to release 1.2.0. Releases after 2.0.0 have signifigant changes to bluetooth communication**


