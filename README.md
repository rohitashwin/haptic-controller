# Haptic Controller Code

This contains the code for controlling a generic haptic actuator (or generic load) based on MPU6050 accelerometer using CC26X0 series of MCUs.

### How to use?

1. Make sure you have a launchpad set up.
2. Compile and load the MCU using XDS11C debugger.
3. Test if the MCU performs to spec.
4. Use a jumper board to load the code onto a CC26X0 MCU.
5. Before soldering off, make sure that the new MCU works by runnning it off of the Jumper board.
6. Place MCU onto a PCB (use premade design from source for best performance).

### Testing (standalone)

It's possible to test the SC subprocessor alone. You'd need an XDS11C debugger and connect it to a supported machine but instead of compiling full source, run the SCS tasks only.

### Specs 

1. Operating temps: min(MCU_SPEC, MPU6050) (one of these tends to be the bottleneck)
2. Operating voltage: 3.3V +/- 0.1V (use a rectifier to stabilise)