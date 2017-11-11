# About

ptouch is a command line tool to print labels on Brother P-Touch
printers on Linux.

There is no need to install the printer via CUPS, the printer is accessed
directly via libusb.

The tool was written for and tested with the PT-2430PC, but it should also
work with the PT-1230PC (untested so far).
Maybe others work too (please report USB VID and PID so I can include support
for further models, too).

Further info can be found at:
https://mockmoon-cybernetics.ch/computer/p-touch2430pc/

# Compile instructions

autoreconf -i
./configure --prefix=/usr
make

# Note

Dear visitor, currently I have absolutely no time for improvements on this
project (my free time currently is about one or two hours PER MONTH).
Therefore, I can not look at suggestions about improvements.
