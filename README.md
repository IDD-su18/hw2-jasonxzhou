# HW2: Text Entry Device
# CarpalTYPE
Cameron Riley & Jason Zhou 

IDD Summer 2018


We created a wearable text-entry device and LED interface. Our glove-like device can be worn on and operated by one hand, allowing users to input text by pressing the four buttons located on each of their fingertips without hindering the hand's grasping ability and finger dexterity. Text recognition is implemented using binary.

User Guide:
Enter the binary code of the letter you wish to enter using your index (0) and middle (1) fingers, then press the enter key on your fourth finger. The fifth finger enters a space.
To toggle CapsLock, press the enter key either prior to entering a character, and after the previous character has been entered.

Technical Information:   

LED Information:  
Strobe Light Show upon startup  
Red LED: CapsLock Indicator  
Yellow LED: Error Indicator  
Green LED: Successful Character Entered Indicator  
  
Finger Mappings:     
Index Finger: Bit 0 Key  
Middle Finger: Bit 1 Key  
Fourth Finger: Enter Key/CapsLock Toggle  
Fifth Finger: Space Key  

Char-to-Binary Chart:  
a: 1  
b: 10  
c: 11  
d: 100  
e: 101  
f: 110  
g: 111  
h: 1000  
i: 1001  
j: 1010  
k: 1011  
l: 1100  
m: 1101  
n: 1110  
o: 1111  
p: 10000  
q: 10001  
r: 10010  
s: 10011  
t: 10100  
u: 10101  
v: 10110  
w: 10111  
x: 11000  
y: 11001  
z: 11010  	 