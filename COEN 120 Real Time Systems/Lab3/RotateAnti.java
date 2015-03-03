import com.ridgesoft.robotics.Servo;
import com.ridgesoft.intellibrain.IntelliBrain;

public class RotateAnti implements Runnable {
public void run(){
Servo leftServo = IntelliBrain.getServo(1);
Servo rightServo = IntelliBrain.getServo(2);
try{
	leftServo.setPosition(0);
	rightServo.setPosition(0);
	Thread.sleep(5000);
	leftServo.off();
	rightServo.off();
}
catch(Throwable t){t.printStackTrace();}
}
}