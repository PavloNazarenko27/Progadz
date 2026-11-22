import java.util.concurrent.ThreadLocalRandom;

public class Main {
    static class State {
        final int n;
        final int[] dishDone = new int[3];
        final int[] dishTaken = new int[3];
        final int[] dishServed = new int[3];
        final int[] nextClientForDish = {1, 1, 1};
        int nextNewClient = 1;
        int finishedClients = 0;

        State(int n) {
            this.n = n;
        }
    }

    public static void main(String[] args) {
        int n = args.length > 0 ? Integer.parseInt(args[0]) : 3;
        if (n <= 0) {
            return;
        }
        State s = new State(n);
        Object lock = new Object();

        Thread cook = new Thread(() -> {
            ThreadLocalRandom rnd = ThreadLocalRandom.current();
            while (true) {
                int dishToCook = 0;
                synchronized (lock) {
                    while (true) {
                        if (s.finishedClients == s.n) {
                            lock.notifyAll();
                            return;
                        }
                        boolean canCook1 = s.nextNewClient <= s.n
                                && s.dishDone[0] == s.dishTaken[0]
                                && s.dishDone[1] == s.dishTaken[1]
                                && s.dishDone[2] == s.dishTaken[2];
                        boolean canCook2 = s.nextClientForDish[1] < s.nextNewClient
                                && s.dishDone[1] < s.nextNewClient - 1
                                && s.dishDone[1] == s.dishTaken[1];
                        boolean canCook3 = s.nextClientForDish[2] < s.nextClientForDish[1]
                                && s.dishDone[2] < s.nextClientForDish[1] - 1
                                && s.dishDone[2] == s.dishTaken[2];

                        if (!canCook1 && !canCook2 && !canCook3) {
                            try {
                                lock.wait();
                            } catch (InterruptedException e) {
                                Thread.currentThread().interrupt();
                                return;
                            }
                            continue;
                        }

                        int[] candidates = new int[3];
                        int cnt = 0;
                        if (canCook1) candidates[cnt++] = 1;
                        if (canCook2) candidates[cnt++] = 2;
                        if (canCook3) candidates[cnt++] = 3;

                        dishToCook = candidates[rnd.nextInt(cnt)];
                        break;
                    }
                }

                try {
                    Thread.sleep(30);
                } catch (InterruptedException e) {
                    Thread.currentThread().interrupt();
                    return;
                }

                synchronized (lock) {
                    s.dishDone[dishToCook - 1]++;
                    System.out.println("Блюдо" + dishToCook + "- кухар");
                    lock.notifyAll();
                }
            }
        });

        Thread waitress = new Thread(() -> {
            while (true) {
                int dishToCarry = 0;
                int targetClient = 0;
                synchronized (lock) {
                    while (true) {
                        if (s.finishedClients == s.n) {
                            lock.notifyAll();
                            return;
                        }
                        int readyDish = 0;
                        for (int d = 1; d <= 3; d++) {
                            if (s.dishDone[d - 1] > s.dishTaken[d - 1]
                                    && s.dishTaken[d - 1] == s.dishServed[d - 1]) {
                                int client = s.nextClientForDish[d - 1];
                                if (d == 1 && client == s.nextNewClient && client <= s.n) {
                                    readyDish = d;
                                    targetClient = client;
                                    break;
                                }
                                if (d == 2 && client < s.nextNewClient) {
                                    readyDish = d;
                                    targetClient = client;
                                    break;
                                }
                                if (d == 3 && client < s.nextClientForDish[1]) {
                                    readyDish = d;
                                    targetClient = client;
                                    break;
                                }
                            }
                        }
                        if (readyDish == 0) {
                            try {
                                lock.wait();
                            } catch (InterruptedException e) {
                                Thread.currentThread().interrupt();
                                return;
                            }
                            continue;
                        }
                        dishToCarry = readyDish;
                        s.dishTaken[dishToCarry - 1]++;
                        if (dishToCarry == 1) {
                            s.nextNewClient++;
                        }
                        s.nextClientForDish[dishToCarry - 1] = targetClient + 1;
                        System.out.println("Блюдо" + dishToCarry + "-офіціантка");
                        break;
                    }
                }

                try {
                    Thread.sleep(30);
                } catch (InterruptedException e) {
                    Thread.currentThread().interrupt();
                    return;
                }

                synchronized (lock) {
                    s.dishServed[dishToCarry - 1]++;
                    System.out.println("Блюдо" + dishToCarry + "-кліент" + targetClient);
                    if (dishToCarry == 3) {
                        s.finishedClients++;
                    }
                    lock.notifyAll();
                }
            }
        });

        Thread clients = new Thread(() -> {
            synchronized (lock) {
                while (s.finishedClients < s.n) {
                    try {
                        lock.wait();
                    } catch (InterruptedException e) {
                        Thread.currentThread().interrupt();
                        return;
                    }
                }
            }
        });

        cook.start();
        waitress.start();
        clients.start();

        try {
            cook.join();
            waitress.join();
            clients.join();
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
    }
}