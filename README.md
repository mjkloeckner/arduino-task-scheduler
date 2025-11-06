# AVR Bare Metal Task Scheduler

This is a simple program that implements a task scheduler for avr based mcus,
in particular ATmega328. It executes a series of tasks attached to the
scheduler after their specified task period has passed

## In this example

Four LEDs are controlled: two blink at different rates, and the other two
controlled by two buttons. The first button implements a 150 ms button debounce,
on idle the LED is off, when the button is pressed the LED toggles on and keeps
on that state for 150 ms, independently of the button state, if the button is
kept pressed the LED will keep on, if the button is released the LED will turn
off. The second button is simpler, if the button is pressed the led is on, and
if the button is not pressed the led is off

## Scheduler usage

The tasks are assigned to the scheduler with the following statements:

```c
task_t tasks[] = {
    //   on_update   period                id
    { toggle_led_1,    1000,  TOGGLE_LED_1_ID },
    { toggle_led_2,     500,  TOGGLE_LED_2_ID },
    { read_button_a,      0,    READ_BTN_A_ID },
    { read_button_b,      0,    READ_BTN_B_ID }
};

scheduler_init(tasks, sizeof(tasks)/sizeof(tasks[0]));
```

The scheduler invokes the `on_update` field function when the specified period
for that task has passed, the period being in milliseconds. When the period is
zero, the function updates on every millisecond. The `id` field is optional, in
the example is used to change the period of the `READ_BTN_A` task, when the
button is pressed the period is set to 150 ms, and on the next upadate it will
be set back to 0 if the button has been released, if the button has not been
released the period stays the same at 150 ms

The `scheduler_tick` must be called on every millisecond, this only signals the
scheduler that a tick has passed, all the tasks execution happens when the
`scheduler_update` function get called

> **NOTE**: tasks are executed sequentially, so if one task takes more than 1 ms
> to execute and another task needs to run at the same time, the first task will
> delay the other

## Dependencies

On Linux the following packages are needed to compile the code:

* `avr-gcc` and `avr-libc` to compile the code
* `avrdude` for uploading the program to the microcontroller

## Compile and upload to the board

Having the dependencies installed, compile the code using `make` from a shell,
as follows:

```console
$ make compile
```

Then with the board connected to the computer, check the port with:

```console
$ ls /dev/tty*
```

Often appears as `/dev/ttyUSB*` or `/dev/ttyACM*`, by default `/dev/ttyUSB0` is
used, to override this execute make assigning the corred port to the `PORT`
shell variable, for example:

```console
$ PORT=/dev/ttyUSB1 make upload
```
