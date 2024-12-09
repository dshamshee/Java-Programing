// Shap Calculater
// Interface for basic shape properties
interface ShapeProperties {
    double calculateArea();
    double calculateCircumference();
}

// Abstract class for 3D shapes
abstract class ThreeDShape {
    abstract double calculateVolume();
}

// Final class for Circle
final class Circle implements ShapeProperties {
    private double radius;

    Circle(double radius) {
        this.radius = radius;
    }

    @Override
    public double calculateArea() {
        return Math.PI * radius * radius;
    }

    @Override
    public double calculateCircumference() {
        return 2 * Math.PI * radius;
    }
}

// Final class for Rectangle
final class Rectangle implements ShapeProperties {
    private double length, width;

    Rectangle(double length, double width) {
        this.length = length;
        this.width = width;
    }

    @Override
    public double calculateArea() {
        return length * width;
    }

    @Override
    public double calculateCircumference() {
        return 2 * (length + width);
    }
}

// Final class for Sphere
final class Sphere extends ThreeDShape implements ShapeProperties {
    private double radius;

    Sphere(double radius) {
        this.radius = radius;
    }

    @Override
    public double calculateArea() {
        return 4 * Math.PI * radius * radius;
    }

    @Override
    public double calculateCircumference() {
        return 2 * Math.PI * radius; // Great circle circumference
    }

    @Override
    public double calculateVolume() {
        return (4.0 / 3.0) * Math.PI * radius * radius * radius;
    }
}

// Final class for Cuboid
final class Cuboid extends ThreeDShape implements ShapeProperties {
    private double length, width, height;

    Cuboid(double length, double width, double height) {
        this.length = length;
        this.width = width;
        this.height = height;
    }

    @Override
    public double calculateArea() {
        return 2 * (length * width + width * height + height * length);
    }

    @Override
    public double calculateCircumference() {
        return 4 * (length + width + height);
    }

    @Override
    public double calculateVolume() {
        return length * width * height;
    }
}

// Main class
public class ShapeCalculator {
    public static void main(String[] args) {
        // Circle
        Circle circle = new Circle(5);
        System.out.println("Circle Area: " + circle.calculateArea());
        System.out.println("Circle Circumference: " + circle.calculateCircumference());

        // Rectangle
        Rectangle rectangle = new Rectangle(4, 6);
        System.out.println("\nRectangle Area: " + rectangle.calculateArea());
        System.out.println("Rectangle Circumference: " + rectangle.calculateCircumference());

        // Sphere
        Sphere sphere = new Sphere(3);
        System.out.println("\nSphere Area: " + sphere.calculateArea());
        System.out.println("Sphere Circumference: " + sphere.calculateCircumference());
        System.out.println("Sphere Volume: " + sphere.calculateVolume());

        // Cuboid
        Cuboid cuboid = new Cuboid(4, 5, 6);
        System.out.println("\nCuboid Area: " + cuboid.calculateArea());
        System.out.println("Cuboid Circumference: " + cuboid.calculateCircumference());
        System.out.println("Cuboid Volume: " + cuboid.calculateVolume());
    }
}
