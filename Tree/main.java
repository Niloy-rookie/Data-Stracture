public class main {
    public static void main(String[] args){
        int[] arr = {3,8,7,6,-2,-8,4,9};
        SegmentTree tree = new SegmentTree(arr);
        tree.printTree(tree.root);
    }
}
