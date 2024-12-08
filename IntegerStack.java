public class IntegerStack {
    private int[] stack;
    private int top;

    // Constructor to initialize the stack with a size of 10
    public IntegerStack() {
        stack = new int[10];
        top = -1; // Stack is empty initially
    }

    // Push method to add an element to the stack
    public void push(int value) {
        if (top < stack.length - 1) {
            stack[++top] = value; // Increment top and add value
            System.out.println(value + " pushed to stack.");
        } else {
            System.out.println("Stack overflow! Cannot push " + value);
        }
    }

    // Pop method to remove and return the element from the stack
    public int pop() {
        if (top >= 0) {
            int poppedValue = stack[top--]; // Get value and decrement top
            System.out.println(poppedValue + " popped from stack.");
            return poppedValue;
        } else {
            System.out.println("Stack underflow! No elements to pop.");
            return -1; // Return -1 to indicate underflow
        }
    }

    // Method to check the top value of the stack without removing it
    public int peek() {
        if (top >= 0) {
            return stack[top];
        } else {
            System.out.println("Stack is empty.");
            return -1;
        }
    }

    // Method to check if the stack is empty
    public boolean isEmpty() {
        return top == -1;
    }

    // Method to check if the stack is full
    public boolean isFull() {
        return top == stack.length - 1;
    }

    public static void main(String[] args) {
        IntegerStack stack = new IntegerStack();

        // Push some elements to the stack
        stack.push(10);
        stack.push(20);
        stack.push(30);
        stack.push(40);
        stack.push(50);

        // Pop elements from the stack
        stack.pop();
        stack.pop();

        // Push more elements to fill the stack
        stack.push(60);
        stack.push(70);
        stack.push(80);
        stack.push(90);
        stack.push(100);

        // Attempting to push when stack is full
        stack.push(110);

        // Pop the remaining elements
        while (!stack.isEmpty()) {
            stack.pop();
        }
    }
}
