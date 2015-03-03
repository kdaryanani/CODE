import com.ridgesoft.robotics.Servo;
import com.ridgesoft.intellibrain.IntelliBrain;
public class RotateClock implements Runnable {

public void run(){
try{
Servo leftServo = IntelliBrain.getServo(1);
Servo rightServo = IntelliBrain.getServo(2);
leftServo.setPosition(100);
rightServo.setPosition(100);
Thread.sleep(5000);
leftServo.off();
rightServo.off();

}
catch (Throwable t) {t.printStackTrace();}
}
}