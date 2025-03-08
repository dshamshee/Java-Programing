class Parent {

    String name;
    Parent(String name){
        this.name = name;
        System.out.println("Parent Constructor" + name);
    }
    public void greet(){
        System.out.println(name);
    }
}

class Child extends Parent {
    
    String name;
    Child(String name){
        super(name);
        this.name = name;
        System.out.println("Child Constructor" + name);
    }

    @Override
    public void greet(){
        super.greet();
        System.out.println("Love " + name);
    }



    public void display(){
        System.out.println("Parent Class Name: " + super.name);
        System.out.println("Child Class Name: " + name);
    }
}


public class SuperKeyword {
    public static void main(String[] args) {
        Child obj = new Child("Danish");
        obj.greet();
        obj.display();
    }
}
