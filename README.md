# Arduino Bare Metal Task Scheduler

This is a simple program which implements a task scheduler. What this does is
basically execute the series of task attached to the scheduler after the
specified task period in ms have passed.

In the example four leds controlled, two blinking at different rates and two
controlled by buttons.

## Dependencies

* `avr-gcc` and `avr-libc` to compile the code
* `avrdude` for uploading the program to the microcontroller

## Compile and upload to the board

Having the dependencies installed, compile the code running `make` or:

```console
$ make compile
```

Then with the board connected to the computer, check the port with:

```console
$ ls /dev/tty*
```

Often appears as `/dev/ttyUSB*` or `/dev/ttyACM*`, by default `/dev/ttyUSB0` is
used, to override this execute make asigning the corret port to the `PORT`
shell variable, for example:

```console
$ PORT=/dev/ttyUSB1 make upload
```
