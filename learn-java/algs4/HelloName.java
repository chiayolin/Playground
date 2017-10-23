public class HelloName {
    public static void main(String[] args) {
        if(args.length == 0)
            System.err.print("Error: missing args\n");
        
        System.out.print("Hello ");
        
        int i = 0, len = args.length;
        while(i != len) 
            System.out.print(args[i++] + ' ');
        System.out.print('\n');

        return;
    }
}
