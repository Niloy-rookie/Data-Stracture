public class bst {
    static boolean flag = false;
    static class Node{
        int data;
        Node right;
        Node left;
        Node(int data){
            this.data=data;
            this.right=this.left=null;
        }
    }
    static class BuildBst{
        static Node insert(Node root,int val){
            if(root == null){
                return new Node(val);
            }
            else if(root.data == val){
                System.out.println("Duplicate value");
                flag = true;
                return root;
            }
            else if(root.data > val){
                root.left = insert(root.left,val);
            }
            else if(root.data < val){
                root.right = insert(root.right,val);
            }
            return root;
        }
        static Node Path(Node root,int key,String path){

            if(root == null){
                return null;
            }
            if(root.data == key){
                System.out.println(root.data+":"+path);
                return root;
            }
            if(root.data > key){
                root.left = Path(root.left,key,path+"-> left");
            }
            if(root.data < key){
                root.right = Path(root.right,key,path+"-> right");
            }
            return root;
        }
    }
    public static void main(String args[]){
        int[] arr = {50,30,70,20,40,60,80,40};
        String path = "root";
        Node root = null;
        for(int val:arr){
            flag = false;
            root = BuildBst.insert(root,val);
            if(flag == true){
                BuildBst.Path(root, val, path);
            }
        }
    }
}
