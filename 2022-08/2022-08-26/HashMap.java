package com.halo.util;

import java.util.Random;

/**
 * HashMap
 */
public class HashMap<K, V> {

    static class Node<K, V> {
        int hash;
        K key;
        V value;

        Node(int hash, K key, V value) {
            this.hash = hash;
            this.key = key;
            this.value = value;
        }
    }

    private final static int defaultCapacity = 10;

    private Node<K, V>[] data;

    private int size;

    public HashMap(int capacity) {
        @SuppressWarnings({ "unchecked" })
        Node<K, V>[] table = (Node<K, V>[]) new Node[capacity];
        data = table;
    }

    public HashMap() {
        this(defaultCapacity);
    }

    public int size() {
        return size;
    }

    public V get(K key) {
        int index = hash(key);
        while (data[index] != null && key != data[index].key) {
            index = hash(key);
        }
        if (data[index] == null) {
            return null;
        }
        return data[index].value;
    }

    public void put(K key, V value) {
        int hash = hash(key);
        while (data[hash] != null) {
            hash = hash(key);
        }
        data[hash] = new Node(hash, key, value);
        size++;
    }

    public void remove(K key) {
        int index = hash(key);
        while (data[index] != null && key != data[index].key) {
            index = hash(key);
        }
        if (data[index] != null) {
            data[index] = null;
            size--;
        }
    }

    private int hash(K key) {
        int h;
        h = (key == null) ? 0 : (h = key.hashCode()) ^ (h >>> 16);
        return h % data.length;
    }
}