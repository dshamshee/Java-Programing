interface Animal{
    void eat();
    void sleep();
}

class Dog implements Animal{
   public void eat(){
        System.out.println("Dog can Eat");
    }

   public void sleep(){
        System.out.println("Dogs are spleep");
    }
}

public class InterfaceExample {
    public static void main(String[] args) {
     Dog obj = new Dog();
     obj.eat();
     obj.sleep();
        
    }

    
}
