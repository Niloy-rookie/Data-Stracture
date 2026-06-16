public class Tree {
    static class Node{
        int data;
        Node left;
        Node right;
        Node(int data){
            this.data =  data;
            this.left=this.right = null;
        }
    }
    class BuildTree{
        static Node buildtree(int[] arr,int i){
            if(i >= arr.length || arr[i] == -1){
                return null;
            }
            Node root = new Node(arr[i]);
            root.left=buildtree(arr, 2*i+1);
            root.right=buildtree(arr,2*i+2);
            return root;
        }
    }
    class traverse{
        static void preorder(Node root){
            if(root == null){
                return;
            }
            System.out.print(root.data+" ");
            preorder(root.left);
            preorder(root.right);
        }
        static void postorder(Node root){
            if(root == null){
                return;
            }
            postorder((root.left));
            postorder(root.right);
            System.out.print(root.data+" ");
        }
    }
    public static void main(String args[]){
        int[] arr = {1,2,3,4,5,6,7,8,9,10};
        Node root = BuildTree.buildtree(arr,0);
        traverse.preorder(root);
        System.out.println();
        traverse.postorder(root);    }
}
