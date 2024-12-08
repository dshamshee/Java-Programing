class JointAccount {
    private int balance;

    public JointAccount(int initialBalance) {
        this.balance = initialBalance;
    }

    public synchronized void deposit(int amount) {
        balance += amount;
        System.out.println(Thread.currentThread().getName() + " deposited " + amount + ". Current balance: " + balance);
        notifyAll();
    }

    public synchronized void withdraw(int amount) {
        while (balance < amount) {
            System.out.println(Thread.currentThread().getName() + " is waiting to withdraw " + amount + " due to insufficient balance.");
            try {
                wait();
            } catch (InterruptedException e) {
                System.out.println("Withdrawal interrupted for " + Thread.currentThread().getName());
            }
        }
        balance -= amount;
        System.out.println(Thread.currentThread().getName() + " withdrew " + amount + ". Current balance: " + balance);
    }
}

class DepositTask extends Thread {
    private JointAccount account;
    private int amount;

    public DepositTask(JointAccount account, int amount, String name) {
        super(name);
        this.account = account;
        this.amount = amount;
    }

    @Override
    public void run() {
        account.deposit(amount);
    }
}

class WithdrawTask extends Thread {
    private JointAccount account;
    private int amount;

    public WithdrawTask(JointAccount account, int amount, String name) {
        super(name);
        this.account = account;
        this.amount = amount;
    }

    @Override
    public void run() {
        account.withdraw(amount);
    }
}

public class BankingMultiThreaded {
    public static void main(String[] args) {
        JointAccount account = new JointAccount(1000); // Initial balance

        // Create threads for depositing and withdrawing
        Thread deposit1 = new DepositTask(account, 500, "Depositor-1");
        Thread withdraw1 = new WithdrawTask(account, 700, "Withdrawer-1");
        Thread withdraw2 = new WithdrawTask(account, 800, "Withdrawer-2");

        // Start threads
        withdraw1.start();
        withdraw2.start();
        deposit1.start();

        // Wait for threads to finish
        try {
            deposit1.join();
            withdraw1.join();
            withdraw2.join();
        } catch (InterruptedException e) {
            System.out.println("Main thread interrupted.");
        }

        System.out.println("Banking operations completed.");
    }
}
