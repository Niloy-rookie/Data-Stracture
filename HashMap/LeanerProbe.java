package HashMap;
import java.util.*;

public class test {
    public static boolean isOccupied(int hashTable[],int bi) {
        return hashTable[bi] != 0; // check if the bucket index bi is occupied (not equal to 0)
    }
    public static void main(String[] args) {
        int hash[] = {54,26,93,17,77,31,44,55,20};
        int hashTable[] = new int[11];
        
        for(int i = 0;i < hashTable.length;i++){
            if(i < hash.length){
                int bi = hash[i] % hashTable.length;
                // linear probing on collision
                while(isOccupied(hashTable, bi)){
                    bi = (bi + 1) % hashTable.length;
                    if(bi == hashTable.length){
                        bi = 0;
                    }
                }
                hashTable[bi] = hash[i];
            }
            else{
                continue;
            }
        }
        for(int i = 0;i < hashTable.length;i++){
            System.out.println("Bucket "+i+": "+hashTable[i]);
        }
    }
}
