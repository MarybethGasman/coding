package com.halo;

import com.halo.util.HashMap;

import java.util.Random;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;

public class ConcurrentTestHashMap {
    public static void main(String[] args) {
        Random r = new Random();
        final HashMap map = new HashMap<>(10);
        var executorService = Executors.newFixedThreadPool(5);
        for (var i = 0; i < 2; i++) {
            executorService.submit(() -> {
                while (true) {
                    map.put(r.nextInt(10), "123");
                    map.get(r.nextInt(10));
                    map.remove(r.nextInt(10));
                }
            });
        }

        executorService.shutdown();
        try {
            executorService.awaitTermination(10, TimeUnit.SECONDS);
            executorService.shutdownNow();
        } catch (InterruptedException e) {
            System.out.println("Error waiting for ExecutorService shutdown");
        }
    }
}
