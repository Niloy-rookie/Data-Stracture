public class SegmentTree {
    public static void main(String[] args){
        int[] arr = {3,8,7,6,-2,-8,4,9};
        SegmentTree tree = new SegmentTree(arr);
    }
    private static class Node {
        int data;
        int start;
        int end;
        Node left;
        Node right;

        public Node(int start,int end){
            this.start = start;
            this.end = end;
        }
    }

    Node root;
    public SegmentTree(int[] arr){
        this.root = buildTree(arr,0,arr.length-1);
    }

    public Node buildTree(int[] arr,int start,int end){
        if(start == end){
            Node leaf = new Node(start,end);
            leaf.data = arr[start];
            return leaf;
        }
        Node node = new Node(start,end);

        int mid = (start+end) / 2;
        node.left = buildTree(arr,start,mid);
        node.right = buildTree(arr,mid+1,end);

        node.data = node.left.data + node.right.data;
        return node;
    }

    public void printTree(Node node){
        String str = "";
        if(node.left != null){
            str = str + "Interval=["+ node.left.start +","+node.left.end+"] and data: "+node.left.data + "+ ->";
        }
        else{
            str = str+"NO left child ";
        }

        //for current node

        str = str + "Interval=[" + node.start+","+node.end+"] and data:"+node.data+"<-";

        if(node.right != null){
            str = str + "Interval=["+ node.right.start +","+node.right.end+"] and data: "+node.right.data + "+ ->";
        }
        else{
            str = str+"NO right child ";
        }
        System.out.println(str);

        if(node.left != null){
            printTree(node.left);
        }
        if(node.right != null){
            printTree(node.right);
        }
    }

    public int query(int start,int end) {
        return query(root,start,end);
    }

    private int query(Node node,int qsi,int qei) {
        if(node.start >= qsi && node.end <= qei){
            return node.data;
        }
        else if(node.start > qei || node.end < qsi){
            return 0;
        }
        else{
            return this.query(node.left,qsi,qei) + this.query(node.right,qsi,qei);
        }
    }

    public void update(int index,int value) {
        this.update(root,index,value);
    }
    private int update(Node node,int index,int value){
        if(index >= node.start && index <=node.end){
            if(node.start == index && node.end == index){
                node.data = value;
                return value;
            }
            else{
                int leftans = update(node.left,index,value);
                int rightans = update(node.right,index,value);
                node.data = node.left.data + node.right.data;
                return node.data;
            }
        }
        return node.data;
    }
}
