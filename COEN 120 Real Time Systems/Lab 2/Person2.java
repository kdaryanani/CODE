package package2;

public class Person2{

public static class  Person{

    public static String name;

    public static String address;



    public void setName(String name){

        this.name=name;

    }



    public static String getName(){

          return name;

    }

    public void setAddress(String address){

             this.address=address;

    }

    public static String getAddress(){

         return address;

    }

    

}




public static class Student extends Person{

    public static int grade;

    public static String school;

    public  void setSchool(String school){

            this.school=school;

    }

    public static String getSchool(){

      return school;

    }



    public void setGrade(int grade){

        this.grade=grade;

    }

    public static int getGradeD(){

                   return grade;

    }

}


 public static class InternationalStudent extends Student{
	 public static String country;
	
	public  void setCountry(String country){
		this.country=country;
	}
	public static String getCountry(){
		return country;
	}
	
	
}
 public static void main(String[]args){
		Person a = new Person();
		a.setName("juanmero");
		a.setAddress("1234 baker street");
		Student b = new Student();
		b.setGrade(6);
		b.setAddress("123123 white hosue drive");
		InternationalStudent c = new InternationalStudent();
		c.setCountry("Africa");	
		
		System.out.println(a.getName());
		System.out.println(a.getAddress());
		System.out.println(b.getGradeD());
		System.out.println(b.getAddress());
		System.out.println(c.getCountry());
		
		
	}

}