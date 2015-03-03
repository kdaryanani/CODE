package package2;

public class SolutionforC {

	interface Person{
		public String getName();
		void setName(String name); 
		
	}	
		public static class Student implements Person{
			String name;
			@Override
			public String getName() {
				return name;
			}

			@Override
			public void setName(String name) {
				this.name=name;
			}
			
	}
	
	public static void main(String[]args){
		Student a = new Student();
		a.setName("Bob");
		System.out.println(a.getName());
	}


}
