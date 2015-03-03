package package2;

public class SolutionforE {
	public static void main(String []args){
		try{
			System.out.println("Your number could be"+ 99/0);
		}
		
		catch(ArithmeticException x){
			System.out.println("You cannot divide this by 0");
		}
	}
}
