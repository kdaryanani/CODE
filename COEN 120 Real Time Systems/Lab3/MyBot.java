import com.ridgesoft.io.Display;
import com.ridgesoft.robotics.PushButton;
import com.ridgesoft.intellibrain.IntelliBrain;

public class MyBot {
public static void main(String args[]) {
try {
Display display = IntelliBrain.getLcdDisplay();
PushButton startButton =
IntelliBrain.getStartButton();
PushButton stopButton =
IntelliBrain.getStopButton();
Runnable functions[] = new Runnable[] {
new DoBeep(),
new DoNothing(),
new RotateClock(),
new RotateAnti(),
new MoveForward(),
};
startButton.waitReleased();
IntelliBrain.setTerminateOnStop(false);
int selectedFunction = 0;
display.print(0, "Function");
display.print(1,
functions[selectedFunction].toString());
while (!startButton.isPressed()) {
if (stopButton.isPressed()) {
if (++selectedFunction >= functions.length)
selectedFunction = 0;
display.print(1,
functions[selectedFunction].toString());
stopButton.waitReleased();
}
}
IntelliBrain.setTerminateOnStop(true);
Screen[] screens = new Screen[] {
new StaticTextScreen("MyBot", "Version 0.3"),
new StaticTextScreen("Screen 1", "karan"),
new StaticTextScreen("Screen 2", "daryanani"),
};
new ScreenManager(display,
screens,
IntelliBrain.getThumbWheel(),
Thread.MIN_PRIORITY,
500);
functions[selectedFunction].run();
}
catch (Throwable t) {
t.printStackTrace();
}
}
}