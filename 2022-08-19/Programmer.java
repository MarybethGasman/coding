public class Programmer {
    public static void main(String args[]) {
        System.out.println("sleep");
        try {
            Thread.currentThread();
            Thread.sleep(10000);
        } catch (InterruptedException e) {
            

        }
        System.out.println("Hello world!");
    }
}
