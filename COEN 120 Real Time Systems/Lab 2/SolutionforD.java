package package2;

public class SolutionforD {

	public interface Shape {
		void setArea(double area);

		double getArea();

		void setVolume(double volume);

		double getVolume();
	}

	public static class Point implements Shape {
		double area;
		double volume;

		@Override
		public void setArea(double area) {
			this.area = area;

		}

		@Override
		public double getArea() {
			return area;
		}

		@Override
		public void setVolume(double volume) {
			this.volume = volume;

		}

		@Override
		public double getVolume() {
			return volume;
		}

	}

	public static void main(String[] args) {
		Point a = new Point();
		a.setArea(2);
		a.setVolume(12);
		System.out.println(a.getArea());
		System.out.println(a.getVolume());
	}
}
