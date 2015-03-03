package package2;

public class Solutionfor1 {

	public static class Person {

		public static String name;

		public void setName1(String name) {

			Person.name = name;

		}

		public static String getName() {

			return name;

		}

	}

	static class Student2 extends Person {

		public static int studentID;

		public void setID(int studentID) {

			Student2.studentID = studentID;

		}

		public static int getID() {

			return studentID;

		}

		public static void main(String[] args) {

			Student2 Bob = new Student2();

			Person.name = "Bob";

			Bob.setID(4);

			System.out.println(getName());

			System.out.println(getID());

		}

	}
}
