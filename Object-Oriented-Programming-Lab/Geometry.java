abstract class Figure {
    protected int dimension1;
    protected int dimension2;
    public Figure(int dimension1, int dimension2) {
        this.dimension1 = dimension1;
        this.dimension2 = dimension2;
    }
    public abstract double area();
}
class Rectangle extends Figure {
    public Rectangle(int length, int width) {
        super(length, width);
    }
    public double area() {
        return dimension1 * dimension2;
    }
}
class Triangle extends Figure {
    public Triangle(int base, int height) {
        super(base, height);
    }
    public double area() {
        return 0.5 * dimension1 * dimension2;
    }
}
class Square extends Figure {
    public Square(int side) {
        super(side, side);
    }
    public double area() {
        return dimension1 * dimension2;
    }
}
class Geometry{
    public static void main(String[] args) {
        Figure rectangle = new Rectangle(5, 10);
        Figure triangle = new Triangle(4, 8);
        Figure square = new Square(6);
        System.out.println("Area of Rectangle: " + rectangle.area());
        System.out.println("Area of Triangle: " + triangle.area());
        System.out.println("Area of Square: " + square.area());
    }
}
