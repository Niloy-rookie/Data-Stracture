package HashMap;

import java.util.*;

public class HashMapCode {
    static class HashMap<k, v> { // generics
        // defining LinkedList of Node
        private class Node {
            k key;
            v value;

            public Node(k key, v value) {
                this.key = key;
                this.value = value;
            }
        }

        private int n; // total number of nodes
        private int N; // total number of buckets
        private LinkedList<Node> buckets[]; // array of buckets (type Linkedlist od nodes)

        @SuppressWarnings("unchecked")
        // for removing warning of generic array creation
        public HashMap() {
            this.N = 4; // intial bucket size
            this.buckets = new LinkedList[N]; // initializing buckets
            for (int i = 0; i < N; i++) {
                buckets[i] = new LinkedList<Node>(); // initializing each bucket as a LinkedList
            }
        }

        private int hashFunction(k key) {
            int bi = key.hashCode(); // hashcode of key
            return Math.abs(bi) % N; //bucket index by taking modulus with N
        }
        private int searchInLL(k key,int bi) {
            LinkedList<Node> ll = buckets[bi]; //get the LinkedList at bucket index bi
            for(int i = 0;i < ll.size();i++){
                if(ll.get(i).key.equals(key)){
                    return i;// if key is found in the LinkedList, return its index
                }
            }
            return -1; // if key is not found, return -1
        }
        private void rehash() {
            LinkedList<Node> oldbucket[] = buckets; // store old buckets
            N= N*2;
            buckets = new LinkedList[N]; // create new buckets with double size
            for(int i = 0;i < N;i++){
                buckets[i] = new LinkedList<Node>();// initialize new buckets
            }
            for(int i = 0; i < oldbucket.length;i++){
                LinkedList<Node> ll = oldbucket[i]; // get the LinkedList at index i of old buckets
                for(int j = 0; j < ll.size();j++){
                    Node node = ll.get(j); // get the node at index j of LinkedList
                    put(node.key,node.value); // put the key and value of node in new buckets using put function
                }
            }
        }

        public void put(k key, v value) {
            int bi = hashFunction(key); // bucket index created by hash function
            int di = searchInLL(key, bi); // data index created by search function
            if (di == -1) {
                buckets[bi].add(new Node(key, value));// if key is not present in the bucket, add new node in LInkedList
                n++;
            }
            else{
                Node node = buckets[bi].get(di); // if key is present, update the value
                node.value = value;
            }
            double lambda = (double)n/N; //load factor
            if(lambda > 2.0){
                rehash(); // if load factor is greater than 2, rehash the HashMap
            }
        }

        public v get(k key) {
            int bi = hashFunction(key);
            int di = searchInLL(key,bi);

            if(di == -1){
                return null; // if key is not found, return null
            }
            else{
                Node node = buckets[bi].get(di); // if key is found, return its value
                return node.value;
            }
        }

        public boolean containsKey(k key) {
            int bi = hashFunction(key);
            int di = searchInLL(key, bi);

            if(di == -1){
                return false;
            }
            else{
                return true;
            }
        }

        public v remove(k key) {  //v is generic type for value
            int bi = hashFunction(key);
            int di = searchInLL(key, bi);

            if(di == -1){
                return null; // if key is not found, return null
            }
            else{
                Node node = buckets[bi].get(di);
                buckets[bi].remove(di); // if key is found, remove the node from LinkedList
                n--;
                return node.value;
            }
        }

        public ArrayList<k> keySet() {
            ArrayList<k> keys = new ArrayList<>(); // create an ArrayList to store keys
            for(int i = 0; i < buckets.length;i++){
                LinkedList<Node> ll = buckets[i]; // get the LinkedList at index i of buckets
                for(int j = 0;j < ll.size();j++){
                    Node node = ll.get(j); // get the node at index j of LinkedList
                    keys.add(node.key); // add the key of node to keys ArrayList
                }
            }
            return keys;
        }
        
        public boolean isEmpty() {
            return n == 0; // if number of nodes is 0, return true, otherwise return false
        }

        public void display() {
            for(int i = 0;i < buckets.length;i++){
                LinkedList<Node> ll = buckets[i];
                System.out.println("Bucket "+i+": ");
                for(int j = 0;j < ll.size();j++){
                    Node node = ll.get(j);
                    System.out.println("Key: "+node.key+" Value: "+node.value);
                }
                System.out.println();
            }
        }
        public static void main(String[] args) {
            HashMap<String,Integer> map = new HashMap<>();
            map.put("India", 100);
            map.put("China", 150);
            map.put("USA", 50);
            map.put("India", 120); // update value for key "India"
            map.put("Russia", 80);
            System.out.println("Value for key 'India': " + map.get("India")); // should print 120
            map.display();
            map.put("japan", 70);
            map.put("Australia",40);
            map.remove("India");
            map.display();
            System.out.println();
            System.out.println("keys in the map: "+map.keySet());
        }
    }
}

