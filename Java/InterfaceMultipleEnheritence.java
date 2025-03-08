interface Animal{
    void eat();
}

interface Birds{
    void fly();
}


// Class implements Multiple Interface
class Bat implements Animal, Birds {
    public void eat(){
        System.out.println("Bat is eating");
    }

    public void fly(){
        System.out.println("Bat is flying");
    }
}

public class InterfaceMultipleEnheritence {
    public static void main(String[] args) {
        Bat obj = new Bat();
        obj.eat();
        obj.fly();
    }
}
