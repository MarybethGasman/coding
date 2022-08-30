package com.halo;

// import java.util.HashMap;
import com.halo.util.HashMap;

public class TestHashMap {
    public static void main(String[] args) {
        final HashMap map = new HashMap(5);
        map.put("kk", "vv");
        map.put("hello", "world");
        map.put("halo", "world");
        System.out.println(map.get("kk"));
        System.out.println(map.get("hello"));
        System.out.println(map.get("halo"));
        map.remove("halo");
        map.remove("aaaa");
        System.out.println(map.get("key"));
    }
}
