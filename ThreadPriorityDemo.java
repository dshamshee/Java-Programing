class CustomThread extends Thread {
    public CustomThread(String name) {
        super(name);
    }

    @Override
    public void run() {
        System.out.println("Thread " + getName() + " is running with priority " + getPriority());
        try {
            Thread.sleep(1000); // Simulate some work
        } catch (InterruptedException e) {
            System.out.println("Thread " + getName() + " was interrupted.");
        }
        System.out.println("Thread " + getName() + " has finished execution.");
    }
}

public class ThreadPriorityDemo {
    public static void main(String[] args) {
        // Create threads with different names
        CustomThread thread1 = new CustomThread("Thread-1");
        CustomThread thread2 = new CustomThread("Thread-2");
        CustomThread thread3 = new CustomThread("Thread-3");

        // Set thread priorities
        thread1.setPriority(Thread.MIN_PRIORITY); // Lowest priority
        thread2.setPriority(Thread.NORM_PRIORITY); // Default priority
        thread3.setPriority(Thread.MAX_PRIORITY); // Highest priority

        // Start threads
        thread1.start();
        thread2.start();
        thread3.start();

        // Get the names and priorities of the threads
        System.out.println("Thread names and priorities:");
        System.out.println(thread1.getName() + " - Priority: " + thread1.getPriority());
        System.out.println(thread2.getName() + " - Priority: " + thread2.getPriority());
        System.out.println(thread3.getName() + " - Priority: " + thread3.getPriority());
    }
}
