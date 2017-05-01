class strCmpTest {
    public static void main(String atg[]) {
        String str1 = new String("hello, world");
        String str2 = new String("hello, world");
        
        /* compares the object "references" */
        System.out.println(str1 == str2); // false

        /* compares the object "values" */
        System.out.println(str1.equals(str2)); // true
    }
}
