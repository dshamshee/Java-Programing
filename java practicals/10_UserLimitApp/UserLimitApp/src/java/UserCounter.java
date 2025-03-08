/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author danis
 */
public class UserCounter {
    private static UserCounter instance = new UserCounter();
    private int userCount = 0;

    private UserCounter() {}

    public static UserCounter getInstance() {
        return instance;
    }

    public synchronized void increment() {
        userCount++;
    }

    public synchronized void decrement() {
        if (userCount > 0) {
            userCount--;
        }
    }

    public synchronized int getUserCount() {
        return userCount;
    }
}
